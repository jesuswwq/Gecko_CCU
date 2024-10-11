#ifndef _PWM_RTE_H_
#define _PWM_RTE_H_

// include adc file library
#include "Std_Types.h"
#include "Pwm_Type.h"
#include "TLE8108EM.h"
#include "Pwm_Cfg.h"
#include "Pwm.h"

extern void Gpio_TLE8108_PwmCtl(uint32 frq,uint16 duty_percent,
                                DO_OUT_Ch_t channel);

#endif