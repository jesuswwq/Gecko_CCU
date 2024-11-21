
#include <string.h>
#include "nck2910.h"
#include "joker.h"
#include "UHF_FML.h"
#include "Immo_Aes_Fml.h"
#include "Pke_Pks_APP.h"
// #include <sdrv_gpio.h>
#include "Fobs_Tracking_Algorithm.H"

//-----------------------------------------------------------------------------

const uint8 Lf_Preamble_CodeViolation[4] =
	{
		0x00, 0xE2, 0xCC, 0X80};

Joker_Work_State u8Njj29c0_WorkStatus = JOKER_INIT;

// Globals
static uint8 u8PepsStep = 0;
static uint8 u8PepsTxCnt = 0;
lf_handle_state lfapp_work_sta = lf_ide;

uint8 u8ButtonTrigFlag = 0;

uint8 u8Lf_Ant_Code[3] = {0}; //??????

uint8 u8FobKeyInDoorInd = 0; //???????????
uint8 u8HitagAuthPass = 0;	 //?????????

// 锟斤拷锟斤拷ID锟斤拷锟斤拷锟斤拷通锟斤拷锟斤拷频钥锟斤拷学习
struct LF_Auth_Buff sLf_Auth_TransmitterInfo;
struct LF_FobLocate_Buff sLf_FobLocate_TransmitterInfo;

static uint8 u8Lf_Tx_Cnt = 0; // 锟斤拷锟节碉拷频锟斤拷锟竭猴�?
static uint8 u8Arr_Mac[2];

BITBYTE tsLfAntDiagStatus;

static uint8 LfAnt_Fault = 0;

uint8 u8FobKeyIndex = 0;

static uint16 u16DiagCycleTime = LF_DIAG_CYCYE; // 2000ms

FLOAT_UNION InCar_CurRssiCalcVal;
FLOAT_UNION Lf_Door_CurRssiCalcVal;
FLOAT_UNION Rf_Door_CurRssiCalcVal;

uint8 u8JokerInitInCarAntDrvCur = 0x1f; // 250ma
uint8 u8JokerInitLfAntDrvCur = 0x1f;	// 500ma
uint8 u8JokerInitRfAntDrvCur = 0x1f;	// 500ma

float Lf_DoorAnt_Rssi_Limit = 0.50;
float Rf_DoorAnt_Rssi_Limit = 0.50;
float Ps_Ant_Rssi_Limit = 0.20;

uint8_t u8PollingUnlockStep = 0;
uint8_t u8PollingLockStep = 0;

static uint8_t u8WecomeGuestWakeUpFobKeyUid[2];

static uint8_t u8PollingMode_Init_State = 0;

extern uint8_t Joker_Init_Status;

static uint8 u8PollingFuncRequestBak = 0;

static uint8_t u8DemoKeyCmd = 0;

static uint8_t u8DemoFunSel = 0;

static uint8 Ecu_PowerOn_Mode = 0;

static boolean bStartImmoAuthFlag = false;

static uint32_t u32Lf_Door_CurRssi[LF_RSSI_CACHE_LEN] = {0};
static uint32_t u32Rf_Door_CurRssi[LF_RSSI_CACHE_LEN] = {0};

static uint32_t u32Lf_CurRssi_Index = 0;
static uint32_t u32Rf_CurRssi_Index = 0;

static uint8 Vehicle_Calibration_Work = 0;
static uint16 Vehicle_Calibration_Num = 0;
#pragma default_function_attributes = @".iram_func"
void Change_Njj29c0_WorkStatus(lf_handle_state sta)
{
	lfapp_work_sta = sta;
}

lf_handle_state Get_Njj29c0_WorkStatus(void)
{
	return lfapp_work_sta;
}

uint8 GetCrc8(uint8 *pBuffer, uint16 bufSize)
{
	uint8 crc = 0;

	// 锟斤拷锟捷合凤拷
	while (bufSize-- != 0)
	{
		for (uint16 i = 0x80; i != 0; i /= 2)
		{
			if ((crc & 0x80) != 0)
			{
				crc *= 2;
				crc ^= 0x07; // 锟斤拷锟斤拷式锟斤拷X8 + X2 + X + 1
			}
			else
			{
				crc *= 2;
			}

			if ((*pBuffer & i) != 0)
			{
				crc ^= 0x07;
			}
		}

		pBuffer++;
	}

	return crc;
}

uint8 GetNJJ29C0InitCompleteStatus(void)
{
	if (u8Njj29c0_WorkStatus == 1)
	{
		return 1;
	}

	return 0;
}

uint8_t Ecu_Read_LfAnt_DiagStatus(void)
{
	return tsLfAntDiagStatus.DATA_BYTE;
}

uint8_t LoFrqAtnErrWarn(void)
{
	return LfAnt_Fault;
}

void SetEcuPowerOnMode(uint8 para)
{
	Ecu_PowerOn_Mode = para;
}

uint8 GetEcuPowerOnMode(void)
{
	return Ecu_PowerOn_Mode;
}

void SetVehicleCalibrationPara(uint8 *para)
{
	LONG_UNION Rand_Val;

	if (para[0] == 0x51)
	{
		para[0] = 0;
		if (para[1] == 0xA0)
		{
			u8JokerInitInCarAntDrvCur = para[2];
			u8JokerInitLfAntDrvCur = para[3];
			u8JokerInitRfAntDrvCur = para[3];

			tnNck2910WorkStatus = NCK2910_INIT;
		}
		else if (para[1] == 0xA1)
		{
			// 标定
			if (tnNck2910WorkStatus == NCK2910_NORMAL)
			{

				Vehicle_Calibration_Work ^= 0x01;

				if (Vehicle_Calibration_Work == 0)
				{
					JOKER_WakeUp();
				}

				Vehicle_Calibration_Num = para[2] * 256 + para[3];
			}
		}
		else if (para[1] == 0xA2)
		{
			// 遥控学习
			u8FobKeyEnterWorkState = 1; // 遥锟斤拷学习

#ifdef QN_DEBUG
			Rand_Val.Value = GetSysRandTimeCount();

			u8Universal_Key[0] = 127 ^ Rand_Val.CHAR_BYTE.High_byte;  // 0x7f
			u8Universal_Key[1] = 102 ^ Rand_Val.CHAR_BYTE.Mhigh_byte; // 0x66
			u8Universal_Key[2] = 182 ^ Rand_Val.CHAR_BYTE.Mlow_byte;  // 0xb6
			u8Universal_Key[3] = 141 ^ Rand_Val.CHAR_BYTE.Low_byte;	  // 0x8d
			u8Universal_Key[4] = 238 ^ Rand_Val.CHAR_BYTE.Mlow_byte;  // 0xee
			u8Universal_Key[5] = 34 ^ Rand_Val.CHAR_BYTE.Low_byte;	  // 0x22
			u8Universal_Key[6] = 203 ^ Rand_Val.CHAR_BYTE.High_byte;  // 0xcb
			u8Universal_Key[7] = 213 ^ Rand_Val.CHAR_BYTE.Mhigh_byte; // 0xd5
			u8Universal_Key[8] = u8Universal_Key[2] ^ u8Universal_Key[0];
			u8Universal_Key[9] = u8Universal_Key[1] ^ u8Universal_Key[0];
			u8Universal_Key[10] = u8Universal_Key[5] ^ u8Universal_Key[3];
			u8Universal_Key[11] = u8Universal_Key[7] ^ u8Universal_Key[3];

			u8Universal_Key[12] = u8Universal_Key[3] ^ u8Universal_Key[0];
			u8Universal_Key[13] = u8Universal_Key[4] ^ u8Universal_Key[0];
			u8Universal_Key[14] = u8Universal_Key[2] ^ u8Universal_Key[3];
			u8Universal_Key[15] = u8Universal_Key[1] ^ u8Universal_Key[3];
#endif
		}
		else if (para[1] == 0xA3)
		{
			// 遥控信息擦除
			u8FobKeyEnterWorkState = 2;
		}
		else if (para[1] == 0xA4)
		{
			// 复位控制�?
#ifdef DEBUG
			// VeKYM_KeySrhReq_enum = 4;

			bStartImmoAuthFlag = TRUE;
#endif
		}
		else if (para[1] == 0xA5)
		{
			// 复位控制�?
#ifdef DEBUG
			VeKYM_KeySrhReq_enum = 6;
#endif

			if (tnNck2910WorkStatus == NCK2910_NORMAL)
			{

				Vehicle_Calibration_Work = 0x01;

				Vehicle_Calibration_Num = para[2] * 256 + para[3];
			}
		}
		para[1] = 0;
	}
}

