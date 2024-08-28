/*
 * TLE75xxx.c
 *
 *  
 *      Author: 
 */
#include "TLE75004_Cfg.h"
#include "TLE75004_Api.h"
#include "IoExp_TCA6424A_Api.h"

#define TLE75XXX_8BIT_DATA_MAK    (0xFFu)

#define TEST_MSKBIT( u8data, bitmask )  (((u8data)&((uint8)(bitmask)))!= 0u)
#define GET_BITPOS( u8data, bitpos )  (TEST_MSKBIT((u8data),((uint8)1u<<((uint8)(bitpos))))?TRUE :FALSE)
#define TLE75004_CLEAR_BIT(value,pos) ((value)&=~(1<<(pos)))
#define TLE75004_SET_BIT(value,pos)   ((value)|= (1<<(pos)))

uint16 g_SpiOutBuf_TLE75004;
uint16 g_SpiInBuf_TLE75004;

static Std_ReturnType TLE75004_8bitDataWrite(uint8 regName, uint8 CmdData);
static Std_ReturnType TLE75004_8bitDataRead(uint8 regName, uint8* RxData);
Std_ReturnType TLE75004_tGetStdDiag(TLE75004_StdDiag_t *pStdDiag);


void TLE75004_Init(void)
{
	//OUT_EXP_B_P14; IDLE pin set high
	IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_B,IOEXP_TCA6424_P14,STD_HIGH);
	
	TLE75004_8bitDataWrite(TLE75004_REG_HWCR, 0x80);//bit HWCR.ACT (7) (Active Mode)
	//Init Diag_IOL Reg  //open all channel's current to diagnostic OLOFF
	TLE75004_8bitDataWrite(TLE75004_REG_DIAG_IOL, 0x03);//add for diag OLOFF for ALL channel
}

void TLE75004_Ctrl_PortOut(TLE75004_Channel_e_ Channel, TLE75004_ChSt_e_ ChannelSt)
{
	Std_ReturnType ret = E_OK;
	uint8 regVal_u8 = 0;

	ret = TLE75004_8bitDataRead(TLE75004_REG_OUT,&regVal_u8);
	
	TLE75004_CLEAR_BIT(regVal_u8, Channel);
	regVal_u8 |= (uint8)(ChannelSt << Channel);
	
	if(ret == E_OK)
	{
		TLE75004_8bitDataWrite(TLE75004_REG_OUT,regVal_u8);
	}
}

// void TLE75004_Output(uint8 CMD)
// {
//     TLE75004_StdDiag_t DiagReg;
// 	TLE75004_8bitDataWrite(TLE75004_REG_OUT, CMD);
//	// TLE75004_tGetStdDiag(&DiagReg);
// }

//ADD FOR DIAG Start
//diag for the ERRn bits in the standard diagnostic register 
uint8 TLE75004_Diag_ERRn(void)
{
    TLE75004_StdDiag_t pStdDiag;
	uint8 ERRn_Data = 0;
	
	TLE75004_tGetStdDiag(&pStdDiag);
	
	ERRn_Data = (uint8)(pStdDiag.bitdef.ERRn);
	
	return ERRn_Data;
}

void TLE75004_ClearAllOutputChError(void)
{
	TLE75004_8bitDataWrite(TLE75004_REG_HWCR_OCL ,0x0F);
}

void TLE75004_ResetChip(void)
{
	TLE75004_8bitDataWrite(TLE75004_REG_HWCR ,0x40);
}

//diag for the standard diagnostic register 
Std_ReturnType TLE75004_tGetStdDiag(TLE75004_StdDiag_t *pStdDiag)
{
	Std_ReturnType ret = E_NOT_OK;

	g_SpiOutBuf_TLE75004 = TLE75004_RREG_ADDRESS_STDDIAG;
	g_SpiInBuf_TLE75004 = 0;

    /**************************Diag frame ***************************************/
    ret = Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_TLE75004, (Spi_DataBufferType*)&g_SpiOutBuf_TLE75004, 
			                                             (Spi_DataBufferType*)&g_SpiInBuf_TLE75004, 1u );
	if(ret == E_OK)
	{
		Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_TLE75004);
	}
	
	/***************************data get frame***********************************/
	ret = Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_TLE75004, (Spi_DataBufferType*)&g_SpiOutBuf_TLE75004, 
					(Spi_DataBufferType*)&g_SpiInBuf_TLE75004, 1u );
	if(ret == E_OK)
	{
		ret = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_TLE75004);

		if(ret == E_OK)
		{
            /* Verify data invalid! */
		    if((g_SpiInBuf_TLE75004&0x8000) != 0)
		    {
		        ret = E_NOT_OK;
		    }
		    else
		    {
		        (*pStdDiag).worddef = (uint16) (g_SpiInBuf_TLE75004);
		        ret = E_OK;
		    }
			
		}
	}

	return ret;
}

