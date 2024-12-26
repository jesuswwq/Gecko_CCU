/*
 * TLE75xxx.c
 *
 *  
 *      Author: 
 */
#include "TLE75242_Cfg.h"
#include "TLE75242_Api.h"
#include "IoExp_TCA6424A_Api.h"
#include "Spi.h"
#include "Xtrg_Cfg.h"
#include "Xtrg.h"
#include "Pwm.h"

/**************************************************************************************************************/
/***                                        MACRO Define                                                    ***/
/*****                                                                                                     ****/
/**************************************************************************************************************/
#define TLE75XXX_8BIT_DATA_MAK    (0xFFu)
#define TLE75XXX_10BIT_DATA_MAK   (0x3FFu)

/**************************************************************************************************************/
/***                                        Type Define                                                     ***/
/*****                                                                                                     ****/
/**************************************************************************************************************/


typedef struct
{
   TLE75242_Chip_e_ ChipId;
   Spi_ChannelType SpiCh;
   Spi_SequenceType SpiSeq;
}TLE75242_Table_t_;

/**************************************************************************************************************/
/***                                        Variable Define                                                 ***/
/*****                                                                                                     ****/
/**************************************************************************************************************/

const TLE75242_Table_t_ TLE75242_List[TLF75242_CHIP_NUM] = 
{
	{TLE75242_CHIP_A, SpiConf_SpiChannel_SpiChannel_TLE75242A, SpiConf_SpiSequence_SpiSequence_TLE75242A },
	{TLE75242_CHIP_B, SpiConf_SpiChannel_SpiChannel_TLE75242B, SpiConf_SpiSequence_SpiSequence_TLE75242B }
};

const TLE75242_CtrlPin_t_ TLE75252_CtrlPin_List[TLF75242_CHIP_NUM] = 
{   
    ///TLE75242_CHIP_A
    {
        .IDLE_Pin = IOEXP_TCA6424_P27,                          ///OUT_EXP_B_P27
        // .IN0_Pin  = DioConf_DioChannel_Dio_75242_A_IN0,
        // .IN1_Pin  = DioConf_DioChannel_Dio_75242_A_IN1,
		.IN0_Pin  = PWM_CONFIG_CHANNEL_PwmChannel_75242_A_IN0,
        .IN1_Pin  = PWM_CONFIG_CHANNEL_PwmChannel_75242_A_IN1,
    },
    ///TLE75242_CHIP_B
    {
        .IDLE_Pin = IOEXP_TCA6424_P26,                          ///OUT_EXP_B_P26
        .IN0_Pin  = DioConf_DioChannel_Dio_75242_B_IN0,
        .IN1_Pin  = DioConf_DioChannel_Dio_75242_B_IN1,
    }
};

uint16 g_SpiOutBuf_Tle75242;
uint16 g_SpiInBuf_Tle75242;

static Std_ReturnType TLE75242_8bitDataWrite(TLE75242_Chip_e_ chip,uint8 regName, uint8 CmdData);
static Std_ReturnType TLE75242_8bitDataRead(TLE75242_Chip_e_ chip ,uint8 regName, uint8* RxData);
static Std_ReturnType TLE75242_10bitDataWrite(TLE75242_Chip_e_ chip, uint8 regName, uint16 CmdData);
static Std_ReturnType TLE75242_10bitDataRead(TLE75242_Chip_e_ chip, uint8 regName, uint16* RxData);
static void TLE75242_PinOutputCtrl(TLE75242_Chip_e_ chip, uint16 channel, Dio_LevelType DioSt);

#define TLE75242_CLEAR_BIT(value,pos) ((value)&=~(1<<(pos)))
#define TLE75242_SET_BIT(value,pos)   ((value)|= (1<<(pos)))

