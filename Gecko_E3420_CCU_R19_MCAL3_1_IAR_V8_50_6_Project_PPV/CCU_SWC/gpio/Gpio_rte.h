#ifndef _GPIO_RTE_H_
#define _GPIO_RTE_H_

// include adc file library
// #include "ME11_ABI.h"
#include "Std_Types.h"
#include "IoExp_TCA6424A_Api.h"
#include "IoExp_TCA6424A_Cfg.h"
#include "TLE75242_Cfg.h"
#include "TLE75242_Api.h"
#include "BTS7020.h"
#include "TLE8108EM.h"
#include "TLE75004_Cfg.h"
#include "TLE75004_Api.h"
#include "I2c.h"
#include "I2c_Cfg.h"
void Gpio_init(void);
extern void Gpio_Run(void);
extern Std_ReturnType Gpio_TCA6424A_SetAllPortVal(void);
extern Std_ReturnType Gpio_TCA6424B_SetAllPortVal(void);
extern Std_ReturnType Gpio_TCA6424C_SetAllPortVal(void);
extern Std_ReturnType Gpio_TCA6424D_SetAllPortVal(void);
extern Std_ReturnType Gpio_TCA6424E_SetAllPortVal(void);
extern void Gpio_TLE75004_DataWrite(void);
extern Std_ReturnType Gpio_TLE75242A_8bitDataWrite(void);
extern Std_ReturnType Gpio_TLE75242B_8bitDataWrite(void);
extern void Gpio_TLE8108_Datawrite(void);
extern Std_ReturnType Gpio_TCA6424E_GetAllPort_OutRegVal(void);


#endif