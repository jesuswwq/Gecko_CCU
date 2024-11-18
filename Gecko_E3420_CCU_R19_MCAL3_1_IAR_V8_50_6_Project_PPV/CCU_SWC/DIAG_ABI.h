#ifndef RTW_HEADER_DIAG_ABI_h_
#define RTW_HEADER_DIAG_ABI_h_

#include "Platform_Types.h"
#include "Dem_Cfg.h"
//#include "NvM_Cfg.h"

/* 动态数据DID */
#define DID_0xF201    2U
#define DID_0xF202    3U
#define DID_0xF203    4U
#define DID_0xF205    6U
#define DID_0xF206    7U
#define DID_0xF251    8U
#define DID_0xF252    9U
#define DID_0xF253    10U
#define DID_0xF254    11U
#define DID_0xF255    12U
#define DID_0xF256    13U
#define DID_0xF257    14U
#define DID_0xF258    15U
#define DID_0xF259    16U
#define DID_0xF25C    19U
#define DID_0xF25D    20U
#define DID_0xF25E    21U
#define DID_0xF25F    22U
#define DID_0xF210    23U
#define DID_0xF211    24U
#define DID_0xF212    25U
#define DID_0xF213    26U
#define DID_0xF215    28U
#define DID_0xF216    29U
#define DID_0xF228    47U

#define DID_0xF204    5U
#define DID_0xF214    27U
#define DID_0xF21D    36U
#define DID_0xF21E    37U
#define DID_0xF21F    38U
#define DID_0xF220    39U

/* 静态数据DID */
#define DID_0xF187    3U
#define DID_0xF191    4U
#define DID_0xF188    5U
#define DID_0xF180    6U
#define DID_0xF163    7U

extern uint8 Buffer_DcmDspData_0xF201H[2];
extern uint8 Buffer_DcmDspData_0xF202H[1];
extern uint8 Buffer_DcmDspData_0xF203H[6];
extern uint8 Buffer_DcmDspData_0xF205H[1];
extern uint8 Buffer_DcmDspData_0xF206H[1];
extern uint8 Buffer_DcmDspData_0xF251H[1];
extern uint8 Buffer_DcmDspData_0xF252H[2];
extern uint8 Buffer_DcmDspData_0xF253H[2];
extern uint8 Buffer_DcmDspData_0xF254H[2];
extern uint8 Buffer_DcmDspData_0xF255H[2];
extern uint8 Buffer_DcmDspData_0xF256H[2];
extern uint8 Buffer_DcmDspData_0xF257H[2];
extern uint8 Buffer_DcmDspData_0xF258H[2];
extern uint8 Buffer_DcmDspData_0xF259H[2];
extern uint8 Buffer_DcmDspData_0xF25CH[1];
extern uint8 Buffer_DcmDspData_0xF25DH[2];
extern uint8 Buffer_DcmDspData_0xF25EH[1];
extern uint8 Buffer_DcmDspData_0xF25FH[1];
extern uint8 Buffer_DcmDspData_0xF210H[1];
extern uint8 Buffer_DcmDspData_0xF211H[2];
extern uint8 Buffer_DcmDspData_0xF212H[2];
extern uint8 Buffer_DcmDspData_0xF213H[1];
extern uint8 Buffer_DcmDspData_0xF215H[2];
extern uint8 Buffer_DcmDspData_0xF216H[2];
extern uint8 Buffer_DcmDspData_0xF228H[1];

extern uint8 Buffer_DcmDspData_F187[16];
extern uint8 Buffer_DcmDspData_F191[21];
extern uint8 Buffer_DcmDspData_F188[19];
extern uint8 Buffer_DcmDspData_F180[19];
extern uint8 Buffer_DcmDspData_F163[19];
extern uint8 Buffer_DcmDspData_0xF204H[3];
extern uint8 Buffer_DcmDspData_0xF220H[1];
extern uint8 Buffer_DcmDspData_0xF21DH[1];
extern uint8 Buffer_DcmDspData_0xF21EH[1];
extern uint8 Buffer_DcmDspData_0xF21FH[1];
extern uint8 Buffer_DcmDspData_0xF214H[2];

