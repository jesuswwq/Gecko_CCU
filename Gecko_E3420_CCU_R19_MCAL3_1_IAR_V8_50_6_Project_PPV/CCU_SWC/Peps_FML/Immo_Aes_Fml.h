

/*********************************Copyright (c)*********************************
 ** File Name:
 ** Created By: Ghost_Tiger
 ** Created date:	2017-7-10
 ** Version: 1.0
 ** Descriptions: First version
 **
 ******************************************************************************/
#ifndef __IMMO_AES_FML_H
#define __IMMO_AES_FML_H

#include <types.h>
#include "LoopFifo.h"

#define IMMO_WAIT_MAX_PERIOD	(uint8)(20/2)

struct Immo_Auth_Buff
{
uint8				Id[4];								//»½ÐÑID£¬Ô¿³×UID
uint8				Challenge[8];						// 8×Ö½ÚËæ»úÊý
uint8				Use_SecretKey[16];					//Ô¿³×ÃØÔ¿
uint8				Mac[2];
};


typedef enum
{
	IMMO_SETTING = 0x00u,
	IMMO_START_CMD,
	IMMO_TRANSCEIVE_GET_IDE_REQ,
	IMMO_TRANSCEIVE_GET_IDE_RES,
	IMMO_TRANS_CHALLENGE_REQ,
	IMMO_TRANS_CHALLENGE_RES,
	IMMO_TRANSCEIVE_SIGNATURE_REQ,
	IMMO_TRANSCEIVE_SIGNATURE_RES,
	IMMO_REPEAT_AUTH_STATE,
	IMMO_AUTH_STATE_WAIT,
	IMMO_AUTH_OK,
	IMMO_AUTH_FAIL,
} phscaCendricCadsUC_Immo_States_t;

typedef enum
{
	FOBKEYLEARN_SET_INIT = 0x00u,
	FOBKEYLEARN_START_CMD,

	FOBKEYLEARN_TRANSCEIVE_GET_IDE_REQ,
	FOBKEYLEARN_TRANSCEIVE_GET_IDE_RES,

	FOBKEYLEARN_TRANSPONDER_RESET_ONE,
	
	FOBKEYLEARN_TRANSCEIVE_XMA_WAIT_REQ,
	FOBKEYLEARN_TRANSCEIVE_XMA_WAIT_RES,

	FOBKEYLEARN_TRANSCEIVE_WR_PAGE_REQ,
	FOBKEYLEARN_TRANSCEIVE_WR_PAGE_RES,
	FOBKEYLEARN_TRANS_WR_DATA_REQ,
	FOBKEYLEARN_TRANS_WR_DATA_RES,
	
	FOBKEYLEARN_TRANSCEIVE_RD_PAGE_REQ,
	FOBKEYLEARN_TRANSCEIVE_RD_PAGE_RES,

	FOBKEYLEARN_TRANSPONDER_RESET_TWO,

	FOBKEYLEARN_END_AUTH_GET_IDE_REQ,
	FOBKEYLEARN_END_AUTH_GET_IDE_RES,
			
	FOBKEYLEARN_END_AUTH_CHALLENGE_REQ,

	FOBKEYLEARN_END_AUTH_SIGNATURE_REQ,

	FOBKEYLEARN_END_AUTH_SIGNATURE_RES,

	FOBKEYLEARN_REPEAT_REQ,
} FobKeyLearn_Immo_States_t;

typedef enum
{
	IMMO_LEARN_RUNNING = 0x00u,
	IMMO_LEARN_MAX_NUM_LIMIT,
	IMMO_LEARN_GET_IDE_FAIL,
	IMMO_LEARN_WR_PAGE_FAIL,
	IMMO_LEARN_END_AUTH_FAIL,
	IMMO_LEARN_OK,
} Immo_FeedBack_States_t;

extern phscaCendricCadsUC_Immo_States_t sphscaCendricCadsUCImmoState;

extern FobKeyLearn_Immo_States_t sphscaCendricCadsLearnImmoState;

extern uint8 u8ImmoLearnWorkCnt;

extern Immo_FeedBack_States_t Get_Fobs_Learn_Status(void);
extern void Change_Fobs_Learn_Status(Immo_FeedBack_States_t sta);

extern void NJJ29C0_Immo_Auth(void);
extern void NJJ29C0_Immo_Check_Uid(void);
extern void FobKey_Immo_Learn_Process(void);

#endif

