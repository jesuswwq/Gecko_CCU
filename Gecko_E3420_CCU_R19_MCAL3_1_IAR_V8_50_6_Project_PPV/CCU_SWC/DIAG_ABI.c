
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "DIAG_ABI.h"
#include "Crc.h"

boolean VBSW_CANComCRCInstFlt_flg[100] = {0};


/* DTC 状态设置 */
void App_Call_Event_DTC_0x100083_SetEventStatus(uint8 FaultStatus)  //加速踏板信号采集差异故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x100083,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x100083,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x100116_SetEventStatus(uint8 FaultStatus)  //加速踏板1电压采集过低
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x100116,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x100116,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x100117_SetEventStatus(uint8 FaultStatus)  //加速踏板1电压采集过高
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x100117,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x100117,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x100316_SetEventStatus(uint8 FaultStatus)  //加速踏板2电压采集过低
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x100316,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x100316,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x100317_SetEventStatus(uint8 FaultStatus)  //加速踏板2电压采集过高
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x100317,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x100317,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x100D16_SetEventStatus(uint8 FaultStatus)  //联锁信号错误-电路电压低于阈值
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x100D16,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x100D16,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x100D17_SetEventStatus(uint8 FaultStatus)  //联锁信号错误-电路电压高于阈值
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x100E17,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x100E17,DEM_EVENT_STATUS_FAILED);
	}
}


void App_Call_Event_DTC_0x101201_SetEventStatus(uint8 FaultStatus)  //传感器供电电压误差(5V1,5V2)-一般电气故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x101201,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x101201,DEM_EVENT_STATUS_FAILED);
	}
}


void App_Call_Event_DTC_0x101501_SetEventStatus(uint8 FaultStatus)  //数字输出错误-一般电气故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x101501,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x101501,DEM_EVENT_STATUS_FAILED);
	}
}


void App_Call_Event_DTC_0x101601_SetEventStatus(uint8 FaultStatus)  //PWM碰撞故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x101601,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x101601,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x101701_SetEventStatus(uint8 FaultStatus)  //pwm输出错误
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x101701,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x101701,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x101D68_SetEventStatus(uint8 FaultStatus)  //碰撞故障（CAN信号）
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x101D68,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x101D68,DEM_EVENT_STATUS_FAILED);
	}
}


void App_Call_Event_DTC_0x102093_SetEventStatus(uint8 FaultStatus)  //BMS响应超时
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x102093,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x102093,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x10211A_SetEventStatus(uint8 FaultStatus)  //高压系统绝缘故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x10211A,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x10211A,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x102496_SetEventStatus(uint8 FaultStatus)  //BMS2级故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x102496,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x102496,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x102596_SetEventStatus(uint8 FaultStatus)  //BMS3级故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x102596,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x102596,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x102696_SetEventStatus(uint8 FaultStatus)  //BMS-SOC值过低
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x102696,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x102696,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x102796_SetEventStatus(uint8 FaultStatus)  //BMS紧急下电
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x102796,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x102796,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x103093_SetEventStatus(uint8 FaultStatus)  //Dcs响应超时
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x103093,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x103093,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x103196_SetEventStatus(uint8 FaultStatus)  //Dcs直流充电故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x103196,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x103196,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x103296_SetEventStatus(uint8 FaultStatus)  //直流充电插枪信号故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x103296,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x103296,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x103396_SetEventStatus(uint8 FaultStatus)  //Dcs充电请求故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x103396,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x103396,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x103496_SetEventStatus(uint8 FaultStatus)  //Dcs充电故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x103496,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x103496,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x104093_SetEventStatus(uint8 FaultStatus)  //DCC响应超时
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x104093,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x104093,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x103996_SetEventStatus(uint8 FaultStatus)  //DCC3级故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x103996,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x103996,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x104196_SetEventStatus(uint8 FaultStatus)  //DCC4级故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x104196,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x104196,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x104296_SetEventStatus(uint8 FaultStatus)  //DCC模式错误
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x104296,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x104296,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x104396_SetEventStatus(uint8 FaultStatus)  //DCC输入电压过低
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x104396,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x104396,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x104496_SetEventStatus(uint8 FaultStatus)  //电机控制器输入电压过低故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x104496,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x104496,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x104696_SetEventStatus(uint8 FaultStatus)  //低压蓄电池SOC低故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x104696,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x104696,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x104796_SetEventStatus(uint8 FaultStatus)  //低压蓄电池SOH低
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x104796,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x104796,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x104896_SetEventStatus(uint8 FaultStatus)  //低压蓄电池过温故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x104896,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x104896,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x105093_SetEventStatus(uint8 FaultStatus)  //AC充电BMS响应超时
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x105093,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x105093,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x105196_SetEventStatus(uint8 FaultStatus)  //车载充电机-4级故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x105196,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x105196,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x105496_SetEventStatus(uint8 FaultStatus)  //车载充电机连接故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x105496,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x105496,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x105596_SetEventStatus(uint8 FaultStatus)  //车载充电机S2无法闭合
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x105596,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x105596,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x105693_SetEventStatus(uint8 FaultStatus)  //车载充电器请求异常故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x105693,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x105693,DEM_EVENT_STATUS_FAILED);
	}
}