/**************************************************************************************************************/
/***                                      Functio Define                                                    ***/
/*****                                                                                                     ****/
/**************************************************************************************************************/
void TLE75242_ModeCtrl(TLE75242_Chip_e_ ChipID, TLE75242_Mode_e_ OpMode)
{   
    
    Dio_LevelType IdleCtrl = STD_LOW;
    Dio_LevelType In0Ctrl = STD_LOW;
    Dio_LevelType In1Ctrl = STD_LOW;
    
    switch (OpMode)
    {
        case TLE75242_MODE_LIMPHOME:
            IdleCtrl = STD_LOW;
            In0Ctrl  = STD_HIGH;
            In1Ctrl  = STD_HIGH;
         break;

       case TLE75242_MODE_ACTIVE:
            IdleCtrl = STD_HIGH;
            In0Ctrl  = STD_HIGH;
            In1Ctrl  = STD_HIGH;
         break;

       case TLE75242_MODE_IDLE:
            IdleCtrl = STD_HIGH;
            In0Ctrl  = STD_LOW;
            In1Ctrl  = STD_LOW;
         break;

       case TLE75242_MODE_SLEEP:
            IdleCtrl = STD_LOW;
            In0Ctrl  = STD_LOW;
            In1Ctrl  = STD_LOW;
         break;

       default:
         break;
    }

    // Dio_WriteChannel(TLE75252_CtrlPin_List[ChipID].IN1_Pin, In1Ctrl);
    // Dio_WriteChannel(TLE75252_CtrlPin_List[ChipID].IN0_Pin, In0Ctrl);
	TLE75242_PinOutputCtrl(ChipID,TLE75252_CtrlPin_List[ChipID].IN1_Pin, In1Ctrl);
	TLE75242_PinOutputCtrl(ChipID,TLE75252_CtrlPin_List[ChipID].IN0_Pin, In0Ctrl);
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_B,TLE75252_CtrlPin_List[ChipID].IDLE_Pin,IdleCtrl);
}

void TLE75242_Init(void)
{
	//map io to pwm
    // extern xtrg_dev_t xtrg_dev;
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_M9, true);
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_H6, true);
	Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_M9);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_H6);
	
    TLE75242_ModeCtrl(TLE75242_CHIP_A,TLE75242_MODE_IDLE);
    TLE75242_ModeCtrl(TLE75242_CHIP_B,TLE75242_MODE_IDLE);
    
	///First set chip mode to active
	TLE75242_8bitDataWrite(TLE75242_CHIP_A, TLE75242_REG_HWCR, 0x80);//bit HWCR.ACT (7) (Active Mode)
	TLE75242_8bitDataWrite(TLE75242_CHIP_B, TLE75242_REG_HWCR, 0x80);//bit HWCR.ACT (7) (Active Mode)
	//Init Diag_IOL Reg  //open all channel's current to diagnostic OLOFF
	// TLE75242_8bitDataWrite(TLE75242_CHIP_A, TLE75242_REG_DIAG_IOL, 0xFF);//add for diag OLOFF for ALL channel
	// TLE75242_8bitDataWrite(TLE75242_CHIP_B, TLE75242_REG_DIAG_IOL, 0xFF);//add for diag OLOFF for ALL channel
    //Init diagnostic mode: open diagnostic function, and set loop mode
	//TLE75242_Enable_OLON_Diag_Loop(TLE75242_CHIP_A);
	//TLE75242_Enable_OLON_Diag_Loop(TLE75242_CHIP_B);
}

