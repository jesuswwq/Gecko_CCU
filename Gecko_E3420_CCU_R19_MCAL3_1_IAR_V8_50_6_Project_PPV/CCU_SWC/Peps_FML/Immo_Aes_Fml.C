
#include <string.h>
#include "platform_cfg.h"
#include "joker.h"
#include "uhf_fml.h"
#include "Immo_Aes_Fml.h"
#include "Pke_Pks_APP.h"
#include "LoopFifo.h"

struct Immo_Auth_Buff sImmo_Auth_Message;

static uint8 u8Read_Universal_Key[16]={0};

static Immo_FeedBack_States_t teFobKey_Learn_Feedback_Status = IMMO_LEARN_RUNNING; 

phscaCendricCadsUC_Immo_States_t sphscaCendricCadsUCImmoState = IMMO_SETTING;

FobKeyLearn_Immo_States_t sphscaCendricCadsLearnImmoState = FOBKEYLEARN_SET_INIT;


const uint8_t u8ImmoPage_Wr_Cmd[5][2]={{0x8b,0x80},{0x93,0x40},{0x9b,0x00},{0xa2,0xc0},{0xaa,0x80}};//Ò³Ð´1£¬2£¬3£¬4£¬5

const uint8_t u8ImmoPage_Rd_Cmd[5][2]={{0xc9,0x80},{0xd1,0x40},{0xd9,0x00},{0xe0,0xc0},{0xe8,0x80}};//Ò³¶Á1£¬2£¬3£¬4£¬5

uint8 u8ImmoLearnWorkCnt = 0;

extern uint8_t g_datCan1Tx_0x330[8];

extern PrintFifo_TypeDef PrintFifo;

extern void Rke_Flash_Write(uint32_t addr,void *buf,uint32_t len);


Immo_FeedBack_States_t Get_Fobs_Learn_Status(void)
{
	return teFobKey_Learn_Feedback_Status;
}

void Change_Fobs_Learn_Status(Immo_FeedBack_States_t sta)
{
	teFobKey_Learn_Feedback_Status = sta;
}


uint8_t Immo_AuthTransmitterInfoInit(uint32_t Uid)
{

	uint8_t byteIdx = 0u;
	uint8_t tmpData[16u] =	{ 0u };
	uint8_t* keyFobIde;
	LONG_UNION		Rand_Val;
	
	if(GetCurUseSecretKey(Uid,sImmo_Auth_Message.Use_SecretKey) == 0)
	{
		return 0;
	}

	if(tsTransmitters[GetFobKeyId()-1].FobKeyEn == 1)
	{
		return 0;
	}
	
	Rand_Val.Value = GetSysRandTimeCount();

	sImmo_Auth_Message.Challenge[0] = 127^Rand_Val.CHAR_BYTE.High_byte;		//0x7f
	sImmo_Auth_Message.Challenge[1] = 102^Rand_Val.CHAR_BYTE.Mhigh_byte;		//0x66
	sImmo_Auth_Message.Challenge[2] = 182^Rand_Val.CHAR_BYTE.Mlow_byte;		//0xb6
	sImmo_Auth_Message.Challenge[3] = 141^Rand_Val.CHAR_BYTE.Low_byte;		//0x8d
	sImmo_Auth_Message.Challenge[4] = 238^Rand_Val.CHAR_BYTE.Mlow_byte;		//0xee
	sImmo_Auth_Message.Challenge[5] = 34^Rand_Val.CHAR_BYTE.Low_byte;		//0x22
	sImmo_Auth_Message.Challenge[6] = 203^Rand_Val.CHAR_BYTE.High_byte;		//0xcb
	sImmo_Auth_Message.Challenge[7] = 213^Rand_Val.CHAR_BYTE.Mhigh_byte;		//0xd5
	
	keyFobIde = (uint8_t*) &sImmo_Auth_Message.Id[0u];
	
	for (byteIdx = 0u; byteIdx < 4u; byteIdx++)
	{
		tmpData[byteIdx] = keyFobIde[byteIdx];
	}

	for (byteIdx = 0u; byteIdx < 4u; byteIdx++)
	{
		tmpData[byteIdx + 4u] = keyFobIde[byteIdx];
	}

	for (byteIdx = 0u; byteIdx < 8u; byteIdx++)
	{
		tmpData[byteIdx + 8u] = sImmo_Auth_Message.Challenge[byteIdx];
	}

	/* Initialize AES */
	AESInit(tmpData);
	/* Calculate AES Data */
	AES128Enc(sImmo_Auth_Message.Use_SecretKey);

	/* get MAC */
	/* data pre-load zero to be XORed */
	sImmo_Auth_Message.Mac[0u] = 0x00u;
	sImmo_Auth_Message.Mac[1u] = 0x00u;

	AESCrypt(sImmo_Auth_Message.Mac, 2u);
	
	return 1;
}


