#ifndef _VNQ7E100_H_
#define _VNQ7E100_H_

#include "stdint.h"
#include "Platform_Types.h"
#include "Dio.h"
#include "Dio_IP.h"
#include "Port_Types.h"
#include "AD_CD4067.h"
#include "Adc_Types.h"
#include "IoExp_TCA6424A_Api.h"
#include "Adc.h"
#include "Std_Types.h"
#include "Pwm.h"
#include "Xtrg_Cfg.h"
#include "Xtrg.h"

typedef enum
{
    VNQ7E100_Ch_Out0=0,
    VNQ7E100_Ch_Out1,
    VNQ7E100_Ch_Out2,
    VNQ7E100_Ch_Out3
}VNQ7E100_Ch;

void VNQ7E100_Init();
Std_ReturnType VNQ7E100_CtrlA(VNQ7E100_Ch ch, uint8 value);
Std_ReturnType VNQ7E100_CtrlB(VNQ7E100_Ch ch, uint32 frq,uint16 duty_percent);
uint16 VNQ7E100_ADC_CtrlA(VNQ7E100_Ch ch);
uint16 VNQ7E100_ADC_CtrlB(VNQ7E100_Ch ch);

#endif