/********************************************************************************************/
/*									PWM control												*/
/********************************************************************************************/
/* Map a output channel as pwm output */
void TLE75242_MapPWMToOutputChannel(TLE75242_Chip_e_ chip, TLE75242_PWM_Channel_e_ pwmCh, TLE75242_Channel_e_ Channel)
{
	uint8 regVal_u8 = 0;

	if(pwmCh < TLE75242_PWM_CHNUM)
	{
		//get the channel map to the pwm generator
		TLE75242_8bitDataRead(chip, TLE75242_REG_HWCR_OUT,&regVal_u8);

		//map the channel to the map register
		regVal_u8 |= (TLE75242_CH_ON << Channel);
		TLE75242_8bitDataWrite(chip, TLE75242_REG_HWCR_OUT,regVal_u8);

		regVal_u8 = 0;
		//TLE75242_PWM_OUTPUTCH1 used pwm generator1, TLE75242_PWM_OUTPUTCH0 use generator0
		if(pwmCh == TLE75242_PWM_CH1)
		{
			regVal_u8 = (1 << Channel);
		}
		TLE75242_8bitDataWrite(chip, TLE75242_REG_HWCR_MAP,regVal_u8);
	}
}

void TLE75242_SetPWMChFrequency(TLE75242_Chip_e_ chip, TLE75242_PWM_Channel_e_ pwmCh, TLE75242_PWM_Frequency_e_ frequency)
{
	uint16 regVal_u16 = 0;

	if(pwmCh == TLE75242_PWM_CH0)
	{	
	    TLE75242_10bitDataRead(chip, TLE75242_REG_HWCR_CR0,&regVal_u16);
	    regVal_u16 |= ((uint16)frequency<<8);
	    
		//set frenquency and duty as 50%
		TLE75242_10bitDataWrite(chip, TLE75242_REG_HWCR_CR0,regVal_u16);
	}
	else
	{
	    TLE75242_10bitDataRead(chip, TLE75242_REG_HWCR_CR1,&regVal_u16);
	    regVal_u16 |= ((uint16)frequency<<8);
		//set frenquency and duty as 50%
		TLE75242_10bitDataWrite(chip, TLE75242_REG_HWCR_CR1,regVal_u16);
	}
}

void TLE75242_EnablePwmChOutput(TLE75242_Chip_e_ chip, TLE75242_PWM_Channel_e_ pwmCh)
{
	uint8 regVal_u8 = 0;

	//get register config
	TLE75242_8bitDataRead(chip, TLE75242_REG_HWCR_PWM,&regVal_u8);

	regVal_u8 |= (1 << pwmCh);

	//enable pwm output
	TLE75242_8bitDataWrite(chip, TLE75242_REG_HWCR_PWM,regVal_u8);

}

void TLE75242_DisablePwmChOutput(TLE75242_Chip_e_ chip, TLE75242_PWM_Channel_e_ pwmCh)
{
	uint8 regVal_u8 = 0;

	//get register config
	TLE75242_8bitDataRead(chip, TLE75242_REG_HWCR_PWM,&regVal_u8);

	TLE75242_CLEAR_BIT(regVal_u8,pwmCh);

	//enable pwm output
	TLE75242_8bitDataWrite(chip, TLE75242_REG_HWCR_PWM,regVal_u8);

}

void TLE75242_AdjustPWMChOutputDuty(TLE75242_Chip_e_ chip, TLE75242_PWM_Channel_e_ pwmCh, uint8 duty_percent)
{
	uint16 regVal_u16 = 0;

	if(pwmCh == TLE75242_PWM_CH0)
	{	
		TLE75242_10bitDataRead(chip, TLE75242_REG_HWCR_CR0,&regVal_u16);
		regVal_u16 |= ((uint16)duty_percent)*0xff/100;

		//set frenquency and duty as 50%
		TLE75242_10bitDataWrite(chip, TLE75242_REG_HWCR_CR0,regVal_u16);
	}
	else
	{
		TLE75242_10bitDataRead(chip, TLE75242_REG_HWCR_CR1,&regVal_u16);
		regVal_u16 |= ((uint16)duty_percent)*0xff/100;

		//set frenquency and duty as 50%
		TLE75242_10bitDataWrite(chip, TLE75242_REG_HWCR_CR1,regVal_u16);
	}
}

