

/*********************************Copyright (c)*********************************
 ** File Name:
 ** Created By: Ghost_Tiger
 ** Created date:	2017-7-10
 ** Version: 1.0
 ** Descriptions: First version
 **
 ******************************************************************************/
#include "UHF_FML.h"
#include "nck2910.h"
#include <string.h>
#include "LoopFifo.h"
#include "Pke_Pks_APP.h"
#include "nxpMath.h"
#include "joker.h"

uint8_t u8Universal_Key[16] = {0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf1,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,0x01};

EEPROM_Save_Buffer tsFobKeyMessageSave_A;

EEPROM_Save_Buffer tsFobKeyMessageSave_B;

Aes128_Buffer tsAes_Crypt_Buffer;

static Rke_CommandMessage tsRke_ReceiveBuf; //RKE高频接收缓存

TransmitterInfo tsFob_LearnBuf; //钥匙学习缓存信息

static uint8_t u8FobKey_Volt_Status = 0;//遥控钥匙电力状态，1为电力低 0为正常

static uint8_t u8EcuLearnMatch_Status = 0; // ECU??????????

static uint8_t u8FobKey_Id_Message = 0;// 当前遥控第几把的操作

static uint16_t u16PressKeyWait = 0;

static UHF_MessageTypeDef tsNck2910RecvFrame;

uint32_t u32Time1sCount = 0x23dc98f6;

uint8_t	u8TransmitterCount; //遥控钥匙数量指定EEPROM中的地址

TransmitterInfo tsTransmitters[MAX_TRANSMITTERS]; //遥控信息指定在EEPROM中的地址

extern LPFifo_TypeDef LPFifo;

static uint8 u8EcuLearnMatchRepeat = 0;//重复学习指示

static uint8  u8FobKeyButtonPressInd = 0;

static uint8  u8FobKeyButtonCmdPre = 0;

static uint8_t u8FobkeyLongPressValidTimeCnt = 0;

static uint16_t u16UnlockLongPressTimingCnt = 0;
static uint16_t u16LockLongPressTimingCnt = 0;
static uint16_t u16TrunkLongPressTimingCnt = 0;

uint8_t u8PlanUseFobKeyUid_Index[2];

uint32_t u32PlanUseFobKeyUid[2];

uint8_t  bWaitAllFobKey_A_WakeUp = 0;
uint8_t  bWaitAllFobKey_B_WakeUp = 0;

uint16_t  u16FobKeyA_Updata_Cnt = 0;
uint16_t  u16FobKeyB_Updata_Cnt = 0;

uint16_t u16UhfFrameRkeAuthOkCount = 0;
uint16_t u16UhfFramePkeAuthOkCount = 0;

uint8 u8Sync_Counter_Err_Flag = 0;

BITBYTE	tuHf_Func01;

BITBYTE	tuHf_Func02;

BITBYTE	tuHf_Bid;


static void FobKeyMessageErase(void);
extern uint8 GetCrc8(uint8 * pBuffer, uint16 bufSize);

//extern void Rke_Flash_Write(uint32_t addr,void *buf,uint32_t len);
//extern  void Rke_Flash_Read(uint32_t addr,void *buf,uint32_t len);

void Rke_Flash_Write(uint32_t addr,void *buf,uint32_t len)
{
	if((addr <= 256)&&(len <= 256))
	{
		memcpy(&u8KeyTempBuffVal[addr],buf,len);
	}
}

void Rke_Flash_Read(uint32_t addr,void *buf,uint32_t len)
{
	if((addr <= 256)&&(len <= 256))
	{
		memcpy(buf,&u8KeyTempBuffVal[addr],len);
	}
}



static void Execute_Command(void);
extern uint8_t _CalculateCRC8(uint8_t * pu8FrameBuf, uint8_t u8Len);

uint32_t	GetSysRandTimeCount(void)
{
	return u32Time1sCount;
}

/*******************************************************************************
 * 函数名  : GetTransmitterCountVal
 * 描述	 : 获取钥匙存储在EEPROM中的数量
 * 输入	 : None
 * 返回	 : 已经匹配遥控器的数量
 *******************************************************************************/
uint8_t GetTransmitterCountVal(void)
{
	return u8TransmitterCount;
}

/*******************************************************************************
 * 函数名  : GetVariableFobKeyVoltStatus
 * 描述	 : 获取钥匙电池电压状态
 * 输入	 : None
 * 返回	 : 遥控钥匙电力状态，1为电力低 0为正常
 *******************************************************************************/
uint8_t GetVariableFobKeyVoltStatus(void)
{
	return u8FobKey_Volt_Status;
}


/*******************************************************************************
 * 函数名  : GetRemotButtonCmd
 * 描述	 : 获取遥控当前按键按下状态
 * 输入	 : None
 * 返回	 : 
 *******************************************************************************/
uint8_t GetFobKeyCmdRequest(void)
{
	return u8Fobkey_Cur_RkeCmd;
}

/*******************************************************************************
 * 函数名  : ClrRemotButtonCmd
 * 描述	 : 清除遥控当前按键按下状态
 * 输入	 : None
 * 返回	 : none
 *******************************************************************************/
void ClrRemotButtonCmd(void)
{
	u8Fobkey_Cur_RkeCmd = RKE_NULL;
}

/*******************************************************************************
 * 函数名  : GetFobKeyLearnCompleteStatus
 * 描述	 : 获取遥控匹配是否成功
 * 输入	 : None
 * 返回	 : 0：匹配未成功,其它值：匹配了几个遥控器成功
 *******************************************************************************/
uint8_t GetFobKeyLearnCompleteStatus(void)
{
	return u8EcuLearnMatch_Status;
}

/*******************************************************************************
 * 函数名  : GetFobKeyId
 * 描述	 : 获取遥控当前是第几把
 * 输入	 : None
 * 返回	 : 遥控器当前是第几把
 *******************************************************************************/
uint8_t GetFobKeyId(void)
{
	return u8FobKey_Id_Message;
}


void SetPs_AuthFobStatus(uint8_t sta)
{
	u8PS_Auth_FobStatus = sta;
}


void SetPe_AuthFobStatus(uint8_t sta)
{
	u8PE_Auth_FobStatus = sta;
}

uint8_t GetTransmitterMaxNumErr(void)//遥控钥匙匹配已达最大数量
{
	if(u8TransmitterCount >= MAX_TRANSMITTERS)
	{
		return 1;
	}
	return 0;
}

uint8 GetSyncCountErr(void)
{
	return u8Sync_Counter_Err_Flag;
}