void App_Call_Event_DTC_0x105796_SetEventStatus(uint8 FaultStatus)  //BMS实际SOC值过低
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x105796,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x105796,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x105896_SetEventStatus(uint8 FaultStatus)  //BMS允许放电电流过小
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x105896,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x105896,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x105996_SetEventStatus(uint8 FaultStatus)  //BMS上报输出过载
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x105996,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x105996,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x105B96_SetEventStatus(uint8 FaultStatus)  //BMS交流充状态异常
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x105B96,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x105B96,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x105C96_SetEventStatus(uint8 FaultStatus)  //车载充电机模式错误
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x105C96,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x105C96,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x108186_SetEventStatus(uint8 FaultStatus)  //wrong content in Gear message-Signal Invalid
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x108186,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x108186,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x108286_SetEventStatus(uint8 FaultStatus)  //车速信号错误
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x108286,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x108286,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x108486_SetEventStatus(uint8 FaultStatus)  //系统电源模式无效
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x108486,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x108486,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x109077_SetEventStatus(uint8 FaultStatus)  //电机控制器响应错误
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x109077,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x109077,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x109196_SetEventStatus(uint8 FaultStatus)  //电机控制器1级故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x109196,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x109196,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x109296_SetEventStatus(uint8 FaultStatus)  //电机控制器2级故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x109296,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x109296,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x109396_SetEventStatus(uint8 FaultStatus)  //电机控制器3级故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x109396,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x109396,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x109496_SetEventStatus(uint8 FaultStatus)  //电机控制器4级故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x109496,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x109496,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x10A182_SetEventStatus(uint8 FaultStatus)  //VCU-Counter计数故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x10A182,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x10A182,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x102A84_SetEventStatus(uint8 FaultStatus)  //BMS单体电压过低
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x102A84,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x102A84,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x100517_SetEventStatus(uint8 FaultStatus)  //加速踏板1和2采集均故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x100517,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x100517,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x100696_SetEventStatus(uint8 FaultStatus)  //制动踏板1和2采集均故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x100696,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x100696,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x105A96_SetEventStatus(uint8 FaultStatus)  //车载充电机错误
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x105A96,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x105A96,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x101301_SetEventStatus(uint8 FaultStatus)  //模拟输入诊断故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x101301,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x101301,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x101401_SetEventStatus(uint8 FaultStatus)  //数字输入诊断故障
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x101401,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x101401,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900011_SetEventStatus(uint8 FaultStatus)  //Left turn signal Short to gnd
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900011,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900011,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900013_SetEventStatus(uint8 FaultStatus)  //Left turn signal open
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900013,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900013,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900111_SetEventStatus(uint8 FaultStatus)  //Right turn signal short to gnd
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900111,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900111,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900113_SetEventStatus(uint8 FaultStatus)  //Right turn signal open
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900113,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900113,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900211_SetEventStatus(uint8 FaultStatus)  //Brake lights short to gnd
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900211,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900211,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900213_SetEventStatus(uint8 FaultStatus)  //Brake lights open
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900213,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900213,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900311_SetEventStatus(uint8 FaultStatus)  //High brake lights short to gnd
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900311,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900311,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900313_SetEventStatus(uint8 FaultStatus)  //High brake lights open
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900313,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900313,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900412_SetEventStatus(uint8 FaultStatus)  //LowBeamRelayShortToBattery
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900412,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900412,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900512_SetEventStatus(uint8 FaultStatus)  //HighBeamRelayShortToBattery
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900512,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900512,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900711_SetEventStatus(uint8 FaultStatus)  //IGN1 relay output short to gnd
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900711,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900711,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900811_SetEventStatus(uint8 FaultStatus)  //IGN2 relay output short to gnd
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900811,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900811,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900923_SetEventStatus(uint8 FaultStatus)  //Left front door antenna open
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900923,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900923,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900924_SetEventStatus(uint8 FaultStatus)  //Short between left front door antenna 
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900924,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900924,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900A23_SetEventStatus(uint8 FaultStatus)  //Right front door antenna open
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900A23,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900A23,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900A24_SetEventStatus(uint8 FaultStatus)  //Short between right front door antenna 
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900A24,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900A24,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900B23_SetEventStatus(uint8 FaultStatus)  //Rear bumper antenna open
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900B23,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900B23,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900B24_SetEventStatus(uint8 FaultStatus)  //Rear bumper antenna open
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900B24,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900B24,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900C23_SetEventStatus(uint8 FaultStatus)  //Rear antenna in the car open
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900C23,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900C23,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900C24_SetEventStatus(uint8 FaultStatus)  //Short between rear antenna in the car
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900C24,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900C24,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900D23_SetEventStatus(uint8 FaultStatus)  //Front antenna in the car open
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900D23,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900D23,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900D24_SetEventStatus(uint8 FaultStatus)  //Short between front antenna in the car
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900D24,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900D24,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900E23_SetEventStatus(uint8 FaultStatus)  //Middle antenna in the car open
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900E23,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900E23,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x900E24_SetEventStatus(uint8 FaultStatus)  //Short between middle antenna in the car
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x900E24,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x900E24,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x901016_SetEventStatus(uint8 FaultStatus)  //Left front tire pressure battery is low
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x901016,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x901016,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x901116_SetEventStatus(uint8 FaultStatus)  //Right front tire pressure battery is low
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x901116,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x901116,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x901216_SetEventStatus(uint8 FaultStatus)  //Left rear tire pressure battery is low
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x901216,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x901216,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x901316_SetEventStatus(uint8 FaultStatus)  //Right rear tire pressure battery is low
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x901316,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x901316,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x901031_SetEventStatus(uint8 FaultStatus)  //Loss left front tire pressure
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x901031,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x901031,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x901131_SetEventStatus(uint8 FaultStatus)  //Loss right front tire pressure 
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x901131,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x901131,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x901231_SetEventStatus(uint8 FaultStatus)  //Loss left rear tire pressure 
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x901231,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x901231,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x901331_SetEventStatus(uint8 FaultStatus)  //Loss right rear tire pressure 
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x901331,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x901331,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0x90141C_SetEventStatus(uint8 FaultStatus)  //Thermalrunaway voltage out of range 
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0x90141C,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0x90141C,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0xF00116_SetEventStatus(uint8 FaultStatus)  //Power supply voltage below threshold
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0xF00116,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0xF00116,DEM_EVENT_STATUS_FAILED);
	}
}