/********************************************************************************************/
/*									IN0/IN1 control output									*/
/********************************************************************************************/
void TLE75242_MapPort_IN0Ctrl(TLE75242_Chip_e_ chip, TLE75242_Channel_e_ Channel)
{
	uint8 regVal_u8 = 0;

	regVal_u8 = (1<<Channel);

	TLE75242_8bitDataWrite(chip, TLE75242_REG_MAPIN0,regVal_u8);
}

void TLE75242_MapPort_IN1Ctrl(TLE75242_Chip_e_ chip, TLE75242_Channel_e_ Channel)
{
	uint8 regVal_u8 = 0;

	regVal_u8 = (1<<Channel);
	
	TLE75242_8bitDataWrite(chip, TLE75242_REG_MAPIN1,regVal_u8);
}

void TLE75242_A_IN0Ctrl_PWMDutyPercent(uint8 duty_percent)
{
	uint32 duty = 0;

    duty = (uint32)duty_percent*(0x8000)/100;
	
	Pwm_SetPeriodAndDuty(PWM_CONFIG_CHANNEL_PwmChannel_75242_A_IN0,10000000,duty);
}

void TLE75242_A_IN1Ctrl_PWMDutyPercent(uint8 duty_percent)
{
	uint32 duty = 0;

    duty = (uint32)duty_percent*(0x8000)/100;
	
	Pwm_SetPeriodAndDuty(PWM_CONFIG_CHANNEL_PwmChannel_75242_A_IN1,10000000,duty);
}
/********************************************************************************************/
/*									output control											*/
/********************************************************************************************/
void TLE75242_Ctrl_PortOut(TLE75242_Chip_e_ chip, TLE75242_Channel_e_ Channel, TLE75242_ChSt_e_ ChannelSt)
{
	Std_ReturnType ret = E_OK;
	uint8 regVal_u8 = 0;

	ret = TLE75242_8bitDataRead(chip, TLE75242_REG_OUT,&regVal_u8);
	
	TLE75242_CLEAR_BIT(regVal_u8, Channel);
	regVal_u8 |= (uint8)(ChannelSt << Channel);
	
	if(ret == E_OK)
	{
		TLE75242_8bitDataWrite(chip, TLE75242_REG_OUT,regVal_u8);
	}
}

Std_ReturnType TLE75242_SetAllOutPortOff(TLE75242_Chip_e_ chip)
{
	Std_ReturnType ret = E_OK;
	uint8 regVal_u8 = 0;
	
	ret = TLE75242_8bitDataWrite(chip, TLE75242_REG_OUT,regVal_u8);

	return ret;
}

Std_ReturnType TLE75242_SetAllPortOutOn(TLE75242_Chip_e_ chip)
{
	Std_ReturnType ret = E_OK;
	uint16 regVal_u8 = 0xff;
	
	ret = TLE75242_8bitDataWrite(chip, TLE75242_REG_OUT,regVal_u8);

	return ret;
}

void HS_Ctrl_75242_A_LS_OUT0_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT0, STD_HIGH);
}

void HS_Ctrl_75242_A_LS_OUT1_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT1, STD_HIGH);
}

void HS_Ctrl_75242_A_LS_OUT2_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT2, STD_HIGH);
}

void HS_Ctrl_75242_A_LS_OUT3_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT3, STD_HIGH);
}

void HS_Ctrl_75242_A_HS_OUT4_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT4, STD_HIGH);
}

void HS_Ctrl_75242_A_HS_OUT5_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT5, STD_HIGH);
}

void HS_Ctrl_75242_A_HS_OUT6_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT6, STD_HIGH);
}

void HS_Ctrl_75242_A_HS_OUT7_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT7, STD_HIGH);
}

void HS_Ctrl_75242_A_LS_OUT0_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT0, STD_LOW);
}

void HS_Ctrl_75242_A_LS_OUT1_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT1, STD_LOW);
}