/* 20241025新增DTC设置 */
extern void App_Call_Event_DTC_0x10A796_SetEventStatus(uint8 FaultStatus);  //ESC 1级故障
extern void App_Call_Event_DTC_0x10A896_SetEventStatus(uint8 FaultStatus);  //ESC 2级故障
extern void App_Call_Event_DTC_0x10A996_SetEventStatus(uint8 FaultStatus);  //ESC 3级故障
extern void App_Call_Event_DTC_0x10AA96_SetEventStatus(uint8 FaultStatus);  //ESC 4级故障
extern void App_Call_Event_DTC_0x10AB96_SetEventStatus(uint8 FaultStatus);  //ESC 5级故障
extern void App_Call_Event_DTC_0x10A296_SetEventStatus(uint8 FaultStatus);  //EHB 1级故障
extern void App_Call_Event_DTC_0x10A396_SetEventStatus(uint8 FaultStatus);  //EHB 2级故障
extern void App_Call_Event_DTC_0x10A496_SetEventStatus(uint8 FaultStatus);  //EHB 3级故障
extern void App_Call_Event_DTC_0x10A596_SetEventStatus(uint8 FaultStatus);  //EHB 4级故障
extern void App_Call_Event_DTC_0x10A696_SetEventStatus(uint8 FaultStatus);  //EHB 5级故障
extern void App_Call_Event_DTC_0x100496_SetEventStatus(uint8 FaultStatus);  //互锁故障-压缩机（次要互锁）
extern void App_Call_Event_DTC_0x100F16_SetEventStatus(uint8 FaultStatus);  //互锁信号错误-电路电压低于阈值（次要互锁）
extern void App_Call_Event_DTC_0x100D16_SetEventStatus(uint8 FaultStatus);  //互锁信号错误-电路电压低于阈值或BMS互锁（主要互锁）
extern void App_Call_Event_DTC_0x100F17_SetEventStatus(uint8 FaultStatus);  //互锁信号错误-电路电压高于阈值（次要互锁）
extern void App_Call_Event_DTC_0x100E17_SetEventStatus(uint8 FaultStatus);  //互锁信号错误-电路电压高于阈值（主要互锁）
extern void App_Call_Event_DTC_0x10AC83_SetEventStatus(uint8 FaultStatus);  //P挡检测失效

extern void App_Call_Event_DTC_0xC11282_SetEventStatus(uint8 FaultStatus);  //BMS Checksum or AliveCnt fail
extern void App_Call_Event_DTC_0xC12282_SetEventStatus(uint8 FaultStatus);  //ESC Checksum or AliveCnt fail
extern void App_Call_Event_DTC_0xD10282_SetEventStatus(uint8 FaultStatus);  //FCM Checksum or AliveCnt faill
extern void App_Call_Event_DTC_0xD11282_SetEventStatus(uint8 FaultStatus);  //CRRR Checksum or AliveCnt fail
extern void App_Call_Event_DTC_0xD10E82_SetEventStatus(uint8 FaultStatus);  //PP Checksum or AliveCnt fail
extern void App_Call_Event_DTC_0xC13082_SetEventStatus(uint8 FaultStatus);  //EPS Checksum or AliveCnt fail
extern void App_Call_Event_DTC_0xC15182_SetEventStatus(uint8 FaultStatus);  //SRS Checksum or AliveCnt fail
extern void App_Call_Event_DTC_0xD11682_SetEventStatus(uint8 FaultStatus);  //ICU Checksum or AliveCnt fail
extern void App_Call_Event_DTC_0xC19882_SetEventStatus(uint8 FaultStatus);  //TBOX Checksum or AliveCnt fail
extern void App_Call_Event_DTC_0xD10882_SetEventStatus(uint8 FaultStatus);  //MCU Checksum or AliveCnt faill
extern void App_Call_Event_DTC_0xC10F82_SetEventStatus(uint8 FaultStatus);  //ACCM Checksum or AliveCnt fail
extern void App_Call_Event_DTC_0xC23082_SetEventStatus(uint8 FaultStatus);  //PTC Checksum or AliveCnt fail
extern void App_Call_Event_DTC_0xD11D82_SetEventStatus(uint8 FaultStatus);  //HU Checksum or AliveCnt fail
extern void App_Call_Event_DTC_0xC14682_SetEventStatus(uint8 FaultStatus);  //IPU Checksum or AliveCnt fail
extern void App_Call_Event_DTC_0xC13182_SetEventStatus(uint8 FaultStatus);  //EHB Checksum or AliveCnt fail
extern void App_Call_Event_DTC_0xC24082_SetEventStatus(uint8 FaultStatus);  //SCS Checksum or AliveCnt faill
extern void App_Call_Event_DTC_0xC27082_SetEventStatus(uint8 FaultStatus);  //CCP Checksum or AliveCnt faill