void App_Call_Event_DTC_0xF00117_SetEventStatus(uint8 FaultStatus)  //Battery voltage is too high
{
	if (0 == FaultStatus)
	{
		Dem_SetEventStatus(DemEventParameter_0xF00117,DEM_EVENT_STATUS_PASSED);
	}
	else
	{
		Dem_SetEventStatus(DemEventParameter_0xF00117,DEM_EVENT_STATUS_FAILED);
	}
}


/* DTC 状态获取,通信诊断相关 */
uint8 App_Call_Event_DTC_0xC04688_GetEventStatus(void) // EPT_CAN Bus-off
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xC04688, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xC05588_GetEventStatus(void) // BOD_CAN Bus-off
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xC05588, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xC07388_GetEventStatus(void) // BAC_CAN Bus-off
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xC07388, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xC06488_GetEventStatus(void) // CHA_CAN  Bus-off
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xC06488, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xC12287_GetEventStatus(void) // Lost Communication With ESC
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xC12287, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xD10287_GetEventStatus(void) // Lost Communication with FCM
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xD10287, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xD11287_GetEventStatus(void) // Lost Communication with CRRR
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xD11287, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xD10E87_GetEventStatus(void) // Lost Communication with PP
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xD10E87, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xC13087_GetEventStatus(void) // Lost Communication With EPS
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xC13087, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xC15187_GetEventStatus(void) // Lost Communication With SRS
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xC15187, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xD11687_GetEventStatus(void) // Lost Communication with ICU
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xD11687, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xC19887_GetEventStatus(void) // Lost Communication With TBOX
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xC19887, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xC11287_GetEventStatus(void) // Lost Communication with BMS
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xC11287, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xD10887_GetEventStatus(void) // Lost Communication with MCU
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xD10887, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xC10F87_GetEventStatus(void) // Lost Communication with ACCM
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xC10F87, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xC23087_GetEventStatus(void) // Lost Communication with PTC
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xC23087, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xD11D87_GetEventStatus(void) // Lost Communication with CDC
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xD11D87, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xC14687_GetEventStatus(void) // Lost Communication with IPU
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xC14687, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xE10005_GetEventStatus(void) // ECU Configuration Error
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xE10005, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xD11F00_GetEventStatus(void) // Ethernet unexpected Link Loss with TBOX
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xD11F00, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xD11F87_GetEventStatus(void) // Lost TCP link communication with TBOX
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xD11F87, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xD12014_GetEventStatus(void) // Ethernet signal lines short or open circuit
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xD12014, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xD12100_GetEventStatus(void) // Insufficient SQI
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xD12100, &DTCStatus);
	return DTCStatus;
}

