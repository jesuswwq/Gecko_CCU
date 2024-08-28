#include "AD_CD4067.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "IoExp_TCA6424A_Cfg.h"
#include "IoExp_TCA6424A_Api.h"
//each CD4067 has 16 chanels
#define MAX_NUM_CHANNELS  20
//max CD4067 numbers in this project
#define MAX_NUM_DEVICES   5
//for AD CD4067 device A
#define AD_CD4067_A_S0PIN IOEXP_TCA6424_P03
#define AD_CD4067_A_S1PIN IOEXP_TCA6424_P04
#define AD_CD4067_A_S2PIN IOEXP_TCA6424_P02
#define AD_CD4067_A_S3PIN IOEXP_TCA6424_P01

//for AD CD4067 device B
#define AD_CD4067_B_S0PIN IOEXP_TCA6424_P20
#define AD_CD4067_B_S1PIN IOEXP_TCA6424_P21
#define AD_CD4067_B_S2PIN IOEXP_TCA6424_P22
#define AD_CD4067_B_S3PIN IOEXP_TCA6424_P23

//for AD CD4067 device C
#define AD_CD4067_C_S0PIN DioConf_DioChannel_ADC_EXP_C_S0
#define AD_CD4067_C_S1PIN DioConf_DioChannel_ADC_EXP_C_S1
#define AD_CD4067_C_S2PIN DioConf_DioChannel_ADC_EXP_C_S2
#define AD_CD4067_C_S3PIN DioConf_DioChannel_ADC_EXP_C_S3

//for AD CD4067 device D
#define AD_CD4067_D_S0PIN DioConf_DioChannel_ADC_EXP_D_S0
#define AD_CD4067_D_S1PIN DioConf_DioChannel_ADC_EXP_D_S1
#define AD_CD4067_D_S2PIN DioConf_DioChannel_ADC_EXP_D_S2
#define AD_CD4067_D_S3PIN DioConf_DioChannel_ADC_EXP_D_S3

// CD4067 device E
#define AD_CD4067_E_S0PIN DioConf_DioChannel_ADC_EXP_E_S0
#define AD_CD4067_E_S1PIN DioConf_DioChannel_ADC_EXP_E_S1
#define AD_CD4067_E_S2PIN DioConf_DioChannel_ADC_EXP_E_S2
#define AD_CD4067_E_S3PIN DioConf_DioChannel_ADC_EXP_E_S3


void Cdd_ADC_Init(void)
{

	//for some init
}

void Set_AD_Channel(int Device, int channel)
{
	
	switch (Device)
	{
	case 0:
		/* code */
                AD4067_IoExp_TCA6424_SetPort0(TCA6424_CHIP_A, channel);
		break;
	case 1:
		/* code */
		AD4067_IoExp_TCA6424_SetPort2(TCA6424_CHIP_E, channel);
		break;
	case 2:
		/* code */
		Dio_WriteChannel(AD_CD4067_C_S0PIN,(channel & 0x01));
		Dio_WriteChannel(AD_CD4067_C_S1PIN,(channel & 0x02) >> 1);
		Dio_WriteChannel(AD_CD4067_C_S2PIN,(channel & 0x04) >> 2);
		Dio_WriteChannel(AD_CD4067_C_S3PIN,(channel & 0x08) >> 3);

		break;
	case 3:
		/* code */
		Dio_WriteChannel(AD_CD4067_D_S0PIN,(channel & 0x01));
		Dio_WriteChannel(AD_CD4067_D_S1PIN,(channel & 0x02) >> 1);
		Dio_WriteChannel(AD_CD4067_D_S2PIN,(channel & 0x04) >> 2);
		Dio_WriteChannel(AD_CD4067_D_S3PIN,(channel & 0x08) >> 3);
		break;

	case 4:
		Dio_WriteChannel(AD_CD4067_E_S0PIN,(channel & 0x01));
		Dio_WriteChannel(AD_CD4067_E_S1PIN,(channel & 0x02) >> 1);
		Dio_WriteChannel(AD_CD4067_E_S2PIN,(channel & 0x04) >> 2);
		Dio_WriteChannel(AD_CD4067_E_S3PIN,(channel & 0x08) >> 3);
		break;
	default:
		break;
	}



}



