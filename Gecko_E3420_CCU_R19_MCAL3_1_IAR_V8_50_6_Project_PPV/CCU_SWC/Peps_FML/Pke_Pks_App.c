
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
static uint8 u8PepsTxCnt = PEPS_TX_MAX_COUNT;

lf_handle_state lfapp_work_sta = lf_ide;

uint8 u8ButtonTrigFlag = 0;

uint8 u8Lf_Ant_Code[3] =
	{
		0};

//??????
uint8 u8FobKeyInDoorInd = 0; //???????????
uint8 u8HitagAuthPass = 0;	 //?????????

uint8 u8WelcomeGuestWakeUpInd = 0; //?????????

// ����ID������ͨ����ƵԿ��ѧϰ
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

uint8 u8JokerInitInCarAntDrvCur = 5; // 47ma
uint8 u8JokerInitLfAntDrvCur = 31;	 // 500ma
uint8 u8JokerInitRfAntDrvCur = 31;	 // 500ma

float Lf_DoorAnt_Rssi_Limit = PE_L_DOORANT_RSSI_LIMIT;
float Rf_DoorAnt_Rssi_Limit = PE_R_DOORANT_RSSI_LIMIT;
float Ps_Ant_Rssi_Limit = PS_ANT_RSSI_LIMIT;

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

static boolean bStartWelcomeGuestLockFlag = false;
static uint32_t u32Lf_Door_CurRssi[LF_RSSI_CACHE_LEN] =
	{
		0};

static uint32_t u32Rf_Door_CurRssi[LF_RSSI_CACHE_LEN] =
	{
		0};

static uint32_t u32Lf_CurRssi_Index = 0;
static uint32_t u32Rf_CurRssi_Index = 0;

static uint8 Vehicle_Calibration_Work = 0;
static uint8 Vehicle_Calibration_AutoWork = 0;

uint16 Vehicle_Calibration_Num = 0;

uint16 u16LfRunTimingCnt = 0;

uint8_t u8_Auth_KeyTest_Feedback = 0;
static float Key_A_next_target_value;
static float Key_B_next_target_value;

static uint8_t u8Key_A_Check_Thread = 0;
static uint8_t u8Key_B_Check_Thread = 0;

static uint8_t u8Welcome_Function_Request_Bak = 0; //???????????????

uint8_t g_datCan1Tx_0x330[8] = {
	0xcc};

uint8 Vehicle_Calibration_Ant = 0;

static uint8 u8waitcantxtimecnt = 0;

uint8 u8LearnFobkey = 0;

uint8 u8Rssi_Can_Tx = 0;

uint8 u8PollingFuncRequest_Qn = 0;

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

// ID = 0X338
void SetVehicleCalibrationPara(uint8 *para)
{
	LONG_UNION Rand_Val;

	// para[0] = message->INV_LrngSubID;
	// para[1] = message->INV_LrngSts;
	// para[2] = message->INV_LrngData02;
	// para[3] = message->INV_LrngData03;

	if (para[0] == 0x51)
	{
		para[0] = 0;

		if (para[1] == 0xA0)
		{
			u8JokerInitInCarAntDrvCur = para[2];
			u8JokerInitLfAntDrvCur = para[3];
			u8JokerInitRfAntDrvCur = para[4];

#ifdef CALIBRATION_DEBUG
			g_datCan1Tx_0x330[0] = 10;
			g_datCan1Tx_0x330[1] = GetNck2910InitCompleteStatus();
			g_datCan1Tx_0x330[2] = GetNJJ29C0InitCompleteStatus();
			BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);
#endif
			u8Njj29c0_WorkStatus = JOKER_INIT;
		}
		else if (para[1] == 0xA1)
		{
			// 标定
			if (tnNck2910WorkStatus == NCK2910_NORMAL)
			{
				if (Vehicle_Calibration_AutoWork == 0)
				{
					Vehicle_Calibration_AutoWork = 0xc9;
				}
				else
				{
					Vehicle_Calibration_AutoWork = 0;
				}
			}
		}
		else if (para[1] == 0xA2)
		{
			// 遥控学习
			u8FobKeyEnterWorkState = 1; // 遥锟斤拷学习
										// u8LearnFobkey = 1;
		}
		else if (para[1] == 0xA3)
		{
			Vehicle_Calibration_Ant++;
			if (Vehicle_Calibration_Ant >= 3)
			{
				Vehicle_Calibration_Ant = 0;
			}
#ifdef CALIBRATION_DEBUG
			g_datCan1Tx_0x330[0] = 11;
			g_datCan1Tx_0x330[1] = Vehicle_Calibration_Ant;
			BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);
#endif
		}
		else if (para[1] == 0xA4)
		{
			u8PollingFuncRequest_Qn = 2;
		}
		else if (para[1] == 0xA5)
		{
			u8PollingFuncRequest_Qn = 3;
		}
		else if (para[1] == 0xA6)
		{
			u8PE_Auth_KeyPosReq = 1;
		}
		else if (para[1] == 0xA7)
		{
			u8PE_Auth_KeyPosReq = 2;
		}
		else if (para[1] == 0xA8)
		{
			u8PS_Auth_KeyPosReq = 1;
		}
		else if (para[1] == 0xA9)
		{
			u8PS_Auth_KeyPosReq = 2;
		}
		else if (para[1] == 0xAA)
		{
			u8PS_Auth_KeyPosReq = 3;
		}
		else if (para[1] == 0xAB)
		{
			memset(g_datCan1Tx_0x330, 0, 8);
			if (para[2] == 0x01)
			{
				Rand_Val.Value = tsTransmitters[0].SerialNo;
			}
			else if (para[2] == 0x02)
			{
				Rand_Val.Value = tsTransmitters[1].SerialNo;
			}
			else if (para[2] == 0x03)
			{
				Rand_Val.Value = tsTransmitters[2].SerialNo;
			}
			else
			{
				Rand_Val.Value = tsTransmitters[3].SerialNo;
			}

			g_datCan1Tx_0x330[4] = Rand_Val.CHAR_BYTE.Low_byte;
			g_datCan1Tx_0x330[5] = Rand_Val.CHAR_BYTE.Mlow_byte;
			g_datCan1Tx_0x330[6] = Rand_Val.CHAR_BYTE.Mhigh_byte;
			g_datCan1Tx_0x330[7] = Rand_Val.CHAR_BYTE.High_byte;

			BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);
		}
		else if (para[1] == 0xAC)
		{
			Rand_Val.Value = u16UhfFrameRkeAuthOkCount;
			// zch debug
			memset(g_datCan1Tx_0x330, 0, 8);
			g_datCan1Tx_0x330[7] = Rand_Val.CHAR_BYTE.Low_byte;
			g_datCan1Tx_0x330[6] = Rand_Val.CHAR_BYTE.Mlow_byte;
			g_datCan1Tx_0x330[5] = Rand_Val.CHAR_BYTE.Mhigh_byte;
			g_datCan1Tx_0x330[4] = u8FobKey_Disable_Status_Feedback; // Rand_Val.CHAR_BYTE.High_byte;

			BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);
		}
		else if (para[1] == 0xAD)
		{
		}
		else if (para[1] == 0xAE)
		{
		}
		else if (para[1] == 0xAF)
		{
			u8FobKeyEnterWorkState = 2;
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

		u16Left_Door_Ant_DriveCurrent = (uint16_t)
			u32calc;
	}

	if (u8RPEDriverCurRead == 1) // 锟揭诧拷PE锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷取
	{
		u32calc = u8JokerInitRfAntDrvCur * 15625;

		u32calc = u32calc / 1000;
		u16Right_Door_Ant_DriveCurrent = (uint16_t)
			u32calc;
	}

	if (u8PSAntDirverCurRead == 1) // PS锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷取
	{
		u32calc = u8JokerInitInCarAntDrvCur * 15625;

		u32calc = u32calc / 1000;
		u16Incar_Ant_DriveCurrent = (uint16_t)
			u32calc;
	}

	if (u16LPEAntRssiLimitRead == 1) // 锟斤拷锟絇E锟斤拷锟竭筹拷强锟斤拷值锟斤拷�?
	{
		u32calc = (uint32_t)(Lf_DoorAnt_Rssi_Limit * 1000.0);

		u16Left_Door_Ant_Rssi_Limit = (uint16_t)
			u32calc;
	}

	if (u16RPEAntRssiLimitRead == 1) // 锟斤拷锟絇E锟斤拷锟竭筹拷强锟斤拷值锟斤拷�?
	{
		u32calc = (uint32_t)(Rf_DoorAnt_Rssi_Limit * 1000.0);

		u16Right_Door_Ant_Rssi_Limit = (uint16_t)
			u32calc;
	}

	if (u16PSAntRssiLimitRead == 1) // 锟斤拷锟絇E锟斤拷锟竭筹拷强锟斤拷值锟斤拷�?
	{
		u32calc = (uint32_t)(Ps_Ant_Rssi_Limit * 1000.0);

		u16Incar_Ant_Rssi_Limit = (uint16_t)
			u32calc;
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
			u8JokerInitLfAntDrvCur = (uint8_t)
										 u32calc /
									 15625;

			u32calc = u16RPEAntDriveCurrentSet * 1000;
			u8JokerInitRfAntDrvCur = (uint8_t)
										 u32calc /
									 15625;

			u32calc = u16PSAntDriveCurrentSet * 1000;
			u16Incar_Ant_DriveCurrent = (uint8_t)
											u32calc /
										15625;

			u8Njj29c0_WorkStatus = JOKER_INIT;
		}
	}

	u16LPEAntDriveCurrentSetLast = u16LPEAntDriveCurrentSet;
	u16RPEAntDriveCurrentSetLast = u16RPEAntDriveCurrentSet;
	u16PSAntDriveCurrentSetLast = u16PSAntDriveCurrentSet;

	if (u16LPEAntRssiLimitSetLast != u16LPEAntRssiLimitSet)
	{
		Lf_DoorAnt_Rssi_Limit = ((float)u16LPEAntRssiLimitSet) / 1000.0;
	}

	if (u16RPEAntRssiLimitSetLast != u16RPEAntRssiLimitSet)
	{
		Rf_DoorAnt_Rssi_Limit = ((float)u16LPEAntRssiLimitSet) / 1000.0;
	}

	if (u16PSAntRssiLimitSetLast != u16PSAntRssiLimitSet)
	{
		Ps_Ant_Rssi_Limit = ((float)u16PSAntRssiLimitSet) / 1000.0;
	}

	u16LPEAntRssiLimitSetLast = u16LPEAntRssiLimitSet;
	u16RPEAntRssiLimitSetLast = u16RPEAntRssiLimitSet;
	u16PSAntRssiLimitSetLast = u16PSAntRssiLimitSet;

	u32calc = (uint32_t)(InCar_CurRssiCalcVal.value * 1000.0);

	if (u32calc > 0xffff)
	{
		u32calc = 0xffff;
	}

	u16InCar_Door_Ant_Rssi = (uint16_t)
		u32calc;

	u32calc = (uint32_t)(Lf_Door_CurRssiCalcVal.value * 1000.0);

	if (u32calc > 0xffff)
	{
		u32calc = 0xffff;
	}

	u16Leftfront_Door_Ant_Rssi = (uint16_t)
		u32calc;

	u32calc = (uint32_t)(Rf_Door_CurRssiCalcVal.value * 1000.0);

	if (u32calc > 0xffff)
	{
		u32calc = 0xffff;
	}

	u16Rightfront_Door_Ant_Rssi = (uint16_t)
		u32calc;
}