//diag which channel is Overload
boolean TLE75004_DIAG_Overload(uint8 u8ChannelIndex)
{
	uint8 u8Error;
	boolean result = FALSE;
	TLE75004_StdDiag_t tStdDiag;
	
	TLE75004_tGetStdDiag((TLE75004_StdDiag_t*)(&tStdDiag));
	u8Error = tStdDiag.bitdef.ERRn;
	//for(u8ChannelIndex = 0; u8ChannelIndex < TLE75004_REG_CHANNEL_NUM ; u8ChannelIndex++)
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
boolean TLE75004_DIAG_OlOff()
{
	boolean result = FALSE;
	uint8 u8OlOffFlag;
	TLE75004_StdDiag_t tStdDiag;
	
	TLE75004_tGetStdDiag((TLE75004_StdDiag_t*)(&tStdDiag));
	
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

boolean TLE75004_Get_OutputStatusMonitor(void)
{
	boolean result = FALSE;
	uint8 regVal_u8 = 0;
	
	TLE75004_8bitDataRead(TLE75004_REG_DIAG_OSM,&regVal_u8);

	return regVal_u8;
	
//	if(regVal_u8 != 0)
//	{
//		result = TRUE;
//	}
//	else
//	{
//		result = FALSE;
//	}
//	return result;
}

static Std_ReturnType TLE75004_8bitDataWrite(uint8 regName, uint8 CmdData)
{
	Std_ReturnType ret = E_NOT_OK;
	
	g_SpiOutBuf_TLE75004 = (TLE75004_CMD_WRITE |(regName<<8)| CmdData);
	g_SpiInBuf_TLE75004 = 0;

	ret = Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_TLE75004, (Spi_DataBufferType*)&g_SpiOutBuf_TLE75004, 
			                                             (Spi_DataBufferType*)&g_SpiInBuf_TLE75004, 1u );
			                                             
	if(ret == E_OK)
	{
		ret = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_TLE75004);
	}

	return ret;
}

static Std_ReturnType TLE75004_8bitDataRead(uint8 regName, uint8* RxData)
{
	Std_ReturnType ret = E_NOT_OK;

	g_SpiOutBuf_TLE75004 = (TLE75004_CMD_READ | regName<<8);
	g_SpiInBuf_TLE75004 = 0;

    /**************************Diag frame ***************************************/
    ret = Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_TLE75004, (Spi_DataBufferType*)&g_SpiOutBuf_TLE75004, 
			                                             (Spi_DataBufferType*)&g_SpiInBuf_TLE75004, 1u );
	if(ret == E_OK)
	{
		Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_TLE75004);
	}
	
	/***************************data get frame***********************************/
	ret = Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_TLE75004, (Spi_DataBufferType*)&g_SpiOutBuf_TLE75004, 
					(Spi_DataBufferType*)&g_SpiInBuf_TLE75004, 1u );
	if(ret == E_OK)
	{
		ret = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_TLE75004);

		if(ret == E_OK)
		{
            /* Verify data invalid! */
		    if((g_SpiInBuf_TLE75004&0xff00) != (0x8000 | regName<<8))
		    {
		        ret = E_NOT_OK;
		    }
		    else
		    {
		        *RxData = (g_SpiInBuf_TLE75004&TLE75XXX_8BIT_DATA_MAK);
		        ret = E_OK;
		    }
			
		}
	}

	return ret;
}

void TLE75004_Output(uint8 CMD)
{
	TLE75004_8bitDataWrite(TLE75004_REG_OUT, CMD);
}