/* 20241025新增DTC获取，通信诊断相关 */
extern uint8 App_Call_Event_DTC_0xC13187_GetEventStatus(void); // Lost Communication with EHB 
extern uint8 App_Call_Event_DTC_0xC24087_GetEventStatus(void); // Lost Communication with SCS
extern uint8 App_Call_Event_DTC_0xC27087_GetEventStatus(void); // Lost Communication with CCP


/* DTC 状态设置 */
extern void App_Call_Event_DTC_0x100083_SetEventStatus(uint8 FaultStatus);  //加速踏板信号采集差异故障
extern void App_Call_Event_DTC_0x100116_SetEventStatus(uint8 FaultStatus);  //加速踏板1电压采集过低
extern void App_Call_Event_DTC_0x100117_SetEventStatus(uint8 FaultStatus);  //加速踏板1电压采集过高
extern void App_Call_Event_DTC_0x100316_SetEventStatus(uint8 FaultStatus);  //加速踏板2电压采集过低
extern void App_Call_Event_DTC_0x100317_SetEventStatus(uint8 FaultStatus);  //加速踏板2电压采集过高
extern void App_Call_Event_DTC_0x100D16_SetEventStatus(uint8 FaultStatus);  //联锁信号错误-电路电压低于阈值
extern void App_Call_Event_DTC_0x100D17_SetEventStatus(uint8 FaultStatus);  //联锁信号错误-电路电压高于阈值
extern void App_Call_Event_DTC_0x101201_SetEventStatus(uint8 FaultStatus);  //传感器供电电压误差(5V1,5V2)-一般电气故障
extern void App_Call_Event_DTC_0x101501_SetEventStatus(uint8 FaultStatus);  //数字输出错误-一般电气故障
extern void App_Call_Event_DTC_0x101601_SetEventStatus(uint8 FaultStatus);  //PWM碰撞故障
extern void App_Call_Event_DTC_0x101701_SetEventStatus(uint8 FaultStatus);  //pwm输出错误
extern void App_Call_Event_DTC_0x101D68_SetEventStatus(uint8 FaultStatus);  //碰撞故障（CAN信号）
extern void App_Call_Event_DTC_0x102093_SetEventStatus(uint8 FaultStatus);  //BMS响应超时
extern void App_Call_Event_DTC_0x10211A_SetEventStatus(uint8 FaultStatus);  //高压系统绝缘故障
extern void App_Call_Event_DTC_0x102496_SetEventStatus(uint8 FaultStatus);  //BMS2级故障
extern void App_Call_Event_DTC_0x102596_SetEventStatus(uint8 FaultStatus);  //BMS3级故障
extern void App_Call_Event_DTC_0x102696_SetEventStatus(uint8 FaultStatus);  //BMS-SOC值过低
extern void App_Call_Event_DTC_0x102796_SetEventStatus(uint8 FaultStatus);  //BMS紧急下电
extern void App_Call_Event_DTC_0x103093_SetEventStatus(uint8 FaultStatus);  //Dcs响应超时
extern void App_Call_Event_DTC_0x103196_SetEventStatus(uint8 FaultStatus);  //Dcs直流充电故障
extern void App_Call_Event_DTC_0x103296_SetEventStatus(uint8 FaultStatus);  //直流充电插枪信号故障
extern void App_Call_Event_DTC_0x103396_SetEventStatus(uint8 FaultStatus);  //Dcs充电请求故障
extern void App_Call_Event_DTC_0x103496_SetEventStatus(uint8 FaultStatus);  //Dcs充电故障
extern void App_Call_Event_DTC_0x104093_SetEventStatus(uint8 FaultStatus);  //DCC响应超时
extern void App_Call_Event_DTC_0x103996_SetEventStatus(uint8 FaultStatus);  //DCC3级故障
extern void App_Call_Event_DTC_0x104196_SetEventStatus(uint8 FaultStatus);  //DCC4级故障
extern void App_Call_Event_DTC_0x104296_SetEventStatus(uint8 FaultStatus);  //DCC模式错误
extern void App_Call_Event_DTC_0x104396_SetEventStatus(uint8 FaultStatus);  //DCC输入电压过低
extern void App_Call_Event_DTC_0x104496_SetEventStatus(uint8 FaultStatus);  //电机控制器输入电压过低故障
extern void App_Call_Event_DTC_0x104696_SetEventStatus(uint8 FaultStatus);  //低压蓄电池SOC低故障
extern void App_Call_Event_DTC_0x104796_SetEventStatus(uint8 FaultStatus);  //低压蓄电池SOH低
extern void App_Call_Event_DTC_0x104896_SetEventStatus(uint8 FaultStatus);  //低压蓄电池过温故障
extern void App_Call_Event_DTC_0x105093_SetEventStatus(uint8 FaultStatus);  //AC充电BMS响应超时
extern void App_Call_Event_DTC_0x105196_SetEventStatus(uint8 FaultStatus);  //车载充电机-4级故障
extern void App_Call_Event_DTC_0x105496_SetEventStatus(uint8 FaultStatus);  //车载充电机连接故障
extern void App_Call_Event_DTC_0x105596_SetEventStatus(uint8 FaultStatus);  //车载充电机S2无法闭合
extern void App_Call_Event_DTC_0x105693_SetEventStatus(uint8 FaultStatus);  //车载充电器请求异常故障
extern void App_Call_Event_DTC_0x105796_SetEventStatus(uint8 FaultStatus);  //BMS实际SOC值过低
extern void App_Call_Event_DTC_0x105896_SetEventStatus(uint8 FaultStatus);  //BMS允许放电电流过小
extern void App_Call_Event_DTC_0x105996_SetEventStatus(uint8 FaultStatus);  //BMS上报输出过载
extern void App_Call_Event_DTC_0x105B96_SetEventStatus(uint8 FaultStatus);  //BMS交流充状态异常
extern void App_Call_Event_DTC_0x105C96_SetEventStatus(uint8 FaultStatus);  //车载充电机模式错误
extern void App_Call_Event_DTC_0x108186_SetEventStatus(uint8 FaultStatus);  //wrong content in Gear message-Signal Invalid
extern void App_Call_Event_DTC_0x108286_SetEventStatus(uint8 FaultStatus);  //车速信号错误
extern void App_Call_Event_DTC_0x108486_SetEventStatus(uint8 FaultStatus);  //系统电源模式无效
extern void App_Call_Event_DTC_0x109077_SetEventStatus(uint8 FaultStatus);  //电机控制器响应错误
extern void App_Call_Event_DTC_0x109196_SetEventStatus(uint8 FaultStatus);  //电机控制器1级故障
extern void App_Call_Event_DTC_0x109296_SetEventStatus(uint8 FaultStatus);  //电机控制器2级故障
extern void App_Call_Event_DTC_0x109396_SetEventStatus(uint8 FaultStatus);  //电机控制器3级故障
extern void App_Call_Event_DTC_0x109496_SetEventStatus(uint8 FaultStatus);  //电机控制器4级故障
extern void App_Call_Event_DTC_0x10A182_SetEventStatus(uint8 FaultStatus);  //VCU-Counter计数故障
extern void App_Call_Event_DTC_0x102A84_SetEventStatus(uint8 FaultStatus);  //BMS单体电压过低
extern void App_Call_Event_DTC_0x100517_SetEventStatus(uint8 FaultStatus);  //加速踏板1和2采集均故障
extern void App_Call_Event_DTC_0x100696_SetEventStatus(uint8 FaultStatus);  //制动踏板1和2采集均故障
extern void App_Call_Event_DTC_0x105A96_SetEventStatus(uint8 FaultStatus);  //车载充电机错误
extern void App_Call_Event_DTC_0x101301_SetEventStatus(uint8 FaultStatus);  //模拟输入诊断故障
extern void App_Call_Event_DTC_0x101401_SetEventStatus(uint8 FaultStatus);  //数字输入诊断故障
extern void App_Call_Event_DTC_0x900011_SetEventStatus(uint8 FaultStatus);  //Left turn signal Short to gnd
extern void App_Call_Event_DTC_0x900013_SetEventStatus(uint8 FaultStatus);  //Left turn signal open
extern void App_Call_Event_DTC_0x900111_SetEventStatus(uint8 FaultStatus);  //Right turn signal short to gnd
extern void App_Call_Event_DTC_0x900113_SetEventStatus(uint8 FaultStatus);  //Right turn signal open
extern void App_Call_Event_DTC_0x900211_SetEventStatus(uint8 FaultStatus);  //Brake lights short to gnd
extern void App_Call_Event_DTC_0x900213_SetEventStatus(uint8 FaultStatus);  //Brake lights open
extern void App_Call_Event_DTC_0x900311_SetEventStatus(uint8 FaultStatus);  //High brake lights short to gnd
extern void App_Call_Event_DTC_0x900313_SetEventStatus(uint8 FaultStatus);  //High brake lights open
extern void App_Call_Event_DTC_0x900412_SetEventStatus(uint8 FaultStatus);  //LowBeamRelayShortToBattery
extern void App_Call_Event_DTC_0x900512_SetEventStatus(uint8 FaultStatus);  //HighBeamRelayShortToBattery
extern void App_Call_Event_DTC_0x900711_SetEventStatus(uint8 FaultStatus);  //IGN1 relay output short to gnd
extern void App_Call_Event_DTC_0x900811_SetEventStatus(uint8 FaultStatus);  //IGN2 relay output short to gnd
extern void App_Call_Event_DTC_0x900923_SetEventStatus(uint8 FaultStatus);  //Left front door antenna open
extern void App_Call_Event_DTC_0x900924_SetEventStatus(uint8 FaultStatus);  //Short between left front door antenna 
extern void App_Call_Event_DTC_0x900A23_SetEventStatus(uint8 FaultStatus);  //Right front door antenna open
extern void App_Call_Event_DTC_0x900A24_SetEventStatus(uint8 FaultStatus);  //Short between right front door antenna 
extern void App_Call_Event_DTC_0x900B23_SetEventStatus(uint8 FaultStatus);  //Rear bumper antenna open
extern void App_Call_Event_DTC_0x900B24_SetEventStatus(uint8 FaultStatus);  //Short between Rrear bumper antenna 
extern void App_Call_Event_DTC_0x900C23_SetEventStatus(uint8 FaultStatus);  //Rear antenna in the car open
extern void App_Call_Event_DTC_0x900C24_SetEventStatus(uint8 FaultStatus);  //Short between rear antenna in the car
extern void App_Call_Event_DTC_0x900D23_SetEventStatus(uint8 FaultStatus);  //Front antenna in the car open
extern void App_Call_Event_DTC_0x900D24_SetEventStatus(uint8 FaultStatus);  //Short between front antenna in the car
extern void App_Call_Event_DTC_0x900E23_SetEventStatus(uint8 FaultStatus);  //Middle antenna in the car open
extern void App_Call_Event_DTC_0x900E24_SetEventStatus(uint8 FaultStatus);  //Short between middle antenna in the car
extern void App_Call_Event_DTC_0x901016_SetEventStatus(uint8 FaultStatus);  //Left front tire pressure battery is low
extern void App_Call_Event_DTC_0x901116_SetEventStatus(uint8 FaultStatus);  //Right front tire pressure battery is low
extern void App_Call_Event_DTC_0x901216_SetEventStatus(uint8 FaultStatus);  //Left rear tire pressure battery is low
extern void App_Call_Event_DTC_0x901316_SetEventStatus(uint8 FaultStatus);  //Right rear tire pressure battery is low
extern void App_Call_Event_DTC_0x901031_SetEventStatus(uint8 FaultStatus);  //Loss left front tire pressure
extern void App_Call_Event_DTC_0x901131_SetEventStatus(uint8 FaultStatus);  //Loss right front tire pressure 
extern void App_Call_Event_DTC_0x901231_SetEventStatus(uint8 FaultStatus);  //Loss left rear tire pressure  
extern void App_Call_Event_DTC_0x901331_SetEventStatus(uint8 FaultStatus);  //Loss right rear tire pressure   
extern void App_Call_Event_DTC_0x90141C_SetEventStatus(uint8 FaultStatus);  //Thermalrunaway voltage out of range
extern void App_Call_Event_DTC_0xF00116_SetEventStatus(uint8 FaultStatus);  //Power supply voltage below threshold   
extern void App_Call_Event_DTC_0xF00117_SetEventStatus(uint8 FaultStatus);  //Battery voltage is too high