static void App_Monitor_Lf_Work_Status(void)
{
	static uint16_t u16LPEAntDriveCurrentSetLast = 0;
	static uint16_t u16RPEAntDriveCurrentSetLast = 0;
	static uint16_t u16PSAntDriveCurrentSetLast = 0;

	static uint16_t u16LPEAntRssiLimitSetLast = 0;
	static uint16_t u16RPEAntRssiLimitSetLast = 0;
	static uint16_t u16PSAntRssiLimitSetLast = 0;

	uint32_t u32calc = 0;

	float tmpcalc = 0.0;

	if (u8LPEDriverCurRead == 1) // 锟斤拷锟絇E锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷取
	{
		u32calc = u8JokerInitLfAntDrvCur * 15625;

		u32calc = u32calc / 1000;

		u16Left_Door_Ant_DriveCurrent = (uint16_t)u32calc;
	}

	if (u8RPEDriverCurRead == 1) // 锟揭诧拷PE锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷取
	{
		u32calc = u8JokerInitRfAntDrvCur * 15625;

		u32calc = u32calc / 1000;
		u16Right_Door_Ant_DriveCurrent = (uint16_t)u32calc;
	}

	if (u8PSAntDirverCurRead == 1) // PS锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷取
	{
		u32calc = u8JokerInitInCarAntDrvCur * 15625;

		u32calc = u32calc / 1000;
		u16Incar_Ant_DriveCurrent = (uint16_t)u32calc;
	}

	if (u16LPEAntRssiLimitRead == 1) // 锟斤拷锟絇E锟斤拷锟竭筹拷强锟斤拷值锟斤拷�?
	{
		u32calc = (uint32_t)(Lf_DoorAnt_Rssi_Limit * 100.0);

		u16Left_Door_Ant_Rssi_Limit = (uint16_t)u32calc;
	}

	if (u16RPEAntRssiLimitRead == 1) // 锟斤拷锟絇E锟斤拷锟竭筹拷强锟斤拷值锟斤拷�?
	{
		u32calc = (uint32_t)(Rf_DoorAnt_Rssi_Limit * 100.0);

		u16Right_Door_Ant_Rssi_Limit = (uint16_t)u32calc;
	}

	if (u16PSAntRssiLimitRead == 1) // 锟斤拷锟絇E锟斤拷锟竭筹拷强锟斤拷值锟斤拷�?
	{
		u32calc = (uint32_t)(Ps_Ant_Rssi_Limit * 100.0);

		u16Incar_Ant_Rssi_Limit = (uint16_t)u32calc;
	}

	u8FobKey_Disable_Status_Feedback = tsTransmitters[0].FobKeyEn;
	u8FobKey_Disable_Status_Feedback |= tsTransmitters[1].FobKeyEn << 1;
	u8FobKey_Disable_Status_Feedback |= tsTransmitters[2].FobKeyEn << 2;
	u8FobKey_Disable_Status_Feedback |= tsTransmitters[3].FobKeyEn << 3;
	// u8FobKey_Disable_Status_Feedback |= tsTransmitters[4].FobKeyEn<<4;

	if ((u16LPEAntDriveCurrentSet > 0) && (u16RPEAntDriveCurrentSet > 0) && (u16PSAntDriveCurrentSet > 0))
	{
		if ((u16LPEAntDriveCurrentSetLast != u16LPEAntDriveCurrentSet) ||
			(u16RPEAntDriveCurrentSetLast != u16RPEAntDriveCurrentSet) ||
			(u16PSAntDriveCurrentSetLast != u16PSAntDriveCurrentSet))
		{
			u32calc = u16LPEAntDriveCurrentSet * 1000;
			u8JokerInitLfAntDrvCur = (uint8_t)u32calc / 15625;

			u32calc = u16RPEAntDriveCurrentSet * 1000;
			u8JokerInitRfAntDrvCur = (uint8_t)u32calc / 15625;

			u32calc = u16PSAntDriveCurrentSet * 1000;
			u16Incar_Ant_DriveCurrent = (uint8_t)u32calc / 15625;

			u8Njj29c0_WorkStatus = JOKER_INIT;
		}
	}

	u16LPEAntDriveCurrentSetLast = u16LPEAntDriveCurrentSet;
	u16RPEAntDriveCurrentSetLast = u16RPEAntDriveCurrentSet;
	u16PSAntDriveCurrentSetLast = u16PSAntDriveCurrentSet;

	if (u16LPEAntRssiLimitSetLast != u16LPEAntRssiLimitSet)
	{
		Lf_DoorAnt_Rssi_Limit = ((float)u16LPEAntRssiLimitSet) / 100.0;
	}

	if (u16RPEAntRssiLimitSetLast != u16RPEAntRssiLimitSet)
	{
		Rf_DoorAnt_Rssi_Limit = ((float)u16LPEAntRssiLimitSet) / 100.0;
	}

	if (u16PSAntRssiLimitSetLast != u16PSAntRssiLimitSet)
	{
		Ps_Ant_Rssi_Limit = ((float)u16PSAntRssiLimitSet) / 100.0;
	}

	u16LPEAntRssiLimitSetLast = u16LPEAntRssiLimitSet;
	u16RPEAntRssiLimitSetLast = u16RPEAntRssiLimitSet;
	u16PSAntRssiLimitSetLast = u16PSAntRssiLimitSet;

	u32calc = (uint32_t)(InCar_CurRssiCalcVal.value * 100.0);
	if (u32calc > 0xffff)
	{
		u32calc = 0xffff;
	}
	u16InCar_Door_Ant_Rssi = (uint16_t)u32calc;

	u32calc = (uint32_t)(Lf_Door_CurRssiCalcVal.value * 100.0);
	if (u32calc > 0xffff)
	{
		u32calc = 0xffff;
	}
	u16Leftfront_Door_Ant_Rssi = (uint16_t)u32calc;

	u32calc = (uint32_t)(Rf_Door_CurRssiCalcVal.value * 100.0);
	if (u32calc > 0xffff)
	{
		u32calc = 0xffff;
	}
	u16Rightfront_Door_Ant_Rssi = (uint16_t)u32calc;
}

/*******************************************************************************
 * 锟斤拷锟斤拷锟斤�? : LfAuthTransmitterInfoInit
 * 锟斤拷锟斤拷	 : 锟斤拷频锟斤拷锟斤拷锟斤拷息锟侥筹拷始锟斤拷
 * 锟斤拷锟斤拷	 : cmd:锟斤拷频锟斤拷锟酵碉拷锟斤拷锟斤�?
 * 锟斤拷锟斤拷	 : NONE
 *******************************************************************************/
static void LfAuthTransmitterInfoInit(uint8 cmd, uint32 Uid)
{
	// IDE (4 bytes) + Command: 0x16 (1 byte) + 32 bit challenge (4 bytes) + 16 bit MAC (2 bytes) + CRC (1 byte)

	uint16 tmp_reg = 0;
	uint8 *tmp;
	LONG_UNION Rand_Val;

	Rand_Val.Value = Uid;

	sLf_Auth_TransmitterInfo.Id[0] = Rand_Val.CHAR_BYTE.High_byte;
	sLf_Auth_TransmitterInfo.Id[1] = Rand_Val.CHAR_BYTE.Mhigh_byte;
	sLf_Auth_TransmitterInfo.Id[2] = Rand_Val.CHAR_BYTE.Mlow_byte;
	sLf_Auth_TransmitterInfo.Id[3] = (uint8)((Rand_Val.CHAR_BYTE.Low_byte & 0x0Fu) << 4) | 0x0Fu;

	sLf_Auth_TransmitterInfo.Command = cmd;

	Rand_Val.Value = GetSysRandTimeCount();
	sLf_Auth_TransmitterInfo.Random[0] = 127 ^ Rand_Val.CHAR_BYTE.High_byte;  // 0x7f
	sLf_Auth_TransmitterInfo.Random[1] = 102 ^ Rand_Val.CHAR_BYTE.Mhigh_byte; // 0x66
	sLf_Auth_TransmitterInfo.Random[2] = 182 ^ Rand_Val.CHAR_BYTE.Mlow_byte;  // 0xb6
	sLf_Auth_TransmitterInfo.Random[3] = 141 ^ Rand_Val.CHAR_BYTE.Low_byte;	  // 0x8d

	Rand_Val.Value = Uid;
	tsAes_Crypt_Buffer.Use_Id[0] = Rand_Val.CHAR_BYTE.High_byte;
	tsAes_Crypt_Buffer.Use_Id[1] = Rand_Val.CHAR_BYTE.Mhigh_byte;
	tsAes_Crypt_Buffer.Use_Id[2] = Rand_Val.CHAR_BYTE.Mlow_byte;
	tsAes_Crypt_Buffer.Use_Id[3] = Rand_Val.CHAR_BYTE.Low_byte;

	tsAes_Crypt_Buffer.Use_Seed[0] = sLf_Auth_TransmitterInfo.Random[0];
	tsAes_Crypt_Buffer.Use_Seed[1] = sLf_Auth_TransmitterInfo.Random[1];
	tsAes_Crypt_Buffer.Use_Seed[2] = sLf_Auth_TransmitterInfo.Random[2];
	tsAes_Crypt_Buffer.Use_Seed[3] = sLf_Auth_TransmitterInfo.Random[3];

	(void)GetCurUseSecretKey(Uid, tsAes_Crypt_Buffer.Use_SecretKey);

	sLf_Auth_TransmitterInfo.Sum = GetCrc8(&sLf_Auth_TransmitterInfo.Command, 5);
}

/*******************************************************************************
 * 锟斤拷锟斤拷锟斤�? : LFGetRssiTransmitterInfoInit
 * 锟斤拷锟斤拷	 : 锟斤拷频锟斤拷贸锟角恐碉拷锟接︼拷锟斤拷锟斤拷锟较拷某锟绞硷拷�?
 * 锟斤拷锟斤拷	 : cmd:锟斤拷频锟斤拷锟酵碉拷锟斤拷锟斤�?
 * 锟斤拷锟斤拷	 : NONE
 *******************************************************************************/
static void LFGetRssiTransmitterInfoInit(uint8 cmd)
{
	// IDE (4 bytes) + Command (1 byte) + fob_num Byte (1 byte) + CRC (1 byte)
	sLf_FobLocate_TransmitterInfo.Command = cmd;
	// sLf_FobLocate_TransmitterInfo.ReadyUse_Ide_Num = num;
	sLf_FobLocate_TransmitterInfo.Sum = GetCrc8(&sLf_FobLocate_TransmitterInfo.Command, 1);
}

#ifdef demoboard