uint8 App_Call_Event_DTC_0xD12241_GetEventStatus(void) // Ethernet CRC Errors
{
	Dem_UdsStatusByteType DTCStatus;
	Dem_GetEventStatus(DemEventParameter_0xD12241, &DTCStatus);
	return DTCStatus;
}


/* 配置字获取 */
uint8 GetVehCfg_TyreSize(void)    //轮胎类型
{
	uint8 CfgData = NvMBlockRamBuffer3[13] & 0x0F;
	return CfgData;
}

uint8 GetVehCfg_TPMSType(void)    //轮胎压力检测系统类型
{
	uint8 CfgData = (NvMBlockRamBuffer3[13] >> 4) & 0x0F;
	return CfgData;
}

uint8 GetVehCfg_CruiseControl(void)    //CC定速巡航
{
	uint8 CfgData = NvMBlockRamBuffer3[25] & 0x0F;
	return CfgData;
}

uint8 GetVehCfg_HillDescentControl(void)    //陡坡缓降
{
	uint8 CfgData = (NvMBlockRamBuffer3[26] >> 4) & 0x0F;
	return CfgData;
}

uint8 GetVehCfg_AdaptiveCruiseControl(void)    //ACC自适应巡航
{
	uint8 CfgData = NvMBlockRamBuffer3[28] & 0x0F;
	return CfgData;
}

uint8 GetVehCfg_CreepControl(void)    //蠕行控制
{
	uint8 CfgData = (NvMBlockRamBuffer3[29] >> 4) & 0x0F;
	return CfgData;
}

uint8 GetVehCfg_KeylessEntry(void)    //无钥匙进入配置
{
	//uint8 CfgData = NvMBlockRamBuffer3[19] & 0x0F;
	return NvMBlockRamBuffer3[19];
}

uint8 GetVehCfg_FrontFogLamp(void)    //前雾灯配置
{
	uint8 CfgData = (NvMBlockRamBuffer3[15] >> 4) & 0x0F;
	return CfgData;
}

uint8 GetVehCfg_IlluminatedEntrySys(void)    //迎宾功能配置
{
	uint8 CfgData = (NvMBlockRamBuffer3[27] >> 4) & 0x0F;
	return CfgData;
}


/* 动态数据DID */
void UpdateDIDData(uint8 data,uint8 didId)
{
	switch (didId)
	{
	case DID_0xF202:
		Buffer_DcmDspData_0xF202H[0]=data;
		break;

	case DID_0xF205:
		Buffer_DcmDspData_0xF205H[0]=data;
		break;

	case DID_0xF206:
		Buffer_DcmDspData_0xF206H[0]=data;
		break;

	case DID_0xF251:
		Buffer_DcmDspData_0xF251H[0]=data;
		break;

	case DID_0xF25C:
		Buffer_DcmDspData_0xF25CH[0]=data;
		break;

	case DID_0xF25E:
		Buffer_DcmDspData_0xF25EH[0]=data;
		break;

	case DID_0xF25F:
		Buffer_DcmDspData_0xF25FH[0]=data;
		break;

    case DID_0xF210:
		Buffer_DcmDspData_0xF210H[0]=data;
		break;

	case DID_0xF213:
		Buffer_DcmDspData_0xF213H[0]=data;
		break;

	case DID_0xF228:
		Buffer_DcmDspData_0xF228H[0]=data;
		break;

	default:
	    break;
	}
}