/* DTC 状态获取,通信诊断相关 */
extern uint8 App_Call_Event_DTC_0xC04688_GetEventStatus(void);    // EPT_CAN Bus-off
extern uint8 App_Call_Event_DTC_0xC05588_GetEventStatus(void);     // BOD_CAN Bus-off
extern uint8 App_Call_Event_DTC_0xC07388_GetEventStatus(void); // BAC_CAN Bus-off
extern uint8 App_Call_Event_DTC_0xC06488_GetEventStatus(void); // CHA_CAN  Bus-off
extern uint8 App_Call_Event_DTC_0xC12287_GetEventStatus(void); // Lost Communication With ESC
extern uint8 App_Call_Event_DTC_0xD10287_GetEventStatus(void); // Lost Communication with FCM
extern uint8 App_Call_Event_DTC_0xD11287_GetEventStatus(void); // Lost Communication with CRRR
extern uint8 App_Call_Event_DTC_0xD10E87_GetEventStatus(void); // Lost Communication with PP
extern uint8 App_Call_Event_DTC_0xC13087_GetEventStatus(void); // Lost Communication With EPS
extern uint8 App_Call_Event_DTC_0xC15187_GetEventStatus(void); // Lost Communication With SRS
extern uint8 App_Call_Event_DTC_0xD11687_GetEventStatus(void); // Lost Communication with ICU
extern uint8 App_Call_Event_DTC_0xC19887_GetEventStatus(void); // Lost Communication With TBOX
extern uint8 App_Call_Event_DTC_0xC11287_GetEventStatus(void); // Lost Communication with BMS
extern uint8 App_Call_Event_DTC_0xD10887_GetEventStatus(void); // Lost Communication with MCU
extern uint8 App_Call_Event_DTC_0xC10F87_GetEventStatus(void); // Lost Communication with ACCM
extern uint8 App_Call_Event_DTC_0xC23087_GetEventStatus(void); // Lost Communication with PTC
extern uint8 App_Call_Event_DTC_0xD11D87_GetEventStatus(void); // Lost Communication with CDC
extern uint8 App_Call_Event_DTC_0xC14687_GetEventStatus(void); // Lost Communication with IPU
extern uint8 App_Call_Event_DTC_0xE10005_GetEventStatus(void); // ECU Configuration Error
extern uint8 App_Call_Event_DTC_0xD11F00_GetEventStatus(void); // Ethernet unexpected Link Loss with TBOX
extern uint8 App_Call_Event_DTC_0xD11F87_GetEventStatus(void); // Lost TCP link communication with TBOX
extern uint8 App_Call_Event_DTC_0xD12014_GetEventStatus(void); // Ethernet signal lines short or open circuit
extern uint8 App_Call_Event_DTC_0xD12100_GetEventStatus(void); // Insufficient SQI
extern uint8 App_Call_Event_DTC_0xD12241_GetEventStatus(void); // Ethernet CRC Errors


