#include "Pwm_rte.h"


extern const Pwm_ChannelType TLE8108_INPin_List[DO_OUT_CH_MAX];
// frq 定义
void Gpio_TLE8108_PwmCtl(uint32 frq,uint16 duty_percent,DO_OUT_Ch_t channel)
{
    //TLE8108EM_Set_ChannelON(channel);
    // Gpio_TLE8108_Datawrite();
    uint16 duty = 0;
    Pwm_ChannelType ChannelNumber;
    ChannelNumber=TLE8108_INPin_List[channel];
    
    duty = (uint32)duty_percent*(0x8000)/100;

    Pwm_SetPeriodAndDuty(ChannelNumber,frq,duty);

}

//void Gpio_BTS7020