void NJJ29C0_Immo_Auth(void)
{
	static uint8_t 	u8ImmoAuthWaitTimeCnt = 0;
	static uint8_t u8ImmoAuthUseCnt = 0;
	uint8_t	Immo_Auth_Cmd[8] = {0};
	LONG_UNION Temp_Val;
	
	switch(sphscaCendricCadsUCImmoState)
	{
		case IMMO_SETTING:
			JOKER_ConfigImmoDriver();
			JOKER_ConfigImmoBPLM();
			JOKER_ConfigImmoReceiver();
			sphscaCendricCadsUCImmoState = IMMO_START_CMD;

		break;

		case IMMO_START_CMD:
			JOKER_StartImmo();
			sphscaCendricCadsUCImmoState = IMMO_TRANSCEIVE_GET_IDE_REQ;
			u8ImmoAuthWaitTimeCnt = IMMO_WAIT_MAX_PERIOD;
		break;
		
		case IMMO_TRANSCEIVE_GET_IDE_REQ:
			if(u8ImmoAuthWaitTimeCnt > 0)
			{
				u8ImmoAuthWaitTimeCnt--;
			}
			else
			{
				Immo_Auth_Cmd[0]	=	AES_START_AUTH;
	   			JOKER_StartImmoTransceive(&Immo_Auth_Cmd[0], 5, 32);
				u8ImmoAuthWaitTimeCnt = IMMO_WAIT_MAX_PERIOD;
				sphscaCendricCadsUCImmoState = IMMO_TRANSCEIVE_GET_IDE_RES;
			}
		break;

		case IMMO_TRANSCEIVE_GET_IDE_RES:
			if(u8ImmoAuthWaitTimeCnt > 0)
			{
				u8ImmoAuthWaitTimeCnt--;
			}
			else
			{	
				JOKER_GetImmoResponse(sImmo_Auth_Message.Id, 32);

				Temp_Val.CHAR_BYTE.High_byte = sImmo_Auth_Message.Id[0];
				Temp_Val.CHAR_BYTE.Mhigh_byte = sImmo_Auth_Message.Id[1];
				Temp_Val.CHAR_BYTE.Mlow_byte = sImmo_Auth_Message.Id[2];
				Temp_Val.CHAR_BYTE.Low_byte = sImmo_Auth_Message.Id[3];

				if(Immo_AuthTransmitterInfoInit(Temp_Val.Value) > 0)
				{
					sphscaCendricCadsUCImmoState = IMMO_TRANS_CHALLENGE_REQ;
				}
				else
				{
					sphscaCendricCadsUCImmoState = IMMO_REPEAT_AUTH_STATE;
				}
			}
		break;
		
		case IMMO_TRANS_CHALLENGE_REQ:
			JOKER_StartImmoTransmit(sImmo_Auth_Message.Challenge , 64);
			sphscaCendricCadsUCImmoState = IMMO_TRANS_CHALLENGE_RES;
			u8ImmoAuthWaitTimeCnt = IMMO_WAIT_MAX_PERIOD;
		break;

		case IMMO_TRANS_CHALLENGE_RES:
			if(u8ImmoAuthWaitTimeCnt > 0)
			{
				u8ImmoAuthWaitTimeCnt--;
			}
			else
			{	
				sphscaCendricCadsUCImmoState = IMMO_TRANSCEIVE_SIGNATURE_REQ;
			}
		break;
		
		case IMMO_TRANSCEIVE_SIGNATURE_REQ:
	   		JOKER_StartImmoTransceive(sImmo_Auth_Message.Mac, 16, 48);
			sphscaCendricCadsUCImmoState = IMMO_TRANSCEIVE_SIGNATURE_RES;
			u8ImmoAuthWaitTimeCnt = IMMO_WAIT_MAX_PERIOD;
		break;

		case IMMO_TRANSCEIVE_SIGNATURE_RES:
			if(u8ImmoAuthWaitTimeCnt > 0)
			{
				u8ImmoAuthWaitTimeCnt--;
			}
			else
			{	
				JOKER_GetImmoResponse(Immo_Auth_Cmd, 48);

				/* Decrypt response */
				AESCrypt(Immo_Auth_Cmd, 6u);

				for (uint8_t byteIdx = 0u; byteIdx < 6u; byteIdx++)
				{
					if (Immo_Auth_Cmd[byteIdx] != 0x00u)
					{
						sphscaCendricCadsUCImmoState = IMMO_REPEAT_AUTH_STATE;
						return;
					}
				}
				JOKER_StopImmo();
				
				sphscaCendricCadsUCImmoState = IMMO_AUTH_OK;

				SetPs_AuthFobStatus(3);
				//JOKER_StartSleepForced();
				Change_Njj29c0_WorkStatus(lf_ide);

				#ifdef QN_DEBUG
					sdrv_gpio_toggle_pin_output_level(GPIO_L8);
				#endif
			}
			
		break;
		
		case IMMO_REPEAT_AUTH_STATE:
			JOKER_StopImmo();
			u8ImmoLearnWorkCnt++;
			if(u8ImmoLearnWorkCnt >= 3)
			{
				sphscaCendricCadsUCImmoState = IMMO_AUTH_FAIL;
				SetPs_AuthFobStatus(2);
				//JOKER_StartSleepForced();
				Change_Njj29c0_WorkStatus(lf_ide);
			#if 0
				//zch debug
				memset(g_datCan1Tx_0x330,0,8);
				g_datCan1Tx_0x330[0] = 0x80;
				g_datCan1Tx_0x330[1] = 0x02;
				g_datCan1Tx_0x330[2] = 0x02;
				BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);
			#else
				if (Print_Fifo_IsFull(&PrintFifo) != True)
				{
					Print_Fifo_Write(&PrintFifo, 1);
				}
			#endif
			}
			else
			{
				u8ImmoAuthWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;
				sphscaCendricCadsUCImmoState = IMMO_AUTH_STATE_WAIT;
			}
		break;
		
		case IMMO_AUTH_STATE_WAIT:
			if(u8ImmoAuthWaitTimeCnt > 0)
			{
				u8ImmoAuthWaitTimeCnt--;
			}
			else
			{	
				sphscaCendricCadsUCImmoState = IMMO_SETTING;
			}
		break;

		default:

		break;
	
	}
}

