#ifndef RTW_HEADER_ME11_ABI_h_
#define RTW_HEADER_ME11_ABI_h_

#include "Platform_Types.h"
#include "stdint.h"
#include "Adc_rte.h"
#include "HBridge_rte.h"
#include "Pwm_rte.h"
#include "VNQ7E100.h"
#include "IoExp_TCA9539_Api.h"
#include "BTS7020.h"
#include "BTS7012.h"
#include "BTS7120.h"
#include "TLE8108EM.h"
#include "Port_Cfg.h"
#include "TLE75004_Api.h"
#include "BswM_Check_Action.h"
#include "NvM.h"
#include "Com_Cfg.h"

typedef enum
{
  TLE8108EM_ClearMode = 0,
  InputDirctMode = 1,
  ON_Mode = 2,
  OFF_Mode = 3
}TLE8108EM_ChannelMode;

typedef union
{
  struct
  {
    TLE8108EM_ChannelMode IN1       :2;
    TLE8108EM_ChannelMode IN2       :2;
    TLE8108EM_ChannelMode IN3       :2;
    TLE8108EM_ChannelMode IN4       :2;
    TLE8108EM_ChannelMode IN5       :2;
    TLE8108EM_ChannelMode IN6       :2;
    TLE8108EM_ChannelMode IN7       :2;
    TLE8108EM_ChannelMode IN8       :2;
  } SI;

  uint16 U;
} TLE8108EM_Data_T;
/* Definition for custom storage class: Define */
#define DID_0xF260                     70U                       /* Referenced by: '<S1499>/Constant5' */
#define DID_0xF261                     71U                       /* Referenced by: '<S1497>/Constant5' */
#define DID_0xF262                     72U                       /* Referenced by: '<S1510>/Constant6' */
#define DID_0xF263                     73U                       /* Referenced by: '<S1509>/Constant6' */
#define DID_0xF264                     74U                       /* Referenced by: '<S1514>/Constant6' */
#define DID_0xF265                     75U                       /* Referenced by: '<S1513>/Constant6' */
#define DID_0xF269                     79U                       /* Referenced by: '<S1135>/Constant6' */
#define DID_0xF26A                     80U                       /* Referenced by: '<S1133>/Constant8' */
#define DID_0xF26B                     81U                       /* Referenced by: '<S1134>/Constant8' */
#define DID_0xF26D                     83U                       /* Referenced by: '<S1126>/Constant1' */
#define DID_0xF26F                     85U                       /* Referenced by: '<S1138>/Constant1' */
#define DID_0xF273                     89U                       /* Referenced by: '<S1088>/Constant5' */
#define DID_0xF274                     90U                       /* Referenced by: '<S444>/Constant5' */
#define DID_0xF275                     91U                       /* Referenced by: '<S437>/Constant5' */
#define DID_0xF276                     92U                       /* Referenced by: '<S437>/Constant8' */
#define DID_0xF277                     93U                       /* Referenced by: '<S923>/Constant5' */
#define DID_0xF278                     94U                       /* Referenced by: '<S923>/Constant1' */
#define DID_0xF279                     95U                       /* Referenced by: '<S15>/Constant5' */
#define DID_0xF27A                     96U                       /* Referenced by: '<S20>/Constant5' */
#define DID_0xF27B                     97U                       /* Referenced by: '<S13>/Constant5' */
#define DID_0xF27F                     101U                      /* Referenced by: '<S1507>/Constant5' */
#define DID_0xF280                     102U                      /* Referenced by: '<S1512>/Constant5' */
#define DID_0xF281                     103U                      /* Referenced by: '<S1515>/Constant5' */
#define DID_0xF282                     104U                      /* Referenced by: '<S1502>/Constant5' */
#define IODID_0x0x3237                 7U                        /* Referenced by: '<S1129>/Constant1' */