static void Test_Peps_Fun(void)
{
	LONG_UNION Rand_Val;

	if (0 == u8DemoFunSel)
	{
		if (u8DemoKeyCmd == 1)
		{
			u8FobKeyEnterWorkState = 1; // 遥锟斤拷学习

#ifdef QN_DEBUG
			Rand_Val.Value = GetSysRandTimeCount();

			u8Universal_Key[0] = 127 ^ Rand_Val.CHAR_BYTE.High_byte;  // 0x7f
			u8Universal_Key[1] = 102 ^ Rand_Val.CHAR_BYTE.Mhigh_byte; // 0x66
			u8Universal_Key[2] = 182 ^ Rand_Val.CHAR_BYTE.Mlow_byte;  // 0xb6
			u8Universal_Key[3] = 141 ^ Rand_Val.CHAR_BYTE.Low_byte;	  // 0x8d
			u8Universal_Key[4] = 238 ^ Rand_Val.CHAR_BYTE.Mlow_byte;  // 0xee
			u8Universal_Key[5] = 34 ^ Rand_Val.CHAR_BYTE.Low_byte;	  // 0x22
			u8Universal_Key[6] = 203 ^ Rand_Val.CHAR_BYTE.High_byte;  // 0xcb
			u8Universal_Key[7] = 213 ^ Rand_Val.CHAR_BYTE.Mhigh_byte; // 0xd5
			u8Universal_Key[8] = u8Universal_Key[2] ^ u8Universal_Key[0];
			u8Universal_Key[9] = u8Universal_Key[1] ^ u8Universal_Key[0];
			u8Universal_Key[10] = u8Universal_Key[5] ^ u8Universal_Key[3];
			u8Universal_Key[11] = u8Universal_Key[7] ^ u8Universal_Key[3];

			u8Universal_Key[12] = u8Universal_Key[3] ^ u8Universal_Key[0];
			u8Universal_Key[13] = u8Universal_Key[4] ^ u8Universal_Key[0];
			u8Universal_Key[14] = u8Universal_Key[2] ^ u8Universal_Key[3];
			u8Universal_Key[15] = u8Universal_Key[1] ^ u8Universal_Key[3];
#endif
		}
		else if (u8DemoKeyCmd == 2)
		{
			u8PS_Auth_KeyPosReq = 1;
			// bStartImmoAuthFlag = true;
		}
		else if (u8DemoKeyCmd == 3)
		{
			u8PE_Auth_KeyPosReq = 1;
		}
		else if (u8DemoKeyCmd == 4)
		{
			u8PE_Auth_KeyPosReq = 2;
		}

		u8DemoKeyCmd = 0;
	}
	else if (3 == u8DemoFunSel)
	{
		if (u8DemoKeyCmd == 1)
		{
			u8PollingFuncRequest = 1; // Close Polling Request
		}
		else if (u8DemoKeyCmd == 2)
		{
			u8PollingFuncRequest = 2; // Polling Lock Request
		}
		else if (u8DemoKeyCmd == 3)
		{
			u8PollingFuncRequest = 3; // Polling Unlock Mode1 Request
		}
		else if (u8DemoKeyCmd == 4)
		{
		}

		u8DemoKeyCmd = 0;
	}
}

void ScanBodyInputSign(void)
{
	static uint8 u8DrDoorButton_Cnt = 0;
	static uint8 bDrDoor_Button_State = 0;

	static uint8 u8DrDoorButton_Cnt01 = 0;
	static uint8 bDrDoor_Button_State01 = 0;

	static uint8 u8DrDoorButton_Cnt02 = 0;
	static uint8 bDrDoor_Button_State02 = 0;

	static uint8 u8DrDoorButton_Cnt03 = 0;
	static uint8 bDrDoor_Button_State03 = 0;

	//============================锟斤拷锟斤拷驶锟脚帮拷锟街帮拷锟斤拷锟斤拷锟?============================
	if (!Dio_ReadChannel(GPIO_D0))
	{
		if (bDrDoor_Button_State == TRUE) // 锟斤拷驶锟斤拷锟脚帮拷锟斤拷 锟铰斤拷锟斤�?
		{
			u8DrDoorButton_Cnt++;

			if (u8DrDoorButton_Cnt >= 8)
			{
				u8DrDoorButton_Cnt = 0;
				bDrDoor_Button_State = 0;
				u8DemoKeyCmd = 1;
			}
		}
	}
	else
	{
		u8DrDoorButton_Cnt = 0;
		bDrDoor_Button_State = 1;
	}

	if (!Dio_ReadChannel(GPIO_D1))
	{
		if (bDrDoor_Button_State01 == TRUE) // 锟斤拷驶锟斤拷锟脚帮拷锟斤拷 锟铰斤拷锟斤�?
		{
			u8DrDoorButton_Cnt01++;

			if (u8DrDoorButton_Cnt01 >= 8)
			{
				u8DrDoorButton_Cnt01 = 0;
				bDrDoor_Button_State01 = 0;
				u8DemoKeyCmd = 2;
			}
		}
	}
	else
	{
		u8DrDoorButton_Cnt01 = 0;
		bDrDoor_Button_State01 = 1;
	}

	if (!Dio_ReadChannel(GPIO_D2))
	{
		if (bDrDoor_Button_State02 == TRUE) // 锟斤拷驶锟斤拷锟脚帮拷锟斤拷 锟铰斤拷锟斤�?
		{
			u8DrDoorButton_Cnt02++;

			if (u8DrDoorButton_Cnt02 >= 8)
			{
				u8DrDoorButton_Cnt02 = 0;
				bDrDoor_Button_State02 = 0;
				u8DemoKeyCmd = 3;
			}
		}
	}
	else
	{
		u8DrDoorButton_Cnt02 = 0;
		bDrDoor_Button_State02 = 1;
	}

	if (!Dio_ReadChannel(GPIO_D3))
	{
		if (bDrDoor_Button_State03 == TRUE) // 锟斤拷驶锟斤拷锟脚帮拷锟斤拷 锟铰斤拷锟斤�?
		{
			u8DrDoorButton_Cnt03++;

			if (u8DrDoorButton_Cnt03 >= 8)
			{
				u8DrDoorButton_Cnt03 = 0;
				bDrDoor_Button_State03 = 0;
				u8DemoKeyCmd = 4;
			}
		}
	}
	else
	{
		u8DrDoorButton_Cnt03 = 0;
		bDrDoor_Button_State03 = 1;
	}

	u8DemoFunSel = 0;
	if (Dio_ReadChannel(GPIO_D40))
	{
		u8DemoFunSel |= 0x1;
	}

	if (Dio_ReadChannel(GPIO_D41))
	{
		u8DemoFunSel |= 0x2;
	}

	Test_Peps_Fun();
}

#endif

static void Lf_Ant_ShortOpenCircuit_Diag(void)
{
	uint8_t status = 0;
	supfc_t Ecu_Supf;
	uint8_t DiagBuf[16];

	if (0 == u8PepsStep)
	{
		status = JOKER_StartDiag((drpi_t)0x0E, (diag_par_t)0X1F);
		u8PepsStep++;
	}
	else if (1 == u8PepsStep)
	{
		status = JOKER_GetOpStatus((opfcm_t *)&DiagBuf[0]);
		if (((status & 0x08) == 0x08) && ((DiagBuf[0] & 0x01) == 0x01))
		{
			JOKER_ClearOpStatus(OPFCM_ALL);
			u8PepsStep++;
		}
	}
	else if (2 == u8PepsStep)
	{
		status = JOKER_GetDiagStatus((drpi_t)0x0E, &Ecu_Supf, DiagBuf);
		if (status == 0)
		{
			tsLfAntDiagStatus.DATA_BYTE = 0;

			if ((DiagBuf[1] & 0x0B) > 0)
			{
				LF_ANT_CHANNEL_TWO_STATUS = 2; // 锟斤拷路
			}
			else if ((DiagBuf[1] & 0x04) > 0)
			{
				LF_ANT_CHANNEL_TWO_STATUS = 1; // 锟斤拷路
			}

			if ((DiagBuf[3] & 0x0B) > 0)
			{
				LF_ANT_CHANNEL_THREE_STATUS = 2; // 锟斤拷路
			}
			else if ((DiagBuf[3] & 0x04) > 0)
			{
				LF_ANT_CHANNEL_THREE_STATUS = 1; // 锟斤拷路
			}

			if ((DiagBuf[5] & 0x0B) > 0)
			{
				LF_ANT_CHANNEL_FOUR_STATUS = 2; // 锟斤拷路
			}
			else if ((DiagBuf[5] & 0x04) > 0)
			{
				LF_ANT_CHANNEL_FOUR_STATUS = 1; // 锟斤拷路
			}

			LfAnt_Fault = 0;
			if (((Ecu_Supf & 0x03) > 0) || (tsLfAntDiagStatus.DATA_BYTE > 0))
			{
				LfAnt_Fault = 1;
			}

			u8PepsStep++;
		}
	}
	else
	{
		JOKER_ClearDiagStatus();
		Change_Njj29c0_WorkStatus(lf_ide);
	}
}

static void NJJ29C0_Pilot_Pe_Process(void)
{
	static uint16 u16waitmaxcnt = 0;
	uint8_t status = 0;

	if (0 == u8PepsStep)
	{

		LfAuthTransmitterInfoInit(0x11, tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo);
		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
		JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
		u8PepsStep++;
	}
	else if (1 == u8PepsStep)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON, RSSI_CARRIER_CON_LEN);
		u8PepsStep++;
	}
	else if (2 == u8PepsStep)
	{
		Peps_Fun_ConfigTimerPolling(0x11, DR4P, 2, DR2P, PS_FUN_POLLING_CYCYE, DR3P, PS_FUN_POLLING_CYCYE);
		//JOKER_StartTimerPolling();
		u16waitmaxcnt = 0;
		u8HitagAuthPass = 0;
		u8PepsStep++;
	}
	else if (3 == u8PepsStep)
	{
		u16waitmaxcnt++;
		if (u16waitmaxcnt >= PE_LF_TX_MAX_PERIOD)
		{   
                        u8PepsTxCnt++;
                        if(u8PepsTxCnt >= 2)
                        {
                            u8PepsTxCnt = 0;
                            if((GetTransmitterCountVal() < 2)||(1 == tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn))
                            {
                                    SetPe_AuthFobStatus(2);
                                    Change_Njj29c0_WorkStatus(lf_ide);
                            }
                            else
                            {
                                    u8PepsStep++;
                            }
                        }
                        else
                        {
                          u8PepsStep = 0;
                        }
			JOKER_StopLfTransmit();
		}        
	}
	else if (4 == u8PepsStep)
	{
		if (0 == tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn)
		{
			LfAuthTransmitterInfoInit(0x11, tsTransmitters[u8PlanUseFobKeyUid_Index[1]].SerialNo);
			JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
			JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
			u8PepsStep++;
		}
		else
		{
			SetPe_AuthFobStatus(2);
			Change_Njj29c0_WorkStatus(lf_ide);
		}
	}
	else if (5 == u8PepsStep)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON, RSSI_CARRIER_CON_LEN);
		u8PepsStep++;
	}
	else if (6 == u8PepsStep)
	{
		Peps_Fun_ConfigTimerPolling(0x11, DR4P, 2, DR2P, PS_FUN_POLLING_CYCYE, DR3P, PS_FUN_POLLING_CYCYE);
		//JOKER_StartTimerPolling();
		u16waitmaxcnt = 0;
		u8HitagAuthPass = 0;
		u8PepsStep++;
	}
	else
	{
		u16waitmaxcnt++;
		if (u16waitmaxcnt >= PE_LF_TX_MAX_PERIOD)
		{
                        u8PepsTxCnt++;
                        if(u8PepsTxCnt >= 2)
                        {
                            u8PepsTxCnt = 0;
                            
                            SetPe_AuthFobStatus(2);
                            Change_Njj29c0_WorkStatus(lf_ide);
                        }
                        else
                        {
                            u8PepsStep = 4;
                        }
                        JOKER_StopLfTransmit();
		}
	}
}