void All_FobKey_Lift_En(void)
{
	tsTransmitters[0].FobKeyEn = 0;
	tsTransmitters[1].FobKeyEn = 0;
	tsTransmitters[2].FobKeyEn = 0;
	tsTransmitters[3].FobKeyEn = 0;
	//tsTransmitters[4].FobKeyEn = 0;

	memcpy(&tsFobKeyMessageSave_A.Fifo_Data[0],&tsTransmitters[0].SerialNo,25);
	memcpy(&tsFobKeyMessageSave_A.Fifo_Data[25],&tsTransmitters[1].SerialNo,25);
	memcpy(&tsFobKeyMessageSave_A.Fifo_Data[50],&tsTransmitters[2].SerialNo,25);
	memcpy(&tsFobKeyMessageSave_A.Fifo_Data[75],&tsTransmitters[3].SerialNo,25);
	//memcpy(&tsFobKeyMessageSave_A.Fifo_Data[100],&tsTransmitters[4].SerialNo,25);
	tsFobKeyMessageSave_A.Crc8 = _CalculateCRC8(tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A) - 1);
	
	//更新EEPROM数据A区,B区
	Rke_Flash_Write(TRANSMITTERS_EEPROM_ADDR,tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A));
}

/*******************************************************************************
 * 函数名  : GetCurUseSecretKey
 * 描述	 : 低频验证时，读取对应ID的秘钥
 * 输入	 : Id->ID值，*buf->秘钥缓存地址指针
 * 返回	 : TRUE或FALSE
 *******************************************************************************/

uint8_t GetCurUseSecretKey(uint32_t Id, uint8_t * buf)
{
	uint8_t	u8TransmitterIdx = 0;
	TransmitterInfo * tsTransmitter = tsTransmitters;

	while (u8TransmitterIdx < GetTransmitterCountVal())
	{
		if (Id == tsTransmitter->SerialNo)
		{
			memcpy(buf, tsTransmitter->SecretKey, KEY_BIT_SIZE >> 3);
			u8FobKey_Id_Message = u8TransmitterIdx + 1;
			return 1;
		}
		else 
		{
			++u8TransmitterIdx;
			++tsTransmitter;
		}
	}

	return 0;
}


void UhfFobKeyLearnRxProcess(void)
{
	uint8_t			u8TransmitterIdx = 0;
	uint8_t			u8Found = 0;
	
	TransmitterInfo * tsTransmitter = tsTransmitters;

	memcpy(tsFob_LearnBuf.SecretKey, u8Universal_Key, KEY_BIT_SIZE >> 3);
	
	while ((u8TransmitterIdx < u8TransmitterCount) && (u8Found == 0))
	{
		if (tsFob_LearnBuf.SerialNo == tsTransmitter->SerialNo)
		{
			u8Found				= 1;
		}
		else 
		{
			++u8TransmitterIdx;
			++tsTransmitter;
		}
	}
	
	if (0 == u8Found)
	{
		//钥匙UID还没学习过
		tsTransmitters[u8TransmitterCount].SerialNo = tsFob_LearnBuf.SerialNo;
		tsTransmitters[u8TransmitterCount].Sync_Counter = 0;
		memcpy(tsTransmitters[u8TransmitterCount].SecretKey, tsFob_LearnBuf.SecretKey, KEY_BIT_SIZE >> 3);
		
		u8EcuLearnMatch_Status++;

		if(u8PlanUseFobKeyUid_Index[0] != u8TransmitterCount)
		{
			u8Found = u8PlanUseFobKeyUid_Index[0];
			u8PlanUseFobKeyUid_Index[0] = u8TransmitterCount;
			u8PlanUseFobKeyUid_Index[1] = u8Found;
			Rke_Flash_Write(TRANSMITTER_ID_SAVE_ADDR,u8PlanUseFobKeyUid_Index,2);
		}
		
		u8TransmitterCount++;
	}
	else 
	{
		tsTransmitters[u8TransmitterIdx].SerialNo = tsFob_LearnBuf.SerialNo;
		tsTransmitters[u8TransmitterIdx].Sync_Counter = 0;
		memcpy(tsTransmitters[u8TransmitterIdx].SecretKey, tsFob_LearnBuf.SecretKey, KEY_BIT_SIZE >> 3); 	

		if(u8PlanUseFobKeyUid_Index[0] != u8TransmitterIdx)
		{
			u8Found = u8PlanUseFobKeyUid_Index[0];
			u8PlanUseFobKeyUid_Index[0] = u8TransmitterIdx;
			u8PlanUseFobKeyUid_Index[1] = u8Found;
			Rke_Flash_Write(TRANSMITTER_ID_SAVE_ADDR,u8PlanUseFobKeyUid_Index,2);
		}
	}

	tsFobKeyMessageSave_A.FobKeyCount = u8TransmitterCount;
	memcpy(&tsFobKeyMessageSave_A.Fifo_Data[0],&tsTransmitters[0].SerialNo,25);
	memcpy(&tsFobKeyMessageSave_A.Fifo_Data[25],&tsTransmitters[1].SerialNo,25);
	memcpy(&tsFobKeyMessageSave_A.Fifo_Data[50],&tsTransmitters[2].SerialNo,25);
	memcpy(&tsFobKeyMessageSave_A.Fifo_Data[75],&tsTransmitters[3].SerialNo,25);
	//memcpy(&tsFobKeyMessageSave_A.Fifo_Data[100],&tsTransmitters[4].SerialNo,25);
	tsFobKeyMessageSave_A.Crc8 = _CalculateCRC8(tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A) - 1);
	
	memcpy(tsFobKeyMessageSave_B.Fifo_Data,tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A));

	//更新EEPROM数据A区,B区
	Rke_Flash_Write(TRANSMITTERS_EEPROM_ADDR,tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A));
	Rke_Flash_Write(TRANSMITTERS_EEPROM_BAK_ADDR,tsFobKeyMessageSave_B.Fifo_Data,sizeof(tsFobKeyMessageSave_B));

}


/*******************************************************************************
 * 函数名  : UhfFobKeyRkeProcess
 * 描述	 : 遥控Rke功能处理
 * 输入	 : None
 * 返回	 : None
 *******************************************************************************/