void UpdateDIDDataArray(uint8 *data, uint8 Length,uint8 didId)
{
	uint8  index;
	switch (didId)
	{
	case DID_0xF201:
		if (Length <= sizeof(Buffer_DcmDspData_0xF201H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF201H[index] = data[index];
			}
		}
		break;

	case DID_0xF203:
		if (Length <= sizeof(Buffer_DcmDspData_0xF203H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF203H[index] = data[index];
			}
		}
		break;

	case DID_0xF252:
		if (Length <= sizeof(Buffer_DcmDspData_0xF252H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF252H[index] = data[index];
			}
		}
		break;

	case DID_0xF253:
		if (Length <= sizeof(Buffer_DcmDspData_0xF253H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF253H[index] = data[index];
			}
		}
		break;

	case DID_0xF254:
		if (Length <= sizeof(Buffer_DcmDspData_0xF254H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF254H[index] = data[index];
			}
		}
		break;

	case DID_0xF255:
		if (Length <= sizeof(Buffer_DcmDspData_0xF255H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF255H[index] = data[index];
			}
		}
		break;

	case DID_0xF256:
		if (Length <= sizeof(Buffer_DcmDspData_0xF256H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF256H[index] = data[index];
			}
		}
		break;

	case DID_0xF257:
		if (Length <= sizeof(Buffer_DcmDspData_0xF257H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF257H[index] = data[index];
			}
		}
		break;

	case DID_0xF258:
		if (Length <= sizeof(Buffer_DcmDspData_0xF258H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF258H[index] = data[index];
			}
		}
		break;

	case DID_0xF259:
		if (Length <= sizeof(Buffer_DcmDspData_0xF259H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF259H[index] = data[index];
			}
		}
		break;

	case DID_0xF25D:
		if (Length <= sizeof(Buffer_DcmDspData_0xF25DH))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF25DH[index] = data[index];
			}
		}
		break;

	case DID_0xF211:
		if (Length <= sizeof(Buffer_DcmDspData_0xF211H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF211H[index] = data[index];
			}
		}
		break;

	case DID_0xF212:
		if (Length <= sizeof(Buffer_DcmDspData_0xF212H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF212H[index] = data[index];
			}
		}
		break;

	case DID_0xF215:
		if (Length <= sizeof(Buffer_DcmDspData_0xF215H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF215H[index] = data[index];
			}
		}
		break;

	case DID_0xF216:
		if (Length <= sizeof(Buffer_DcmDspData_0xF216H))
		{
			for (index = 0;index < Length;index++)
			{
				Buffer_DcmDspData_0xF216H[index] = data[index];
			}
		}
		break;

	default:
	    break;
	}
}


void SetStaticDIDData(uint8 *data,uint8 didId)
{
	switch (didId)
	{
	case DID_0xF187:
		if (2 == sizeof(data))
		{
			Buffer_DcmDspData_F187[14] = data[0] + 48U;
			Buffer_DcmDspData_F187[15] = data[1] + 48U;
		}
		break;

	case DID_0xF191:
		if (4 == sizeof(data))
		{
			Buffer_DcmDspData_F191[16] = data[0] + 48U;
			Buffer_DcmDspData_F191[17] = data[1] + 48U;
			Buffer_DcmDspData_F191[19] = data[2] + 48U;
			Buffer_DcmDspData_F191[20] = data[3] + 48U;
		}
		break;

	case DID_0xF188:
		if (4 == sizeof(data))
		{
			Buffer_DcmDspData_F188[14] = data[0] + 48U;
			Buffer_DcmDspData_F188[15] = data[1] + 48U;
			Buffer_DcmDspData_F188[17] = data[2] + 48U;
			Buffer_DcmDspData_F188[18] = data[3] + 48U;
		}
		break;

	case DID_0xF180:
		if (4 == sizeof(data))
		{
			Buffer_DcmDspData_F180[14] = data[0] + 48U;
			Buffer_DcmDspData_F180[15] = data[1] + 48U;
			Buffer_DcmDspData_F180[17] = data[2] + 48U;
			Buffer_DcmDspData_F180[18] = data[3] + 48U;
		}
		break;

	case DID_0xF163:
		if (4 == sizeof(data))
		{
			Buffer_DcmDspData_F163[14] = data[0] + 48U;
			Buffer_DcmDspData_F163[15] = data[1] + 48U;
			Buffer_DcmDspData_F163[17] = data[2] + 48U;
			Buffer_DcmDspData_F163[18] = data[3] + 48U;
		}
		break;

	default:
	    break;
	}
}