static void NJJ29C0_Copilot_Pe_Process(void)
{
	static uint16 u16waitmaxcnt = 0;
	uint8_t status = 0;

	if (0 == u8PepsStep)
	{

		LfAuthTransmitterInfoInit(0x12, tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo);
		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
		JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
		u8PepsStep++;
	}
	else if (1 == u8PepsStep)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON, RSSI_CARRIER_CON_LEN);
		u8PepsStep++;
	}
	else if (2 == u8PepsStep)
	{
		Peps_Fun_ConfigTimerPolling(0x12, DR4P, 2, DR2P, PS_FUN_POLLING_CYCYE, DR3P, PS_FUN_POLLING_CYCYE);
		//JOKER_StartTimerPolling();
		u16waitmaxcnt = 0;
		u8HitagAuthPass = 0;
		u8PepsStep++;
	}
	else if (3 == u8PepsStep)
	{
		u16waitmaxcnt++;
		if (u16waitmaxcnt >= PE_LF_TX_MAX_PERIOD)
		{               
                        u8PepsTxCnt++;
                        if(u8PepsTxCnt >= 2)
                        {
                            u8PepsTxCnt = 0;
                          if((GetTransmitterCountVal() < 2)||(1 == tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn))
                          {
                                  SetPe_AuthFobStatus(2);
                                  Change_Njj29c0_WorkStatus(lf_ide);
                          }
                          else
                          {
                                  u8PepsStep++;
                          }
                        }
                        else
                        {       
                          u8PepsStep = 0;
                        }
                        JOKER_StopLfTransmit();
		}
	}
	else if (4 == u8PepsStep)
	{
		if (0 == tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn)
		{
			LfAuthTransmitterInfoInit(0x12, tsTransmitters[u8PlanUseFobKeyUid_Index[1]].SerialNo);
			JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
			JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
			u8PepsStep++;
		}
		else
		{
			SetPe_AuthFobStatus(2);
			Change_Njj29c0_WorkStatus(lf_ide);
		}
	}
	else if (5 == u8PepsStep)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON, RSSI_CARRIER_CON_LEN);
		u8PepsStep++;
	}
	else if (6 == u8PepsStep)
	{
		Peps_Fun_ConfigTimerPolling(0x12, DR4P, 2, DR2P, PS_FUN_POLLING_CYCYE, DR3P, PS_FUN_POLLING_CYCYE);
		//JOKER_StartTimerPolling();
		u16waitmaxcnt = 0;
		u8HitagAuthPass = 0;
		u8PepsStep++;
	}
	else
	{
		u16waitmaxcnt++;
		if (u16waitmaxcnt >= PE_LF_TX_MAX_PERIOD)
		{
			u8PepsTxCnt++;
                        if(u8PepsTxCnt >= 2)
                        {
                            u8PepsTxCnt = 0;
                            
                            SetPe_AuthFobStatus(2);
                            Change_Njj29c0_WorkStatus(lf_ide);
                        }
                        else
                        {
                            u8PepsStep = 4;
                        }
                        JOKER_StopLfTransmit();
		}
	}
}

static void NJJ29C0_Ps_Process(void)
{
	static uint16 u16waitmaxcnt = 0;
	uint8_t status = 0;

	if (0 == u8PepsStep)
	{
                  LfAuthTransmitterInfoInit(0x10, tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo);
		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
		JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
		u8PepsStep++;
	}
	else if (1 == u8PepsStep)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON, RSSI_CARRIER_CON_LEN);
		u8PepsStep++;
	}
	else if (2 == u8PepsStep)
	{
		Peps_Fun_ConfigTimerPolling(0x10, DR4P, PS_FUN_POLLING_CYCYE, DR2P, 2, DR3P, 2);
		//JOKER_StartTimerPolling();
		u16waitmaxcnt = 0;
		u8HitagAuthPass = 0;
		u8PepsStep++;
	}
	else if (3 == u8PepsStep)
	{
		u16waitmaxcnt++;
		if (u16waitmaxcnt >= PE_LF_TX_MAX_PERIOD)
		{
                        u8PepsTxCnt++;
                        if(u8PepsTxCnt >= 2)
                        {
                            u8PepsTxCnt = 0;
                  
                            if((GetTransmitterCountVal() < 2)||(1 == tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn))
                            {
                                    //SetPs_AuthFobStatus(2);
                                    bStartImmoAuthFlag = true;
                                    Change_Njj29c0_WorkStatus(lf_ide);
                            }
                            else
                            {
                                    u8PepsStep++;
                            }
                       }
                       else
                       {
                          u8PepsStep = 0;
                       }
                       JOKER_StopLfTransmit();
		}
	}
	else if (4 == u8PepsStep)
	{
		if (0 == tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn)
		{
			LfAuthTransmitterInfoInit(0x10, tsTransmitters[u8PlanUseFobKeyUid_Index[1]].SerialNo);
			JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
			JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
			u8PepsStep++;
		}
		else
		{
			SetPs_AuthFobStatus(2);
			Change_Njj29c0_WorkStatus(lf_ide);
		}
	}
	else if (5 == u8PepsStep)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON, RSSI_CARRIER_CON_LEN);
		u8PepsStep++;
	}
	else if (6 == u8PepsStep)
	{
		Peps_Fun_ConfigTimerPolling(0x10, DR4P, PS_FUN_POLLING_CYCYE, DR2P, 2, DR3P, 2);
		//JOKER_StartTimerPolling();
		u16waitmaxcnt = 0;
		u8HitagAuthPass = 0;
		u8PepsStep++;
	}
	else
	{
		u16waitmaxcnt++;
		if (u16waitmaxcnt >= PE_LF_TX_MAX_PERIOD)
		{
                        u8PepsTxCnt++;
                        if(u8PepsTxCnt >= 2)
                        {
                            u8PepsTxCnt = 0;
                          // SetPs_AuthFobStatus(2);
                          Change_Njj29c0_WorkStatus(lf_ide);
                          bStartImmoAuthFlag = true;
                        }
                        else
                        {
                          u8PepsStep = 4;
                        }
		}
	}
}

static void NJJ29C0_Prohibit_Process(void)
{
	static uint16 u16waitmaxcnt = 0;
	uint8_t status = 0;

	if (0 == u8PepsStep)
	{
		LfAuthTransmitterInfoInit(0x10, tsTransmitters[u8FobKeyIndex].SerialNo);
		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
		JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
		u8PepsStep++;
	}
	else if (1 == u8PepsStep)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON, RSSI_CARRIER_CON_LEN);
		u8PepsStep++;
	}
	else if (2 == u8PepsStep)
	{
		Peps_Fun_ConfigTimerPolling(0x10, DR4P, PS_FUN_POLLING_CYCYE, DR2P, 2, DR3P, 2);
		//JOKER_StartTimerPolling();
		u16waitmaxcnt = 0;
		u8HitagAuthPass = 0;
		u8PepsStep++;
	}
	else
	{
		u16waitmaxcnt++;
		if (u16waitmaxcnt >= PE_LF_TX_MAX_PERIOD)
		{
			u8FobKeyIndex++;
			if (u8FobKeyIndex >= GetTransmitterCountVal())
			{
                                u8PepsTxCnt++;
                              if(u8PepsTxCnt >= 2)
                              {
                                  u8PepsTxCnt = 0;
				Change_Njj29c0_WorkStatus(lf_ide);
                              }
                              else
                              {
                                  u8PepsStep = 0;
                              }
			}
			else
			{
				u8PepsStep = 0;
			}
		}
	}
}

static int8_t WelcomeGuest_Auth(uint8 use_fobkey_num)
{
	uint8 spitxFrame[32] = {0};
	LONG_UNION Rand_Val;
	static uint8 u8WelcomeGuest01_Set_Step = 0;
	int8_t fun_sta = 0;

	u8WelcomeGuest01_Set_Step++;

	if (1 == u8WelcomeGuest01_Set_Step)
	{
		LfAuthTransmitterInfoInit(0x14, tsTransmitters[use_fobkey_num].SerialNo);
		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
		JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
	}
	else if (2 == u8WelcomeGuest01_Set_Step)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
	}
	else
	{
		Peps_Fun_ConfigTimerPolling(0x14, NULL, NULL, DR2P, PS_FUN_POLLING_CYCYE, DR3P, PS_FUN_POLLING_CYCYE);
		JOKER_StartTimerPolling();
		u8WelcomeGuest01_Set_Step = 0;
		u8HitagAuthPass = 0;
		fun_sta = 1;
	}

	return fun_sta;
}