void HS_Ctrl_75242_A_LS_OUT2_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT2, STD_LOW);
}

void HS_Ctrl_75242_A_LS_OUT3_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT3, STD_LOW);
}

void HS_Ctrl_75242_A_HS_OUT4_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT4, STD_LOW);
}

void HS_Ctrl_75242_A_HS_OUT5_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT5, STD_LOW);
}

void HS_Ctrl_75242_A_HS_OUT6_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT6, STD_LOW);
}

void HS_Ctrl_75242_A_HS_OUT7_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_A,TLE75242_CH_OUT7, STD_LOW);
}

void HS_Ctrl_75242_B_LS_OUT0_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT0, STD_HIGH);
}

void HS_Ctrl_75242_B_LS_OUT1_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT1, STD_HIGH);
}

void HS_Ctrl_75242_B_LS_OUT2_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT2, STD_HIGH);
}

void HS_Ctrl_75242_B_HS_OUT3_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT3, STD_HIGH);
}

void HS_Ctrl_75242_B_HS_OUT4_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT4, STD_HIGH);
}

void HS_Ctrl_75242_B_HS_OUT5_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT5, STD_HIGH);
}

void HS_Ctrl_75242_B_HS_OUT6_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT6, STD_HIGH);
}

void HS_Ctrl_75242_B_HS_OUT7_On(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT7, STD_HIGH);
}

void HS_Ctrl_75242_B_LS_OUT0_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT0, STD_LOW);
}

void HS_Ctrl_75242_B_LS_OUT1_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT1, STD_LOW);
}

void HS_Ctrl_75242_B_LS_OUT2_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT2, STD_LOW);
}

void HS_Ctrl_75242_B_HS_OUT3_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT3, STD_LOW);
}

void HS_Ctrl_75242_B_HS_OUT4_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT4, STD_LOW);
}

void HS_Ctrl_75242_B_HS_OUT5_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT5, STD_LOW);
}

void HS_Ctrl_75242_B_HS_OUT6_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT6, STD_LOW);
}

void HS_Ctrl_75242_B_HS_OUT7_Off(void)
{
	TLE75242_Ctrl_PortOut(TLE75242_CHIP_B,TLE75242_CH_OUT7, STD_LOW);
}


/********************************************************************************************/
/*									Diagnostic												*/
/********************************************************************************************/
//diag for the standard diagnostic register 
Std_ReturnType TLE75242_tGetStdDiag(TLE75242_Chip_e_ chip, TLE75242_StdDiag_t *pStdDiag)
{
	Std_ReturnType ret = E_NOT_OK;
	Spi_ChannelType SpiCh;
    Spi_SequenceType SpiSeq;

	SpiCh = TLE75242_List[chip].SpiCh;
	SpiSeq = TLE75242_List[chip].SpiSeq;

	g_SpiOutBuf_Tle75242 = TLE75242_RREG_ADDRESS_STDDIAG;
	g_SpiInBuf_Tle75242 = 0;

    /**************************Diag frame ***************************************/
	SuspendAllInterrupts();
    ret = Spi_SetupEB( SpiCh, (Spi_DataBufferType*)&g_SpiOutBuf_Tle75242, 
					(Spi_DataBufferType*)&g_SpiInBuf_Tle75242, 1u );

	if(ret == E_OK)
	{
            Spi_SyncTransmit(SpiSeq);
	}
	  ResumeAllInterrupts();
	  SuspendAllInterrupts();
	/***************************data get frame***********************************/
	ret = Spi_SetupEB( SpiCh, (Spi_DataBufferType*)&g_SpiOutBuf_Tle75242, 
					(Spi_DataBufferType*)&g_SpiInBuf_Tle75242, 1u );
	if(ret == E_OK)
	{
		ret = Spi_SyncTransmit(SpiSeq);

		if(ret == E_OK)
		{
            /* Verify data invalid! */
		    if((g_SpiInBuf_Tle75242&0x8000) != 0)
		    {
		        ret = E_NOT_OK;
		    }
		    else
		    {
		        (*pStdDiag).worddef = (uint16) (g_SpiInBuf_Tle75242);
		        ret = E_OK;
		    }
			
		}
	}
	ResumeAllInterrupts();
	return ret;
}