static void UhfFobKeyRkeProcess(void)
{
	static uint32 Save_CounterValue = 0;
	LONG_UNION	Rand_Val;
	static uint8_t u8Tmp_Mac[6];
	uint8_t u8arr_AESInreg[16]; // array for Inreg data
	uint8_t u8arr_AESOutreg[16]; // array for outreg data
	uint8_t u8arr_AESKey[16]; // array for crypto key
	uint32_t u32tmp_reg = 0;

	if((FRAME_LEN != 8)||(tsTransmitters[FOBKEY_NUM].FobKeyEn == 1))
	{
		return;
	}

	tsRke_ReceiveBuf.Mac[0] = tsNck2910RecvFrame.m_Data[5];
	tsRke_ReceiveBuf.Mac[1] = tsNck2910RecvFrame.m_Data[6];
	tsRke_ReceiveBuf.Mac[2] = tsNck2910RecvFrame.m_Data[7];

	if ((u8Tmp_Mac[0] == tsRke_ReceiveBuf.Mac[0]) && (u8Tmp_Mac[1] == tsRke_ReceiveBuf.Mac[1]) && (u8Tmp_Mac[2] == tsRke_ReceiveBuf.Mac[2]))
	{
		return; //重复帧
	}

	memcpy(u8SpiCurReadUhfDataBuf, &tsNck2910RecvFrame.m_Data[0], 8);

	tsRke_ReceiveBuf.Fun = tsNck2910RecvFrame.m_Data[0];
	
	tuHf_Bid.DATA_BYTE = tsNck2910RecvFrame.m_Data[1];

	tsRke_ReceiveBuf.CommandCode = KEY_CMD;

	tsRke_ReceiveBuf.Sync_Counter = (uint32_t)tsNck2910RecvFrame.m_Data[4];
	tsRke_ReceiveBuf.Sync_Counter |= ((uint32_t)tsNck2910RecvFrame.m_Data[3])<<8;
	tsRke_ReceiveBuf.Sync_Counter |= ((uint32_t)tsNck2910RecvFrame.m_Data[2])<<16;

	tsRke_ReceiveBuf.SerialNo = tsTransmitters[FOBKEY_NUM].SerialNo;

	Rand_Val.Value = tsRke_ReceiveBuf.SerialNo;

	u8arr_AESInreg[0] = Rand_Val.CHAR_BYTE.High_byte;
    u8arr_AESInreg[1] = Rand_Val.CHAR_BYTE.Mhigh_byte;
    u8arr_AESInreg[2] = Rand_Val.CHAR_BYTE.Mlow_byte;
    u8arr_AESInreg[3] = Rand_Val.CHAR_BYTE.Low_byte;
	u8arr_AESInreg[4] = tsRke_ReceiveBuf.CommandCode;
	u8arr_AESInreg[5] = tsNck2910RecvFrame.m_Data[4];//LSB
    u8arr_AESInreg[6] = tsNck2910RecvFrame.m_Data[3];
    u8arr_AESInreg[7] = tsNck2910RecvFrame.m_Data[2];

	u8arr_AESInreg[8] = u8arr_AESInreg[0];
    u8arr_AESInreg[9] = u8arr_AESInreg[1];
    u8arr_AESInreg[10] = u8arr_AESInreg[2];
    u8arr_AESInreg[11] = u8arr_AESInreg[3];
	u8arr_AESInreg[12] = u8arr_AESInreg[4];
	u8arr_AESInreg[13] = u8arr_AESInreg[5];
    u8arr_AESInreg[14] = u8arr_AESInreg[6];
    u8arr_AESInreg[15] = u8arr_AESInreg[7];

	memcpy(u8arr_AESKey, tsTransmitters[FOBKEY_NUM].SecretKey, 16);
	AES_ExpandKey(u8arr_AESKey);
	AES_Encrypt(u8arr_AESInreg, u8arr_AESOutreg);

	/* Calculate "Select Bytes" */
	uint8_t S0 = 0;
	if ((tsNck2910RecvFrame.m_Data[4] & (1 << 7)) != 0)
	{
		S0 |= (1 << 0);
	} /* S0 Bit0: SiCounter 0b7 */
	if ((tsNck2910RecvFrame.m_Data[4] & (1 << 5)) != 0)
	{
		S0 |= (1 << 1);
	} /* S0 Bit1: SiCounter 0b5 */
	if ((tsNck2910RecvFrame.m_Data[4] & (1 << 3)) != 0)
	{
		S0 |= (1 << 2);
	} /* S0 Bit2: SiCounter 1b3 */
	if ((tsNck2910RecvFrame.m_Data[4] & (1 << 1)) != 0)
	{
		S0 |= (1 << 3);
	} /* S0 Bit3: SiCounter 1b1 */

	uint8_t S1 = 0;
	if ((tsNck2910RecvFrame.m_Data[3] & (1 << 6)) != 0)
	{
		S1 |= (1 << 0);
	} /* S1 Bit0: SiCounter 0b6 */
	if ((tsNck2910RecvFrame.m_Data[3] & (1 << 4)) != 0)
	{
		S1 |= (1 << 1);
	} /* S1 Bit1: SiCounter 0b4 */
	if ((tsNck2910RecvFrame.m_Data[4] & (1 << 2)) != 0)
	{
		S1 |= (1 << 2);
	} /* S1 Bit2: SiCounter 1b2 */
	if ((tsNck2910RecvFrame.m_Data[4] & (1 << 0)) != 0)
	{
		S1 |= (1 << 3);
	} /* S1 Bit3: SiCounter 1b0 */

	uint8_t S2 = 0;
	if ((tsNck2910RecvFrame.m_Data[3] & (1 << 4)) != 0)
	{
		S2 |= (1 << 0);
	} /* S2 Bit0: SiCounter 0b4 */
	if ((tsNck2910RecvFrame.m_Data[3] & (1 << 5)) != 0)
	{
		S2 |= (1 << 1);
	} /* S2 Bit1: SiCounter 0b5 */
	if ((tsNck2910RecvFrame.m_Data[4] & (1 << 2)) != 0)
	{
		S2 |= (1 << 2);
	} /* S2 Bit2: SiCounter 0b2 */
	if ((tsNck2910RecvFrame.m_Data[4] & (1 << 1)) != 0)
	{
		S2 |= (1 << 3);
	} /* S2 Bit3: SiCounter 0b1 */

	u8arr_AESInreg[0] = u8arr_AESOutreg[S2];
	u8arr_AESInreg[1] = u8arr_AESOutreg[S1];
	u8arr_AESInreg[2] = u8arr_AESOutreg[S0];
	
	u16UhfFrameRkeAuthOkCount++;
	
	if((tsRke_ReceiveBuf.Mac[0] == u8arr_AESInreg[0])&&(tsRke_ReceiveBuf.Mac[1] == u8arr_AESInreg[1])&&(tsRke_ReceiveBuf.Mac[2] == u8arr_AESInreg[2]))
	{
		u8FobKey_Id_Message = FOBKEY_NUM + 1;

		u8FobKey_Volt_Status = BAT_VOL_LOW_IND;

		u16UhfFrameRkeAuthOkCount++;
		//=============================同步计数值是否满足要求=============================
		if(Save_CounterValue > 0)
		{
			u32tmp_reg = 0;
			if(tsRke_ReceiveBuf.Sync_Counter > Save_CounterValue)
			{
				u32tmp_reg = tsRke_ReceiveBuf.Sync_Counter - Save_CounterValue;
			}

			if((u32tmp_reg == 0)||(u32tmp_reg > 0x7FFF))
			{
				//不在双操作窗口内
                return ;
			}
			else if(u32tmp_reg > WINDOW_SIZE)
			{

				//还在第二操作窗口内
				Save_CounterValue = tsRke_ReceiveBuf.Sync_Counter;//继续同步
                return ;
			}
			else
			{
				Save_CounterValue = 0;//同步成功
			}
		}
		else
		{
			if(tsRke_ReceiveBuf.Sync_Counter <= tsTransmitters[FOBKEY_NUM].Sync_Counter)
			{
				u8Sync_Counter_Err_Flag = 1 << FOBKEY_NUM;
				return;
			}
			else
			{
				u32tmp_reg = tsRke_ReceiveBuf.Sync_Counter - tsTransmitters[FOBKEY_NUM].Sync_Counter;
				
				if(u32tmp_reg > 0x7FFFF)
				{
					//不在双操作窗口内
					u8Sync_Counter_Err_Flag = 1 << FOBKEY_NUM;
	                return ;
				}
				else if (u32tmp_reg > WINDOW_SIZE)
				{
					//同步值在双操作窗口内,需要按下一次遥控，进行同步
					Save_CounterValue = tsRke_ReceiveBuf.Sync_Counter;
					return;
				}
			}
		}
		
		u16UhfFrameRkeAuthOkCount++;
		
		Execute_Command();

		memcpy(u8Tmp_Mac, tsRke_ReceiveBuf.Mac, 3);

		if(u8PlanUseFobKeyUid_Index[0] != FOBKEY_NUM)
		{
			u32tmp_reg = u8PlanUseFobKeyUid_Index[0];
			u8PlanUseFobKeyUid_Index[0] = FOBKEY_NUM;
			u8PlanUseFobKeyUid_Index[1] = (uint8)u32tmp_reg;
			Rke_Flash_Write(TRANSMITTER_ID_SAVE_ADDR,u8PlanUseFobKeyUid_Index,2);
		}
		
		tsTransmitters[FOBKEY_NUM].Sync_Counter = tsRke_ReceiveBuf.Sync_Counter; 

		//更新同步计数值
		tsFobKeyMessageSave_A.FobKeyCount = u8TransmitterCount;
		memcpy(&tsFobKeyMessageSave_A.Fifo_Data[0],&tsTransmitters[0].SerialNo,25);
		memcpy(&tsFobKeyMessageSave_A.Fifo_Data[25],&tsTransmitters[1].SerialNo,25);
		memcpy(&tsFobKeyMessageSave_A.Fifo_Data[50],&tsTransmitters[2].SerialNo,25);
		memcpy(&tsFobKeyMessageSave_A.Fifo_Data[75],&tsTransmitters[3].SerialNo,25);
		//memcpy(&tsFobKeyMessageSave_A.Fifo_Data[100],&tsTransmitters[4].SerialNo,25);
		tsFobKeyMessageSave_A.Crc8 = _CalculateCRC8(tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A) - 1);
		
		//更新EEPROM数据A区,B区
		Rke_Flash_Write(TRANSMITTERS_EEPROM_ADDR,tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A));

		#ifdef QN_DEBUG
			sdrv_gpio_toggle_pin_output_level(GPIO_L7);
		#endif
		
	}
	else
	{


	}
}

