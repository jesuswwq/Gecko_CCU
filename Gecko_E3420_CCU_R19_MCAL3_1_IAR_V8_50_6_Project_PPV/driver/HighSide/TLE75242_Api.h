#ifndef _TLE75242_API_H_
#define _TLE75242_API_H_

#include "Std_Types.h"
#include "Dio.h"

typedef enum
{
	TLE75242_CHIP_A,
	TLE75242_CHIP_B,
	TLF75242_CHIP_NUM
}TLE75242_Chip_e_;

typedef enum
{
	TLE75242_CH_OUT0,
	TLE75242_CH_OUT1,
	TLE75242_CH_OUT2,
	TLE75242_CH_OUT3,
	TLE75242_CH_OUT4,
	TLE75242_CH_OUT5,
	TLE75242_CH_OUT6,
	TLE75242_CH_OUT7,
	TLE75242_CH_NUM
}TLE75242_Channel_e_;

typedef enum
{
	TLE75242_CH_OFF,
	TLE75242_CH_ON,

	TLE75242_CH_STNUM
}TLE75242_ChSt_e_;

typedef enum
{
    TLE75242_MODE_UNKNOW,
    TLE75242_MODE_LIMPHOME,
    TLE75242_MODE_ACTIVE,
    TLE75242_MODE_IDLE,
    TLE75242_MODE_SLEEP,    

    TLE75242_MODE_NUM
}TLE75242_Mode_e_;

typedef enum
{
	TLE75242_PWM_FREQ_100HZ,
	TLE75242_PWM_FREQ_200HZ,
	TLE75242_PWM_FREQ_400HZ,

	TLE75242_PWM_FREQUENCYNUM
}TLE75242_PWM_Frequency_e_;

typedef enum
{
	TLE75242_PWM_CH0,		//map the pwm generator0
	TLE75242_PWM_CH1,		//map the pwm generator1

	TLE75242_PWM_CHNUM
}TLE75242_PWM_Channel_e_;


extern void TLE75242_ModeCtrl(TLE75242_Chip_e_ ChipID, TLE75242_Mode_e_ OpMode);

extern void TLE75242_Init(void);

/*********************************************PWM Output Control**************************************************/
/*******Demo: set TLE75242_CHIP_B TLE75242_CH_OUT4 output pwm 100hz 50%duty *******/
/*TLE75242_MapPWMToOutputChannel(TLE75242_CHIP_B,TLE75242_PWM_CH0,TLE75242_CH_OUT4);*/
/*TLE75242_SetPWMChFrequency(TLE75242_CHIP_B,TLE75242_PWM_CH0,TLE75242_PWM_FREQ_100HZ);*/
/*TLE75242_EnablePwmChOutput(TLE75242_CHIP_B,TLE75242_PWM_CH0);*/

/*******Demo: adjust output pwm 70%duty *******/
/*TLE75242_AdjustPWMChOutputDuty(TLE75242_CHIP_B,TLE75242_PWM_OUTPUTCH0,70);*/
extern void TLE75242_MapPWMToOutputChannel(TLE75242_Chip_e_ chip, TLE75242_PWM_Channel_e_ pwmCh, TLE75242_Channel_e_ Channel);
extern void TLE75242_SetPWMChFrequency(TLE75242_Chip_e_ chip, TLE75242_PWM_Channel_e_ pwmCh, TLE75242_PWM_Frequency_e_ frequency);
extern void TLE75242_EnablePwmChOutput(TLE75242_Chip_e_ chip, TLE75242_PWM_Channel_e_ pwmCh);
extern void TLE75242_DisablePwmChOutput(TLE75242_Chip_e_ chip, TLE75242_PWM_Channel_e_ pwmCh);
extern void TLE75242_AdjustPWMChOutputDuty(TLE75242_Chip_e_ chip, TLE75242_PWM_Channel_e_ pwmCh, uint8 duty_percent);

/********************************************IN0&IN1 Output Control************************************************/
extern void TLE75242_MapPort_IN0Ctrl(TLE75242_Chip_e_ chip, TLE75242_Channel_e_ Channel);
extern void TLE75242_MapPort_IN1Ctrl(TLE75242_Chip_e_ chip, TLE75242_Channel_e_ Channel);
extern void TLE75242_A_IN0Ctrl_PWMDutyPercent(uint8 duty_percent);
extern void TLE75242_A_IN1Ctrl_PWMDutyPercent(uint8 duty_percent);