static int8_t NJJ29C0_WelcomeGuest_SearchTrack_Key(uint8_t Carrier_En, uint16_t cycle) // 钥锟阶轨迹锟斤拷锟斤�?
{
	uint8 spitxFrame[32] = {0};
	LONG_UNION Rand_Val;
	static uint8 u8WelcomeGuest1_Set_Step = 0;
	static uint8 u8WecomeGuestWakeUpFobKeyUidInd = 0;
	int8_t fun_sta = 0;

	u8WelcomeGuest1_Set_Step++;

	if (1 == u8WelcomeGuest1_Set_Step)
	{
		if ((1 == tsTransmitters[u8PlanUseFobKeyUid_Index[0]].FobKeyEn) && (1 == tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn))
		{
			Change_Njj29c0_WorkStatus(lf_ide);
			u8WelcomeGuest1_Set_Step = 0;
			fun_sta = 0;
		}

		u8WecomeGuestWakeUpFobKeyUidInd = 0;
		if (0 == tsTransmitters[u8PlanUseFobKeyUid_Index[0]].FobKeyEn)
		{
			u8WecomeGuestWakeUpFobKeyUidInd |= 0x01;
		}

		if (0 == tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn)
		{
			u8WecomeGuestWakeUpFobKeyUidInd |= 0x02;
		}
	}
	else if (2 == u8WelcomeGuest1_Set_Step)
	{
		if (u8WecomeGuestWakeUpFobKeyUidInd == 3)
		{
			Rand_Val.Value = tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo;
			spitxFrame[0] = Rand_Val.CHAR_BYTE.High_byte;
			spitxFrame[1] = Rand_Val.CHAR_BYTE.Mhigh_byte;
			spitxFrame[2] = Rand_Val.CHAR_BYTE.Mlow_byte;
			spitxFrame[3] = (uint8)((Rand_Val.CHAR_BYTE.Low_byte & 0x0Fu) << 4) | 0x0Fu;
			JOKER_SetLfData(DATA_ID_WUP1, 4, spitxFrame);

			Rand_Val.Value = tsTransmitters[u8PlanUseFobKeyUid_Index[1]].SerialNo;
			spitxFrame[0] = Rand_Val.CHAR_BYTE.High_byte;
			spitxFrame[1] = Rand_Val.CHAR_BYTE.Mhigh_byte;
			spitxFrame[2] = Rand_Val.CHAR_BYTE.Mlow_byte;
			spitxFrame[3] = (uint8)((Rand_Val.CHAR_BYTE.Low_byte & 0x0Fu) << 4) | 0x0Fu;
			JOKER_SetLfData(DATA_ID_WUP2, 4, spitxFrame);
		}
		else
		{
			if (u8WecomeGuestWakeUpFobKeyUidInd == 1)
			{
				Rand_Val.Value = tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo;
			}
			else
			{
				Rand_Val.Value = tsTransmitters[u8PlanUseFobKeyUid_Index[1]].SerialNo;
			}

			spitxFrame[0] = Rand_Val.CHAR_BYTE.High_byte;
			spitxFrame[1] = Rand_Val.CHAR_BYTE.Mhigh_byte;
			spitxFrame[2] = Rand_Val.CHAR_BYTE.Mlow_byte;
			spitxFrame[3] = (uint8)((Rand_Val.CHAR_BYTE.Low_byte & 0x0Fu) << 4) | 0x0Fu;
			JOKER_SetLfData(DATA_ID_WUP1, 4, spitxFrame);
		}
	}
	else if (3 == u8WelcomeGuest1_Set_Step)
	{
		if (u8WecomeGuestWakeUpFobKeyUidInd == 3)
		{
			LFGetRssiTransmitterInfoInit(0x15);
			JOKER_SetLfData(DATA_ID_DATA_PE, 3, &sLf_FobLocate_TransmitterInfo.Command);

			LFGetRssiTransmitterInfoInit(0x16);
			JOKER_SetLfData(DATA_ID_CC_5, 3, &sLf_FobLocate_TransmitterInfo.Command);
		}
		else
		{
			if (u8WecomeGuestWakeUpFobKeyUidInd == 1)
			{
				LFGetRssiTransmitterInfoInit(0x15);
			}
			else
			{
				LFGetRssiTransmitterInfoInit(0x16);
			}

			JOKER_SetLfData(DATA_ID_DATA_PE, 3, &sLf_FobLocate_TransmitterInfo.Command);
		}
	}
	else if (4 == u8WelcomeGuest1_Set_Step)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON, RSSI_CARRIER_CON_LEN);
	}
	else
	{
		if (u8WecomeGuestWakeUpFobKeyUidInd == 3)
		{
			WelcomeGuest_ConfigTimerPollingTwo(2, DR2P | DR3P, 4, DR2P | DR3P, cycle, Carrier_En);
		}
		else
		{
			WelcomeGuest_ConfigTimerPollingTwo(1, DR2P | DR3P, cycle, 0, 0, Carrier_En);
		}
		JOKER_StartTimerPolling();
		u8WelcomeGuest1_Set_Step = 0;
		fun_sta = 1;
	}

	return fun_sta;
}