extern uint8 Buffer_DcmDspData_F260H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F261H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F262H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F263H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F264H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F265H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F269H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F26AH[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F26BH[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F26DH[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F26EH[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F26FH[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F273H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F274H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F275H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F276H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F277H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F278H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F279H[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F27AH[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F27BH[ 1 ] ;
extern uint8 Buffer_DcmDspData_F27EH[ 2 ] ;
extern uint8 Buffer_DcmDspData_F27FH[ 1 ] ;
extern uint8 Buffer_DcmDspData_3237[ 1 ]  ;
extern uint8 Buffer_DcmDspData_F281H[ 1 ] ;
extern uint8 Buffer_DcmDspData_F280H[ 1 ] ;
extern uint8 Buffer_DcmDspData_F282H[ 1 ] ;

extern uint8 u8Key_Match_flg;
extern void startAuKeyMatch();

extern uint8 GetHw_KL15A(void);
extern uint8 GetHw_KL15B(void);
extern uint8 GetHw_DrvrDoorLckSts(void);
extern uint8 GetHw_DrvrDoorAjarSts(void);
extern uint8 GetHw_BrkSwLo(void);
extern uint16 GetHw_AccPedCh1Volt(void);
extern uint16 GetHw_ShftPstnSwSts(void);
extern uint16 GetHw_AccPedCh1SuplyVolt(void);
extern uint16 GetHw_AccPedCh2Volt(void);
extern void SetHw_IG1RlyCls(uint8 state);
extern void SetHw_IG2RlyCls(uint8 state);
extern void SetHw_WakeupBMS(uint8 state);
extern uint16 GetHw_BrkPedVolt(void);

//-------------------------------------------------------------------//
/*#######################  New Definition  #########################*/
//------------------------------------------------------------------//
extern uint8 GetHw_BrkSwHi(void);//刹车开关信号（常高）
extern uint8 GetHw_OBCWakeup(void);//OBC硬线唤醒CCU
extern uint8 GetHw_BMSWakeup(void);//BMS硬线唤醒CCU
extern uint8 GetHw_EmgcyShutOff(void);//急停开关
extern uint8 GetHw_HzrdLampSw(void);//危险报警灯开关
extern uint8 GetHw_FrntWshrSw(void);//洗涤开关
extern uint8 GetHw_WiprStopPstnDtct(void);//雨刮停止位检测
extern uint8 GetHw_AlrmHornSw(void);//电喇叭开关
extern uint8 GetHw_PsngrDoorAjarSts(void);//副驾门状态
extern uint8 GetHw_RearFogLampSw(void);//后雾灯开关
extern uint16 GetHw_LoBeamSwSts(void);//位置灯/近光灯开关电压检测
extern uint16 GetHw_HiBeamSwSts(void);//远光灯/超车灯开关电压检测
extern uint16 GetHw_TurnLampSwSts(void);//左右转向灯开关信号检测
extern uint16 GetHw_WiprSwSts(void);//雨刮开关电压检测
extern uint16 GetHw_WiprIntSwSts(void);//雨刮间歇开关电压检测
extern uint16 GetHw_AccPedCh1Volt(void);// 加速踏板     
extern uint16 GetHw_ShftPstnSwSts(void);// 换挡开关输入
extern void SetHw_WiprOn(uint8 state);//雨刮电源（低速）
extern void SetHw_WiprHiSpd(uint8 state);//高速雨刮
extern void SetHw_FrntWshrOn(uint8 state);//前洗涤
extern void SetHw_GlbDoorUnlck(uint8 state);//四门解锁
extern void SetHw_GlbDoorLck(uint8 state);//四门上锁
extern void SetHw_DrvrWinUp(uint8 state);//主驾车窗上升
extern void SetHw_DrvrWinDwn(uint8 state);//主驾车窗下降
extern void SetHw_PsngrWinUp(uint8 state);//副驾车窗上升
extern void SetHw_PsngrWinDwn(uint8 state);//副驾车窗下降
extern void SetHw_PstnLampOn(uint8 state);//位置灯
extern void SetHw_TurnLampOnLeft(uint8 state);//左转向灯
extern void SetHw_TurnLampOnRght(uint8 state);//右转向灯
extern void SetHw_BrkLghtOn(uint8 state);//刹车灯
extern void SetHw_RvrsLampOn(uint8 state);//倒车灯
extern void SetHw_HzrdLampOn(uint8 state);//危险报警灯
extern void SetHw_LoBeamOn(uint8 state);//近光灯
extern void SetHw_HiBeamOn(uint8 state);//远光灯
extern void SetHw_AlrmHornOn(uint8 state);//电喇叭
extern void SetHw_RearFogLampOn(uint8 state);//后雾灯
extern void SetHw_SavePwrEnbl(uint8 state);//节电输出
extern void SetHw_DayRunLghtOn(uint8 state);//日间行车灯
extern void SetHw_CabinLampPWM(uint8 frq,uint8 duty);//室内灯
extern void set_OUT_EXP_D_P27(uint8 stats);  // 高频模块复位信号
extern void set_OUT_EXP_C_P00(uint8 stats);  // 低频模块复位信号 

extern uint8 GetHw_FRPESwSta(void);
extern uint8 GetHw_FLPESwSta(void);
extern uint16 GetHw_RLTurnIndcrVol(void);
extern uint16 GetHw_RRTurnIndcrVol(void);

// TMS
/* 输入 */
extern uint16 get_CabinValtage(void);  // 乘员舱温度
extern uint16 get_EnvValtage(void);   // 环境温度
extern uint16 get_FaceDuctValtage(void); // 吹面风道温度
extern uint16 get_FootDuctValtage(void); // 吹脚风道温度
extern uint16 get_ACCMHighTempValtage(void);  
extern uint16 get_WCCHighTempValtage(void);
extern uint16 get_OHXTempValtage(void);
extern uint16 get_EVAPTempValtage(void);
extern uint16 get_ChillTempValtage(void);
extern uint16 get_MotInletTempValtage(void);
extern uint16 get_EVAPSurfTempValtage(void);
extern uint16 get_SolorValtage(void);
extern uint16 get_WCCHighPressValtage(void);
extern uint16 get_LowPressValtage(void);
extern uint16 get_MixDoorValtage(void);
extern uint16 get_RecircValtage(void);
extern uint16 get_ModeMotorValtage(void);
/* 输出 */ 
extern void set_BlwFan(uint16 Frq,uint16 duty);
extern void set_CoolFan(uint8 frq,uint8 duty);
extern void set_ModeMotor(uint8 p,uint8 n);
extern void set_MixDoor(uint8 p, uint8 n);
extern void set_RecircMotor(uint8 p, uint8 n);
extern void set_PwrHVPart(uint8 u);
extern void set_PwrACPump(uint8 u);
extern void set_PwrFanCabin(uint8 u);
extern void set_PwrSensor(uint8 u);
extern void set_PwrSOV(uint8 u);
extern void set_PwrFanAndPump(uint8 status);
#if 0
extern uint8 GetHw_HiBeamDigSts(void);
extern uint8 GetHw_LoBeamDigSts(void);
#endif
typedef struct
{
uint16 adc2_group0_0;
uint16 adc2_group0_1;
uint16 adc2_group0_2;
}adc2_group0;
typedef struct
{
uint16 adc2_group1_0;
uint16 adc2_group1_1;
uint16 adc2_group1_2;
    uint16 adc2_group1_3;
uint16 adc2_group1_4;
uint16 adc2_group1_5;
    uint16 adc2_group1_6;
uint16 adc2_group1_7;
uint16 adc2_group1_8;
    uint16 adc2_group1_9;
}adc2_group1;
typedef struct
{
uint16 adc2_group2_0;
uint16 adc2_group2_1;
uint16 adc2_group2_2;
uint16 adc2_group2_3;
uint16 adc2_group2_4;
}adc2_group2;
extern adc2_group0 Get_adc2_group0_resultbuffer();
extern adc2_group1 Get_adc2_group1_resultbuffer();
extern adc2_group2 Get_adc2_group2_resultbuffer();
///////////////
#if 0
uint16 GetHw_EPBACurrt(void);//EPB A输出电流检测
uint16 GetHw_EPBBCurrt(void);//EPB B输出电流检测
void SetHw_EPBARels(uint8 state);//EPB A释放控制
void SetHw_EPBAApply(uint8 state);//EPB A拉起控制
void SetHw_EPBBRels(uint8 state);//EPB B释放控制
void SetHw_EPBBApply(uint8 state);//EPB B拉起控制
void SetHw_EPBAEnblPWM(uint8 frq,uint8 duty);//EPB A输出使能控制
void SetHw_EPBBEnblPWM(uint8 frq,uint8 duty);//EPB B输出使能控制
#endif
extern uint8 Get_PSAuthentRes(void);
extern uint8 GetHw_CrashPWMSta(void);
extern uint8 Get_RKEReq(void);
extern uint16 GetHw_TurnIndcrVol(uint8 Sts);
extern void Set_TrunkUnLock(uint8 Sts);
extern void Set_BSDRightCtl(uint8 Sts);
extern void Set_BSDLeftCtl(uint8 Sts);
extern uint16 GetHw_DrvSeatResis(void);
extern uint8 GetHw_DoorAjarRL(void);
extern uint8 GetHw_TrunkSts(void);
extern uint8 GetHw_TrunkLckSts(void);
extern uint8 GetHw_DoorAjarRR(void);
extern uint8 GetHw_TrunkAjarSts(void);
extern uint8 GetHw_HoodAjarSts(void);
extern uint8 Get_KeyPos(void);
extern uint16 GetHw_DrvWinMotorCur(void);
extern uint16 GetHw_DrvWinSwResis(void);
extern uint16 GetHw_DrvPsgWinSwResis(void);
extern uint16 GetHw_PsgWinSwResis(void);
extern uint16 GetHw_PsgWinMotorCur(void);
extern uint16 GetHw_Lightlntst(void);
extern void SetHw_PwrSup(uint8 Sts);
extern void SetHw_RearMirrorHeat(uint8 Sts);
extern void SetHw_BoxLampSta(uint8 Sts);

//  12V蓄电池电压
extern uint16 GetHw_LowBatValtage();
extern uint8 GetHw_FrontFogLampSw(void);// 前雾灯
extern void SetHw_FrontFogLamps(uint8 Sts); // 前雾灯驱动
extern void SetHw_BackLightDrv(uint8 frq,uint8 duty); // 背光灯驱动
extern void SetHw_DrvSeatHeat(uint8 frq,uint8 duty);  // 座椅加热PWM驱动
extern uint16 GetHw_DrvSeatTempFrb(void);   // 座椅加热温度反馈


extern Std_ReturnType NvmVcuBlock01ReadData(uint8 *data, uint8 Length);
extern Std_ReturnType NvmVcuBlock01WriteData(uint8 *data, uint8 Length);
extern Std_ReturnType NvmTmsBlockReadData(uint8 *data, uint8 Length);
extern Std_ReturnType NvmTmsBlockWriteData(uint8 *data, uint8 Length);
extern Std_ReturnType NvmBCmBlock_Imm_ReadData(uint8 *data, uint8 Length) ;
extern Std_ReturnType  NvmBcmBlock_Imm_WriteData(uint8 *data, uint8 Length);//即时存
extern Std_ReturnType NvmBcmBlock02ReadData(uint8 *data, uint8 Length);
extern Std_ReturnType NvmBcmBlock02WriteData(uint8 *data, uint8 Length);
extern boolean BCM_IMMOAuthResp1_EPT_Send_Notication(uint8 *data);//确认0x330 发送
extern boolean INV_IMMO_Req_EPT_Rec_callout();//确认接收到0x338
extern boolean INV_IMMO_Req_EPT_Rec_ClaerFlg();//取消0x338接收标志位 
uint8 Get_EcuWakeupReasn(void);				//控制器唤醒原因
uint8 Set_EcuCommReq(uint8 state);			//允许控制器休眠标志位
uint8 Set_EcuSleepAllow(uint8 state);		//开启网络通信请求标志位
void Set_RtcWakeupTime(uint16 Param);			//	配置RTC唤醒时间

extern void BCM_SKRead(uint8 *data, uint8 length); //SK读取


extern uint16  GetHw_SteerWhlTempFrb(void) ;//方向盘加热温度反馈
extern void SetHw_SteerWhlHeat(uint8 Sts);//方向盘加热驱动
//extern void Dem_SetEventStatus(uint8 EventId,uint8 EventStatus);
extern void SetHw_PwrBlower(uint8 state);//blower
extern uint16 GetHW_VCCAcq(void);  // VCC
extern void Rte_DIDReadData(uint8 data,uint8 didId);
extern uint8 Rte_IOCtrl(uint8 didID);
extern uint8 GetHw_DrvModeSw(void);
extern uint8 GetHw_CreepModeSw(void);
uint8 GetHw_HiBeamDigSts(void);
uint8 GetHw_LoBeamDigSts(void);
#endif
// extern uint8 