/* 配置字获取 */
extern uint8 GetVehCfg_TyreSize(void);    //轮胎类型
extern uint8 GetVehCfg_TPMSType(void);    //轮胎压力检测系统类型
extern uint8 GetVehCfg_CruiseControl(void);    //CC定速巡航
extern uint8 GetVehCfg_HillDescentControl(void);    //陡坡缓降
extern uint8 GetVehCfg_AdaptiveCruiseControl(void);    //ACC自适应巡航
extern uint8 GetVehCfg_CreepControl(void);    //蠕行控制
extern uint8 GetVehCfg_KeylessEntry(void);    //无钥匙进入配置
extern uint8 GetVehCfg_FrontFogLamp(void);    //前雾灯配置
extern uint8 GetVehCfg_IlluminatedEntrySys(void);    //迎宾功能配置


/* 动态数据DID */
extern void UpdateDIDData(uint8 data,uint8 didId);
extern void UpdateDIDDataArray(uint8 *data, uint8 Length,uint8 didId);

/* 静态数据DID */
extern void SetStaticDIDData(uint8 *data,uint8 didId);

extern void App_Call_Event_IODID_0x3231_GetEventStatus(uint8 *data);
extern void App_Call_Event_IODID_0x3232_GetEventStatus(uint8 *data);
extern void App_Call_Event_IODID_0x3233_GetEventStatus(uint8 *data);
extern void App_Call_Event_IODID_0x3234_GetEventStatus(uint8 *data);
extern void App_Call_Event_IODID_0x3235_GetEventStatus(uint8 *data);
extern void App_Call_Event_IODID_0x3236_GetEventStatus(uint8 *data);

/* CRC校验 */
extern Std_ReturnType Com_RxChksumAliveCnt_Check(uint16 MsgID, uint8 *MsgDataPtr, uint32 MsgDataLen, uint8 *ChksumByte, uint8 ChksumNum, uint8 *LastAliveCnt);
extern Std_ReturnType Com_TxChksumAliveCnt_Calc(uint16 MsgID, uint8 *MsgDataPtr, uint32 MsgDataLen, uint8 *ChksumByte, uint8 ChksumNum, uint8 *LastAliveCnt);

#endif