/*******************************************************************************
 * 锟斤拷锟斤拷锟斤�? : LfAuthTransmitterInfoInit
 * 锟斤拷锟斤拷	 : 锟斤拷频锟斤拷锟斤拷锟斤拷息锟侥筹拷�?
	�锟斤拷
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

	(void)
		GetCurUseSecretKey(Uid, tsAes_Crypt_Buffer.Use_SecretKey);

	sLf_Auth_TransmitterInfo.Sum = GetCrc8(&sLf_Auth_TransmitterInfo.Command, 5);
}

/*******************************************************************************
 * 锟斤拷锟斤拷锟斤�? : LFGetRssiTransmitterInfoInit
 * 锟斤拷锟斤拷	 : 锟斤拷频锟斤拷贸锟角恐碉拷锟接︼拷锟�?
	�拷锟斤拷锟较拷某锟绞硷拷�?
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

static void Lf_Ant_ShortOpenCircuit_Diag(void)
{
	uint8_t status = 0;
	supfc_t Ecu_Supf;
	uint8_t DiagBuf[16];

	static uint16_t u16RunMaxTimeCnt = 0;

	u16RunMaxTimeCnt++;
	if (u16RunMaxTimeCnt >= 30)
	{
		u16RunMaxTimeCnt = 0;
		Change_Njj29c0_WorkStatus(lf_ide);
		return;
	}

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
		u16RunMaxTimeCnt = 0;
		JOKER_ClearDiagStatus();
		// JOKER_StartSleepForced();
		Change_Njj29c0_WorkStatus(lf_ide);
	}
}

static void NJJ29C0_Pilot_Pe_Process(void)
{
	static uint16 u16waitmaxcnt = 0;
	uint8 u8LfTx_DATAIDx[3][8] = {0};

	if (0 == u8PepsStep)
	{
		// sdrv_gpio_set_pin_output_level(GPIO_D22,1);
		LfAuthTransmitterInfoInit(PE_PILOT_LF_CMD, tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo);
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);

		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_OFF, RSSI_CARRIER_OFF_LEN);
		JOKER_SetLfCarrier(DATA_ID_DATA_CB, CARRIER_CON, RSSI_CARRIER_ON_LEN);

		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
		JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
		u8PepsStep++;
		// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
	}
	else if (1 == u8PepsStep)
	{
		// sdrv_gpio_set_pin_output_level(GPIO_D22,1);
		u8LfTx_DATAIDx[0][0] = DATA_ID_PREMABLE;
		u8LfTx_DATAIDx[0][1] = DATA_ID_CV;
		u8LfTx_DATAIDx[0][2] = DATA_ID_WUP1;
		u8LfTx_DATAIDx[0][3] = DATA_ID_DATA_PE;
		u8LfTx_DATAIDx[0][4] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[0][5] = DATA_ID_DATA_CB;

		u8LfTx_DATAIDx[1][0] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[1][1] = DATA_ID_DATA_CB;

		// u8LfTx_DATAIDx[2][0] = DATA_ID_DATA_RSSI;
		// u8LfTx_DATAIDx[2][1] = DATA_ID_DATA_CB;

		Peps_Cfg_Joker_Tx_Message(DR2P, 6, &u8LfTx_DATAIDx[0][0], DR4P, 2, &u8LfTx_DATAIDx[1][0], DRP_NULL, 0, &u8LfTx_DATAIDx[2][0]);
		u16waitmaxcnt = PE_LF_TX_MAX_PERIOD;
		u8HitagAuthPass = 0;
		u8PepsStep++;
		// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
	}
	else if (2 == u8PepsStep)
	{
		u16waitmaxcnt--;
		if (u16waitmaxcnt == 0)
		{
			JOKER_StopLfTransmit();
			// sdrv_gpio_set_pin_output_level(GPIO_D22,0);

			u8PepsTxCnt--;
			if (u8PepsTxCnt == 0)
			{
				u8PepsTxCnt = PEPS_TX_MAX_COUNT;

				if (1 == tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn)
				{
					SetPe_AuthFobStatus(2);
					// JOKER_StartSleepForced();
					Change_Njj29c0_WorkStatus(lf_ide);
					return;
				}

				if (GetTransmitterCountVal() == 0)
				{
					// JOKER_StartSleepForced();
					Change_Njj29c0_WorkStatus(lf_ide);
					return;
				}
				else if (GetTransmitterCountVal() == 1)
				{
					SetPe_AuthFobStatus(2);
					// JOKER_StartSleepForced();
					Change_Njj29c0_WorkStatus(lf_ide);

					// zch debug
					memset(g_datCan1Tx_0x330, 0, 8);
					g_datCan1Tx_0x330[0] = 0x80;
					g_datCan1Tx_0x330[1] = 0x01;
					g_datCan1Tx_0x330[2] = 0x01;

					BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);

					return;
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
		}
		else
		{
			if (u8HitagAuthPass == 1)
			{
				u8HitagAuthPass = 0;
				JOKER_StopLfTransmit();
				// JOKER_StartSleepForced();
				//  sdrv_gpio_set_pin_output_level(GPIO_D22,0);
				Change_Njj29c0_WorkStatus(lf_ide);
			}
		}
	}
	else if (3 == u8PepsStep)
	{
		// sdrv_gpio_set_pin_output_level(GPIO_D22,1);
		LfAuthTransmitterInfoInit(PE_PILOT_LF_CMD, tsTransmitters[u8PlanUseFobKeyUid_Index[1]].SerialNo);
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);

		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_OFF, RSSI_CARRIER_OFF_LEN);
		JOKER_SetLfCarrier(DATA_ID_DATA_CB, CARRIER_CON, RSSI_CARRIER_ON_LEN);

		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
		JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
		u8PepsStep++;
		// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
	}
	else if (4 == u8PepsStep)
	{
		// sdrv_gpio_set_pin_output_level(GPIO_D22,1);
		u8LfTx_DATAIDx[0][0] = DATA_ID_PREMABLE;
		u8LfTx_DATAIDx[0][1] = DATA_ID_CV;
		u8LfTx_DATAIDx[0][2] = DATA_ID_WUP1;
		u8LfTx_DATAIDx[0][3] = DATA_ID_DATA_PE;
		u8LfTx_DATAIDx[0][4] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[0][5] = DATA_ID_DATA_CB;

		u8LfTx_DATAIDx[1][0] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[1][1] = DATA_ID_DATA_CB;

		// u8LfTx_DATAIDx[2][0] = DATA_ID_DATA_RSSI;
		// u8LfTx_DATAIDx[2][1] = DATA_ID_DATA_CB;

		Peps_Cfg_Joker_Tx_Message(DR2P, 6, &u8LfTx_DATAIDx[0][0], DR4P, 2, &u8LfTx_DATAIDx[1][0], DRP_NULL, 0, &u8LfTx_DATAIDx[2][0]);
		u16waitmaxcnt = PE_LF_TX_MAX_PERIOD;
		u8HitagAuthPass = 0;
		u8PepsStep++;
		// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
	}
	else
	{
		u16waitmaxcnt--;
		if (u16waitmaxcnt == 0)
		{
			JOKER_StopLfTransmit();
			// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
			u8PepsTxCnt--;
			if (u8PepsTxCnt == 0)
			{
				u8PepsTxCnt = PEPS_TX_MAX_COUNT;

				SetPe_AuthFobStatus(2);
				// JOKER_StartSleepForced();
				Change_Njj29c0_WorkStatus(lf_ide);
				// zch debug
				memset(g_datCan1Tx_0x330, 0, 8);
				g_datCan1Tx_0x330[0] = 0x80;
				g_datCan1Tx_0x330[1] = 0x01;
				g_datCan1Tx_0x330[2] = 0x02;

				BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);
			}
			else
			{
				u8PepsStep = 3;
			}
		}
		else
		{
			if (u8HitagAuthPass == 1)
			{
				u8HitagAuthPass = 0;
				JOKER_StopLfTransmit();
				// JOKER_StartSleepForced();
				//  sdrv_gpio_set_pin_output_level(GPIO_D22,0);
				Change_Njj29c0_WorkStatus(lf_ide);
			}
		}
	}
}

static void NJJ29C0_Copilot_Pe_Process(void)
{
	static uint16 u16waitmaxcnt = 0;
	uint8 u8LfTx_DATAIDx[3][8] = {0};

	if (0 == u8PepsStep)
	{
		// Dio_WriteChannel(175, 0);
		//  sdrv_gpio_set_pin_output_level(GPIO_D22,1);
		LfAuthTransmitterInfoInit(PE_COPILOT_LF_CMD, tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo);

		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);

		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_OFF, RSSI_CARRIER_OFF_LEN);
		JOKER_SetLfCarrier(DATA_ID_DATA_CB, CARRIER_CON, RSSI_CARRIER_ON_LEN);

		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
		JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
		u8PepsStep++;
		// Dio_WriteChannel(175, 1);
		// Change_Njj29c0_WorkStatus(lf_ide);
		//  sdrv_gpio_set_pin_output_level(GPIO_D22,0);
	}
	else if (1 == u8PepsStep)
	{
		// sdrv_gpio_set_pin_output_level(GPIO_D22,1);

		u8LfTx_DATAIDx[0][0] = DATA_ID_PREMABLE;
		u8LfTx_DATAIDx[0][1] = DATA_ID_CV;
		u8LfTx_DATAIDx[0][2] = DATA_ID_WUP1;
		u8LfTx_DATAIDx[0][3] = DATA_ID_DATA_PE;
		u8LfTx_DATAIDx[0][4] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[0][5] = DATA_ID_DATA_CB;

		u8LfTx_DATAIDx[1][0] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[1][1] = DATA_ID_DATA_CB;

		// u8LfTx_DATAIDx[2][0] = DATA_ID_DATA_RSSI;
		// u8LfTx_DATAIDx[2][1] = DATA_ID_DATA_CB;

		Peps_Cfg_Joker_Tx_Message(DR3P, 6, &u8LfTx_DATAIDx[0][0], DR4P, 2, &u8LfTx_DATAIDx[1][0], DRP_NULL, 0, &u8LfTx_DATAIDx[2][0]);
		u16waitmaxcnt = PE_LF_TX_MAX_PERIOD;
		u8HitagAuthPass = 0;
		u8PepsStep++;
		// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
	}
	else if (2 == u8PepsStep)
	{
		u16waitmaxcnt--;
		if (u16waitmaxcnt == 0)
		{
			JOKER_StopLfTransmit();
			// sdrv_gpio_set_pin_output_level(GPIO_D22,0);

			u8PepsTxCnt--;
			if (u8PepsTxCnt == 0)
			{
				u8PepsTxCnt = PEPS_TX_MAX_COUNT;

				if (1 == tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn)
				{
					SetPe_AuthFobStatus(2);
					// JOKER_StartSleepForced();
					Change_Njj29c0_WorkStatus(lf_ide);
					return;
				}

				if (GetTransmitterCountVal() == 0)
				{
					// JOKER_StartSleepForced();
					Change_Njj29c0_WorkStatus(lf_ide);
					return;
				}
				else if (GetTransmitterCountVal() == 1)
				{
					SetPe_AuthFobStatus(2);
					// JOKER_StartSleepForced();
					Change_Njj29c0_WorkStatus(lf_ide);
					// zch debug
					memset(g_datCan1Tx_0x330, 0, 8);
					g_datCan1Tx_0x330[0] = 0x80;
					g_datCan1Tx_0x330[1] = 0x01;
					g_datCan1Tx_0x330[2] = 0x03;

					BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);
					return;
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
		}
		else
		{
			if (u8HitagAuthPass == 1)
			{
				u8HitagAuthPass = 0;
				JOKER_StopLfTransmit();
				// JOKER_StartSleepForced();
				//   sdrv_gpio_set_pin_output_level(GPIO_D22,0);
				Change_Njj29c0_WorkStatus(lf_ide);
			}
		}
	}
	else if (3 == u8PepsStep)
	{
		// sdrv_gpio_set_pin_output_level(GPIO_D22,1);
		LfAuthTransmitterInfoInit(PE_COPILOT_LF_CMD, tsTransmitters[u8PlanUseFobKeyUid_Index[1]].SerialNo);
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);

		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_OFF, RSSI_CARRIER_OFF_LEN);
		JOKER_SetLfCarrier(DATA_ID_DATA_CB, CARRIER_CON, RSSI_CARRIER_ON_LEN);

		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
		JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
		u8PepsStep++;
		// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
	}
	else if (4 == u8PepsStep)
	{
		// sdrv_gpio_set_pin_output_level(GPIO_D22,1);

		u8LfTx_DATAIDx[0][0] = DATA_ID_PREMABLE;
		u8LfTx_DATAIDx[0][1] = DATA_ID_CV;
		u8LfTx_DATAIDx[0][2] = DATA_ID_WUP1;
		u8LfTx_DATAIDx[0][3] = DATA_ID_DATA_PE;
		u8LfTx_DATAIDx[0][4] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[0][5] = DATA_ID_DATA_CB;

		u8LfTx_DATAIDx[1][0] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[1][1] = DATA_ID_DATA_CB;

		// u8LfTx_DATAIDx[2][0] = DATA_ID_DATA_RSSI;
		// u8LfTx_DATAIDx[2][1] = DATA_ID_DATA_CB;

		Peps_Cfg_Joker_Tx_Message(DR3P, 6, &u8LfTx_DATAIDx[0][0], DR4P, 2, &u8LfTx_DATAIDx[1][0], DRP_NULL, 0, &u8LfTx_DATAIDx[2][0]);
		u16waitmaxcnt = PE_LF_TX_MAX_PERIOD;
		u8HitagAuthPass = 0;
		u8PepsStep++;
		// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
	}
	else
	{
		u16waitmaxcnt--;
		if (u16waitmaxcnt == 0)
		{
			JOKER_StopLfTransmit();
			// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
			u8PepsTxCnt--;
			if (u8PepsTxCnt == 0)
			{
				u8PepsTxCnt = PEPS_TX_MAX_COUNT;

				SetPe_AuthFobStatus(2);
				// JOKER_StartSleepForced();
				Change_Njj29c0_WorkStatus(lf_ide);
				// zch debug
				memset(g_datCan1Tx_0x330, 0, 8);
				g_datCan1Tx_0x330[0] = 0x80;
				g_datCan1Tx_0x330[1] = 0x01;
				g_datCan1Tx_0x330[2] = 0x04;
				BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);
			}
			else
			{
				u8PepsStep = 3;
			}
		}
		else
		{
			if (u8HitagAuthPass == 1)
			{
				u8HitagAuthPass = 0;
				JOKER_StopLfTransmit();
				// JOKER_StartSleepForced();
				//  sdrv_gpio_set_pin_output_level(GPIO_D22,0);
				Change_Njj29c0_WorkStatus(lf_ide);
			}
		}
	}
}

static void NJJ29C0_Ps_Process(void)
{
	static uint16 u16waitmaxcnt = 0;
	uint8 u8LfTx_DATAIDx[3][8] = {0};

	if (0 == u8PepsStep)
	{
		// sdrv_gpio_set_pin_output_level(GPIO_D22,1);
		LfAuthTransmitterInfoInit(PS_LF_CMD, tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo);
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);

		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_OFF, RSSI_CARRIER_OFF_LEN);
		JOKER_SetLfCarrier(DATA_ID_DATA_CB, CARRIER_CON, RSSI_CARRIER_ON_LEN);

		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
		JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
		u8PepsStep++;
		// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
	}
	else if (1 == u8PepsStep)
	{
		// sdrv_gpio_set_pin_output_level(GPIO_D22,1);
		u8LfTx_DATAIDx[0][0] = DATA_ID_PREMABLE;
		u8LfTx_DATAIDx[0][1] = DATA_ID_CV;
		u8LfTx_DATAIDx[0][2] = DATA_ID_WUP1;
		u8LfTx_DATAIDx[0][3] = DATA_ID_DATA_PE;
		u8LfTx_DATAIDx[0][4] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[0][5] = DATA_ID_DATA_CB;

		u8LfTx_DATAIDx[1][0] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[1][1] = DATA_ID_DATA_CB;

		u8LfTx_DATAIDx[2][0] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[2][1] = DATA_ID_DATA_CB;

		Peps_Cfg_Joker_Tx_Message(DR4P, 6, &u8LfTx_DATAIDx[0][0], DR2P, 2, &u8LfTx_DATAIDx[1][0], DR3P, 2, &u8LfTx_DATAIDx[2][0]);
		u16waitmaxcnt = PE_LF_TX_MAX_PERIOD;
		u8HitagAuthPass = 0;
		u8PepsStep++;
		// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
	}
	else if (2 == u8PepsStep)
	{
		u16waitmaxcnt--;
		if (u16waitmaxcnt == 0)
		{
			JOKER_StopLfTransmit();
			// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
			u8PepsTxCnt--;
			if (u8PepsTxCnt == 0)
			{
				u8PepsTxCnt = PEPS_TX_MAX_COUNT;

				if (1 == tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn)
				{
					bStartImmoAuthFlag = true;
					Change_Njj29c0_WorkStatus(lf_ide);
					return;
				}

				if (GetTransmitterCountVal() == 0)
				{
					// JOKER_StartSleepForced();
					Change_Njj29c0_WorkStatus(lf_ide);
					return;
				}
				else if (GetTransmitterCountVal() == 1)
				{
					bStartImmoAuthFlag = true;
					Change_Njj29c0_WorkStatus(lf_ide);
					return;
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
		}
		else
		{
			if (u8HitagAuthPass == 1)
			{
				u8HitagAuthPass = 0;
				JOKER_StopLfTransmit();
				// JOKER_StartSleepForced();
				//  sdrv_gpio_set_pin_output_level(GPIO_D22,0);
				Change_Njj29c0_WorkStatus(lf_ide);
			}
		}
	}
	else if (3 == u8PepsStep)
	{
		// sdrv_gpio_set_pin_output_level(GPIO_D22,1);
		LfAuthTransmitterInfoInit(PS_LF_CMD, tsTransmitters[u8PlanUseFobKeyUid_Index[1]].SerialNo);
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);

		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_OFF, RSSI_CARRIER_OFF_LEN);
		JOKER_SetLfCarrier(DATA_ID_DATA_CB, CARRIER_CON, RSSI_CARRIER_ON_LEN);

		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
		JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);

		u8PepsStep++;
		// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
	}
	else if (4 == u8PepsStep)
	{
		// sdrv_gpio_set_pin_output_level(GPIO_D22,1);
		u8LfTx_DATAIDx[0][0] = DATA_ID_PREMABLE;
		u8LfTx_DATAIDx[0][1] = DATA_ID_CV;
		u8LfTx_DATAIDx[0][2] = DATA_ID_WUP1;
		u8LfTx_DATAIDx[0][3] = DATA_ID_DATA_PE;
		u8LfTx_DATAIDx[0][4] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[0][5] = DATA_ID_DATA_CB;

		u8LfTx_DATAIDx[1][0] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[1][1] = DATA_ID_DATA_CB;

		u8LfTx_DATAIDx[2][0] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[2][1] = DATA_ID_DATA_CB;

		Peps_Cfg_Joker_Tx_Message(DR4P, 6, &u8LfTx_DATAIDx[0][0], DR2P, 2, &u8LfTx_DATAIDx[1][0], DR3P, 2, &u8LfTx_DATAIDx[2][0]);
		u16waitmaxcnt = PE_LF_TX_MAX_PERIOD;
		u8HitagAuthPass = 0;
		u8PepsStep++;
		// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
	}
	else
	{
		u16waitmaxcnt--;
		if (u16waitmaxcnt == 0)
		{
			JOKER_StopLfTransmit();
			// sdrv_gpio_set_pin_output_level(GPIO_D22,0);
			u8PepsTxCnt--;
			if (u8PepsTxCnt == 0)
			{
				u8PepsTxCnt = PEPS_TX_MAX_COUNT;

				// bStartImmoAuthFlag = true;
				Change_Njj29c0_WorkStatus(lf_ide);
			}
			else
			{
				u8PepsStep = 3;
			}
		}
		else
		{
			if (u8HitagAuthPass == 1)
			{
				u8HitagAuthPass = 0;
				JOKER_StopLfTransmit();
				// JOKER_StartSleepForced();
				//  sdrv_gpio_set_pin_output_level(GPIO_D22,0);
				Change_Njj29c0_WorkStatus(lf_ide);
			}
		}
	}
}

static void NJJ29C0_Prohibit_Process(void)
{
	static uint16 u16waitmaxcnt = 0;
	uint8 u8LfTx_DATAIDx[3][8] = {0};

	if (0 == u8PepsStep)
	{
		LfAuthTransmitterInfoInit(PS_LF_CMD, tsTransmitters[u8FobKeyIndex].SerialNo);
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);

		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_OFF, RSSI_CARRIER_OFF_LEN);
		JOKER_SetLfCarrier(DATA_ID_DATA_CB, CARRIER_CON, RSSI_CARRIER_ON_LEN);

		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
		JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);
		u8PepsStep++;
	}
	else if (1 == u8PepsStep)
	{
		u8LfTx_DATAIDx[0][0] = DATA_ID_PREMABLE;
		u8LfTx_DATAIDx[0][1] = DATA_ID_CV;
		u8LfTx_DATAIDx[0][2] = DATA_ID_WUP1;
		u8LfTx_DATAIDx[0][3] = DATA_ID_DATA_PE;
		u8LfTx_DATAIDx[0][4] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[0][5] = DATA_ID_DATA_CB;

		u8LfTx_DATAIDx[1][0] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[1][1] = DATA_ID_DATA_CB;

		u8LfTx_DATAIDx[2][0] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[2][1] = DATA_ID_DATA_CB;

		Peps_Cfg_Joker_Tx_Message(DR4P, 6, &u8LfTx_DATAIDx[0][0], DR2P, 2, &u8LfTx_DATAIDx[1][0], DR3P, 2, &u8LfTx_DATAIDx[2][0]);
		u16waitmaxcnt = PE_LF_TX_MAX_PERIOD;
		u8HitagAuthPass = 0;
		u8PepsStep++;
	}
	else // if (2 == u8PepsStep)
	{
		if (u8HitagAuthPass == 1)
		{
			// Quickly jump to the next remote search
			u8HitagAuthPass = 0;
			u16waitmaxcnt = 1;
			u8PepsTxCnt = 1;
		}

		u16waitmaxcnt--;
		if (u16waitmaxcnt == 0)
		{
			JOKER_StopLfTransmit();
			u8PepsTxCnt--;
			if (u8PepsTxCnt == 0)
			{
				u8PepsTxCnt = PEPS_TX_MAX_COUNT;

				u8FobKeyIndex++;
				if (u8FobKeyIndex >= GetTransmitterCountVal())
				{
					// JOKER_StartSleepForced();
					Change_Njj29c0_WorkStatus(lf_ide);
					return;
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

static void NJJ29C0_Prohibit_WelcomeGuest_Process(void)
{
	static uint16 u16waitmaxcnt = 0;
	uint8 u8LfTx_DATAIDx[3][8] = {0};

	if (0 == u8PepsStep)
	{
		LfAuthTransmitterInfoInit(0x10, tsTransmitters[u8PlanUseFobKeyUid_Index[u8FobKeyIndex]].SerialNo);
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);

		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_OFF, RSSI_CARRIER_OFF_LEN);
		JOKER_SetLfCarrier(DATA_ID_DATA_CB, CARRIER_CON, RSSI_CARRIER_ON_LEN);

		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);
		JOKER_SetLfData(DATA_ID_DATA_PE, 6, &sLf_Auth_TransmitterInfo.Command);

		u8PepsStep++;
	}
	else if (1 == u8PepsStep)
	{
		u8LfTx_DATAIDx[0][0] = DATA_ID_PREMABLE;
		u8LfTx_DATAIDx[0][1] = DATA_ID_CV;
		u8LfTx_DATAIDx[0][2] = DATA_ID_WUP1;
		u8LfTx_DATAIDx[0][3] = DATA_ID_DATA_PE;
		u8LfTx_DATAIDx[0][4] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[0][5] = DATA_ID_DATA_CB;

		u8LfTx_DATAIDx[1][0] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[1][1] = DATA_ID_DATA_CB;

		u8LfTx_DATAIDx[2][0] = DATA_ID_DATA_RSSI;
		u8LfTx_DATAIDx[2][1] = DATA_ID_DATA_CB;

		Peps_Cfg_Joker_Tx_Message(DR4P, 6, &u8LfTx_DATAIDx[0][0], DR2P, 2, &u8LfTx_DATAIDx[1][0], DR3P, 2, &u8LfTx_DATAIDx[2][0]);
		u16waitmaxcnt = PE_LF_TX_MAX_PERIOD;
		u8HitagAuthPass = 0;
		u8PepsStep++;
	}
	else if (2 == u8PepsStep)
	{
		if (u8HitagAuthPass == 1)
		{
			// Quickly jump to the next remote search
			u8HitagAuthPass = 0;
			u16waitmaxcnt = 1;
			u8PepsTxCnt = 1;
		}

		u16waitmaxcnt--;
		if (u16waitmaxcnt == 0)
		{
			JOKER_StopLfTransmit();
			u8PepsTxCnt--;
			if (u8PepsTxCnt == 0)
			{
				u8PepsTxCnt = PEPS_TX_MAX_COUNT;
				u8FobKeyIndex++;
				if (u8FobKeyIndex >= 2)
				{
					// JOKER_StartSleepForced();
					Change_Njj29c0_WorkStatus(lf_ide);
					return;
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
	uint8 spitxFrame[32] =
		{
			0};
	LONG_UNION Rand_Val;
	static uint8 u8WelcomeGuest01_Set_Step = 0;
	int8_t fun_sta = 0;

	u8WelcomeGuest01_Set_Step++;

	if (1 == u8WelcomeGuest01_Set_Step)
	{
		LfAuthTransmitterInfoInit(WELCOMEGUEST_AUTH_LF_CMD, tsTransmitters[use_fobkey_num].SerialNo);
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
		Peps_Fun_ConfigTimerPolling(WELCOMEGUEST_AUTH_LF_CMD, NULL, NULL, DR2P, (PS_FUN_POLLING_CYCYE + PS_FUN_POLLING_CYCYE), DR3P, (PS_FUN_POLLING_CYCYE + PS_FUN_POLLING_CYCYE));
		JOKER_StartTimerPolling();
		u8WelcomeGuest01_Set_Step = 0;
		u8HitagAuthPass = 0;
		fun_sta = 1;
	}

	return fun_sta;
}

static int8_t NJJ29C0_WelcomeGuest_Unlock_SearchTrack_Key(uint8_t Carrier_En, uint16_t cycle) // Ô¿ï¿½×¹ì¼£ï¿½ï¿½ï¿½ï¿½
{
	uint8 spitxFrame[32] = {0};
	LONG_UNION Rand_Val;
	static uint8 u8WelcomeGuest1_Set_Step = 0;
	static uint8 u8WecomeGuestWakeUpFobKeyUidInd = 0;
	int8_t fun_sta = 0;

	u8WelcomeGuest1_Set_Step++;

	if (1 == u8WelcomeGuest1_Set_Step)
	{
		if (u8WelcomeGuestWakeUpInd == 0)
		{
			u8WelcomeGuest1_Set_Step = 0;
			fun_sta = -1;
		}
	}
	else if (2 == u8WelcomeGuest1_Set_Step)
	{
		if (u8WelcomeGuestWakeUpInd >= 0x03)
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
			if (u8WelcomeGuestWakeUpInd == 0x01)
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
		if (u8WelcomeGuestWakeUpInd == 3)
		{
			LFGetRssiTransmitterInfoInit(0x15);
			JOKER_SetLfData(DATA_ID_DATA_PE, 2, &sLf_FobLocate_TransmitterInfo.Command);

			LFGetRssiTransmitterInfoInit(0x16);
			JOKER_SetLfData(DATA_ID_CC_5, 2, &sLf_FobLocate_TransmitterInfo.Command);
		}
		else
		{
			if (u8WelcomeGuestWakeUpInd == 1)
			{
				LFGetRssiTransmitterInfoInit(0x15);
			}
			else
			{
				LFGetRssiTransmitterInfoInit(0x16);
			}

			JOKER_SetLfData(DATA_ID_DATA_PE, 2, &sLf_FobLocate_TransmitterInfo.Command);
		}
	}
	else if (4 == u8WelcomeGuest1_Set_Step)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON, RSSI_CARRIER_ON_LEN);
	}
	else if (5 == u8WelcomeGuest1_Set_Step)
	{
		if (u8WelcomeGuestWakeUpInd == 3)
		{
			WelcomeGuest_ConfigTimerPollingTwo(2, DR2P | DR3P, 30, DR2P | DR3P, cycle, Carrier_En);
		}
		else
		{
			WelcomeGuest_ConfigTimerPollingTwo(1, DR2P | DR3P, cycle, 0, 0, Carrier_En);
		}
		JOKER_StartTimerPolling();
		u8WelcomeGuest1_Set_Step = 0;
		fun_sta = 1;
	}
	else
	{
		u8WelcomeGuest1_Set_Step = 0;
	}

	return fun_sta;
}

static int8_t NJJ29C2_PollingWakeUpFobkey_Process(uint16_t cycle)
{
	uint8 spitxFrame[32] = {0};
	static uint8 u8WelcomeGuest1_Set_Step = 0;
	LONG_UNION Rand_Val;
	int8_t fun_sta = 0;

	if (0 == u8WelcomeGuest1_Set_Step)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		u8WelcomeGuest1_Set_Step++;
	}
	else if (1 == u8WelcomeGuest1_Set_Step)
	{
		Rand_Val.Value = WUPA_ID;
		spitxFrame[0] = Rand_Val.CHAR_BYTE.High_byte;
		spitxFrame[1] = Rand_Val.CHAR_BYTE.Mhigh_byte;
		spitxFrame[2] = Rand_Val.CHAR_BYTE.Mlow_byte;
		spitxFrame[3] = Rand_Val.CHAR_BYTE.Low_byte;
		JOKER_SetLfData(DATA_ID_WUP1, 4, spitxFrame);

		spitxFrame[0] = 0x09;
		spitxFrame[1] = u8WelcomeGuestPollingWakeUpUid[0];
		spitxFrame[2] = u8WelcomeGuestPollingWakeUpUid[1];
		JOKER_SetLfData(DATA_ID_DATA_PE, 3, &spitxFrame[0]);

		u8WelcomeGuest1_Set_Step++;
	}
	else
	{
		WelcomeGuest_ConfigTimerPollingWakeUp(DR2P | DR3P, cycle);
		// WelcomeGuest_Unlock_PollingWakeUp(DR2P,DR3P,cycle);
		JOKER_StartTimerPolling();
		u8WelcomeGuestWakeUpInd = 0;
		u8WelcomeGuest1_Set_Step = 0;
		fun_sta = 1;
	}
	return fun_sta;
}

static int8_t NJJ29C0_WelcomeGuest_Lock_SearchTrack_Key(uint8_t Carrier_En, uint16_t cycle)
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
			u8WelcomeGuest1_Set_Step = 0;
			fun_sta = -1;
		}

		u8WecomeGuestWakeUpFobKeyUidInd = 0;
		if (0 == tsTransmitters[u8PlanUseFobKeyUid_Index[0]].FobKeyEn)
		{
			u8WecomeGuestWakeUpFobKeyUidInd |= 0x01;
		}

		if (0 == tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn)
		{
			if (u8TransmitterCount > 1)
			{
				u8WecomeGuestWakeUpFobKeyUidInd |= 0x02;
			}
		}

		u8WelcomeGuestWakeUpInd = u8WecomeGuestWakeUpFobKeyUidInd;
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
			JOKER_SetLfData(DATA_ID_DATA_PE, 2, &sLf_FobLocate_TransmitterInfo.Command);

			LFGetRssiTransmitterInfoInit(0x16);
			JOKER_SetLfData(DATA_ID_CC_5, 2, &sLf_FobLocate_TransmitterInfo.Command);
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

			JOKER_SetLfData(DATA_ID_DATA_PE, 2, &sLf_FobLocate_TransmitterInfo.Command);
		}
	}
	else if (4 == u8WelcomeGuest1_Set_Step)
	{
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);
		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_CON, RSSI_CARRIER_ON_LEN);
	}
	else if (5 == u8WelcomeGuest1_Set_Step)
	{
		if (u8WecomeGuestWakeUpFobKeyUidInd == 3)
		{
			WelcomeGuest_ConfigTimerPollingTwo(2, DR2P | DR3P, 30, DR2P | DR3P, cycle, Carrier_En);
		}
		else
		{
			WelcomeGuest_ConfigTimerPollingTwo(1, DR2P | DR3P, cycle, 0, 0, Carrier_En);
		}
		JOKER_StartTimerPolling();
		u8WelcomeGuest1_Set_Step = 0;
		fun_sta = 1;
	}
	else
	{
		u8WelcomeGuest1_Set_Step = 0;
	}

	return fun_sta;
}

void NJJ29C0_PollingUnlock_Process(void)
{
	static uint16_t u16PollingUnlockWaitMaxTime = 0;
	static uint8_t u8WakeUpFobsIndex = 0;
	int8_t s8TmpStatus = 0;

	if ((u8PollingFuncRequest > 0) || (u8PE_Auth_KeyPosReq > 0) || (u8PS_Auth_KeyPosReq > 0))
	{
		JOKER_WakeUp();
		// JOKER_StartSleepForced();
		Change_Njj29c0_WorkStatus(lf_ide);
		return;
	}

	if (u8PollingFuncRequestBak == 0)
	{
		u8Lf_Polling_Work_State = 2;
	}
	else
	{
		u8Lf_Polling_Work_State = 3;
	}

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

		if (NJJ29C2_PollingWakeUpFobkey_Process(u16PollingUnlockWaitMaxTime) == 1)
		{
			bWaitAllFobKey_A_WakeUp = 0;
			bWaitAllFobKey_B_WakeUp = 0;
			Lf_Door_CurRssiCalcVal.value = 0;
			Rf_Door_CurRssiCalcVal.value = 0;
			// u32Lf_CurRssi_Index = 0;
			// u32Rf_CurRssi_Index = 0;
			u16PollingUnlockWaitMaxTime = 0;
			u8PollingUnlockStep++;
		}
		break;

	case 1:
		if (u8WelcomeGuestWakeUpInd > 0)
		{
			JOKER_WakeUp();
			u8PollingUnlockStep++;
			u8WakeUpFobsIndex = 0;
		}
		break;

	case 2:
		u16PollingUnlockWaitMaxTime++;
		if ((u16PollingUnlockWaitMaxTime >= 90) || (u8WelcomeGuestWakeUpInd >= 0x03)) // 180ms
		{
			u16PollingUnlockWaitMaxTime = 0;
			u8PollingUnlockStep++;
		}
		break;

	case 3:
		s8TmpStatus = NJJ29C0_WelcomeGuest_Unlock_SearchTrack_Key(1, WELCOMEGUEST_POLLING_CYCLE01);

		if (s8TmpStatus == -1)
		{
			JOKER_WakeUp();
			u8PollingUnlockStep = 0;
		}
		else if (s8TmpStatus == 1)
		{
			bWaitAllFobKey_A_WakeUp = 0;
			bWaitAllFobKey_B_WakeUp = 0;
			u8Welcome_Function_Request_Bak = 0;
			Lf_Door_CurRssiCalcVal.value = 0;
			Rf_Door_CurRssiCalcVal.value = 0;
			u16PollingUnlockWaitMaxTime = 0;
			u8PollingUnlockStep++;
			u8Key_A_Check_Thread = 0;
			u8Key_B_Check_Thread = 0;
		}

		break;

	case 4:
		if ((bWaitAllFobKey_A_WakeUp == 0) && (bWaitAllFobKey_B_WakeUp == 0))
		{
			u16PollingUnlockWaitMaxTime++;

			if (u16PollingUnlockWaitMaxTime >= 1000)
			{
				// Neither of the 2 remote control keys awakened is a matching remote control.
				JOKER_WakeUp();
				u8PollingUnlockStep = 0;
				return;
			}
		}
		else
		{
			u16PollingUnlockWaitMaxTime = 0;
		}

		switch (u8Key_A_Check_Thread)
		{
		case 0:
			if (bWaitAllFobKey_A_WakeUp == 1)
			{
				bWaitAllFobKey_A_WakeUp = 0;

				if (Lf_Door_CurRssiCalcVal.value >= DOORANT_RSSI_Z1_LIMIT)
				{
					// u8Welcome_Function_Request_Bak = 1;
					//  Key_A_next_target_value = Lf_Door_CurRssiCalcVal.value + 860000;
				}
				else if (Lf_Door_CurRssiCalcVal.value >= DOORANT_RSSI_Z2_LIMIT)
				{
					u8Key_A_Check_Thread++;
					Key_A_next_target_value = Lf_Door_CurRssiCalcVal.value + 0.38;
				}
				else
				{
					if (u8Welcome_Function_Request_Bak == 0)
					{
						u8Welcome_Function_Request = 1; // Polling light Request

						// zch debug
						memset(g_datCan1Tx_0x330, 0, 8);
						g_datCan1Tx_0x330[0] = 0x80;
						g_datCan1Tx_0x330[1] = 0x03;
						g_datCan1Tx_0x330[2] = 0x06;
						BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);
					}
					u8Key_A_Check_Thread++;
					Key_A_next_target_value = Lf_Door_CurRssiCalcVal.value + 0.5;
				}

				Lf_Door_CurRssiCalcVal.value = 0;
			}
			break;

		case 1:
			if (bWaitAllFobKey_A_WakeUp == 1)
			{
				bWaitAllFobKey_A_WakeUp = 0;

				if (Lf_Door_CurRssiCalcVal.value >= Key_A_next_target_value)
				{
					JOKER_WakeUp();
					u8PollingUnlockStep++;
					u8Key_A_Check_Thread = 0;
					u8WakeUpFobsIndex = u8PlanUseFobKeyUid_Index[0];
				}

				Lf_Door_CurRssiCalcVal.value = 0;
			}
			break;

		default:
			u8Key_A_Check_Thread = 0;
			break;
		}

		switch (u8Key_B_Check_Thread)
		{
		case 0:
			if (bWaitAllFobKey_B_WakeUp == 1)
			{
				bWaitAllFobKey_B_WakeUp = 0;
				if (Rf_Door_CurRssiCalcVal.value >= DOORANT_RSSI_Z1_LIMIT)
				{
					// u8Welcome_Function_Request_Bak = 1;
					//  Key_B_next_target_value = Rf_Door_CurRssiCalcVal.value + 860000.0;
				}
				else if (Rf_Door_CurRssiCalcVal.value >= DOORANT_RSSI_Z2_LIMIT)
				{
					u8Key_B_Check_Thread++;
					Key_B_next_target_value = Rf_Door_CurRssiCalcVal.value + 0.38;
				}
				else
				{
					if (u8Welcome_Function_Request_Bak == 0)
					{
						u8Welcome_Function_Request = 1; // Polling light Request
					}
					u8Key_B_Check_Thread++;
					Key_B_next_target_value = Rf_Door_CurRssiCalcVal.value + 0.5;
				}

				Rf_Door_CurRssiCalcVal.value = 0;
			}
			break;

		case 1:
			if (bWaitAllFobKey_B_WakeUp == 1)
			{
				bWaitAllFobKey_B_WakeUp = 0;

				if (Rf_Door_CurRssiCalcVal.value >= Key_B_next_target_value)
				{
					JOKER_WakeUp();
					u8PollingUnlockStep++;
					u8Key_B_Check_Thread = 0;
					u8WakeUpFobsIndex = u8PlanUseFobKeyUid_Index[1];
				}

				Rf_Door_CurRssiCalcVal.value = 0;
			}
			break;

		default:
			u8Key_B_Check_Thread = 0;
			break;
		}

		break;

	case 5:
		if (WelcomeGuest_Auth(u8WakeUpFobsIndex) == 1)
		{
			u16PollingUnlockWaitMaxTime = 0;
			u8PollingUnlockStep++;
		}
		break;

	case 6:
		u16PollingUnlockWaitMaxTime++;
		if (u16PollingUnlockWaitMaxTime >= 300)
		{
			JOKER_WakeUp();
			u8PollingUnlockStep++;
		}
		else
		{
			if (u8HitagAuthPass == 1)
			{
				JOKER_WakeUp();
				Change_Njj29c0_WorkStatus(lf_ide);

				u8Welcome_Function_Request = 2; // Polling light Request
				// zch debug
				memset(g_datCan1Tx_0x330, 0, 8);
				g_datCan1Tx_0x330[0] = 0x80;
				g_datCan1Tx_0x330[1] = 0x03;
				g_datCan1Tx_0x330[2] = 0x07;
				BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);

				if (u8PlanUseFobKeyUid_Index[0] != u8WakeUpFobsIndex)
				{
					uint8_t tmpreg = u8PlanUseFobKeyUid_Index[0];
					u8PlanUseFobKeyUid_Index[0] = FOBKEY_NUM;
					u8PlanUseFobKeyUid_Index[1] = tmpreg;
					Rke_Flash_Write(TRANSMITTER_ID_SAVE_ADDR, u8PlanUseFobKeyUid_Index, 2);
				}
			}
		}

		break;

	default:
		u8PollingUnlockStep = 0;
		break;
	}
}

void NJJ29C0_PollingLock_Process(void)
{
	static uint16_t u16PollingLockWaitMaxTime = 0;
	static uint16_t u16PollingLockNeedTime = 0;
	static uint8_t u8WakeUpFobsIndex = 0;
	int8_t sTmpStatus = 0;

	if ((u8PollingFuncRequest > 0) || (u8PE_Auth_KeyPosReq > 0) || (u8PS_Auth_KeyPosReq > 0))
	{
		JOKER_WakeUp();
		// JOKER_StartSleepForced();
		Change_Njj29c0_WorkStatus(lf_ide);
		return;
	}

	u8Lf_Polling_Work_State = 1;

	switch (u8PollingLockStep)
	{
	case 0:
		if (NJJ29C2_PollingWakeUpFobkey_Process(WELCOMEGUEST_POLLING_CYCLE01) == 1)
		{
			u16PollingLockWaitMaxTime = 0;
			u8PollingLockStep++;
		}
		break;

	case 1:
		u16PollingLockWaitMaxTime++;
		if (u16PollingLockWaitMaxTime >= 25)
		{
			JOKER_WakeUp();
			u16PollingLockNeedTime = WELCOMEGUEST_POLLING_CYCLE01;
			u8PollingLockStep++;
		}
		break;

	case 2:
		sTmpStatus = NJJ29C0_WelcomeGuest_Lock_SearchTrack_Key(1, u16PollingLockNeedTime);
		if (sTmpStatus == -1)
		{
			// The two recently used remote controls are both in the car and are disabled.
			tsTransmitters[u8PlanUseFobKeyUid_Index[0]].FobKeyEn = 0;
			tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn = 0;
			JOKER_WakeUp();
			Change_Njj29c0_WorkStatus(lf_ide);
		}
		else if (sTmpStatus == 1)
		{
			tsTransmitters[u8PlanUseFobKeyUid_Index[0]].FobKeyEn = 0;
			tsTransmitters[u8PlanUseFobKeyUid_Index[1]].FobKeyEn = 0;
			bWaitAllFobKey_A_WakeUp = 0;
			bWaitAllFobKey_B_WakeUp = 0;
			Lf_Door_CurRssiCalcVal.value = 0;
			Rf_Door_CurRssiCalcVal.value = 0;
			// u32Lf_CurRssi_Index = 0;
			// u32Rf_CurRssi_Index = 0;
			u16PollingLockWaitMaxTime = 0;
			u8PollingLockStep++;
			u8Key_A_Check_Thread = 0;
			u8Key_B_Check_Thread = 0;
			u8WakeUpFobsIndex = 0;
		}
		break;

	case 3:
		if ((u8WelcomeGuestWakeUpInd & 0x01) > 0)
		{
			if (bWaitAllFobKey_A_WakeUp == 1)
			{
				bWaitAllFobKey_A_WakeUp = 0;
				if (Lf_Door_CurRssiCalcVal.value < DOORANT_RSSI_Z2_LIMIT)
				{
					Lf_Door_CurRssiCalcVal.value = 0;
					if ((u8WelcomeGuestWakeUpInd & 0x02) > 0)
					{
						u8PollingLockStep = 4;
					}
					else
					{
						u8PollingLockStep = 6;
					}
					u16PollingLockWaitMaxTime = 0;

					return;
				}
			}
		}

		if ((u8WelcomeGuestWakeUpInd & 0x02) > 0)
		{
			if (bWaitAllFobKey_B_WakeUp == 1)
			{
				bWaitAllFobKey_B_WakeUp = 0;
				if (Rf_Door_CurRssiCalcVal.value < DOORANT_RSSI_Z2_LIMIT)
				{
					Rf_Door_CurRssiCalcVal.value = 0;
					if ((u8WelcomeGuestWakeUpInd & 0x01) > 0)
					{
						u8PollingLockStep = 5;
					}
					else
					{
						u8PollingLockStep = 6;
					}
					u16PollingLockWaitMaxTime = 0;

					return;
				}
			}
		}
		break;

	case 4:
		if (bWaitAllFobKey_B_WakeUp == 1)
		{
			bWaitAllFobKey_B_WakeUp = 0;
			if (Rf_Door_CurRssiCalcVal.value < DOORANT_RSSI_Z2_LIMIT)
			{
				JOKER_WakeUp();
				u8PollingLockStep = 6;
				u8WakeUpFobsIndex = u8PlanUseFobKeyUid_Index[1];
			}

			Rf_Door_CurRssiCalcVal.value = 0;
		}
		else
		{
			u16PollingLockWaitMaxTime++;
			if (u16PollingLockWaitMaxTime >= 300) // If the feedback of the B key has not been received for more than 600ms, the B key may suddenly disappear or the power is insufficient.
			{
				u8PollingLockStep = 6;
				u8WakeUpFobsIndex = u8PlanUseFobKeyUid_Index[0];
			}
		}
		break;

	case 5:
		if (bWaitAllFobKey_A_WakeUp == 1)
		{
			bWaitAllFobKey_A_WakeUp = 0;
			if (Lf_Door_CurRssiCalcVal.value < DOORANT_RSSI_Z2_LIMIT)
			{
				JOKER_WakeUp();
				u8PollingLockStep = 6;
				u8WakeUpFobsIndex = u8PlanUseFobKeyUid_Index[0];
			}

			Lf_Door_CurRssiCalcVal.value = 0;
		}
		else
		{
			u16PollingLockWaitMaxTime++;
			if (u16PollingLockWaitMaxTime >= 300) // If the feedback of the A key has not been received for more than 600ms, the A key may suddenly disappear or the power is insufficient.
			{
				u8PollingLockStep = 6;
				u8WakeUpFobsIndex = u8PlanUseFobKeyUid_Index[1];
			}
		}
		break;

	case 6:
		if (WelcomeGuest_Auth(u8WakeUpFobsIndex) == 1)
		{
			u16PollingLockWaitMaxTime = 0;
			u8PollingLockStep++;
		}
		break;

	case 7:
		u16PollingLockWaitMaxTime++;
		if (u16PollingLockWaitMaxTime >= 300)
		{
			JOKER_WakeUp();
			u8PollingLockStep = 0;
		}
		else
		{
			if (u8HitagAuthPass == 1)
			{
				u8Welcome_Function_Request = 3; // Polling Lock Reques
				JOKER_WakeUp();
				Change_Njj29c0_WorkStatus(lf_ide);

				// zch debug
				memset(g_datCan1Tx_0x330, 0, 8);
				g_datCan1Tx_0x330[0] = 0x80;
				g_datCan1Tx_0x330[1] = 0x03;
				g_datCan1Tx_0x330[2] = 0x08;
				BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);

				if (u8PlanUseFobKeyUid_Index[0] != u8WakeUpFobsIndex)
				{
					uint8_t tmpreg = u8PlanUseFobKeyUid_Index[0];
					u8PlanUseFobKeyUid_Index[0] = FOBKEY_NUM;
					u8PlanUseFobKeyUid_Index[1] = tmpreg;
					Rke_Flash_Write(TRANSMITTER_ID_SAVE_ADDR, u8PlanUseFobKeyUid_Index, 2);
				}
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
	uint8 u8LfTx_DATAIDx[3][8] = {0};

	if (0 == u8PepsStep)
	{
		LfAuthTransmitterInfoInit(PEPS_LF_CALIBRATION_CMD, tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo);
		JOKER_SetLfData(DATA_ID_PREMABLE, 1, (uint8 *)&Lf_Preamble_CodeViolation[0]);
		JOKER_SetLfNrz(DATA_ID_CV, 3, (uint8 *)&Lf_Preamble_CodeViolation[1]);

		JOKER_SetLfCarrier(DATA_ID_DATA_RSSI, CARRIER_OFF, 31);
		JOKER_SetLfCarrier(DATA_ID_DATA_CB, CARRIER_CON, RSSI_CARRIER_ON_LEN);
		u8PepsStep++;
	}
	else if (1 == u8PepsStep)
	{
		JOKER_SetLfData(DATA_ID_WUP1, 4, sLf_Auth_TransmitterInfo.Id);

		sLf_Auth_TransmitterInfo.Random[0] = 0x00;
		sLf_Auth_TransmitterInfo.Random[1] = 0x97;
		sLf_Auth_TransmitterInfo.Random[2] = GetCrc8(sLf_Auth_TransmitterInfo.Random, 2);

		JOKER_SetLfData(DATA_ID_DATA_PE, 3, sLf_Auth_TransmitterInfo.Random);

		u8LfTx_DATAIDx[0][0] = DATA_ID_PREMABLE;
		u8LfTx_DATAIDx[0][1] = DATA_ID_CV;
		u8LfTx_DATAIDx[0][2] = DATA_ID_WUP1;
		u8LfTx_DATAIDx[0][3] = DATA_ID_DATA_PE;
		u8LfTx_DATAIDx[0][4] = DATA_ID_DATA_CB;
		u8LfTx_DATAIDx[0][5] = DATA_ID_DATA_RSSI;

		u8LfTx_DATAIDx[1][0] = DATA_ID_DATA_CB;
		u8LfTx_DATAIDx[1][1] = DATA_ID_DATA_RSSI;

		u8LfTx_DATAIDx[2][0] = DATA_ID_DATA_CB;
		u8LfTx_DATAIDx[2][1] = DATA_ID_DATA_RSSI;

		if (Vehicle_Calibration_Ant == 0)
		{
			Peps_Cfg_Joker_Tx_Message(DR4P, 6, &u8LfTx_DATAIDx[0][0], DR2P, 2, &u8LfTx_DATAIDx[1][0], DR3P, 2, &u8LfTx_DATAIDx[2][0]);
		}
		else if (Vehicle_Calibration_Ant == 1)
		{
			Peps_Cfg_Joker_Tx_Message(DR2P, 6, &u8LfTx_DATAIDx[0][0], DR3P, 2, &u8LfTx_DATAIDx[1][0], DR4P, 2, &u8LfTx_DATAIDx[2][0]);
		}
		else
		{
			Peps_Cfg_Joker_Tx_Message(DR3P, 6, &u8LfTx_DATAIDx[0][0], DR2P, 2, &u8LfTx_DATAIDx[1][0], DR4P, 2, &u8LfTx_DATAIDx[2][0]);
		}
		u16waitmaxcnt = 20;
		u8HitagAuthPass = 0;
		u8PepsStep++;
	}
	else
	{
		u16waitmaxcnt--;
		if (u16waitmaxcnt == 0)
		{
			JOKER_StopLfTransmit();
			JOKER_StartSleep();
			Change_Njj29c0_WorkStatus(lf_ide);
		}
	}
}

void NJJ29C0_Task(void)
{
	static uint16 u16WaitMaxTimingCnt = 0;

	static lf_handle_state lfapp_work_sta_last = 0;

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
		}

		break;

	case JOKER_NORMAL:
		switch (lfapp_work_sta)
		{
		case lf_ide:
			if (bStartImmoAuthFlag == true)
			{
				Change_Njj29c0_WorkStatus(immo_ps);
				bStartImmoAuthFlag = false;
				u16DiagCycleTime = LF_DIAG_CYCYE;
			}
			else if (bStartWelcomeGuestLockFlag == true)
			{
				Change_Njj29c0_WorkStatus(lf_polling_lock);
				bStartWelcomeGuestLockFlag = false;
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
			else if (1 == u8PollingFuncRequest)
			{
				JOKER_WakeUp();
				u8PollingFuncRequest = 0;
				u8Lf_Polling_Work_State = 0;
			}
			else if ((2 == u8PollingFuncRequest) || (u8PollingFuncRequest_Qn == 2))
			{
				// Change_Njj29c0_WorkStatus(lf_polling_lock);
				Change_Njj29c0_WorkStatus(lf_prohibit_WelcomeGuest_key);
				bStartWelcomeGuestLockFlag = true;
				u16DiagCycleTime = LF_DIAG_CYCYE;
				u8PollingFuncRequest = 0;
			}
			else if ((3 == u8PollingFuncRequest) || (u8PollingFuncRequest_Qn == 3))
			{
				Change_Njj29c0_WorkStatus(lf_polling_unlock);
				u8PollingFuncRequestBak = 0; // 锟斤拷锟?锟斤�?
				u16DiagCycleTime = LF_DIAG_CYCYE;
				u8PollingFuncRequest = 0;
			}
			else if (4 == u8PollingFuncRequest)
			{
				Change_Njj29c0_WorkStatus(lf_polling_unlock);
				u16DiagCycleTime = LF_DIAG_CYCYE;
				u8PollingFuncRequestBak = 1; // 锟斤�?锟斤�?
				u8PollingFuncRequest = 0;
			}
			else if (1 == u8_Auth_KeyTestReq)
			{
				Change_Njj29c0_WorkStatus(immo_diag_uid);
				u16DiagCycleTime = LF_DIAG_CYCYE;
			}
			else if (1 == u8FobKeyEnterWorkState)
			{
				u8FobKeyEnterWorkState = 0;
				u8LearnFobkey = 0;
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
					// Change_Njj29c0_WorkStatus(lf_diag);
				}
			}
			u8PollingFuncRequest_Qn = 0;

			u8PE_Auth_KeyPosReq = 0;
			u8PS_Auth_KeyPosReq = 0;
			// u8PollingFuncRequest = 0;
			// u8Lf_Polling_Work_State = 0;
			u8_Auth_KeyTestReq = 0;

			Vehicle_Calibration_Work = 0;
			u8ImmoLearnWorkCnt = 0;
			u32Rf_CurRssi_Index = 0;
			u32Lf_CurRssi_Index = 0;
			u8FobKeyIndex = 0;
			u8PepsStep = 0;
			u8PepsTxCnt = PEPS_TX_MAX_COUNT;
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

		case lf_prohibit_WelcomeGuest_key:
			NJJ29C0_Prohibit_WelcomeGuest_Process();
			break;

		case lf_polling_lock:
			NJJ29C0_PollingLock_Process();
			break;

		case lf_polling_unlock:
			NJJ29C0_PollingUnlock_Process();
			break;

		case lf_diag:
			Lf_Ant_ShortOpenCircuit_Diag();
			break;

		case immo_diag_uid:
			NJJ29C0_Immo_Check_Uid();
			break;

		case lf_calibration:
			NJJ29C0_Calibration_Process();
			break;

		case immo_ps:
			NJJ29C0_Immo_Auth();
			break;

		case immo_learn_fobkey:
			FobKey_Immo_Learn_Process();
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

	if (lfapp_work_sta_last != lfapp_work_sta)
	{
		Vehicle_Calibration_AutoWork = 0xC9;
	}

	lfapp_work_sta_last = lfapp_work_sta;

	App_Monitor_Lf_Work_Status();

	if (Vehicle_Calibration_AutoWork == 0xC9)
	{
		u16WaitMaxTimingCnt++;
		if (u16WaitMaxTimingCnt >= 50)
		{

			// u16WaitMaxTimingCnt = 0;
			// Vehicle_Calibration_Work = 1;
			//  zch debug
			Vehicle_Calibration_AutoWork = 0;
			memset(g_datCan1Tx_0x330, 0, 8);
			g_datCan1Tx_0x330[0] = 0x80;
			g_datCan1Tx_0x330[1] = 0x00;
			g_datCan1Tx_0x330[2] = 0x02;
			g_datCan1Tx_0x330[3] = lfapp_work_sta;

			BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);
		}
	}
	else
	{
		u16WaitMaxTimingCnt = 0;
	}
}

void Nck2910_Task(void)
{
	static uint8_t u8Dostep = 0;
	static uint8_t u8Fobkey_Cur_RkeCmd_Last = 0;

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

	if (u8Fobkey_Cur_RkeCmd_Last != u8Fobkey_Cur_RkeCmd)
	{
		// zch debug
		memset(g_datCan1Tx_0x330, 0, 8);
		g_datCan1Tx_0x330[0] = 0x80;
		g_datCan1Tx_0x330[1] = 0x00;
		g_datCan1Tx_0x330[2] = 0x04;
		g_datCan1Tx_0x330[3] = u8Fobkey_Cur_RkeCmd;

		BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);
	}

	u8Fobkey_Cur_RkeCmd_Last = u8Fobkey_Cur_RkeCmd;

#ifdef CALIBRATION_DEBUG
	if (u8HitagAuthPass == 11)
	{
		u8Dostep++;
		if (u8Dostep == 1)
		{
			g_datCan1Tx_0x330[0] = 1;
			g_datCan1Tx_0x330[1] = u32InCarAntRssi.CHAR_BYTE.Low_byte;
			g_datCan1Tx_0x330[2] = u32InCarAntRssi.CHAR_BYTE.Mlow_byte;
			g_datCan1Tx_0x330[3] = u32InCarAntRssi.CHAR_BYTE.Mhigh_byte;
			g_datCan1Tx_0x330[4] = u32InCarAntRssi.CHAR_BYTE.High_byte;
			BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);
		}
		else if (u8Dostep == 2)
		{
			g_datCan1Tx_0x330[0] = 2;
			g_datCan1Tx_0x330[1] = u32LfAntRssi.CHAR_BYTE.Low_byte;
			g_datCan1Tx_0x330[2] = u32LfAntRssi.CHAR_BYTE.Mlow_byte;
			g_datCan1Tx_0x330[3] = u32LfAntRssi.CHAR_BYTE.Mhigh_byte;
			g_datCan1Tx_0x330[4] = u32LfAntRssi.CHAR_BYTE.High_byte;
			BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);
		}
		else
		{
			g_datCan1Tx_0x330[0] = 3;
			g_datCan1Tx_0x330[1] = u32RfAntRssi.CHAR_BYTE.Low_byte;
			g_datCan1Tx_0x330[2] = u32RfAntRssi.CHAR_BYTE.Mlow_byte;
			g_datCan1Tx_0x330[3] = u32RfAntRssi.CHAR_BYTE.Mhigh_byte;
			g_datCan1Tx_0x330[4] = u32RfAntRssi.CHAR_BYTE.High_byte;
			BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);

			u8HitagAuthPass = 0;
		}
	}
	else
	{
		u8Dostep = 0;
	}
#endif
}

// RKE_PKE模锟斤拷锟绞硷拷�?
void PEPS_Module_Init(void)
{
	_NCK2910_Hal_Init();

	InitFobKeyEepromMessage();
}

void PEPS_Module_EnterSleep(void)
{
	if (0 == u8Lf_Polling_Work_State)
	{
		JOKER_StartSleepForced();
	}
}

void Spi2_Test(void)
{
	uint8 u8txbuf[2];

	u8txbuf[0] = 0x55;
	u8txbuf[0] = 0xAA;

	(void)
		NJJ29C0_Spi_ReadWrite(u8txbuf, NULL, 2);
}
