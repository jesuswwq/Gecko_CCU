
#ifndef __UHF_FML_H
#define __UHF_FML_H

#include <types.h>
#include "aes.h"
#include "aes_cf.h"

#define MAX_TRANSMITTERS		(uint32_t)4U //×î´óÔ¿³×ÊýÁ¿

#define KEY_BIT_SIZE			128	//ÃØÔ¿Î»³¤

#define WINDOW_SIZE 			(uint32_t)256U	//Í¬²½ÖµµÚÒ»´°¿Ú

#define BUFFER_LEN				(uint8_t)(MAX_TRANSMITTERS * 25)

#define SK_CODE_SAVE_ADDR 				(uint8_t)0x00

#define TRANSMITTER_ID_SAVE_ADDR 		(uint8_t)0x10//×î½üÊ¹ÓÃµÄÁ½¸öÒ£¿ØÆ÷ID±£´æµØÖ·

#define TRANSMITTERS_EEPROM_ADDR 		(uint8_t)0x18//Ò£¿ØÐÅÏ¢±£´æµØÖ·AÇø

#define TRANSMITTERS_EEPROM_BAK_ADDR 	(uint8_t)0x80//Ò£¿ØÐÅÏ¢±£´æµØÖ·BÇø(±¸·ÝÇøÓò)

#define PABS_LONGPRESS_MAX		14u

#define DOUBLE_CLICK_MAXIMUM_TIME 100u // 500MS

#define NOT_PRESSED 				0u
#define SHORT_PRESSED 				1u
#define LONG_PRESSED 				2u
#define DOUBLE_PRESSED 				3u

#define FOBKEY_RKE_IDLE				0x00

#define FOBKEY_RKE_UNLOCK			0x11
#define FOBKEY_RKE_LOCK				0x12
#define FOBKEY_RKE_FINDCAR			0x13

#define FOBKEY_RKE_UNLOCK_REPEAT	0x21
#define FOBKEY_RKE_SEEK_CAK			0x22
#define FOBKEY_RKE_TRUNK_UNLOCK		0x23

#define FOBKEY_RKE_OPENWINDOW		0x31
#define FOBKEY_RKE_CLOSEWINDOW		0x32
#define FOBKEY_RKE_TRUNK_ALWAYS		0x33

typedef union
{
    uint8_t DATA_BYTE;
	
    struct BIT
    {
        unsigned B0: 1, B1: 1, B2: 1, B3: 1, B4: 1, B5: 1, B6: 1, B7: 1;
    } BIT;

    struct BITS
    {
        unsigned B0_1: 2, B2_3: 2, B4_5: 2, B6_7: 2;
    } BITS;

	struct BITS1
    {
        unsigned B0_4: 5, B5_6: 2, B7: 1;
    } BITS1;

    struct BITS2
    {
        unsigned B0_4: 5, B5: 1, B6: 1, B7: 1;
    } BITS2;
}
//-------------------------------------------------------------------------
BITBYTE;

//! Command message payload fields including the CMAC value.
typedef struct 
{
uint8_t			Fun;
uint32_t 			SerialNo;							//ÐòÁÐºÅ  
uint8_t			CommandCode;						//¸ßÆµÃüÁî  
uint32_t 			Sync_Counter;						//Í¬²½¼ÆÊýÖµ
uint8_t			Mac[6]; 							//¹öÂë   6
} Rke_CommandMessage;

typedef struct 
{
uint8_t			PkeCmd;
uint8_t			Data[16]; 							
uint8_t			Data_len;
} Pke_CommandMessage;


//! Collects info for one associated transmitter.
typedef struct 
{
uint32_t 		SerialNo;							//IDºÅ
uint32_t 		Sync_Counter;						//Í¬²½Öµ
uint8_t			SecretKey[16];
uint8_t 		FobKeyEn;							//½ûÄÜ±êÊ¶
} TransmitterInfo;