uint32_t u32calc_val01 = 0;
uint32_t u32calc_val02 = 0;

static void UhfPkePkgProcess(void)
{	
	uint8_t u8arr_AESInreg[16]; // array for Inreg data
    uint8_t u8arr_AESKey[16]; // array for crypto key
    uint8_t u8arr_AESOutreg[16]; // array for outreg data

	static uint8_t u8RecodeCnt = 0;
	
	if(GetCrc8(&tsNck2910RecvFrame.m_Data[0],FRAME_LEN -1) == tsNck2910RecvFrame.m_Data[FRAME_LEN -1])
	{
		tuHf_Func02.DATA_BYTE = tsNck2910RecvFrame.m_Data[1];
		u8FobKey_Id_Message = FOBKEY_NUM + 1;
		u8FobKey_Volt_Status = BAT_VOL_LOW;
		
		if((FRAME_LF_CMD >= 0x10)&&(FRAME_LF_CMD <= 0x14))
		{
			u8arr_AESInreg[0]	= tsAes_Crypt_Buffer.Use_Seed[3];
			u8arr_AESInreg[1]	= tsAes_Crypt_Buffer.Use_Seed[2];
			u8arr_AESInreg[2]	= tsAes_Crypt_Buffer.Use_Seed[1];
			u8arr_AESInreg[3]	= tsAes_Crypt_Buffer.Use_Seed[0];
			
			u8arr_AESInreg[4]	= tsAes_Crypt_Buffer.Use_Id[0]^tsAes_Crypt_Buffer.Use_Id[2];
			u8arr_AESInreg[5]	= tsAes_Crypt_Buffer.Use_Id[1]^tsAes_Crypt_Buffer.Use_Id[3];
			
			u8arr_AESInreg[6]	= ((tsAes_Crypt_Buffer.Use_Seed[0]^tsAes_Crypt_Buffer.Use_Id[3]));
			u8arr_AESInreg[7]	= ((tsAes_Crypt_Buffer.Use_Seed[1]^tsAes_Crypt_Buffer.Use_Id[2]));
			u8arr_AESInreg[8]	= ((tsAes_Crypt_Buffer.Use_Seed[2]^tsAes_Crypt_Buffer.Use_Id[1]));
			u8arr_AESInreg[9]	= ((tsAes_Crypt_Buffer.Use_Seed[3]^tsAes_Crypt_Buffer.Use_Id[0]));
			u8arr_AESInreg[10]	= ((tsAes_Crypt_Buffer.Use_Seed[0]^tsAes_Crypt_Buffer.Use_Seed[1]));
			u8arr_AESInreg[11]	= ((tsAes_Crypt_Buffer.Use_Seed[0]^tsAes_Crypt_Buffer.Use_Seed[2]));
			u8arr_AESInreg[12]	= ((tsAes_Crypt_Buffer.Use_Seed[0]^tsAes_Crypt_Buffer.Use_Seed[3]));
			u8arr_AESInreg[13]	= ((tsAes_Crypt_Buffer.Use_Seed[1]^tsAes_Crypt_Buffer.Use_Seed[2]));
			u8arr_AESInreg[14]	= ((tsAes_Crypt_Buffer.Use_Seed[1]^tsAes_Crypt_Buffer.Use_Seed[3]));
			u8arr_AESInreg[15]	= ((tsAes_Crypt_Buffer.Use_Seed[2]^tsAes_Crypt_Buffer.Use_Seed[3]));
		
			memcpy(u8arr_AESKey,tsAes_Crypt_Buffer.Use_SecretKey,16);

			AES_ExpandKey(u8arr_AESKey);
			AES_Encrypt(u8arr_AESInreg, u8arr_AESOutreg);

			tsAes_Crypt_Buffer.Calc_Mac_Code[0] = u8arr_AESOutreg[0];
			tsAes_Crypt_Buffer.Calc_Mac_Code[1] = u8arr_AESOutreg[1];
                        
            u16UhfFramePkeAuthOkCount++;
		
			if((tsAes_Crypt_Buffer.Calc_Mac_Code[0] == tsNck2910RecvFrame.m_Data[2])&&(tsAes_Crypt_Buffer.Calc_Mac_Code[1] == tsNck2910RecvFrame.m_Data[3]))
			{
				memcpy(u8SpiCurReadUhfDataBuf, &tsNck2910RecvFrame.m_Data[0], 14);
				
				u16UhfFramePkeAuthOkCount++;

				u8HitagAuthPass = 1;

				u32calc_val02 = (uint32_t)(Ps_Ant_Rssi_Limit * 1000.0);
				
				if(FRAME_LF_CMD == 0x10)
				{
                                        JOKER_StopLfTransmit();
					InCar_CurRssiCalcVal.value = NXPFloat24_to_IEEEFloat(&tsNck2910RecvFrame.m_Data[4]);
					//Lf_Door_CurRssiCalcVal.value = NXPFloat24_to_IEEEFloat(&tsNck2910RecvFrame.m_Data[7]);
					//Rf_Door_CurRssiCalcVal.value = NXPFloat24_to_IEEEFloat(&tsNck2910RecvFrame.m_Data[10]);

					u32calc_val01 = (uint32_t)(InCar_CurRssiCalcVal.value * 1000.0);
					if(Get_Njj29c0_WorkStatus() == lf_ps)
					{
					#if 0
						if(u32calc_val01 >= u32calc_val02)
						{
							JOKER_WakeUp();
							Change_Njj29c0_WorkStatus(lf_ide);
							SetPs_AuthFobStatus(1);
						}
					#else
						Change_Njj29c0_WorkStatus(lf_ide);
						SetPs_AuthFobStatus(1);
					#endif

						if(u8PlanUseFobKeyUid_Index[0] != FOBKEY_NUM)
						{
							u8arr_AESOutreg[0] = u8PlanUseFobKeyUid_Index[0];
							u8PlanUseFobKeyUid_Index[0] = FOBKEY_NUM;
							u8PlanUseFobKeyUid_Index[1] = u8arr_AESOutreg[0];
							Rke_Flash_Write(TRANSMITTER_ID_SAVE_ADDR,u8PlanUseFobKeyUid_Index,2);
						}
					}
					else if(Get_Njj29c0_WorkStatus() == lf_prohibit_key)
					{					
#if 1
                                                //if(u32calc_val01 >= u32calc_val02)
						{
							if(u8PlanUseFobKeyUid_Index[0] != FOBKEY_NUM)
							{
								tsTransmitters[FOBKEY_NUM].FobKeyEn = 1;
							}

						}
#else
                                                tsTransmitters[FOBKEY_NUM].FobKeyEn = 1;
#endif
					}
					else
					{
						
					}
				}
				else if(FRAME_LF_CMD == 0x11)
				{
                                        JOKER_StopLfTransmit();
					if(Get_Njj29c0_WorkStatus() == lf_ide)
					{
						return;
					}
					
					Lf_Door_CurRssiCalcVal.value = NXPFloat24_to_IEEEFloat(&tsNck2910RecvFrame.m_Data[4]);
					InCar_CurRssiCalcVal.value = NXPFloat24_to_IEEEFloat(&tsNck2910RecvFrame.m_Data[7]);

					Change_Njj29c0_WorkStatus(lf_ide);

					u32calc_val01 = (uint32_t)(InCar_CurRssiCalcVal.value * 1000.0);
				#if 0									
					if(u32calc_val01 >= u32calc_val02)
					{
						SetPe_AuthFobStatus(3);
					}
					else
					{
						SetPe_AuthFobStatus(1);
					}
				#else
					SetPe_AuthFobStatus(1);
				#endif

					if(u8PlanUseFobKeyUid_Index[0] != FOBKEY_NUM)
					{
						u8arr_AESOutreg[0] = u8PlanUseFobKeyUid_Index[0];
						u8PlanUseFobKeyUid_Index[0] = FOBKEY_NUM;
						u8PlanUseFobKeyUid_Index[1] = u8arr_AESOutreg[0];
						Rke_Flash_Write(TRANSMITTER_ID_SAVE_ADDR,u8PlanUseFobKeyUid_Index,2);
					}
				}
				else if(FRAME_LF_CMD == 0x12)
				{
                                        JOKER_StopLfTransmit();
                                        
					if(Get_Njj29c0_WorkStatus() == lf_ide)
					{
					      return;
					}
					//Rf_Door_CurRssiCalcVal.value = NXPFloat24_to_IEEEFloat(&tsNck2910RecvFrame.m_Data[4]);
					InCar_CurRssiCalcVal.value = NXPFloat24_to_IEEEFloat(&tsNck2910RecvFrame.m_Data[7]);

					Change_Njj29c0_WorkStatus(lf_ide);

					u32calc_val01 = (uint32_t)(InCar_CurRssiCalcVal.value * 1000.0);
				#if 0	
					if(u32calc_val01 >= u32calc_val02)
					{
						SetPe_AuthFobStatus(3);
					}
					else
					{
						SetPe_AuthFobStatus(1);
					}
				#else
					SetPe_AuthFobStatus(1);
				#endif
					if(u8PlanUseFobKeyUid_Index[0] != FOBKEY_NUM)
					{
						u8arr_AESOutreg[0] = u8PlanUseFobKeyUid_Index[0];
						u8PlanUseFobKeyUid_Index[0] = FOBKEY_NUM;
						u8PlanUseFobKeyUid_Index[1] = u8arr_AESOutreg[0];
						Rke_Flash_Write(TRANSMITTER_ID_SAVE_ADDR,u8PlanUseFobKeyUid_Index,2);
					}
				}
				else if(FRAME_LF_CMD == 0x13)
				{
					Lf_Door_CurRssiCalcVal.value = NXPFloat24_to_IEEEFloat(&tsNck2910RecvFrame.m_Data[4]);
				}
				else
				{
					
				}

				#ifdef QN_DEBUG
					sdrv_gpio_toggle_pin_output_level(GPIO_L8);
				#endif
			}
		}
		else if(FRAME_LF_CMD == 0x15)
		{
			bWaitAllFobKey_A_WakeUp = 1;
			Lf_Door_CurRssiCalcVal.value = NXPFloat24_to_IEEEFloat(&tsNck2910RecvFrame.m_Data[2]);
		}
		else if(FRAME_LF_CMD == 0x16)
		{
			bWaitAllFobKey_B_WakeUp = 1;
			Rf_Door_CurRssiCalcVal.value = NXPFloat24_to_IEEEFloat(&tsNck2910RecvFrame.m_Data[2]);
		}
	}
}