//ADD FOR DIAG Start
//diag for the ERRn bits in the standard diagnostic register 
uint8 TLE75242_Diag_ERRn(TLE75242_Chip_e_ chip)
{
    TLE75242_StdDiag_t pStdDiag;
	uint8 ERRn_Data = 0;
	
	TLE75242_tGetStdDiag(chip, &pStdDiag);
	
	ERRn_Data = (uint8)(pStdDiag.bitdef.ERRn);
	
	return ERRn_Data;
}

void TLE75242_ClearAllOutputChError(TLE75242_Chip_e_ chip)
{
	TLE75242_8bitDataWrite(chip, TLE75242_REG_HWCR_OCL ,0xFF);
}

void TLE75242_ResetChip(TLE75242_Chip_e_ chip)
{
	TLE75242_8bitDataWrite(chip, TLE75242_REG_HWCR ,0x40);
}

//diag which channel is Overload
boolean TLE75242_DIAG_Overload(TLE75242_Chip_e_ chip, uint8 u8ChannelIndex)
{
	uint8 u8Error;
	boolean result = FALSE;
	TLE75242_StdDiag_t tStdDiag;
	
	TLE75242_tGetStdDiag(chip, (TLE75242_StdDiag_t*)(&tStdDiag));
	u8Error = tStdDiag.bitdef.ERRn;
	//for(u8ChannelIndex = 0; u8ChannelIndex < TLE75242_REG_CHANNEL_NUM ; u8ChannelIndex++)
	//{
		if(GET_BITPOS(u8Error, u8ChannelIndex))
		{
			result = FALSE;
		}
		else
		{
			result = TRUE;
		}
	//}
	return result;
}

//diag for if  OLOFF is happened
boolean TLE75242_DIAG_OlOff(TLE75242_Chip_e_ chip)
{
	boolean result = FALSE;
	uint8 u8OlOffFlag;
	TLE75242_StdDiag_t tStdDiag;
	
	TLE75242_tGetStdDiag(chip, (TLE75242_StdDiag_t*)(&tStdDiag));
	
	u8OlOffFlag = tStdDiag.bitdef.OLOFF;
	if(u8OlOffFlag != 0)
	{
		result = TRUE;
	}
	else
	{
		result = FALSE;
	}
	return result;
}

uint8 TLE75242_Diag_GetAll_OlOff_Channel(TLE75242_Chip_e_ chip)
{
	uint8 u8data;

	TLE75242_8bitDataRead(chip, TLE75242_REG_DIAG_OSM,&u8data);

	return u8data;
}

uint8 TLE75242_Diag_OlON_Channel(TLE75242_Chip_e_ chip)
{
	uint8 u8data;
	TLE75242_8bitDataRead(chip, TLE75242_REG_DIAG_OLON, &u8data);

	return u8data;
}

void TLE75242_Enable_OLON_Diag_Loop(TLE75242_Chip_e_ chip)
{
	TLE75242_8bitDataWrite(chip, TLE75242_REG_DIAG_OLONEN, 0x0A );
}

void TLE75242_Disable_OLON_Diag_Loop(TLE75242_Chip_e_ chip)
{
	TLE75242_8bitDataWrite(chip, TLE75242_REG_DIAG_OLONEN, 0x0A );
}