/******************************************HS LS Output Control****************************************************/
extern void TLE75242_Ctrl_PortOut(TLE75242_Chip_e_ chip, TLE75242_Channel_e_ Channel, TLE75242_ChSt_e_ ChannelSt);
extern Std_ReturnType TLE75242_SetAllOutPortOff(TLE75242_Chip_e_ chip);
extern Std_ReturnType TLE75242_SetAllPortOutOn(TLE75242_Chip_e_ chip);
extern void HS_Ctrl_75242_A_LS_OUT0_On(void);
extern void HS_Ctrl_75242_A_LS_OUT1_On(void);
extern void HS_Ctrl_75242_A_LS_OUT2_On(void);
extern void HS_Ctrl_75242_A_LS_OUT3_On(void);
extern void HS_Ctrl_75242_A_HS_OUT4_On(void);
extern void HS_Ctrl_75242_A_HS_OUT5_On(void);
extern void HS_Ctrl_75242_A_HS_OUT6_On(void);
extern void HS_Ctrl_75242_A_HS_OUT7_On(void);
extern void HS_Ctrl_75242_A_LS_OUT0_Off(void);
extern void HS_Ctrl_75242_A_LS_OUT1_Off(void);
extern void HS_Ctrl_75242_A_LS_OUT2_Off(void);
extern void HS_Ctrl_75242_A_LS_OUT3_Off(void);
extern void HS_Ctrl_75242_A_HS_OUT4_Off(void);
extern void HS_Ctrl_75242_A_HS_OUT5_Off(void);
extern void HS_Ctrl_75242_A_HS_OUT6_Off(void);
extern void HS_Ctrl_75242_A_HS_OUT7_Off(void);
extern void HS_Ctrl_75242_B_LS_OUT0_On(void);
extern void HS_Ctrl_75242_B_LS_OUT1_On(void);
extern void HS_Ctrl_75242_B_LS_OUT2_On(void);
extern void HS_Ctrl_75242_B_HS_OUT3_On(void);
extern void HS_Ctrl_75242_B_HS_OUT4_On(void);
extern void HS_Ctrl_75242_B_HS_OUT5_On(void);
extern void HS_Ctrl_75242_B_HS_OUT6_On(void);
extern void HS_Ctrl_75242_B_HS_OUT7_On(void);
extern void HS_Ctrl_75242_B_LS_OUT0_Off(void);
extern void HS_Ctrl_75242_B_LS_OUT1_Off(void);
extern void HS_Ctrl_75242_B_LS_OUT2_Off(void);
extern void HS_Ctrl_75242_B_HS_OUT3_Off(void);
extern void HS_Ctrl_75242_B_HS_OUT4_Off(void);
extern void HS_Ctrl_75242_B_HS_OUT5_Off(void);
extern void HS_Ctrl_75242_B_HS_OUT6_Off(void);
extern void HS_Ctrl_75242_B_HS_OUT7_Off(void);


extern void TLE75242_ClearAllOutputChError(TLE75242_Chip_e_ chip);
extern void TLE75242_ResetChip(TLE75242_Chip_e_ chip);

extern uint8 TLE75242_Diag_ERRn(TLE75242_Chip_e_ chip);
extern boolean TLE75242_DIAG_Overload(TLE75242_Chip_e_ chip, uint8 u8ChannelIndex);
extern boolean TLE75242_DIAG_OlOff(TLE75242_Chip_e_ chip);
extern uint8 TLE75242_Diag_GetAll_OlOff_Channel(TLE75242_Chip_e_ chip);
extern uint8 TLE75242_Diag_OlON_Channel(TLE75242_Chip_e_ chip);
extern void TLE75242_Enable_OLON_Diag_Loop(TLE75242_Chip_e_ chip);
extern void TLE75242_Disable_OLON_Diag_Loop(TLE75242_Chip_e_ chip);
extern void TLE75242_DataWrite(TLE75242_Chip_e_ chip, uint8 CmdData);
void TLE75242_OUT2_3_Switch(TLE75242_Chip_e_ chip, Dio_LevelType level,TLE75242_Channel_e_ channel);

#endif