static void Calibration_Rssi_Process(void)
{
	uint32 u32tmpreg = 0;

	InCar_CurRssiCalcVal.value = NXPFloat24_to_IEEEFloat(&tsNck2910RecvFrame.m_Data[2]);
	u32tmpreg = (uint32)(InCar_CurRssiCalcVal.value * 100.0);
	
	Lf_Door_CurRssiCalcVal.value = NXPFloat24_to_IEEEFloat(&tsNck2910RecvFrame.m_Data[5]);
	u32tmpreg = (uint32)(Lf_Door_CurRssiCalcVal.value * 100.0);
	
	Rf_Door_CurRssiCalcVal.value = NXPFloat24_to_IEEEFloat(&tsNck2910RecvFrame.m_Data[8]);
	u32tmpreg = (uint32)(Rf_Door_CurRssiCalcVal.value * 100.0);
	
	u8HitagAuthPass  = 1;
}


/*******************************************************************************
 * 函数名  : UhfRxHandler
 * 描述	 : 高频接收数据处理
 * 输入	 : None
 * 返回	 : None
 *******************************************************************************/
void UhfRxHandler(void)
{		
	static uint8_t u8FobKeyEnterMatchPatternLast = 0;

	if (False == Fifo_IsEmpty(&LPFifo))
	{
		tsNck2910RecvFrame = Fifo_Read(&LPFifo);

		if(tsNck2910RecvFrame.m_DataLength > 4)
		{
			tuHf_Func01.DATA_BYTE = tsNck2910RecvFrame.m_Data[0]; 		

			if((tsNck2910RecvFrame.m_Data[0] == 0x0b)&&(tsNck2910RecvFrame.m_Data[1] == 0x00))
			{
				Calibration_Rssi_Process();
			}
			else
			{
				if(0 == FRAME_TYPE)
				{
					UhfFobKeyRkeProcess();
				}
				else
				{
					UhfPkePkgProcess();	
				}
			}
		}
		else
		{	
			if(u8FobKeyButtonCmdPre > 0)
			{
				tsNck2910RecvFrame.m_Data[0] = tsNck2910RecvFrame.m_Data[0] & 0x0f;
				if(tsNck2910RecvFrame.m_Data[0] == 0x08)
				{
					
				}
				else
				{
					u8FobkeyLongPressValidTimeCnt = 0;
					u8FobKeyButtonPressInd = 0;
					u8FobKeyButtonCmdPre = 0;

					if(u8Fobkey_Cur_RkeCmd >= 0x31)
					{
						u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_IDLE;
					}
					return;
				}

				if((tsNck2910RecvFrame.m_Data[1] & 0x10) == 0x10)
				{					
					//遥控最后一帧数据
					if(u8Fobkey_Cur_RkeCmd >=0x31)
					{
						u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_IDLE;
					}
				}
				else if((tsNck2910RecvFrame.m_Data[1] & 0x10) == 0x00)
				{
                                    tsNck2910RecvFrame.m_Data[1] = tsNck2910RecvFrame.m_Data[1] & 0x07;
					if(tsNck2910RecvFrame.m_Data[1] == u8FobKeyButtonCmdPre)
					{
						//前后2个按键是同一个按键
						u8FobKeyButtonPressInd = 1;
						u8FobkeyLongPressValidTimeCnt = 0;
						if(u8FobKeyButtonCmdPre == 0x01)
						{
							u16LockLongPressTimingCnt++;
							if(u16LockLongPressTimingCnt >= PABS_LONGPRESS_MAX)
							{
								u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_CLOSEWINDOW;
							}
						}
						else if(u8FobKeyButtonCmdPre == 0x02)
						{
							u16UnlockLongPressTimingCnt++;
							if(u16UnlockLongPressTimingCnt >= PABS_LONGPRESS_MAX)
							{
								u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_OPENWINDOW;
							}
						}
						else if(u8FobKeyButtonCmdPre == 0x04)
						{
							u16TrunkLongPressTimingCnt++;
							if(u16TrunkLongPressTimingCnt >= PABS_LONGPRESS_MAX)
							{
								u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_TRUNK_ALWAYS;
							}
						}
					}
				}
			}
		}
	}

	if(1 == u8FobKeyButtonPressInd)
	{
		u8FobkeyLongPressValidTimeCnt++;
		if(u8FobkeyLongPressValidTimeCnt >= DOUBLE_CLICK_MAXIMUM_TIME)
		{
			u8FobkeyLongPressValidTimeCnt = 0;
                        u8FobKeyButtonCmdPre = 0;
                        u8FobKeyButtonPressInd = 0;
                        
                        if(u8Fobkey_Cur_RkeCmd >=0x31)
                        {
                          u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_IDLE;
			}
		}//按键信号超过300ms都没有更新。
	}

	if(1 == u8FobKeyEnterWorkState)
	{
		if(u8FobKeyEnterMatchPatternLast != 1)
		{
			u8EcuLearnMatchRepeat = 0;
		}
	}
	else if(2 == u8FobKeyEnterWorkState)
	{
		if(u8FobKeyEnterMatchPatternLast != 2)
		{
			u8FobKey_Id_Message = 0;
			u8EcuLearnMatch_Status = 0;
			FobKeyMessageErase();
		}
	}
	
	u8FobKeyEnterMatchPatternLast = u8FobKeyEnterWorkState;
	
	u32Time1sCount++;
}