void NJJ29C0_Immo_Check_Uid(void)
{
	static uint8_t 	u8ImmoAuthWaitTimeCnt = 0;
	static uint8_t u8ImmoAuthUseCnt = 0;
	uint8_t	Immo_Auth_Cmd[8] = {0};
	LONG_UNION Temp_Val;
	
	switch(sphscaCendricCadsUCImmoState)
	{
		case IMMO_SETTING:
			JOKER_ConfigImmoDriver();
			JOKER_ConfigImmoBPLM();
			JOKER_ConfigImmoReceiver();
			sphscaCendricCadsUCImmoState = IMMO_START_CMD;

		break;

		case IMMO_START_CMD:
			JOKER_StartImmo();
			sphscaCendricCadsUCImmoState = IMMO_TRANSCEIVE_GET_IDE_REQ;
			u8ImmoAuthWaitTimeCnt = IMMO_WAIT_MAX_PERIOD;
		break;
		
		case IMMO_TRANSCEIVE_GET_IDE_REQ:
			if(u8ImmoAuthWaitTimeCnt > 0)
			{
				u8ImmoAuthWaitTimeCnt--;
			}
			else
			{
				Immo_Auth_Cmd[0]	=	AES_START_AUTH;
	   			JOKER_StartImmoTransceive(&Immo_Auth_Cmd[0], 5, 32);
				u8ImmoAuthWaitTimeCnt = IMMO_WAIT_MAX_PERIOD;
				sphscaCendricCadsUCImmoState = IMMO_TRANSCEIVE_GET_IDE_RES;
			}
		break;

		case IMMO_TRANSCEIVE_GET_IDE_RES:
			if(u8ImmoAuthWaitTimeCnt > 0)
			{
				u8ImmoAuthWaitTimeCnt--;
			}
			else
			{	
				JOKER_GetImmoResponse(sImmo_Auth_Message.Id, 32);

				Temp_Val.CHAR_BYTE.High_byte = sImmo_Auth_Message.Id[0];
				Temp_Val.CHAR_BYTE.Mhigh_byte = sImmo_Auth_Message.Id[1];
				Temp_Val.CHAR_BYTE.Mlow_byte = sImmo_Auth_Message.Id[2];
				Temp_Val.CHAR_BYTE.Low_byte = sImmo_Auth_Message.Id[3];

				if((sImmo_Auth_Message.Id[3] & 0xF0) == 0xE0)
				{
					if(GetCurUseSecretKey(Temp_Val.Value,sImmo_Auth_Message.Use_SecretKey) > 0)
					{
						u8_Auth_KeyTest_Feedback = 1;
					}
					else
					{
						u8_Auth_KeyTest_Feedback = 2;
					}
					JOKER_StopImmo();
					//JOKER_StartSleepForced();
					Change_Njj29c0_WorkStatus(lf_ide);
				}
				else
				{
					sphscaCendricCadsUCImmoState = IMMO_REPEAT_AUTH_STATE;
				}
				
			}
		break;
		
		case IMMO_REPEAT_AUTH_STATE:
			JOKER_StopImmo();
			u8ImmoLearnWorkCnt++;
			if(u8ImmoLearnWorkCnt >= 3)
			{
				u8_Auth_KeyTest_Feedback = 3;
				//JOKER_StartSleepForced();
				Change_Njj29c0_WorkStatus(lf_ide);
			}
			else
			{
				u8ImmoAuthWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;
				sphscaCendricCadsUCImmoState = IMMO_AUTH_STATE_WAIT;
			}
		break;
		
		case IMMO_AUTH_STATE_WAIT:
			if(u8ImmoAuthWaitTimeCnt > 0)
			{
				u8ImmoAuthWaitTimeCnt--;
			}
			else
			{	
				sphscaCendricCadsUCImmoState = IMMO_SETTING;
			}
		break;

		default:

		break;
	
	}
}

