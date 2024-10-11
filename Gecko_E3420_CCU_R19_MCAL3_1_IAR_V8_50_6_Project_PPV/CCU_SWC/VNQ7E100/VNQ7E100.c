#include "VNQ7E100.h"

#define CLEAR_BIT(x, bit) (x &= ~(0x01 << bit))
#define VNQ7E100_SET_BIT(x, bit) ((x)|=(0x01<<bit))
extern uint8 tca6424D[4];
uint32 adc1_group_VNQ7E100[4] = {0};
/* init */
#pragma default_function_attributes = @".iram_func"
void VNQ7E100_Init()
{
	//map io to pwm

	Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_H5);
}

Std_ReturnType VNQ7E100_CtrlA(VNQ7E100_Ch ch, uint8 value)
{
	Std_ReturnType ret = E_OK;
	switch (ch)
	{
	case VNQ7E100_Ch_Out0:
		/* code */
		Dio_WriteChannel(GPIO_C13, value);
		break;
	case VNQ7E100_Ch_Out1:
		Dio_WriteChannel(GPIO_D0, value);
		break;
	case VNQ7E100_Ch_Out2:
		Dio_WriteChannel(GPIO_D17, value);
		break;
	case VNQ7E100_Ch_Out3:
		Dio_WriteChannel(GPIO_D40, value);
		break;
	default:
		return E_NOT_OK;
		break;
	}
	return ret;
}
Std_ReturnType VNQ7E100_CtrlB(VNQ7E100_Ch ch, uint32 frq, uint16 duty_percent)
{
	Std_ReturnType ret = E_OK;

	switch (ch)
	{
	case VNQ7E100_Ch_Out0:
//          Dio_WriteChannel(GPIO_H5,duty);
		Pwm_SetPeriodAndDuty(PWM_CONFIG_CHANNEL_PwmChannel_7E100B_IN0, frq, duty_percent);
//		Pwm_SetDutyCycle(PwmConf_PwmChannel_PwmChannel_7E100B_IN0,  duty_percent);
		break;
	case VNQ7E100_Ch_Out1:
		// Dio_WriteChannel(GPIO_D0,value);
		break;
	case VNQ7E100_Ch_Out2:
		// Dio_WriteChannel(GPIO_D17,value);
		break;
	case VNQ7E100_Ch_Out3:
		// Dio_WriteChannel(GPIO_D40,value);
		break;
	default:
		return E_NOT_OK;
		break;
	}
	return ret;
}

uint16 VNQ7E100_ADC_CtrlA(VNQ7E100_Ch ch)
{
	float ad_V = 0.0;
	uint16 ad_R = 0;
	VNQ7E100_SET_BIT(tca6424D[3], 0);
	// uint16 ret = 0;
	switch (ch)
	{
	case VNQ7E100_Ch_Out0:
		CLEAR_BIT(tca6424D[3], 3);
		CLEAR_BIT(tca6424D[3], 4);
		break;
	case VNQ7E100_Ch_Out1:
		VNQ7E100_SET_BIT(tca6424D[3], 3);
		CLEAR_BIT(tca6424D[3], 4);
		break;
	case VNQ7E100_Ch_Out2:
		VNQ7E100_SET_BIT(tca6424D[3], 4);
		CLEAR_BIT(tca6424D[3], 3);
		break;
	case VNQ7E100_Ch_Out3:
		VNQ7E100_SET_BIT(tca6424D[3], 3);
		VNQ7E100_SET_BIT(tca6424D[3], 4);
		break;
	default:
		return E_NOT_OK;
		break;
	}
	Set_AD_Channel(3, 15);
	Adc_StartGroupConversion(0);
	Adc_ReadGroup(0, adc1_group_VNQ7E100);
	ad_V = ((float)adc1_group_VNQ7E100[0]) / 4095.0 * 3300.0 * 6.0 / 5.0;
	ad_R = (uint16)(ad_V / (4600.0 - ad_V) * 2000.0);

	return ad_R;
}

uint16 VNQ7E100_ADC_CtrlB(VNQ7E100_Ch ch)
{
	float ad_V = 0.0;
	uint16 ad_R = 0;
	VNQ7E100_SET_BIT(tca6424D[3], 2);
	// uint16 ret = 0;
	switch (ch)
	{
	case VNQ7E100_Ch_Out0:
		CLEAR_BIT(tca6424D[3], 5);
		CLEAR_BIT(tca6424D[3], 6);
		break;
	case VNQ7E100_Ch_Out1:
		VNQ7E100_SET_BIT(tca6424D[3], 5);
		CLEAR_BIT(tca6424D[3], 6);
		break;
	case VNQ7E100_Ch_Out2:
		VNQ7E100_SET_BIT(tca6424D[3], 6);
		CLEAR_BIT(tca6424D[3], 5);
		break;
	case VNQ7E100_Ch_Out3:
		VNQ7E100_SET_BIT(tca6424D[3], 5);
		VNQ7E100_SET_BIT(tca6424D[3], 6);
		break;
	default:
		return E_NOT_OK;
		break;
	}
	Set_AD_Channel(3, 14);
	Adc_StartGroupConversion(0);
	Adc_ReadGroup(0, adc1_group_VNQ7E100);
	ad_V = ((float)adc1_group_VNQ7E100[0]) / 4095.0 * 3300.0 * 6.0 / 5.0;
	ad_R = (uint16)(ad_V / (4600.0 - ad_V) * 2000.0);

	return ad_R;
}
#pragma default_function_attributes = 