typedef enum //¸ßÆµ¹¦ÄÜÃüÁî
{
	RKE_NULL,
	RKE_UNLOCK, 										//Ò£¿Ø±ÕËø
	RKE_LOCK,											//Ò£¿ØÉÏËø
	RKE_TRUNK,											//Ò£¿ØÑ°³µ
} UHF_COMMAND;


//×Ô¶¨ÒåÊý¾Ý½á¹¹Ìå
typedef struct 
{
	uint8_t				Fifo_Data[BUFFER_LEN];	
	uint8_t				FobKeyCount;
	uint8_t				Crc8;							
} EEPROM_Save_Buffer;


typedef struct 
{
uint8_t				Use_Id[4];							//Ô¿³×ID
uint8_t				Use_Seed[4];					//Ô¿³×Ëæ»úÊýChallenge
uint8_t				Use_SecretKey[16];					//Ô¿³×ÃØÔ¿
uint8_t				Calc_Mac_Code[6];					//¼ÆËã¹öÂëÖµ
} Aes128_Buffer;


extern BITBYTE	tuHf_Func01;
#define FRAME_LEN						tuHf_Func01.BITS1.B0_4 //ä¾¦é•¿åº?
#define FOBKEY_NUM						tuHf_Func01.BITS1.B5_6 //é¥æŽ§ç¼–å·
#define FRAME_TYPE						tuHf_Func01.BITS1.B7	//rke/peps


extern BITBYTE	tuHf_Func02;
#define FRAME_LF_CMD					tuHf_Func02.BITS1.B0_4 //ä½Žé¢‘ä¾¦å‘½ä»?
#define RECENT_FOBKEY_NUM				tuHf_Func02.BITS1.B5_6 //æœ€è¿‘ä½¿ç”¨é¥æŽ§ç¼–å?
#define BAT_VOL_LOW						tuHf_Func02.BITS1.B7	//ç”µåŠ›çŠ¶æ€?


extern BITBYTE	tuHf_Bid;
#define KEY_CMD							tuHf_Bid.BITS2.B0_4	//cmd
#define KEY_PRESS_IND					tuHf_Bid.BITS2.B5	//æŒ‰é”®æ˜¯å¦é‡Šæ”¾
#define HOPPING_FRQ_IND					tuHf_Bid.BITS2.B6  //è·³é¢‘æŒ‡ç¤º
#define BAT_VOL_LOW_IND					tuHf_Bid.BITS2.B7 //ç”µåŠ›çŠ¶æ€?

extern TransmitterInfo tsTransmitters[MAX_TRANSMITTERS];
extern Aes128_Buffer tsAes_Crypt_Buffer;
extern uint8_t	u8TransmitterCount;

extern uint8_t u8Universal_Key[16];

extern uint8_t  bWaitAllFobKey_A_WakeUp;
extern uint8_t  bWaitAllFobKey_B_WakeUp;

extern uint16_t  u16FobKeyA_Updata_Cnt;
extern uint16_t  u16FobKeyB_Updata_Cnt;

extern TransmitterInfo tsFob_LearnBuf;
extern uint16_t u16UhfFrameRkeAuthOkCount;
extern uint16_t u16UhfFramePkeAuthOkCount;
extern uint8_t u8PlanUseFobKeyUid_Index[2];
extern uint32_t u32PlanUseFobKeyUid[2];

void SetFobKeyEnterMatchPattern(void);
void SetFobKeyEnterErase(void);
uint8_t GetTransmitterCountVal(void);
uint8_t GetVariableFobKeyVoltStatus(void);
uint32_t	GetSysRandTimeCount(void);
void ClrRemotButtonCmd(void);
void All_FobKey_Lift_En(void);
uint8_t GetFobKeyLearnCompleteStatus(void);
uint8_t GetCurUseSecretKey(uint32_t Id, uint8_t * buf);
void UhfRxHandler(void);
void InitFobKeyEepromMessage(void);
uint8_t GetFobKeyId(void);
void ExitFobKeyEnterMatchPattern(void);

void SetPs_AuthFobStatus(uint8_t sta);
void SetPe_AuthFobStatus(uint8_t sta);

void UhfFobKeyLearnRxProcess(void);

#endif

