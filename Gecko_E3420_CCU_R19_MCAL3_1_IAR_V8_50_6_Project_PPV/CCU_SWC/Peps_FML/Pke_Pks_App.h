

/*********************************Copyright (c)*********************************
 ** File Name:
 ** Created By: Ghost_Tiger
 ** Created date:	2017-7-10
 ** Version: 1.0
 ** Descriptions: First version
 **
 ******************************************************************************/
#ifndef __PEPS_APP_H
#define __PEPS_APP_H
#include <types.h>
#include "UHF_FML.h"
#include "Platform_cfg.h"

#define WUPA_ID 				(uint32)0X35C9872E

#define PEPS_LF_CALIBRATION_CMD 			(uint8)0x00
#define PS_LF_CMD 							(uint8)0x10
#define PE_PILOT_LF_CMD 					(uint8)0x11
#define PE_COPILOT_LF_CMD 					(uint8)0x12

#define WELCOMEGUEST_AUTH_LF_CMD 			(uint8)0x14
#define WELCOMEGUEST_PILOT_RSSI_LF_CMD 		(uint8)0x15
#define WELCOMEGUEST_COPILOT_RSSI_LF_CMD 	(uint8)0x16

#define TRAVERSAL_CNT			(uint8)2 // ï¿½ï¿½ï¿½LFÉ¨ï¿½ï¿½ï¿½ï¿½ï¿?

#define DR_DOOR_ANT 			(uint8)2	   // ï¿½ï¿½ï¿½ï¿½Ê»ï¿½Å°ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½
#define CODR_DOOR_ANT			(uint8)3	   // ï¿½ï¿½ï¿½ï¿½Ê»ï¿½Å°ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½
#define CAR_FRONT_ROW_ANT		(uint8)4 // ï¿½ï¿½ï¿½ï¿½Ç°ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½

#define LF_DRIVE_CURRENT		25	   // 15.625 * (25+1) = 406.25MA
#define LF_FRONTROW_CURRENT 	51 // 15.625 * (51+1) = 812.5MA

#define CW_LENGTH				(uint8)0x08 // ï¿½Ø²ï¿½ï¿½ï¿½ï¿½Í³ï¿½ï¿½ï¿½

#define PEPS_TX_MAX_COUNT			(uint8)2

#define PE_LF_TX_MAX_PERIOD			(uint8)(120/2) //PEµÍÆµ·¢ËÍ¼ä¸ôÖÜÆÚ
#define RSSI_LF_TX_MAX_PERIOD		(uint8)(60/2) // RSSIµÍÆµ·¢ËÍ¼ä¸ôÖÜÆÚ


#define LEFTSIDE_ANT_INDEX		0
#define RIGHTSIDE_ANT_INDEX 	1
#define INDOOR_ANT_INDEX		2

#define RSSI_CARRIER_OFF_LEN		(uint8)4//500us
#define RSSI_CARRIER_ON_LEN			(uint8)62 //6.4ms

#define WELCOMEGUEST_POLLING_CYCLE01 (uint16)250  // 250ms
#define WELCOMEGUEST_POLLING_CYCLE02 (uint16)1000 // 1000ms
#define WELCOMEGUEST_POLLING_CYCLE03 (uint16)1250 // 1250ms

#define L_DOORANT_RSSI_Z4_LIMIT 0.002f

#define L_DOORANT_RSSI_Z3_LIMIT 0.005f

#define L_DOORANT_RSSI_Z2_LIMIT 0.026f

#define L_DOORANT_RSSI_Z1_LIMIT 1.471f

#define R_DOORANT_RSSI_Z4_LIMIT 0.001f

#define R_DOORANT_RSSI_Z3_LIMIT 0.003f

#define R_DOORANT_RSSI_Z2_LIMIT 0.014f

#define R_DOORANT_RSSI_Z1_LIMIT 0.668f

#define PE_L_DOORANT_RSSI_LIMIT 0.325f

#define PE_R_DOORANT_RSSI_LIMIT 0.226f

#define PS_ANT_RSSI_LIMIT 		0.227f

#define PS_FUN_POLLING_CYCYE	(uint16)60

#define LF_DIAG_CYCYE			(uint16)(5000 / 2)

#define LF_RSSI_CACHE_LEN		16

typedef enum // ï¿½ï¿½Æµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
{
JOKER_INIT, 										// NJJ29C0ï¿½ï¿½Ê¼ï¿½ï¿½
JOKER_NORMAL,										// NJJ29C0ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½×´Ì¬
JOKER_FAIL, 										// NJJ29C0ï¿½ï¿½Ê¼ï¿½ï¿½Ê§ï¿½ï¿½
} Joker_Work_State;


typedef enum 
{
lf_ide = 0, 
lf_pilot_pe, 
lf_copilot_pe, 
lf_ps, 
lf_prohibit_key, 
lf_polling_lock, 
lf_polling_unlock, 
immo_diag_uid, 
lf_diag, 
lf_calibration, 
immo_ps, 
immo_learn_fobkey, 
} lf_handle_state;


struct LF_Auth_Buff
{
uint8			Id[4];								// ï¿½ï¿½ï¿½ï¿½IDï¿½ï¿½Ô¿ï¿½ï¿½UID
uint8			Command;
uint8			Random[4];							// 4ï¿½Ö½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?seed
uint8			Sum;								// crc8
};


struct LF_FobLocate_Buff
{
uint8			Command;

// uint8				ReadyUse_Ide_Num;					//ï¿½ï¿½ï¿½Ê¹ï¿½Ãµï¿½Ò£ï¿½Ø±ï¿½ï¿½
uint8			Sum;								// crc
};


extern BITBYTE	tsLfAntDiagStatus;

#define LF_ANT_CHANNEL_ONE_STATUS tsLfAntDiagStatus.BITS.B0_1
#define LF_ANT_CHANNEL_TWO_STATUS tsLfAntDiagStatus.BITS.B2_3
#define LF_ANT_CHANNEL_THREE_STATUS tsLfAntDiagStatus.BITS.B4_5
#define LF_ANT_CHANNEL_FOUR_STATUS tsLfAntDiagStatus.BITS.B6_7

extern FLOAT_UNION InCar_CurRssiCalcVal;
extern FLOAT_UNION Lf_Door_CurRssiCalcVal;
extern FLOAT_UNION Rf_Door_CurRssiCalcVal;
extern uint8	u8HitagAuthPass;

extern uint8_t	u8PollingUnlockStep;

extern float	Lf_DoorAnt_Rssi_Limit;
extern float	Rf_DoorAnt_Rssi_Limit;
extern float	Ps_Ant_Rssi_Limit;

extern Joker_Work_State u8Njj29c0_WorkStatus;
extern lf_handle_state lfapp_work_sta;

extern uint8 Vehicle_Calibration_Ant;
extern uint16 Vehicle_Calibration_Num;

extern uint8_t g_datCan1Tx_0x330[8];
extern uint8_t u8_Auth_KeyTest_Feedback;
void Change_Njj29c0_WorkStatus(lf_handle_state sta);
lf_handle_state Get_Njj29c0_WorkStatus(void);
uint8 GetNJJ29C0InitCompleteStatus(void);
void NJJ29C0_Task(void);
void Nck2910_Task(void);
void ScanBodyInputSign(void);
void PEPS_Module_Init(void);
void Spi2_Test(void);
void SetVehicleCalibrationPara(uint8 * para);

#endif