/**************************************************************************************************************/
/*****************************************for write command just send one fame ********************************/
/**************************************************************************************************************/
Std_ReturnType TLE75242_8bitDataWrite(TLE75242_Chip_e_ chip, uint8 regName, uint8 CmdData)
{
	Std_ReturnType ret = E_NOT_OK;
	Spi_ChannelType SpiCh;
    Spi_SequenceType SpiSeq;

	SpiCh = TLE75242_List[chip].SpiCh;
	SpiSeq = TLE75242_List[chip].SpiSeq;
	
	g_SpiOutBuf_Tle75242 = (TLE75242_CMD_WRITE |(regName<<8)| CmdData);
	g_SpiInBuf_Tle75242 = 0;
	 SuspendAllInterrupts();
	ret = Spi_SetupEB( SpiCh, (Spi_DataBufferType*)&g_SpiOutBuf_Tle75242, 
					(Spi_DataBufferType*)&g_SpiInBuf_Tle75242, 1u );
	if(ret == E_OK)
	{
		ret = Spi_SyncTransmit(SpiSeq);
	}
	ResumeAllInterrupts();
	return ret;
}

/**************************************************************************************************************/
/*****************************************for read command 2 frame need send   ********************************/
/*                                     Frame A: Read command send |    Frame B: Read Frame Again              */
/**                Frame A Recaeived: Diag Frame for Last Frame   |    Frame B: Last Read Reg data Received  **/
/**************************************************************************************************************/
Std_ReturnType TLE75242_8bitDataRead(TLE75242_Chip_e_ chip, uint8 regName, uint8* RxData)
{
	Std_ReturnType ret = E_NOT_OK;
    Spi_ChannelType SpiCh;
    Spi_SequenceType SpiSeq;

	SpiCh = TLE75242_List[chip].SpiCh;
	SpiSeq = TLE75242_List[chip].SpiSeq;
	
	g_SpiOutBuf_Tle75242 = (TLE75242_CMD_READ | regName<<8);
	g_SpiInBuf_Tle75242 = 0;

    /**************************Diag frame ***************************************/
	 SuspendAllInterrupts();
    ret = Spi_SetupEB( SpiCh, (Spi_DataBufferType*)&g_SpiOutBuf_Tle75242, 
					(Spi_DataBufferType*)&g_SpiInBuf_Tle75242, 1u );
	if(ret == E_OK)
	{
		Spi_SyncTransmit(SpiSeq);
	}
	ResumeAllInterrupts();
	/***************************data get frame***********************************/
	 SuspendAllInterrupts();
	ret = Spi_SetupEB( SpiCh, (Spi_DataBufferType*)&g_SpiOutBuf_Tle75242, 
					(Spi_DataBufferType*)&g_SpiInBuf_Tle75242, 1u );
	if(ret == E_OK)
	{
		ret = Spi_SyncTransmit(SpiSeq);

		if(ret == E_OK)
		{
            /* Verify data invalid! */
		    if((g_SpiInBuf_Tle75242&0xff00) != (0x8000 | regName<<8))
		    {
		        ret = E_NOT_OK;
		    }
		    else
		    {
		        *RxData = (g_SpiInBuf_Tle75242&TLE75XXX_8BIT_DATA_MAK);
		        ret = E_OK;
		    }
			
		}
	}
	ResumeAllInterrupts();
	return ret;
}


Std_ReturnType TLE75242_10bitDataWrite(TLE75242_Chip_e_ chip, uint8 regName, uint16 CmdData)
{
	Std_ReturnType ret = E_NOT_OK;
	Spi_ChannelType SpiCh;
    Spi_SequenceType SpiSeq;

	SpiCh = TLE75242_List[chip].SpiCh;
	SpiSeq = TLE75242_List[chip].SpiSeq;
	
	g_SpiOutBuf_Tle75242 = (TLE75242_CMD_WRITE |(regName<<10)| CmdData);
	g_SpiInBuf_Tle75242 = 0;
	SuspendAllInterrupts();
	ret = Spi_SetupEB( SpiCh, (Spi_DataBufferType*)&g_SpiOutBuf_Tle75242, 
					(Spi_DataBufferType*)&g_SpiInBuf_Tle75242, 1u );
	if(ret == E_OK)
	{
		ret = Spi_SyncTransmit(SpiSeq);
	}
	ResumeAllInterrupts();
	return ret;
}