/*******************************************************************************
 * 函数名  : Execute_Command
 * 描述	 : 执行RKE动作
 * 输入	 : Button_Mode	FALSE:短按  TRUE: 长按
 * 返回	 : None
 *******************************************************************************/
static void 	Execute_Command(void)
{
	static uint8_t	u8UnlockPressOn = 0;
	static uint32_t	u32UnlockPressOnLastTime[2];

	static uint8_t	u8LockPressOn = 0;
	static uint32_t	u32LockPressOnLastTime[2];

	static uint8_t	u8TrunkPressOn = 0;
	static uint32_t	u32TrunkPressOnLastTime[2];
	uint32_t	tmpreg = 0;		

	tsRke_ReceiveBuf.CommandCode = tsRke_ReceiveBuf.CommandCode & 0x07;

	if(tsRke_ReceiveBuf.CommandCode == 0x01)
	{
		u32LockPressOnLastTime[u8LockPressOn++] = u32Time1sCount;

		if (u8LockPressOn >= 2)
		{
			if (u32LockPressOnLastTime[1] >= u32LockPressOnLastTime[0])
			{
				tmpreg				= u32LockPressOnLastTime[1] -u32LockPressOnLastTime[0];
			}
			else 
			{
				tmpreg				= u32LockPressOnLastTime[1] + (0xFFFFFFFF - u32LockPressOnLastTime[0]);
			}

			if (tmpreg < DOUBLE_CLICK_MAXIMUM_TIME)
			{
				u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_SEEK_CAK;
				u8LockPressOn		= 0;
			}
			else 
			{
				u32LockPressOnLastTime[0] = u32LockPressOnLastTime[1];
				u8LockPressOn		= 1;
				u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_LOCK;
			}
		}
		else
		{
			u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_LOCK;
		}
	}
	else if(tsRke_ReceiveBuf.CommandCode == 0x02)
	{
		u32UnlockPressOnLastTime[u8UnlockPressOn++] = u32Time1sCount;

		if (u8UnlockPressOn >= 2)
		{
			if (u32UnlockPressOnLastTime[1] >= u32UnlockPressOnLastTime[0])
			{
				tmpreg				= u32UnlockPressOnLastTime[1] -u32UnlockPressOnLastTime[0];
			}
			else 
			{
				tmpreg				= u32UnlockPressOnLastTime[1] + (0xFFFFFFFF - u32UnlockPressOnLastTime[0]);
			}

			if (tmpreg < DOUBLE_CLICK_MAXIMUM_TIME)
			{
				u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_UNLOCK_REPEAT;
				u8UnlockPressOn		= 0;
			}
			else 
			{
				u32UnlockPressOnLastTime[0] = u32UnlockPressOnLastTime[1];
				u8UnlockPressOn		= 1;
				u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_UNLOCK;
			}
		}
		else
		{
			u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_UNLOCK;
		}
	}
	else if(tsRke_ReceiveBuf.CommandCode == 0x04)
	{					
		u32TrunkPressOnLastTime[u8TrunkPressOn++] = u32Time1sCount;

		if (u8TrunkPressOn >= 2)
		{
			if (u32TrunkPressOnLastTime[1] >= u32TrunkPressOnLastTime[0])
			{
				tmpreg				= u32TrunkPressOnLastTime[1] -u32TrunkPressOnLastTime[0];
			}
			else 
			{
				tmpreg				= u32TrunkPressOnLastTime[1] + (0xFFFFFFFF - u32TrunkPressOnLastTime[0]);
			}

			if (tmpreg < DOUBLE_CLICK_MAXIMUM_TIME)
			{
				u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_TRUNK_UNLOCK;
				u8TrunkPressOn		= 0;
			}
			else 
			{
				u32TrunkPressOnLastTime[0] = u32TrunkPressOnLastTime[1];
				u8TrunkPressOn		= 1;
				u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_FINDCAR;
			}
		}
		else
		{
			u8Fobkey_Cur_RkeCmd = FOBKEY_RKE_FINDCAR;
		}
	}
	else
	{
		return;//没有任何按键或复合键
	}

	u8FobKeyButtonCmdPre = tsRke_ReceiveBuf.CommandCode;
	tsRke_ReceiveBuf.CommandCode = 0;
	u16LockLongPressTimingCnt = 0;
	u16UnlockLongPressTimingCnt = 0;
	u16TrunkLongPressTimingCnt = 0;
}

