
#ifndef _ADAU1462_API_H_
#define _ADAU1462_API_H_

#include "Std_Types.h"
#include "Dio.h"

typedef enum
{
    ADAU1462_BOOTFROM_SPI,
    ADAU1462_BOOTFROM_EEPROM

}ADAU1462_BootMode_e;

typedef enum
{
    ADAU1462_CLKOUT_3072KHZ,
    ADAU1462_CLKOUT_6144KHZ,
    ADAU1462_CLKOUT_12288KHZ,
    ADAU1462_CLKOUT_24576KHZ,

    ADAU1462_CLKOUT_SELNUM
}ADAU1462_CLKOUT_Frequency_e;

extern void ADAU1462_Init(void);
extern void ADAU1462_Select_SelfBootMode(ADAU1462_BootMode_e BootMode);

extern void ADAU1462_Ctrl_CLKOUT(ADAU1462_CLKOUT_Frequency_e Frequency,boolean enableOut);
extern void ADAU1462_InitMP6ToOutPin(void);
extern void ADAU1462_InitMP7ToOutPin(void);
extern void ADAU1462_CtrlMP6OutLevel(Dio_LevelType PinLevel);
extern void ADAU1462_CtrlMP7OutLevel(Dio_LevelType PinLevel);
extern void ADAU1462_SetMic1Clock(void);
extern void ADAU1462_SetSDATA_IN0(void);
extern void ADAU1462_SetSDATA_IN2(void);

#endif /*__ADAU1462_API_H_*/