Std_ReturnType TLE75242_10bitDataRead(TLE75242_Chip_e_ chip, uint8 regName, uint16* RxData)
{
	Std_ReturnType ret = E_NOT_OK;
	Spi_ChannelType SpiCh;
    Spi_SequenceType SpiSeq;

	SpiCh = TLE75242_List[chip].SpiCh;
	SpiSeq = TLE75242_List[chip].SpiSeq;
	
	g_SpiOutBuf_Tle75242 = (TLE75242_CMD_READ | regName<<10);
	g_SpiInBuf_Tle75242 = 0;

    /**************************Diag frame ***************************************/
	SuspendAllInterrupts();
    ret = Spi_SetupEB( SpiCh, (Spi_DataBufferType*)&g_SpiOutBuf_Tle75242, 
					(Spi_DataBufferType*)&g_SpiInBuf_Tle75242, 1u );
	if(ret == E_OK)
	{
		Spi_SyncTransmit(SpiSeq);
	}
	ResumeAllInterrupts();
	SuspendAllInterrupts();
	/***************************data get frame***********************************/
	ret = Spi_SetupEB( SpiCh, (Spi_DataBufferType*)&g_SpiOutBuf_Tle75242, 
					(Spi_DataBufferType*)&g_SpiInBuf_Tle75242, 1u );
	if(ret == E_OK)
	{
		ret = Spi_SyncTransmit(SpiSeq);

		if(ret == E_OK)
		{
			*RxData = (g_SpiInBuf_Tle75242&TLE75XXX_10BIT_DATA_MAK);
		}
	}
	ResumeAllInterrupts();
	return ret;
}

static void TLE75242_PinOutputCtrl(TLE75242_Chip_e_ chip, uint16 channel, Dio_LevelType DioSt)
{
	if(chip == TLE75242_CHIP_A)
	{
		if(DioSt == STD_HIGH)
		{
			Pwm_SetPeriodAndDuty(channel,10000000,0x8000);
		}
		else
		{
			Pwm_SetPeriodAndDuty(channel,10000000,0);
		}
	}
	else
	{
		Dio_WriteChannel(channel, DioSt);
	}
}

void TLE75242_DataWrite(TLE75242_Chip_e_ chip, uint8 CmdData)
{
	Std_ReturnType ret = E_OK;
	uint8 regVal_u8 = 0;

	ret = TLE75242_8bitDataRead(chip, TLE75242_REG_OUT, &regVal_u8);
	if (ret == E_OK)
	{
		TLE75242_8bitDataWrite(chip, TLE75242_REG_OUT, CmdData);
	}
}
void TLE75242_OUT2_3_Switch(TLE75242_Chip_e_ chip, Dio_LevelType level,TLE75242_Channel_e_ channel)
{
	if(level == STD_LOW)
	{
		if(channel == TLE75242_CH_OUT2)
		{
			TLE75242_PinOutputCtrl(chip,TLE75252_CtrlPin_List[chip].IN0_Pin,STD_LOW);
		}
		if(channel == TLE75242_CH_OUT3)
		{
			TLE75242_PinOutputCtrl(chip,TLE75252_CtrlPin_List[chip].IN1_Pin,STD_LOW);
		}
		
		
	}
	else{
		if(channel == TLE75242_CH_OUT2)
		{
			TLE75242_PinOutputCtrl(chip,TLE75252_CtrlPin_List[chip].IN0_Pin,STD_HIGH);
		}
		if(channel == TLE75242_CH_OUT3)
		{
			TLE75242_PinOutputCtrl(chip,TLE75252_CtrlPin_List[chip].IN1_Pin,STD_HIGH);
		}
		
	}
		

}