#if 0
static void NJJ29C0_WelcomeGuest_SearchFocus_Key(void)//茂驴陆茂驴陆脦禄脭驴茂驴陆茂驴陆
{
	uint8 spitxFrame[32] ={0};
	LONG_UNION	Rand_Val;
	static uint16 u16Welcomewaitmaxcnt = 0;		
	static uint8 u8WecomeGuestWakeUpFobKeyUidInd = 0;

	if(0 == u8PepsStep)
	{
		LFGetRssiTransmitterInfoInit(0x15,0);
		Rand_Val.Value = tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo;
		spitxFrame[0] = Rand_Val.CHAR_BYTE.High_byte;
		spitxFrame[1] = Rand_Val.CHAR_BYTE.Mhigh_byte;
		spitxFrame[2] = Rand_Val.CHAR_BYTE.Mlow_byte;
		spitxFrame[3] = (uint8)((Rand_Val.CHAR_BYTE.Low_byte & 0x0Fu) << 4) | 0x0Fu;
		JOKER_SetLfData(DATA_ID_WUP1, 4, spitxFrame);
		JOKER_SetLfData(DATA_ID_DATA_PE, 3, &sLf_FobLocate_TransmitterInfo.Command);
		u8PepsStep++;
	}
	else if(1 == u8PepsStep)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON , RSSI_CARRIER_CON_LEN);
		u8PepsStep++;
	}
	else if(2 == u8PepsStep)
	{
		WelcomeGuest_ConfigTimerPollingOne(DR4P,PS_FUN_POLLING_CYCYE,DR2P,2,DR3P,2);
		JOKER_StartTimerPolling();		
		u16Welcomewaitmaxcnt = 0;
		u8HitagAuthPass = 0;
		u8PepsStep++;
	}
	else if(3 == u8PepsStep)
	{
		u16Welcomewaitmaxcnt++;
		if(u16Welcomewaitmaxcnt >= (PE_LF_TX_MAX_PERIOD + 25))
		{
			u8PepsStep++;
		}
		else if(u16Welcomewaitmaxcnt >= PE_LF_TX_MAX_PERIOD)
		{
			JOKER_WakeUp();
		}
	}
	else if(4 == u8PepsStep)
	{
		LFGetRssiTransmitterInfoInit(0x15,1);
		Rand_Val.Value = tsTransmitters[u8PlanUseFobKeyUid_Index[1]].SerialNo;
		spitxFrame[0] = Rand_Val.CHAR_BYTE.High_byte;
		spitxFrame[1] = Rand_Val.CHAR_BYTE.Mhigh_byte;
		spitxFrame[2] = Rand_Val.CHAR_BYTE.Mlow_byte;
		spitxFrame[3] = (uint8)((Rand_Val.CHAR_BYTE.Low_byte & 0x0Fu) << 4) | 0x0Fu;
		JOKER_SetLfData(DATA_ID_WUP1, 4, spitxFrame);
		JOKER_SetLfData(DATA_ID_DATA_PE, 3, &sLf_FobLocate_TransmitterInfo.Command);
		u8PepsStep++;
	}
	else if(5 == u8PepsStep)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON , RSSI_CARRIER_CON_LEN);
		u8PepsStep++;
	}
	else if(6 == u8PepsStep)
	{
		WelcomeGuest_ConfigTimerPollingOne(DR4P,PS_FUN_POLLING_CYCYE,DR2P,2,DR3P,2);
		JOKER_StartTimerPolling();		
		u16Welcomewaitmaxcnt = 0;
		u8HitagAuthPass = 0;
		u8PepsStep++;
	}
	else
	{
		u16Welcomewaitmaxcnt++;
		if(u16Welcomewaitmaxcnt >= (PE_LF_TX_MAX_PERIOD + 25))
		{
			u8PollingMode_Init_State = 1;
		}
		else if(u16Welcomewaitmaxcnt >= PE_LF_TX_MAX_PERIOD)
		{
			JOKER_WakeUp();
		}
	}
}
#endif
void NJJ29C0_PollingUnlock_Process(void)
{
	static uint16_t u16PollingUnlockWaitMaxTime = 0;
	static uint8_t u8WakeUpFobsIndex = 0;

	switch (u8PollingUnlockStep)
	{
	case 0:
		if (u8PollingFuncRequestBak == 0)
		{
			u16PollingUnlockWaitMaxTime = WELCOMEGUEST_POLLING_CYCLE02;
		}
		else
		{
			u16PollingUnlockWaitMaxTime = WELCOMEGUEST_POLLING_CYCLE03;
		}

		if (NJJ29C0_WelcomeGuest_SearchTrack_Key(0, u16PollingUnlockWaitMaxTime) == 1)
		{
			bWaitAllFobKey_A_WakeUp = 0;
			bWaitAllFobKey_B_WakeUp = 0;
			Lf_Door_CurRssiCalcVal.value = 0;
			Rf_Door_CurRssiCalcVal.value = 0;
			u32Lf_CurRssi_Index = 0;
			u32Rf_CurRssi_Index = 0;
			u16PollingUnlockWaitMaxTime = 0;
			u8PollingUnlockStep++;
		}
		break;

	case 1:
		if (bWaitAllFobKey_A_WakeUp > 0)
		{
			JOKER_WakeUp();
			Lf_Door_CurRssiCalcVal.value = 0;
			u8PollingUnlockStep++;
		}
		else if (bWaitAllFobKey_B_WakeUp > 0)
		{
			JOKER_WakeUp();
			Rf_Door_CurRssiCalcVal.value = 0;
			u8PollingUnlockStep++;
		}

		break;

	case 2:
		if (NJJ29C0_WelcomeGuest_SearchTrack_Key(1, WELCOMEGUEST_POLLING_CYCLE01) == 1)
		{
			bWaitAllFobKey_A_WakeUp = 0;
			bWaitAllFobKey_B_WakeUp = 0;
			Lf_Door_CurRssiCalcVal.value = 0;
			Rf_Door_CurRssiCalcVal.value = 0;
			u16PollingUnlockWaitMaxTime = 0;
			u8PollingUnlockStep++;
		}
		break;

	case 3:

		if ((bWaitAllFobKey_A_WakeUp == 0) && (bWaitAllFobKey_B_WakeUp == 0))
		{
			u16PollingUnlockWaitMaxTime++;
			if (u16PollingUnlockWaitMaxTime >= 250)
			{
				// 500ms未锟斤拷锟秸碉拷强锟饺凤拷锟斤拷值锟斤拷钥锟斤拷锟斤拷失锟斤拷Z4锟斤拷锟津，伙拷钥锟斤拷一直锟斤拷锟斤拷锟脚ｏ拷锟斤拷锟斤拷失锟斤�?
				JOKER_WakeUp();
				u8PollingUnlockStep = 0; // 锟斤拷锟铰斤拷锟斤拷却锟?
				return;
			}
		}
		else
		{
			u16PollingUnlockWaitMaxTime = 0;
		}

		if (bWaitAllFobKey_A_WakeUp == 1)
		{
			bWaitAllFobKey_A_WakeUp = 0;

			if (u32Lf_CurRssi_Index >= LF_RSSI_CACHE_LEN)
			{
				u32Lf_Door_CurRssi[0] = u32Lf_Door_CurRssi[1];
				u32Lf_Door_CurRssi[1] = u32Lf_Door_CurRssi[2];
				u32Lf_Door_CurRssi[2] = u32Lf_Door_CurRssi[3];
				u32Lf_Door_CurRssi[3] = u32Lf_Door_CurRssi[4];
				u32Lf_Door_CurRssi[4] = u32Lf_Door_CurRssi[5];
				u32Lf_Door_CurRssi[5] = u32Lf_Door_CurRssi[6];
				u32Lf_Door_CurRssi[6] = u32Lf_Door_CurRssi[7];
				u32Lf_Door_CurRssi[7] = u32Lf_Door_CurRssi[8];
				u32Lf_Door_CurRssi[8] = u32Lf_Door_CurRssi[9];
				u32Lf_Door_CurRssi[9] = u32Lf_Door_CurRssi[10];
				u32Lf_Door_CurRssi[10] = u32Lf_Door_CurRssi[11];
				u32Lf_Door_CurRssi[11] = u32Lf_Door_CurRssi[12];
				u32Lf_Door_CurRssi[12] = u32Lf_Door_CurRssi[13];
				u32Lf_Door_CurRssi[13] = u32Lf_Door_CurRssi[14];
				u32Lf_Door_CurRssi[14] = u32Lf_Door_CurRssi[15];
				u32Lf_Door_CurRssi[15] = (uint32_t)(Lf_Door_CurRssiCalcVal.value * 1000.0);
			}
			else
			{
				u32Lf_Door_CurRssi[u32Lf_CurRssi_Index] = (uint32_t)(Lf_Door_CurRssiCalcVal.value * 1000.0);
			}

			u32Lf_CurRssi_Index++;

			if (Lf_Door_CurRssiCalcVal.value > L_DOORANT_RSSI_Z1_LIMIT)
			{
				if (FobKey_Tracking_Positioning_Algorithm(u32Lf_Door_CurRssi, u32Lf_CurRssi_Index, 200) == UPWARD)
				{
					// 强锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤�?
					JOKER_WakeUp();
					u8PollingUnlockStep++;
					u8WakeUpFobsIndex = 0;
				}
			}
			else if (Lf_Door_CurRssiCalcVal.value > L_DOORANT_RSSI_Z3_LIMIT)
			{
				if (FobKey_Tracking_Positioning_Algorithm(u32Lf_Door_CurRssi, u32Lf_CurRssi_Index, 1) == UPWARD)
				{
					// 强锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤�?
					u8Welcome_Function_Request = 1; // Polling light Request
				}
			}

			Lf_Door_CurRssiCalcVal.value = 0;
		}

		if (bWaitAllFobKey_B_WakeUp == 1)
		{
			bWaitAllFobKey_B_WakeUp = 0;

			if (u32Rf_CurRssi_Index >= LF_RSSI_CACHE_LEN)
			{
				u32Rf_Door_CurRssi[0] = u32Rf_Door_CurRssi[1];
				u32Rf_Door_CurRssi[1] = u32Rf_Door_CurRssi[2];
				u32Rf_Door_CurRssi[2] = u32Rf_Door_CurRssi[3];
				u32Rf_Door_CurRssi[3] = u32Rf_Door_CurRssi[4];
				u32Rf_Door_CurRssi[4] = u32Rf_Door_CurRssi[5];
				u32Rf_Door_CurRssi[5] = u32Rf_Door_CurRssi[6];
				u32Rf_Door_CurRssi[6] = u32Rf_Door_CurRssi[7];
				u32Rf_Door_CurRssi[7] = u32Rf_Door_CurRssi[8];
				u32Rf_Door_CurRssi[8] = u32Rf_Door_CurRssi[9];
				u32Rf_Door_CurRssi[9] = u32Rf_Door_CurRssi[10];
				u32Rf_Door_CurRssi[10] = u32Rf_Door_CurRssi[11];
				u32Rf_Door_CurRssi[11] = u32Rf_Door_CurRssi[12];
				u32Rf_Door_CurRssi[12] = u32Rf_Door_CurRssi[13];
				u32Rf_Door_CurRssi[13] = u32Rf_Door_CurRssi[14];
				u32Rf_Door_CurRssi[14] = u32Rf_Door_CurRssi[15];
				u32Rf_Door_CurRssi[15] = (uint32_t)(Rf_Door_CurRssiCalcVal.value * 1000.0);
			}
			else
			{
				u32Rf_Door_CurRssi[u32Rf_CurRssi_Index] = (uint32_t)(Rf_Door_CurRssiCalcVal.value * 1000.0);
			}

			u32Rf_CurRssi_Index++;

			if (Rf_Door_CurRssiCalcVal.value > R_DOORANT_RSSI_Z1_LIMIT)
			{
				if (FobKey_Tracking_Positioning_Algorithm(u32Rf_Door_CurRssi, u32Rf_CurRssi_Index, 200) == UPWARD)
				{
					// 强锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤�?
					JOKER_WakeUp();
					u8PollingUnlockStep++;
					u8WakeUpFobsIndex = 1;
				}
			}
			else if (Rf_Door_CurRssiCalcVal.value > R_DOORANT_RSSI_Z3_LIMIT)
			{
				if (FobKey_Tracking_Positioning_Algorithm(u32Rf_Door_CurRssi, u32Rf_CurRssi_Index, 1) == UPWARD)
				{
					// 强锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤�?
					u8Welcome_Function_Request = 1; // Polling light Request
				}
			}
			Rf_Door_CurRssiCalcVal.value = 0;
		}
		break;

	case 4:
		// 锟斤拷证锟斤拷锟斤拷
		if (WelcomeGuest_Auth(u8WakeUpFobsIndex) == 1)
		{
			u16PollingUnlockWaitMaxTime = 0;
			u8PollingUnlockStep++;
		}
		break;

	case 5:
		u16PollingUnlockWaitMaxTime++;
		if (u16PollingUnlockWaitMaxTime >= 150)
		{
			// JOKER_WakeUp();
			// u8PollingUnlockStep = 0;  //锟斤拷锟铰斤拷锟斤拷却锟?
			u8PollingUnlockStep++;
			return;
		}
		else
		{
			if (u8HitagAuthPass == 1)
			{
				// 锟斤拷锟斤拷Z1锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷证锟缴癸拷
				JOKER_WakeUp();
				u8Welcome_Function_Request = 2; // Polling light Request
				u8PollingUnlockStep = 0;
				Change_Njj29c0_WorkStatus(lf_ide);
			}
		}
		break;

	case 6:

		break;

	default:
		u8PollingUnlockStep = 0;
		break;
	}
}