/*******************************************************************************
 * 函数名	: FobKeyMessageErase()
 * 描述	: 钥匙信息擦除
 * 输入	: None
 * 返回	: None
 *******************************************************************************/
static void FobKeyMessageErase(void)
{
	memset(tsFobKeyMessageSave_A.Fifo_Data,0,sizeof(tsFobKeyMessageSave_A));
	tsFobKeyMessageSave_A.Crc8 = _CalculateCRC8(tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A) - 1);
	memcpy(tsFobKeyMessageSave_B.Fifo_Data,tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A));
	
	//更新EEPROM数据A区,B区
	
	Rke_Flash_Write(TRANSMITTERS_EEPROM_ADDR,tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A));
	Rke_Flash_Write(TRANSMITTERS_EEPROM_BAK_ADDR,tsFobKeyMessageSave_B.Fifo_Data,sizeof(tsFobKeyMessageSave_B));

	
	u8TransmitterCount = tsFobKeyMessageSave_A.FobKeyCount;
	
	memcpy(&tsTransmitters[0].SerialNo,&tsFobKeyMessageSave_A.Fifo_Data[0],25);
	memcpy(&tsTransmitters[1].SerialNo,&tsFobKeyMessageSave_A.Fifo_Data[25],25);
	memcpy(&tsTransmitters[2].SerialNo,&tsFobKeyMessageSave_A.Fifo_Data[50],25);
	memcpy(&tsTransmitters[3].SerialNo,&tsFobKeyMessageSave_A.Fifo_Data[75],25);
	//memcpy(&tsTransmitters[4].SerialNo,&tsFobKeyMessageSave_A.Fifo_Data[100],25);
}

/*******************************************************************************
 * 函数名  : InitFobKeyEepromMessage
 * 描述	 : 初始化遥控钥匙信息
 * 输入	 : None
 * 返回	 : None
 *******************************************************************************/