void FobKey_Immo_Learn_Process(void)
{
	LONG_UNION	 	Temp_Val;
	static uint8_t 	u8IskIndex = 0;
	static uint8_t 	u8ImmoLearnWaitTimeCnt = 0;
	uint8_t	Immo_Cmd[8] = {0};
	uint8_t Immo_RecvFrame[16];
	static uint8_t u8FobKey_Num_Set = 0;
	static uint8_t u8ImmoUseCnt = 0;
	LONG_UNION Rand_Val;
	
	uint8_t byteIdx = 0u;
	uint8_t tmpData[16u] =	{ 0u };
	uint8_t* keyFobIde;
	
    switch(sphscaCendricCadsLearnImmoState)
	{
		case FOBKEYLEARN_SET_INIT:
			JOKER_ConfigImmoDriver();
			JOKER_ConfigImmoBPLM();
			JOKER_ConfigImmoReceiver();
			sphscaCendricCadsLearnImmoState = FOBKEYLEARN_START_CMD;
			u8ImmoLearnWaitTimeCnt = 1;
		#ifdef QN_DEBUG
			sdrv_gpio_set_pin_output_level(GPIO_L6,1);	
		#endif
		break;
		
		case FOBKEYLEARN_START_CMD:
			u8ImmoLearnWaitTimeCnt--;
			if(u8ImmoLearnWaitTimeCnt == 0)
			{
				JOKER_StartImmo();
				u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD;
				sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_GET_IDE_REQ;
			}
		break;

		case FOBKEYLEARN_TRANSCEIVE_GET_IDE_REQ:
			u8ImmoLearnWaitTimeCnt--;
			if(u8ImmoLearnWaitTimeCnt == 0)
			{
				Immo_Cmd[0]	=	AES_START_AUTH;
		   		JOKER_StartImmoTransceive(&Immo_Cmd[0], 5, 32);
				u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD;
				sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_GET_IDE_RES;
			}
		break;
		
		case FOBKEYLEARN_TRANSCEIVE_GET_IDE_RES:
			u8ImmoLearnWaitTimeCnt--;
			if(u8ImmoLearnWaitTimeCnt == 0)
			{
				JOKER_GetImmoResponse(Immo_RecvFrame, 32);

				Temp_Val.CHAR_BYTE.High_byte = Immo_RecvFrame[0];
				Temp_Val.CHAR_BYTE.Mhigh_byte = Immo_RecvFrame[1];
				Temp_Val.CHAR_BYTE.Mlow_byte = Immo_RecvFrame[2];
				Temp_Val.CHAR_BYTE.Low_byte = Immo_RecvFrame[3];

				tsFob_LearnBuf.SerialNo = 0;
				if((Immo_RecvFrame[3] & 0xF0) == 0xE0)
				{
					tsFob_LearnBuf.SerialNo = Temp_Val.Value;
					u8ImmoUseCnt = 0;

					if(GetCurUseSecretKey(tsFob_LearnBuf.SerialNo,sImmo_Auth_Message.Use_SecretKey) > 0)
					{
						u8FobKey_Num_Set = GetFobKeyId() - 1;
					}
					else
					{
						if(GetTransmitterCountVal() >=  MAX_TRANSMITTERS)
						{
							JOKER_StopImmo();
							teFobKey_Learn_Feedback_Status = IMMO_LEARN_MAX_NUM_LIMIT;
							u8FobKey_Information_Management_Feedback = 3;//Keys  Full
							//JOKER_StartSleepForced();
							Change_Njj29c0_WorkStatus(lf_ide);
							return;
						}
						else
						{
							u8FobKey_Num_Set = GetTransmitterCountVal();
						}
					}
					u8ImmoLearnWaitTimeCnt = 0;
					sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSPONDER_RESET_ONE;
				}
				else
				{
					JOKER_StopImmo();
				
					u8ImmoUseCnt++;
					if(u8ImmoUseCnt >= 3)
					{
						u8ImmoUseCnt = 0;
						teFobKey_Learn_Feedback_Status = IMMO_LEARN_GET_IDE_FAIL;
						u8FobKey_Information_Management_Feedback = 2;//
						//JOKER_StartSleepForced();
						Change_Njj29c0_WorkStatus(lf_ide);
					}
					else
					{
						u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;  
						sphscaCendricCadsLearnImmoState = FOBKEYLEARN_START_CMD;
					}
				}	
			}
		break;
			
		case FOBKEYLEARN_TRANSPONDER_RESET_ONE:
			u8ImmoLearnWaitTimeCnt++;
			if(u8ImmoLearnWaitTimeCnt == 1)
			{
				Immo_Cmd[0] = AES_SOFT_RST;
				JOKER_StartImmoTransmit(Immo_Cmd , 1);
			}
			else if(u8ImmoLearnWaitTimeCnt >= 2)
			{
				sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_XMA_WAIT_REQ;				
			}
		break;

		case FOBKEYLEARN_TRANSCEIVE_XMA_WAIT_REQ:
			Immo_Cmd[0]	=	AES_XMA_WAIT;
	   		JOKER_StartImmoTransceive(&Immo_Cmd[0], 5, 16);
			u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD;
			sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_XMA_WAIT_RES;
		break;
		
		case FOBKEYLEARN_TRANSCEIVE_XMA_WAIT_RES:
			u8ImmoLearnWaitTimeCnt--;
			if(u8ImmoLearnWaitTimeCnt == 0)
			{
				JOKER_GetImmoResponse(Immo_RecvFrame, 16);
				sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_WR_PAGE_REQ;
				u8IskIndex = 0;
				
				/*if((Immo_RecvFrame[0] == 0x03)&&(Immo_RecvFrame[1] == 0x81))
				{
					sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_WR_PAGE_REQ;
					u8IskIndex = 0;
				}
				else
				{
					JOKER_StopImmo();
					u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;
					sphscaCendricCadsLearnImmoState = FOBKEYLEARN_REPEAT_REQ;
				}*/
			}
		break;

		case FOBKEYLEARN_TRANSCEIVE_WR_PAGE_REQ:
			JOKER_StartImmoTransceive((uint8_t *)&u8ImmoPage_Wr_Cmd[u8IskIndex][0], 10, 10);
			u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD >> 1;
			sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_WR_PAGE_RES;
		break;
		
		case FOBKEYLEARN_TRANSCEIVE_WR_PAGE_RES:
			u8ImmoLearnWaitTimeCnt--;
			if(u8ImmoLearnWaitTimeCnt == 0)
			{
				JOKER_GetImmoResponse(Immo_RecvFrame, 10);
				sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANS_WR_DATA_REQ;
			}
		break;

		case FOBKEYLEARN_TRANS_WR_DATA_REQ:
			if(u8IskIndex == 0)
			{
				Immo_Cmd[0] = u8Universal_Key[0];
				Immo_Cmd[1] = u8Universal_Key[1];
				Immo_Cmd[2] = u8Universal_Key[2];
				Immo_Cmd[3] = u8Universal_Key[3];
			}
			else if(u8IskIndex == 1)
			{
				Immo_Cmd[0] = u8Universal_Key[4];
				Immo_Cmd[1] = u8Universal_Key[5];
				Immo_Cmd[2] = u8Universal_Key[6];
				Immo_Cmd[3] = u8Universal_Key[7];
			}
			else if(u8IskIndex == 2)
			{
				Immo_Cmd[0] = u8Universal_Key[8];
				Immo_Cmd[1] = u8Universal_Key[9];
				Immo_Cmd[2] = u8Universal_Key[10];
				Immo_Cmd[3] = u8Universal_Key[11];
			}
			else if(u8IskIndex == 3)
			{
				Immo_Cmd[0] = u8Universal_Key[12];
				Immo_Cmd[1] = u8Universal_Key[13];
				Immo_Cmd[2] = u8Universal_Key[14];
				Immo_Cmd[3] = u8Universal_Key[15];
			}
			else
			{
				if(u8TransmitterCount == 0)
				{
					Rand_Val.Value = GetSysRandTimeCount();

					u8WelcomeGuestPollingWakeUpUid[0] = Rand_Val.CHAR_BYTE.Low_byte;
					u8WelcomeGuestPollingWakeUpUid[1] = Rand_Val.CHAR_BYTE.Mlow_byte;
					Rke_Flash_Write(PKE_POLLING_ID_SAVE_ADDR, u8WelcomeGuestPollingWakeUpUid, 2);
				}
				Immo_Cmd[0] = 0x00;
				Immo_Cmd[1] = u8WelcomeGuestPollingWakeUpUid[0];
				Immo_Cmd[2] = u8WelcomeGuestPollingWakeUpUid[1];
				Immo_Cmd[3] = u8FobKey_Num_Set;
			}
			
			JOKER_StartImmoTransmit(Immo_Cmd , 32);
			u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;
			sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANS_WR_DATA_RES;
		break;

		case FOBKEYLEARN_TRANS_WR_DATA_RES:
			u8ImmoLearnWaitTimeCnt--;
			if(u8ImmoLearnWaitTimeCnt == 0)
			{
				u8IskIndex++;
				if(u8IskIndex >= 5)
				{
					u8IskIndex = 0;
					sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_RD_PAGE_REQ;
				}
				else
				{
					sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_WR_PAGE_REQ;
				}
			}
		break;
		
		case FOBKEYLEARN_TRANSCEIVE_RD_PAGE_REQ:
			JOKER_StartImmoTransceive((uint8_t *)&u8ImmoPage_Rd_Cmd[u8IskIndex][0], 10, 32);
			u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD;
			sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_RD_PAGE_RES;
		break;
		
		case FOBKEYLEARN_TRANSCEIVE_RD_PAGE_RES:
			u8ImmoLearnWaitTimeCnt--;
			if(u8ImmoLearnWaitTimeCnt == 0)
			{
				JOKER_GetImmoResponse(Immo_RecvFrame, 32);
				u8IskIndex++;
				if(u8IskIndex == 1)
				{
					if( (u8Universal_Key[0] != Immo_RecvFrame[0])||
						(u8Universal_Key[1] != Immo_RecvFrame[1])||
						(u8Universal_Key[2] != Immo_RecvFrame[2])||
						(u8Universal_Key[3] != Immo_RecvFrame[3]))
					{
						JOKER_StopImmo();
						u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;
						sphscaCendricCadsLearnImmoState = FOBKEYLEARN_REPEAT_REQ;
						teFobKey_Learn_Feedback_Status = IMMO_LEARN_WR_PAGE_FAIL;
					}
					else
					{
						sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_RD_PAGE_REQ;
					}
				}
				else if(u8IskIndex == 2)
				{
					if( (u8Universal_Key[4] != Immo_RecvFrame[0])||
						(u8Universal_Key[5] != Immo_RecvFrame[1])||
						(u8Universal_Key[6] != Immo_RecvFrame[2])||
						(u8Universal_Key[7] != Immo_RecvFrame[3]))
					{
						JOKER_StopImmo();
						u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;
						sphscaCendricCadsLearnImmoState = FOBKEYLEARN_REPEAT_REQ;
						teFobKey_Learn_Feedback_Status = IMMO_LEARN_WR_PAGE_FAIL;
					}
					else
					{
						sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_RD_PAGE_REQ;
					}
				}
				else if(u8IskIndex == 3)
				{
					if( (u8Universal_Key[8] != Immo_RecvFrame[0])||
						(u8Universal_Key[9] != Immo_RecvFrame[1])||
						(u8Universal_Key[10] != Immo_RecvFrame[2])||
						(u8Universal_Key[11] != Immo_RecvFrame[3]))
					{
						JOKER_StopImmo();
						u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;
						sphscaCendricCadsLearnImmoState = FOBKEYLEARN_REPEAT_REQ;
						teFobKey_Learn_Feedback_Status = IMMO_LEARN_WR_PAGE_FAIL;
					}
					else
					{
						sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_RD_PAGE_REQ;
					}
				}	
				else if(u8IskIndex == 4)
				{
					if( (u8Universal_Key[12] != Immo_RecvFrame[0])||
						(u8Universal_Key[13] != Immo_RecvFrame[1])||
						(u8Universal_Key[14] != Immo_RecvFrame[2])||
						(u8Universal_Key[15] != Immo_RecvFrame[3]))
					{
						JOKER_StopImmo();
						u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;
						sphscaCendricCadsLearnImmoState = FOBKEYLEARN_REPEAT_REQ;
						teFobKey_Learn_Feedback_Status = IMMO_LEARN_WR_PAGE_FAIL;
					}
					else
					{
						sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSCEIVE_RD_PAGE_REQ;
					}
				}
				else
				{
					u8IskIndex = 0;
					
					if((Immo_RecvFrame[0] != 0)||
						(Immo_RecvFrame[1] != u8WelcomeGuestPollingWakeUpUid[0])||
						(Immo_RecvFrame[2] != u8WelcomeGuestPollingWakeUpUid[1])||
						(Immo_RecvFrame[3] != u8FobKey_Num_Set))
					{
						JOKER_StopImmo();
						u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;
						sphscaCendricCadsLearnImmoState = FOBKEYLEARN_REPEAT_REQ;
						teFobKey_Learn_Feedback_Status = IMMO_LEARN_WR_PAGE_FAIL;
					}
					else
					{
						u8ImmoLearnWaitTimeCnt = 0;
						sphscaCendricCadsLearnImmoState = FOBKEYLEARN_TRANSPONDER_RESET_TWO;
					}
				}
			}
		break;
			
		case FOBKEYLEARN_TRANSPONDER_RESET_TWO:
			u8ImmoLearnWaitTimeCnt++;
			if(u8ImmoLearnWaitTimeCnt == 1)
			{
				Immo_Cmd[0] = AES_SOFT_RST;
				JOKER_StartImmoTransmit(Immo_Cmd , 1);
			}
			else if(u8ImmoLearnWaitTimeCnt >= IMMO_WAIT_MAX_PERIOD)
			{
				sphscaCendricCadsLearnImmoState = FOBKEYLEARN_END_AUTH_GET_IDE_REQ;				
			}
		break;
		

		case FOBKEYLEARN_END_AUTH_GET_IDE_REQ:
			Immo_Cmd[0]	=	AES_START_AUTH;
	   		JOKER_StartImmoTransceive(&Immo_Cmd[0], 5, 32);
			u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD;
			sphscaCendricCadsLearnImmoState = FOBKEYLEARN_END_AUTH_GET_IDE_RES;
		break;

		case FOBKEYLEARN_END_AUTH_GET_IDE_RES:
			u8ImmoLearnWaitTimeCnt--;
			if(u8ImmoLearnWaitTimeCnt == 0)
			{
				JOKER_GetImmoResponse(sImmo_Auth_Message.Id, 32);
				Temp_Val.CHAR_BYTE.High_byte = sImmo_Auth_Message.Id[0];
				Temp_Val.CHAR_BYTE.Mhigh_byte = sImmo_Auth_Message.Id[1];
				Temp_Val.CHAR_BYTE.Mlow_byte = sImmo_Auth_Message.Id[2];
				Temp_Val.CHAR_BYTE.Low_byte = sImmo_Auth_Message.Id[3];
				
				if(Temp_Val.Value != tsFob_LearnBuf.SerialNo)
				{
					JOKER_StopImmo();
					u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;
					sphscaCendricCadsLearnImmoState = FOBKEYLEARN_REPEAT_REQ;
					teFobKey_Learn_Feedback_Status = IMMO_LEARN_GET_IDE_FAIL;
					return;
				}
				
				Temp_Val.Value = GetSysRandTimeCount();

				sImmo_Auth_Message.Challenge[0] = 127^Temp_Val.CHAR_BYTE.High_byte;		//0x7f
				sImmo_Auth_Message.Challenge[1] = 102^Temp_Val.CHAR_BYTE.Mhigh_byte;		//0x66
				sImmo_Auth_Message.Challenge[2] = 182^Temp_Val.CHAR_BYTE.Mlow_byte;		//0xb6
				sImmo_Auth_Message.Challenge[3] = 141^Temp_Val.CHAR_BYTE.Low_byte;		//0x8d
				sImmo_Auth_Message.Challenge[4] = 238^Temp_Val.CHAR_BYTE.Mlow_byte;		//0xee
				sImmo_Auth_Message.Challenge[5] = 34^Temp_Val.CHAR_BYTE.Low_byte;		//0x22
				sImmo_Auth_Message.Challenge[6] = 203^Temp_Val.CHAR_BYTE.High_byte;		//0xcb
				sImmo_Auth_Message.Challenge[7] = 213^Temp_Val.CHAR_BYTE.Mhigh_byte;		//0xd5
				
				keyFobIde = (uint8_t*) &sImmo_Auth_Message.Id[0u];
				
				for (byteIdx = 0u; byteIdx < 4u; byteIdx++)
				{
					tmpData[byteIdx] = keyFobIde[byteIdx];
				}

				for (byteIdx = 0u; byteIdx < 4u; byteIdx++)
				{
					tmpData[byteIdx + 4u] = keyFobIde[byteIdx];
				}

				for (byteIdx = 0u; byteIdx < 8u; byteIdx++)
				{
					tmpData[byteIdx + 8u] = sImmo_Auth_Message.Challenge[byteIdx];
				}

				/* Initialize AES */
				AESInit(tmpData);
				/* Calculate AES Data */
				AES128Enc(u8Universal_Key);

				/* get MAC */
				/* data pre-load zero to be XORed */
				sImmo_Auth_Message.Mac[0u] = 0x00u;
				sImmo_Auth_Message.Mac[1u] = 0x00u;

				AESCrypt(sImmo_Auth_Message.Mac, 2u);

				sphscaCendricCadsLearnImmoState = FOBKEYLEARN_END_AUTH_CHALLENGE_REQ;

			}
		break;
		
		case FOBKEYLEARN_END_AUTH_CHALLENGE_REQ:
			JOKER_StartImmoTransmit(sImmo_Auth_Message.Challenge , 64);
			u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;
			sphscaCendricCadsLearnImmoState = FOBKEYLEARN_END_AUTH_SIGNATURE_REQ;
		break;

		case FOBKEYLEARN_END_AUTH_SIGNATURE_REQ:
			u8ImmoLearnWaitTimeCnt--;
			if(u8ImmoLearnWaitTimeCnt == 0)
			{
				JOKER_StartImmoTransceive(sImmo_Auth_Message.Mac, 16, 48);
				u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;
				sphscaCendricCadsLearnImmoState = FOBKEYLEARN_END_AUTH_SIGNATURE_RES;
			}
		break;

		case FOBKEYLEARN_END_AUTH_SIGNATURE_RES:
			u8ImmoLearnWaitTimeCnt--;
			if(u8ImmoLearnWaitTimeCnt == 0)
			{
				JOKER_GetImmoResponse(tmpData, 48);

				/* Decrypt response */
				AESCrypt(tmpData, 6u);

				for (byteIdx = 0u; byteIdx < 6u; byteIdx++)
				{
					if (tmpData[byteIdx] != 0x00u)
					{
						JOKER_StopImmo();
						u8ImmoLearnWaitTimeCnt = IMMO_WAIT_MAX_PERIOD << 1;
						sphscaCendricCadsLearnImmoState = FOBKEYLEARN_REPEAT_REQ;
						teFobKey_Learn_Feedback_Status = IMMO_LEARN_END_AUTH_FAIL;
						return;
					}
				}

				JOKER_StopImmo();
				UhfFobKeyLearnRxProcess();
				u8FobKey_Information_Management_Feedback = 1;//Success
				//JOKER_StartSleepForced();
				Change_Njj29c0_WorkStatus(lf_ide);

			#ifdef QN_DEBUG
				sdrv_gpio_set_pin_output_level(GPIO_L6,0);	
			#endif
			}
		break;

		case FOBKEYLEARN_REPEAT_REQ:
			u8ImmoLearnWaitTimeCnt--;
			if(u8ImmoLearnWaitTimeCnt == 0)
			{
				u8ImmoLearnWorkCnt++;
				if(u8ImmoLearnWorkCnt >= 5)
				{
					JOKER_StopImmo();
					u8FobKey_Information_Management_Feedback = 2;
					//JOKER_StartSleepForced();
					Change_Njj29c0_WorkStatus(lf_ide);
				}
				else
				{
					u8ImmoLearnWaitTimeCnt = 1;
					sphscaCendricCadsLearnImmoState = FOBKEYLEARN_START_CMD;
				}
			}
		break;
		
		default:
			sphscaCendricCadsLearnImmoState = FOBKEYLEARN_SET_INIT;
		break;
    }
}