#if 0
static void WelcomeGuest_Lock_SearchTrack_Key(void) //脭驴茂驴陆脳鹿矛录拢茂驴陆茂驴陆茂驴陆茂驴陆
{
	uint8 spitxFrame[32] ={0};
	LONG_UNION	Rand_Val;
	static uint8 u8WelcomeGuest02_Set_Step = 0;
	
	u8WelcomeGuest02_Set_Step++;

	if(1 == u8WelcomeGuest02_Set_Step)
	{
		if((bWaitAllFobKey_A_WakeUp == 0)&&(bWaitAllFobKey_B_WakeUp == 0))
		{
			Rand_Val.Value = tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo;
			spitxFrame[0] = Rand_Val.CHAR_BYTE.High_byte;
			spitxFrame[1] = Rand_Val.CHAR_BYTE.Mhigh_byte;
			spitxFrame[2] = Rand_Val.CHAR_BYTE.Mlow_byte;
			spitxFrame[3] = (uint8)((Rand_Val.CHAR_BYTE.Low_byte & 0x0Fu) << 4) | 0x0Fu;
			JOKER_SetLfData(DATA_ID_WUP1, 4, spitxFrame);

			Rand_Val.Value = tsTransmitters[u8PlanUseFobKeyUid_Index[1]].SerialNo;
			spitxFrame[0] = Rand_Val.CHAR_BYTE.High_byte;
			spitxFrame[1] = Rand_Val.CHAR_BYTE.Mhigh_byte;
			spitxFrame[2] = Rand_Val.CHAR_BYTE.Mlow_byte;
			spitxFrame[3] = (uint8)((Rand_Val.CHAR_BYTE.Low_byte & 0x0Fu) << 4) | 0x0Fu;
			JOKER_SetLfData(DATA_ID_WUP2, 4, spitxFrame);
		}
		else
		{
			if(bWaitAllFobKey_A_WakeUp == 0)
			{
				Rand_Val.Value = tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo;
			}
			else
			{
				Rand_Val.Value = tsTransmitters[u8PlanUseFobKeyUid_Index[1]].SerialNo;
			}

			spitxFrame[0] = Rand_Val.CHAR_BYTE.High_byte;
			spitxFrame[1] = Rand_Val.CHAR_BYTE.Mhigh_byte;
			spitxFrame[2] = Rand_Val.CHAR_BYTE.Mlow_byte;
			spitxFrame[3] = (uint8)((Rand_Val.CHAR_BYTE.Low_byte & 0x0Fu) << 4) | 0x0Fu;
			JOKER_SetLfData(DATA_ID_WUP1, 4, spitxFrame);
		}
	}
	else if(2 == u8WelcomeGuest02_Set_Step)
	{
		if((bWaitAllFobKey_A_WakeUp == 0)&&(bWaitAllFobKey_B_WakeUp == 0))
		{
			LFGetRssiTransmitterInfoInit(0x16,0);
			JOKER_SetLfData(DATA_ID_DATA_PE, 3, &sLf_FobLocate_TransmitterInfo.Command);

			LFGetRssiTransmitterInfoInit(0x16,1);
			JOKER_SetLfData(DATA_ID_CC_5, 3, &sLf_FobLocate_TransmitterInfo.Command);
		}
		else
		{
			if(bWaitAllFobKey_A_WakeUp == 0)
			{
				LFGetRssiTransmitterInfoInit(0x16,0);
			}
			else
			{
				LFGetRssiTransmitterInfoInit(0x16,1);
			}
			
			JOKER_SetLfData(DATA_ID_DATA_PE, 3, &sLf_FobLocate_TransmitterInfo.Command);
		}
	}
	else if(3 == u8WelcomeGuest02_Set_Step)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON , RSSI_CARRIER_CON_LEN);
	}
	else
	{
		if((bWaitAllFobKey_A_WakeUp == 0)&&(bWaitAllFobKey_B_WakeUp == 0))
		{
			WelcomeGuest_ConfigTimerPollingTwo(2,DR2P|DR3P,8,DR2P|DR3P,WELCOMEGUEST_POLLING_CYCLE02);
		}
		else 
		{
			WelcomeGuest_ConfigTimerPollingTwo(1,DR2P|DR3P,WELCOMEGUEST_POLLING_CYCLE02,0,0);
		}
		JOKER_StartTimerPolling();		
		u8PollingMode_Init_State = 1;
		u8WelcomeGuest02_Set_Step = 0;
	}
}
#endif
void NJJ29C0_PollingLock_Process(void)
{
	static uint16_t u16PollingLockWaitMaxTime = 0;
	static uint8_t u8WakeUpFobsIndex = 0;

	switch (u8PollingLockStep)
	{
	case 0:
		if (NJJ29C0_WelcomeGuest_SearchTrack_Key(1, WELCOMEGUEST_POLLING_CYCLE01) == 1)
		{
			bWaitAllFobKey_A_WakeUp = 0;
			bWaitAllFobKey_B_WakeUp = 0;
			Lf_Door_CurRssiCalcVal.value = 0;
			Rf_Door_CurRssiCalcVal.value = 0;
			u32Lf_CurRssi_Index = 0;
			u32Rf_CurRssi_Index = 0;
			u8PollingLockStep++;
		}
		break;

	case 1:
		if (bWaitAllFobKey_A_WakeUp == 1)
		{
			bWaitAllFobKey_A_WakeUp = 0;

			if (u32Lf_CurRssi_Index >= LF_RSSI_CACHE_LEN)
			{
				u32Lf_Door_CurRssi[0] = u32Lf_Door_CurRssi[1];
				u32Lf_Door_CurRssi[1] = u32Lf_Door_CurRssi[2];
				u32Lf_Door_CurRssi[2] = u32Lf_Door_CurRssi[3];
				u32Lf_Door_CurRssi[3] = u32Lf_Door_CurRssi[4];
				u32Lf_Door_CurRssi[4] = u32Lf_Door_CurRssi[5];
				u32Lf_Door_CurRssi[5] = u32Lf_Door_CurRssi[6];
				u32Lf_Door_CurRssi[6] = u32Lf_Door_CurRssi[7];
				u32Lf_Door_CurRssi[7] = u32Lf_Door_CurRssi[8];
				u32Lf_Door_CurRssi[8] = u32Lf_Door_CurRssi[9];
				u32Lf_Door_CurRssi[9] = u32Lf_Door_CurRssi[10];
				u32Lf_Door_CurRssi[10] = u32Lf_Door_CurRssi[11];
				u32Lf_Door_CurRssi[11] = u32Lf_Door_CurRssi[12];
				u32Lf_Door_CurRssi[12] = u32Lf_Door_CurRssi[13];
				u32Lf_Door_CurRssi[13] = u32Lf_Door_CurRssi[14];
				u32Lf_Door_CurRssi[14] = u32Lf_Door_CurRssi[15];
				u32Lf_Door_CurRssi[15] = (uint32_t)(Lf_Door_CurRssiCalcVal.value * 1000.0);
			}
			else
			{
				u32Lf_Door_CurRssi[u32Lf_CurRssi_Index] = (uint32_t)(Lf_Door_CurRssiCalcVal.value * 1000.0);
			}

			u32Lf_CurRssi_Index++;

			if (Lf_Door_CurRssiCalcVal.value < L_DOORANT_RSSI_Z2_LIMIT)
			{
				if (FobKey_Tracking_Positioning_Algorithm(u32Lf_Door_CurRssi, u32Lf_CurRssi_Index, 200) == DOWNWARD)
				{
					// 强锟斤拷锟斤拷锟铰斤拷锟斤拷锟斤�?
					JOKER_WakeUp();
					u8PollingLockStep++;
					u8WakeUpFobsIndex = 0;
				}
			}
			Lf_Door_CurRssiCalcVal.value = 0;
		}

		if (bWaitAllFobKey_B_WakeUp == 1)
		{
			bWaitAllFobKey_B_WakeUp = 0;

			if (u32Rf_CurRssi_Index >= LF_RSSI_CACHE_LEN)
			{
				u32Rf_Door_CurRssi[0] = u32Rf_Door_CurRssi[1];
				u32Rf_Door_CurRssi[1] = u32Rf_Door_CurRssi[2];
				u32Rf_Door_CurRssi[2] = u32Rf_Door_CurRssi[3];
				u32Rf_Door_CurRssi[3] = u32Rf_Door_CurRssi[4];
				u32Rf_Door_CurRssi[4] = u32Rf_Door_CurRssi[5];
				u32Rf_Door_CurRssi[5] = u32Rf_Door_CurRssi[6];
				u32Rf_Door_CurRssi[6] = u32Rf_Door_CurRssi[7];
				u32Rf_Door_CurRssi[7] = u32Rf_Door_CurRssi[8];
				u32Rf_Door_CurRssi[8] = u32Rf_Door_CurRssi[9];
				u32Rf_Door_CurRssi[9] = u32Rf_Door_CurRssi[10];
				u32Rf_Door_CurRssi[10] = u32Rf_Door_CurRssi[11];
				u32Rf_Door_CurRssi[11] = u32Rf_Door_CurRssi[12];
				u32Rf_Door_CurRssi[12] = u32Rf_Door_CurRssi[13];
				u32Rf_Door_CurRssi[13] = u32Rf_Door_CurRssi[14];
				u32Rf_Door_CurRssi[14] = u32Rf_Door_CurRssi[15];
				u32Rf_Door_CurRssi[15] = (uint32_t)(Rf_Door_CurRssiCalcVal.value * 1000.0);
			}
			else
			{
				u32Rf_Door_CurRssi[u32Rf_CurRssi_Index] = (uint32_t)(Rf_Door_CurRssiCalcVal.value * 1000.0);
			}

			u32Rf_CurRssi_Index++;

			if (Rf_Door_CurRssiCalcVal.value < R_DOORANT_RSSI_Z2_LIMIT)
			{
				if (FobKey_Tracking_Positioning_Algorithm(u32Rf_Door_CurRssi, u32Rf_CurRssi_Index, 200) == DOWNWARD)
				{
					// 强锟斤拷锟斤拷锟铰斤拷锟斤拷锟斤�?
					JOKER_WakeUp();
					u8PollingLockStep++;
					u8WakeUpFobsIndex = 1;
				}
			}
			Rf_Door_CurRssiCalcVal.value = 0;
		}

		break;

	case 2:
		if (WelcomeGuest_Auth(u8WakeUpFobsIndex) == 1)
		{
			u16PollingLockWaitMaxTime = 0;
			u8PollingLockStep++;
		}
		break;

	case 3:
		u16PollingLockWaitMaxTime++;
		if (u16PollingLockWaitMaxTime >= 150)
		{
			JOKER_WakeUp();
			u8PollingLockStep = 0;
			return;
		}
		else
		{
			if (u8HitagAuthPass == 1)
			{
				// 锟斤拷锟斤拷Z3锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷证锟缴癸拷
				JOKER_WakeUp();
				u8Welcome_Function_Request = 3; // Polling Lock Reques
				u8PollingLockStep = 0;
				Change_Njj29c0_WorkStatus(lf_ide);
			}
		}

		break;

	default:
		u8PollingLockStep = 0;
		break;
	}
}