void InitFobKeyEepromMessage(void)
{
	uint8 u8ReadBuf[8];
	//EEPROM读出数据A区和B区
	
	Rke_Flash_Read(TRANSMITTERS_EEPROM_ADDR,(void *)&tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A));
	Rke_Flash_Read(TRANSMITTERS_EEPROM_BAK_ADDR,(void *)&tsFobKeyMessageSave_B.Fifo_Data,sizeof(tsFobKeyMessageSave_B));
	if(tsFobKeyMessageSave_A.Crc8 == _CalculateCRC8(tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A) - 1))
	{
		uint8 u8DoCnt = 3;
		
		while(u8DoCnt > 0)
		{
			Rke_Flash_Write(TRANSMITTERS_EEPROM_BAK_ADDR,tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A));
			
			Rke_Flash_Read(TRANSMITTERS_EEPROM_BAK_ADDR, (void *) &tsFobKeyMessageSave_B.Fifo_Data,sizeof(tsFobKeyMessageSave_B));

			if (tsFobKeyMessageSave_A.Crc8 == _CalculateCRC8(tsFobKeyMessageSave_B.Fifo_Data, sizeof(tsFobKeyMessageSave_B) - 1))
			{
				u8DoCnt = 0;
			}
			else
			{
				u8DoCnt--;
			}
		}
	}
	else
	{
		if(tsFobKeyMessageSave_B.Crc8 == _CalculateCRC8(tsFobKeyMessageSave_B.Fifo_Data,sizeof(tsFobKeyMessageSave_B) - 1))
		{
			//更新B区数据到A区	
			Rke_Flash_Write(TRANSMITTERS_EEPROM_ADDR,tsFobKeyMessageSave_B.Fifo_Data,sizeof(tsFobKeyMessageSave_B));
		}
		else
		{
			//第一次上电
			memset(&tsFobKeyMessageSave_A.Fifo_Data[0],0,sizeof(tsFobKeyMessageSave_A));
			tsFobKeyMessageSave_A.Crc8 = _CalculateCRC8(tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A) - 1);
			memcpy(tsFobKeyMessageSave_B.Fifo_Data,tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A));

			//更新EEPROM数据A区,B区
			Rke_Flash_Write(TRANSMITTERS_EEPROM_ADDR,tsFobKeyMessageSave_A.Fifo_Data,sizeof(tsFobKeyMessageSave_A));
			Rke_Flash_Write(TRANSMITTERS_EEPROM_BAK_ADDR,tsFobKeyMessageSave_B.Fifo_Data,sizeof(tsFobKeyMessageSave_B));
		}
	}

	u8TransmitterCount = tsFobKeyMessageSave_A.FobKeyCount;

	memcpy(&tsTransmitters[0].SerialNo,&tsFobKeyMessageSave_A.Fifo_Data[0],25);
	memcpy(&tsTransmitters[1].SerialNo,&tsFobKeyMessageSave_A.Fifo_Data[25],25);
	memcpy(&tsTransmitters[2].SerialNo,&tsFobKeyMessageSave_A.Fifo_Data[50],25);
	memcpy(&tsTransmitters[3].SerialNo,&tsFobKeyMessageSave_A.Fifo_Data[75],25);
	//memcpy(&tsTransmitters[4].SerialNo,&tsFobKeyMessageSave_A.Fifo_Data[100],25);

	Rke_Flash_Read(SK_CODE_SAVE_ADDR,u8Universal_Key,16);

	Rke_Flash_Read(TRANSMITTER_ID_SAVE_ADDR,u8PlanUseFobKeyUid_Index,2);

	if(u8PlanUseFobKeyUid_Index[0] >= 4)
	{
		u8PlanUseFobKeyUid_Index[0] = 0;
	}

	if(u8PlanUseFobKeyUid_Index[1] >= 4)
	{
		u8PlanUseFobKeyUid_Index[1] = 0;
	}

	u32PlanUseFobKeyUid[0] = tsTransmitters[u8PlanUseFobKeyUid_Index[0]].SerialNo;
	u32PlanUseFobKeyUid[1] = tsTransmitters[u8PlanUseFobKeyUid_Index[1]].SerialNo;
	
	Fifo_Init(&LPFifo, 5);
	
	#ifdef QN_DEBUG
        tsTransmitters[0].SerialNo = 0xf647B3e3;//0xd52280ec;
        tsTransmitters[0].Sync_Counter = 0x00000000;

		//tsTransmitters[0].SerialNo = 0x2f607ee1;
		//tsTransmitters[0].Sync_Counter = 0x00000000;
		
        tsTransmitters[0].SecretKey[0] = 0x5c;
        tsTransmitters[0].SecretKey[1] = 0xba;
        tsTransmitters[0].SecretKey[2] = 0x10;
        tsTransmitters[0].SecretKey[3] = 0x77;
        
        tsTransmitters[0].SecretKey[4] = 0x48;
        tsTransmitters[0].SecretKey[5] = 0xd8;
        tsTransmitters[0].SecretKey[6] = 0xe8;
        tsTransmitters[0].SecretKey[7] = 0x09;
        
        tsTransmitters[0].SecretKey[8] = 0x4c;
        tsTransmitters[0].SecretKey[9] = 0xe6;
        tsTransmitters[0].SecretKey[10] = 0xaf;
        tsTransmitters[0].SecretKey[11] = 0x7e;

		tsTransmitters[0].SecretKey[12] = 0x2b;
        tsTransmitters[0].SecretKey[13] = 0x14;
        tsTransmitters[0].SecretKey[14] = 0x67;
        tsTransmitters[0].SecretKey[15] = 0xcd;
		
		tsTransmitters[0].FobKeyEn = 0;
		

		tsTransmitters[1].SerialNo = 0x3bb97fec ;
        tsTransmitters[1].Sync_Counter = 0x00000000;
		
        tsTransmitters[1].SecretKey[0] = 0x12;
        tsTransmitters[1].SecretKey[1] = 0x34;
        tsTransmitters[1].SecretKey[2] = 0x56;
        tsTransmitters[1].SecretKey[3] = 0x78;
        
        tsTransmitters[1].SecretKey[4] = 0x9a;
        tsTransmitters[1].SecretKey[5] = 0xbc;
        tsTransmitters[1].SecretKey[6] = 0xde;
        tsTransmitters[1].SecretKey[7] = 0xf1;
        
        tsTransmitters[1].SecretKey[8] = 0x23;
        tsTransmitters[1].SecretKey[9] = 0x45;
        tsTransmitters[1].SecretKey[10] = 0x67;
        tsTransmitters[1].SecretKey[11] = 0x89;

		tsTransmitters[1].SecretKey[12] = 0xab;
        tsTransmitters[1].SecretKey[13] = 0xcd;
        tsTransmitters[1].SecretKey[14] = 0xef;
        tsTransmitters[1].SecretKey[15] = 0x01;
		
		tsTransmitters[1].FobKeyEn = 0;
		
        u8TransmitterCount= 2;

		u8PlanUseFobKeyUid_Index[0] = 0;//0x3bb97fec;
		u8PlanUseFobKeyUid_Index[1] = 1;//0xd52280ec;
	#endif
}