void App_Call_Event_IODID_0x3231_GetEventStatus(uint8 *data) 
{
 //Rte_Call_Dcm_CSDataServices_DcmDspData_3231_ReadData(0,data,0);
  data[0] = 0;
  data[1] = 0;
}

void App_Call_Event_IODID_0x3232_GetEventStatus(uint8 *data) 
{
 //Rte_Call_Dcm_CSDataServices_DcmDspData_3232_ReadData(0,data,0);
 *data = 0;
}
void App_Call_Event_IODID_0x3233_GetEventStatus(uint8 *data) 
{
 //Rte_Call_Dcm_CSDataServices_DcmDspData_3233_ReadData(0,data,0);
 *data = 0;
}
void App_Call_Event_IODID_0x3234_GetEventStatus(uint8 *data) 
{
 //Rte_Call_Dcm_CSDataServices_DcmDspData_3234_ReadData(0,data,0);
 *data = 0;
}

void App_Call_Event_IODID_0x3235_GetEventStatus(uint8 *data) 
{
 //Rte_Call_Dcm_CSDataServices_DcmDspData_3235_ReadData(0,data,0);
 *data = 0;
}

void App_Call_Event_IODID_0x3236_GetEventStatus(uint8 *data) 
{
 //Rte_Call_Dcm_CSDataServices_DcmDspData_3236_ReadData(0,data,0);
 *data = 0;
}


/* CRC校验 */
Std_ReturnType Com_RxChksumAliveCnt_Check(uint16 MsgID, uint8 *MsgDataPtr, uint32 MsgDataLen, uint8 *ChksumByte, uint8 ChksumNum, uint8 *LastAliveCnt)
{
	if (255 == ChksumByte[0])
	{
		return E_NOT_OK;
	}

    uint8 RxChksum;
    uint8 RxAliveCnt;
    uint8 CalcChksum;
    uint8 ChksumBegin;
	uint8 AliveCntErr;
    boolean CrcFlt = FALSE;
    boolean CntFlt = FALSE;
    for (uint8 k = 0; k < ChksumNum; k++)
    {
        ChksumBegin = ChksumByte[k];
		if ((ChksumBegin+7) < MsgDataLen)
		{
			RxChksum = MsgDataPtr[ChksumBegin];
            RxAliveCnt = MsgDataPtr[ChksumBegin + 1] & 0x0F;
            CalcChksum = Crc_CalculateCRC8H2F(&MsgDataPtr[ChksumBegin + 1], 7, 0xFF, TRUE);
            CrcFlt |= (CalcChksum != RxChksum);
			if (RxAliveCnt >= LastAliveCnt[k])
			{
				AliveCntErr = RxAliveCnt - LastAliveCnt[k];
			}
			else
			{
				AliveCntErr = RxAliveCnt + 16 - LastAliveCnt[k];
			}
            CntFlt |= ((AliveCntErr != 1) && (AliveCntErr != 2));
            LastAliveCnt[k] = RxAliveCnt;
		}
    }
	if(MsgID < sizeof(VBSW_CANComCRCInstFlt_flg))
	{
		VBSW_CANComCRCInstFlt_flg[MsgID] = CrcFlt || CntFlt;
	}

	return E_OK;
}


Std_ReturnType Com_TxChksumAliveCnt_Calc(uint16 MsgID, uint8 *MsgDataPtr, uint32 MsgDataLen, uint8 *ChksumByte, uint8 ChksumNum, uint8 *LastAliveCnt)
{
	if (255 == ChksumByte[0])
	{
		return E_NOT_OK;
	}

    uint8 TxChksum;
	uint8 TxAliveCnt;
    uint8 ChksumBegin;
    for (uint8 k = 0; k < ChksumNum; k++)
    {
        ChksumBegin = ChksumByte[k];
		if ((ChksumBegin+7) < MsgDataLen)
		{
			TxAliveCnt = (LastAliveCnt[k] + 1) & 0x0F;
			MsgDataPtr[ChksumBegin + 1] = (MsgDataPtr[ChksumBegin + 1] & 0xF0) + (TxAliveCnt & 0x0F);
			TxChksum = Crc_CalculateCRC8H2F(&MsgDataPtr[ChksumBegin + 1], 7, 0xFF, TRUE);
			MsgDataPtr[ChksumBegin] = TxChksum;
			LastAliveCnt[k] = TxAliveCnt;
		}
    }

	return E_OK;
}