static void NJJ29C0_Calibration_Process(void)
{
	static uint16 u16waitmaxcnt = 0;
	uint8_t status = 0;
	uint8_t u8Lf_DrvCur_Set[3];

	uint32 u32tmpreg = 0;

	if (0 == u8PepsStep)
	{
		LfAuthTransmitterInfoInit(0x00, tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo);
		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);

		sLf_Auth_TransmitterInfo.Random[0] = 0x00;
		sLf_Auth_TransmitterInfo.Random[1] = 0x97;
		sLf_Auth_TransmitterInfo.Random[2] = GetCrc8(sLf_Auth_TransmitterInfo.Random, 2);

		JOKER_SetLfData(DATA_ID_DATA_PE, 3, sLf_Auth_TransmitterInfo.Random);
		u8PepsStep++;
	}
	else if (1 == u8PepsStep)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON, RSSI_CARRIER_CON_LEN);
		u8PepsStep++;
	}
	else if (2 == u8PepsStep)
	{
		Peps_Fun_ConfigTimerPolling(0x00, DR4P, PS_FUN_POLLING_CYCYE, DR2P, 2, DR3P, 2);
		JOKER_StartTimerPolling();
		u16waitmaxcnt = 0;
		u8HitagAuthPass = 0;
		u8PepsStep++;
	}
	else if (3 == u8PepsStep)
	{
	}
	else if (4 == u8PepsStep)
	{
		u16waitmaxcnt++;
		if (u16waitmaxcnt >= 100)
		{
			u8PepsStep++;
		}
		else if (u16waitmaxcnt >= 70)
		{
			JOKER_WakeUp();
		}

		if (u8HitagAuthPass == 1)
		{
			/*
				¼ÓÔØÊÒÄÚÌìÏßRSSIÖµ£¬Í¨¹ýCAN·¢ËÍ¸øÉÏÎ»»ú
			*/
#ifdef CALIBRATION_DEBUG

			// g_datCan1Tx_0x7fe[0] = (uint8)(Vehicle_Calibration_Num >> 8);
			// g_datCan1Tx_0x7fe[1] = (uint8)(Vehicle_Calibration_Num & 0xff);

			u32tmpreg = (uint32)(InCar_CurRssiCalcVal.value * 100.0);

			if (u32tmpreg > 0xffff)
			{
				u32tmpreg = 0xffff;
			}

			Vehicle_Calibration_Num = (uint16)(u32tmpreg & 0x0000ffff);

			g_datCan1Tx_0x7fe[0] = (uint8)(Vehicle_Calibration_Num >> 8);
			g_datCan1Tx_0x7fe[1] = (uint8)(Vehicle_Calibration_Num & 0xff);

			u32tmpreg = (uint32)(Lf_Door_CurRssiCalcVal.value * 100.0);
			if (u32tmpreg > 0xffff)
			{
				u32tmpreg = 0xffff;
			}
			Vehicle_Calibration_Num = (uint16)(u32tmpreg & 0x0000ffff);

			g_datCan1Tx_0x7fe[2] = (uint8)(Vehicle_Calibration_Num >> 8);
			g_datCan1Tx_0x7fe[3] = (uint8)(Vehicle_Calibration_Num & 0xff);

			u32tmpreg = (uint32)(Rf_Door_CurRssiCalcVal.value * 100.0);
			if (u32tmpreg > 0xffff)
			{
				u32tmpreg = 0xffff;
			}
			Vehicle_Calibration_Num = (uint16)(u32tmpreg & 0x0000ffff);

			g_datCan1Tx_0x7fe[4] = (uint8)(Vehicle_Calibration_Num >> 8);
			g_datCan1Tx_0x7fe[5] = (uint8)(Vehicle_Calibration_Num & 0xff);

			CCS_SetPduStatus(0, 0x7fe, 1);
#endif
			u16waitmaxcnt = 0x7fff;
		}
	}
	else
	{
		Change_Njj29c0_WorkStatus(lf_ide);
	}
}

void NJJ29C0_Task(void)
{       
	switch (u8Njj29c0_WorkStatus)
	{
	case JOKER_INIT:
		if (tnNck2910WorkStatus == NCK2910_INIT)
		{
			return;
		}

		JOKER_Init();
		if (Joker_Init_Status == 0)
		{
			u8Njj29c0_WorkStatus = JOKER_FAIL;
		}
		else if (Joker_Init_Status == 1)
		{
			u8Njj29c0_WorkStatus = JOKER_NORMAL;
			u8Lf_Ant_Code[LEFTSIDE_ANT_INDEX] = 1 << (DR_DOOR_ANT - 1);
			u8Lf_Ant_Code[RIGHTSIDE_ANT_INDEX] = 1 << (CODR_DOOR_ANT - 1);
			u8Lf_Ant_Code[INDOOR_ANT_INDEX] = 1 << (CAR_FRONT_ROW_ANT - 1);
			// NJJ29C0_Interrupt_En();
		}
		break;

	case JOKER_NORMAL:
		switch (lfapp_work_sta)
		{
		case lf_ide:
			if (bStartImmoAuthFlag == true)
			{
				Change_Njj29c0_WorkStatus(immo_ps);
				u16DiagCycleTime = LF_DIAG_CYCYE;
			}
			else if (1 == u8PE_Auth_KeyPosReq)
			{

                                  Change_Njj29c0_WorkStatus(lf_pilot_pe);
				  u16DiagCycleTime = LF_DIAG_CYCYE;
                                
			}
			else if (2 == u8PE_Auth_KeyPosReq)
			{

                                  Change_Njj29c0_WorkStatus(lf_copilot_pe);
                                  u16DiagCycleTime = LF_DIAG_CYCYE;
                                
			}
			else if (1 == u8PS_Auth_KeyPosReq)
			{
                            
				Change_Njj29c0_WorkStatus(lf_ps);
				u16DiagCycleTime = LF_DIAG_CYCYE;
                                
			}
			else if (2 == u8PS_Auth_KeyPosReq)
			{
                         
				Change_Njj29c0_WorkStatus(lf_prohibit_key);
				u16DiagCycleTime = LF_DIAG_CYCYE;
                              
			}
			else if (3 == u8PS_Auth_KeyPosReq)
			{
				All_FobKey_Lift_En();
			}
			else if (2 == u8PollingFuncRequest)
			{
				Change_Njj29c0_WorkStatus(lf_polling_lock);
				u16DiagCycleTime = LF_DIAG_CYCYE;
			}
			else if (3 == u8PollingFuncRequest)
			{
				Change_Njj29c0_WorkStatus(lf_polling_unlock);
				u8PollingFuncRequestBak = 0; // 锟斤拷锟?锟斤�?
				u16DiagCycleTime = LF_DIAG_CYCYE;
			}
			else if (4 == u8PollingFuncRequest)
			{
				Change_Njj29c0_WorkStatus(lf_polling_unlock);
				u16DiagCycleTime = LF_DIAG_CYCYE;
				u8PollingFuncRequestBak = 1; // 锟斤�?锟斤�?
			}
			else if (1 == u8FobKeyEnterWorkState)
			{
				u8FobKeyEnterWorkState = 0;
				u8FobKey_Information_Management_Feedback = 0;
				Change_Fobs_Learn_Status(IMMO_LEARN_RUNNING);
				u16DiagCycleTime = LF_DIAG_CYCYE;
				Change_Njj29c0_WorkStatus(immo_learn_fobkey);
			}
			else if (u8AntDigRequest == 1)
			{
				Change_Njj29c0_WorkStatus(lf_diag);
			}
			else if (1 == Vehicle_Calibration_Work)
			{
				Change_Njj29c0_WorkStatus(lf_calibration);
			}
			else
			{
				u16DiagCycleTime--;
				if (u16DiagCycleTime == 0)
				{
					u16DiagCycleTime = LF_DIAG_CYCYE;
					Change_Njj29c0_WorkStatus(lf_diag);
				}
			}
                        
			// Vehicle_Calibration_Work = 0;
			u8PollingFuncRequest = 0;
			u8ImmoLearnWorkCnt = 0;
			bStartImmoAuthFlag = false;
                        u8PE_Auth_KeyPosReq = 0;
                        u8PS_Auth_KeyPosReq = 0;
			u8FobKeyIndex = 0;
			u8PepsStep = 0;
                        u8PepsTxCnt = 0;
			u8PollingUnlockStep = 0;
			u8PollingLockStep = 0;
			sphscaCendricCadsLearnImmoState = FOBKEYLEARN_SET_INIT;
			sphscaCendricCadsUCImmoState = IMMO_SETTING;
			break;

		case lf_pilot_pe:
			NJJ29C0_Pilot_Pe_Process();
			break;

		case lf_copilot_pe:
			NJJ29C0_Copilot_Pe_Process();
			break;

		case lf_ps:
			NJJ29C0_Ps_Process();
			break;

		case lf_prohibit_key:
			NJJ29C0_Prohibit_Process();
			break;

		case lf_polling_lock:
			NJJ29C0_PollingLock_Process();

			if (1 == u8PollingFuncRequest)
			{
				JOKER_WakeUp();
				Change_Njj29c0_WorkStatus(lf_ide);
			}
			break;

		case lf_polling_unlock:
			NJJ29C0_PollingUnlock_Process();
			if (1 == u8PollingFuncRequest)
			{
				JOKER_WakeUp();
				Change_Njj29c0_WorkStatus(lf_ide);
			}
			break;

		case lf_diag:
			Lf_Ant_ShortOpenCircuit_Diag();
			break;

		case lf_calibration:
			NJJ29C0_Calibration_Process();
			break;

		case immo_ps:
			NJJ29C0_Immo_Auth();
			if (sphscaCendricCadsUCImmoState == IMMO_AUTH_FAIL)
			{
				SetPs_AuthFobStatus(2);
				Change_Njj29c0_WorkStatus(lf_ide);
			}
			else if (sphscaCendricCadsUCImmoState == IMMO_AUTH_OK)
			{
				SetPs_AuthFobStatus(3);
				Change_Njj29c0_WorkStatus(lf_ide);
			}
			break;

		case immo_learn_fobkey:
			FobKey_Immo_Learn_Process();

			if (u8FobKey_Information_Management_Feedback > 0)
			{
				Change_Njj29c0_WorkStatus(lf_ide);
			}
			break;

		default:
			break;
		}
		break;

	case JOKER_FAIL:

		break;
	default:
		break;
	}

	App_Monitor_Lf_Work_Status();
        
        //u8PE_Auth_KeyPosReq_Last = u8PE_Auth_KeyPosReq;
          
        //u8PS_Auth_KeyPosReq_Last = u8PS_Auth_KeyPosReq;
}

void Nck2910_Task(void)
{
	switch (tnNck2910WorkStatus)
	{
	case NCK2910_INIT:
		Nck2910_Init();
		break;

	case NCK2910_NORMAL:
		Nck2910_DataProcess();
		break;

	case NCK2910_FAIL:
		break;

	default:
		tnNck2910WorkStatus = NCK2910_INIT;
		break;
	}

	UhfRxHandler();
}

// RKE_PKE模锟斤拷锟绞硷拷�?
void PEPS_Module_Init(void)
{
	_NCK2910_Hal_Init();

	InitFobKeyEepromMessage();
}

void Spi2_Test(void)
{
	uint8 u8txbuf[2];

	u8txbuf[0] = 0x55;
	u8txbuf[0] = 0xAA;

	(void)NJJ29C0_Spi_ReadWrite(u8txbuf, NULL, 2);
}
#pragma default_function_attributes =