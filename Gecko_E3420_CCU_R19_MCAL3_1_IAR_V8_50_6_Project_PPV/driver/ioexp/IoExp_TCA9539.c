#include "IoExp_TCA9539_Cfg.h"
#include "IoExp_TCA9539_Api.h"
#include "IoExp_TCA6424A_Api.h"

#include "I2c.h"
#include "I2c_Cfg.h"


uint8 Tca9539_IOValue[CHANNEL_NUM][CHIP_PIN_ID] ={{0,0}};

extern unsigned char NACK;
I2c_adap_dev_t *I2c_adap_dev_TCA9539[TCA9539_CHIP_NUM];
I2c_adap_dev_t *I2c3_adap_dev;

uint8 TCA9539_wbuf1[4];
uint8 TCA9539_PortInRegVal_u8[TCA9539_CHIP_NUM][TCA9539_PORTGROUPNUM];

#define TCA9539_CLEAR_BIT(value,pos) ((value)&=~(1<<(pos)))
#define TCA9539_SET_BIT(value,pos)   ((value)|= (1<<(pos)))

WakeupSourceType WakeUpSource[WAKEUP_SOURCE_NUM]=
{
    {28,0x34,0xFF},/*BMS*/
    {27,0x33,0xFF},/*OBC*/
    {24,0x32,0xFF},/*IG1*/
    {25,0x32,0xFF},/*IG2*/
    {20,0x35,0x01},/*Brake fall*/
    {26,0x36,0x02},/*Brake up*/
    {11,0x37,0x03},/*Engine cover CN12-8*/
    {2,0x38,0x04},/*Warning CN12-33*/
    {6,0x39,0x05},/*Driver door lock CN12-35*/
    {7,0x3A,0x06},/*Driver door CN12-21*/
    {8,0x3B,0x07},/*Front passenger CN12-10*/
    {13,0x3C,0x08},/*left door CN12-20*/
    {14,0x3D,0x09},/*Right door CN12-6*/
    {12,0x3E,0x0A},/*back door CN12-7*/
    {21,0x3F,0x0B},/*Left PE CN12-38*/
    {22,0x40,0x0C},/*Right PE CN12-37*/
    {23,0x41,0x0D},/*back PE CN12-36*/
    {15,0x42,0x0E},/*Alarm CN12-19*/
    {4,0x11,0xFF},/*NM*/
    {4,0x13,0xFF},/*Lin*/
    {4,0x12,0xFF},/*Applicaton Pdu*/
    {4,0x31,0xFF},/*RF*/
    {4,0x22,0xFF},/*RTC*/
    {4,0xFF,0xFF}/*Other*/
};

const TCA9539_Ctrl_t TCA9539_CrtlList[TCA9539_CHIP_NUM] = 
{
//     {
//         .I2C_Channel        = I2cConf_I2cChannel_I2cChannel_I2C3,
// //        .I2C_CtrlBlock      = I2c_adap_dev_TCA9539[TCA9539_CHIP_A],
//         .Device_Addr        = TCA9539_A_ADDRESS,
//         .Port0Dir           = TCA9539_PORTDIRALLOUT,
//         .Port1Dir           = TCA9539_PORTDIRALLOUT,
//         .RstPin             = DioConf_DioChannel_RESET_6424_BD_9539,
//     },

    {
        .I2C_Channel        = I2cConf_I2cChannel_I2cChannel_I2C3,
//        .I2C_CtrlBlock      = I2c_adap_dev_TCA9539[TCA9539_CHIP_B],
        .Device_Addr        = TCA9539_A_ADDRESS,
        .Port0Dir           = TCA9539_PORTDIRALLIN,
        .Port1Dir           = TCA9539_PORTDIRALLIN,
        .RstPin             = IOEXP_TCA6424_P05,        //OUT_EXP_A_P05
    },

    {
        .I2C_Channel        = I2cConf_I2cChannel_I2cChannel_I2C3,
//        .I2C_CtrlBlock      = I2c_adap_dev_TCA9539[TCA9539_CHIP_C],
        .Device_Addr        = TCA9539_B_ADDRESS,
        .Port0Dir           = TCA9539_PORTDIRALLIN,
        .Port1Dir           = TCA9539_PORTDIRALLIN,
        .RstPin             = IOEXP_TCA6424_P05,        //OUT_EXP_A_P05
    }
};

// ****************************************************************************
//! @fn          void TCA9539InitDefault(TCA9539Regs* Regs)
//! @brief
//!				 Initializes the confRegs structure which is
//!              a local mirror of the TPL7200 config registers
//!              additional TPL7200writeConfigRegisters(confRegs) function call
//! 			 is needed in order to get the TPL7200 registers updated
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA9539InitDefault(TCA9539Regs* Regs){
	Regs->Output.all = 0x00FFFFFF;
	Regs->PolarityInversion.all = 0x00000000;
	Regs->Config.all = 0x00000000;//all is output
}


// ****************************************************************************
//! @fn          void TCA9539InitI2CReg(TCA9539Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA9539InitI2CReg(TCA9539Regs* Regs){
	//I2c_write(3, TCA9539_A_ADDRESS, TCA9539_POLARITY_REG0 | 0x80, (unsigned char*)&Regs->PolarityInversion, 0);
	//I2c_write(3, TCA9539_A_ADDRESS, TCA9539_CONFIG_REG0 | 0x80, (unsigned char*)&Regs->Config, 0);
	//I2c_write(3, TCA9539_A_ADDRESS, TCA9539_OUTPUT_REG0 | 0x80, (unsigned char*)&Regs->Output, 0);

}

// ****************************************************************************
//! @fn          void TCA9539ReadInputReg(TCA9539Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA9539ReadInputReg(TCA9539Regs* Regs)
{
	//I2c_read(3,TCA9539_A_ADDRESS, TCA9539_INPUT_REG0 | 0x80, (unsigned char *)&Regs->Input);
}


// ****************************************************************************
//! @fn          void TCA9539InitI2CReg(TCA9539Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA9539WriteReg(unsigned char regaddress, unsigned char regVal)
{
	//I2c_write_Byte(TCA9539_A_ADDRESS, regaddress, regVal);
	if(NACK)
	{
		//handle I2C failure later

	}

}

unsigned char TCA9539ReadReg(unsigned char address, unsigned char regaddress)
{
	//return (unsigned char) I2C_Read_Byte(address,regaddress);
}

void TCA9539WriteConfig(TCA9539Regs * Regs)
{
	//I2c_write(3, TCA9539_A_ADDRESS, TCA9539_CONFIG_REG0 | 0x80, (unsigned char*)&Regs->Config, 0);
}

void TCA9539WriteOutput(TCA9539Regs * Regs)
{
	//I2c_write(3, TCA9539_A_ADDRESS, TCA9539_OUTPUT_REG0 | 0x80, (unsigned char*)&Regs->Output, 0);
}

void TCA9539WritePolarity(TCA9539Regs * Regs)
{
	//I2c_write(3, TCA9539_A_ADDRESS, TCA9539_POLARITY_REG0 | 0x80, (unsigned char*)&Regs->PolarityInversion, 0);
}

void TCA9539AReadChannel_P0(TCA9539_ChipID_e_ ChipID, uint8 *read_buffer)
{
	switch (ChipID)
	{
	case TCA9539_CHIP_A:
		/* code */
		I2c_read_reg(I2c3_adap_dev, TCA9539_A_ADDRESS, TCA9539_INPUT_REG0, read_buffer);
		break;
	case TCA9539_CHIP_B:
		/* code */
		I2c_read_reg(I2c3_adap_dev, TCA9539_B_ADDRESS, TCA9539_INPUT_REG0, read_buffer);
		break;
	
	default:
		break;
	}

}

void TCA9539AReadChannel_P1(TCA9539_ChipID_e_ ChipID, uint8 *read_buffer)
{
	switch (ChipID)
	{
	case TCA9539_CHIP_A:
		/* code */
		I2c_read_reg(I2c3_adap_dev, TCA9539_A_ADDRESS, TCA9539_INPUT_REG1, read_buffer);
		break;
	case TCA9539_CHIP_B:
		/* code */
		I2c_read_reg(I2c3_adap_dev, TCA9539_B_ADDRESS, TCA9539_INPUT_REG1, read_buffer);
		break;
	
	default:
		break;
	}

}


static void I2c_Init_Device(void)
{
    TCA9539_ChipID_e_ chipid = TCA9539_CHIP_B;

    /*init i2c ctrl block */
    for(chipid = TCA9539_CHIP_A; chipid < TCA9539_CHIP_NUM; chipid++)
    {
//        TCA9539_CrtlList[chipid].I2C_CtrlBlock = I2cGlobalDev[TCA9539_CrtlList[chipid].I2C_Channel];
        I2c_adap_dev_TCA9539[chipid] = I2cGlobalDev[TCA9539_CrtlList[chipid].I2C_Channel];
        I2c_adap_dev_TCA9539[chipid]->retry = 2; 
    }
    //release reset pin
    //Dio_WriteChannel(TCA9539_CrtlList[TCA9539_CHIP_A].RstPin,STD_HIGH);
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_A,TCA9539_CrtlList[TCA9539_CHIP_B].RstPin,STD_LOW);
}

static void IoExp_TCA9539_InitPortDir(void)
{
    TCA9539_ChipID_e_ chipid = TCA9539_CHIP_B;
    uint8 buf_w[3];

    /* Init chip port direction register */
    for(chipid = TCA9539_CHIP_A; chipid < TCA9539_CHIP_NUM; chipid++)
    {
         /* clear contrl REG at first to set all port not output */
        buf_w[0] = TCA9539_OUTPUT_REG0;
        buf_w[1] = 0x00;
    	buf_w[2] = 0x00;
        I2c_write(I2c_adap_dev_TCA9539[chipid], 
                 TCA9539_CrtlList[chipid].Device_Addr, buf_w, 3);

        /* Config port direction */         
        buf_w[0] = TCA9539_CONFIG_REG0;
        buf_w[1] =  TCA9539_CrtlList[chipid].Port0Dir;
        buf_w[2] =  TCA9539_CrtlList[chipid].Port1Dir;
        
        I2c_write(I2c_adap_dev_TCA9539[chipid], 
                 TCA9539_CrtlList[chipid].Device_Addr, buf_w, 3);
    }
}

void TCA9539_Init(void)
{
    I2c_Init_Device();
    IoExp_TCA9539_InitPortDir();
}

Std_ReturnType IoExp_TCA9539_SetChannelOutLevel(TCA9539_ChipID_e_ ChipID, 
                                                                TCA9539_Channel_e_ ChannelNum, Dio_LevelType OutLevel)
{
    Std_ReturnType ret = E_OK;
    uint8 regVal_u8 = 0;
    uint8 regAddr_u8 = 0;
    uint8 channelPos = 0;
    TCA9539_PortGoup_e_ portId;
    uint8 regbuf_w[2] = {0};

    if(ChannelNum < IOEXP_TCA9539_PORT_NUM)
    {
        /*get channel position*/
        if( ChannelNum < IOEXP_TCA9539_P10)   /*PORT 0*/
        {
//            regVal_u8 =  TCA9539_PortInRegVal_u8[ChipID][TCA9539_PORTGROUP0];
            channelPos = ChannelNum;
            regAddr_u8 = TCA9539_OUTPUT_REG0;
//            portId = TCA9539_PORTGROUP0;
        }
        else  /* port 1*/
        {
//            regVal_u8 =  TCA9539_PortInRegVal_u8[ChipID][TCA9539_PORTGROUP1];
            channelPos = ChannelNum - IOEXP_TCA9539_P10;
            regAddr_u8 = TCA9539_OUTPUT_REG1;
//            portId = TCA9539_PORTGROUP1;
        }

        /* Read current port status */
        ret = I2c_read_reg(I2c_adap_dev_TCA9539[ChipID], 
                       TCA9539_CrtlList[ChipID].Device_Addr,regAddr_u8, &regVal_u8);
                       
        if(ret == E_OK)
        {
            if(OutLevel == STD_LOW)
            {
                TCA9539_CLEAR_BIT(regVal_u8,channelPos);
            }
            else
            {
                TCA9539_SET_BIT(regVal_u8,channelPos);
            }
            
           regbuf_w[0] = regAddr_u8;
           regbuf_w[1] = regVal_u8;

            // ret = I2c_write_reg(I2c_adap_dev_TCA9539[ChipID], 
            //                                 TCA9539_CrtlList[ChipID].Device_Addr, regAddr_u8, regVal_u8);
           ret = I2c_write(I2c_adap_dev_TCA9539[ChipID], 
                                         TCA9539_CrtlList[ChipID].Device_Addr, regbuf_w, 2);
    //        if(ret == E_OK)
    //        {
    //            TCA9539_PortInRegVal_u8[ChipID][portId] = regVal_u8;
    //        }
        }
        
    }
    else
    {
        ret = E_NOT_OK;
    }
   
    return ret;
}

Std_ReturnType IoExp_TCA9539_SetAllPortHigh(TCA9539_ChipID_e_ ChipID)
{
    Std_ReturnType ret = E_OK;
    uint8 regVal_u8 = 0xff;

    TCA9539_wbuf1[0] =TCA9539_OUTPUT_REG0;
    TCA9539_wbuf1[1] = 0xFF;
	TCA9539_wbuf1[2] = 0xFF;
    
    ret = I2c_write(I2c_adap_dev_TCA9539[ChipID], 
                    TCA9539_CrtlList[ChipID].Device_Addr, TCA9539_wbuf1, 3);

//    if(ret == E_OK)
//    {
//        TCA9539_PortInRegVal_u8[ChipID][0] = TCA9539_wbuf1[1];
//        TCA9539_PortInRegVal_u8[ChipID][1] = TCA9539_wbuf1[2];
//    }
    
    return ret;
}

Std_ReturnType IoExp_TCA9539_SetAllPortLow(TCA9539_ChipID_e_ ChipID)
{
    Std_ReturnType ret = E_OK;
    
    TCA9539_wbuf1[0] =TCA9539_OUTPUT_REG0;
    TCA9539_wbuf1[1] = 0x00;
	TCA9539_wbuf1[2] = 0x00;
    
    ret = I2c_write(I2c_adap_dev_TCA9539[ChipID], TCA9539_CrtlList[ChipID].Device_Addr, TCA9539_wbuf1, 3);

//    if(ret == E_OK)
//    {
//        TCA9539_PortInRegVal_u8[ChipID][0] = TCA9539_wbuf1[1];
//        TCA9539_PortInRegVal_u8[ChipID][1] = TCA9539_wbuf1[2];
//    }

    return ret;
}

///Notice : Only could be used for port configed for input
Std_ReturnType IoExp_TCA9539_GetPortInputValue(TCA9539_ChipID_e_ ChipID, TCA9539_PortGoup_e_ PortIdx,uint8* PortValue)
{
    uint8 regAddr_u8 = 0;
    Std_ReturnType ret = E_NOT_OK;
    
//    regVal_u8 =  TCA9539_PortInRegVal_u8[ChipID][PortIdx];

    if(TCA9539_PORTGROUP0 == PortIdx)
    {
        regAddr_u8 = TCA9539_INPUT_REG0;
    }
    else
    {
        regAddr_u8 = TCA9539_INPUT_REG1;
    }
        
    ret = I2c_read_reg(I2c_adap_dev_TCA9539[ChipID], 
                       TCA9539_CrtlList[ChipID].Device_Addr,regAddr_u8, PortValue);                   
    return ret;
}

///Notice : Only could be used for port configed for input
Dio_LevelType IoExp_TCA9539_GetChannelInputLevel(TCA9539_ChipID_e_ ChipID, TCA9539_Channel_e_ Channel)
{
    uint8 regVal_u8 = 0;
    Dio_LevelType InputLevel = STD_LOW;
    uint8 channelPos = 0;
    uint8 regAddr_u8 = 0;
    
    if( Channel < IOEXP_TCA9539_P10)   /*PORT 0*/
    {
//        regVal_u8 =  TCA9539_PortInRegVal_u8[ChipId][0];
        channelPos = Channel;
        regAddr_u8 = TCA9539_INPUT_REG0;
    }
    else  /* port 1*/
    {
//        regVal_u8 =  TCA9539_PortInRegVal_u8[ChipId][1];
        channelPos = Channel - IOEXP_TCA9539_P10;
        regAddr_u8 = TCA9539_INPUT_REG1;
    }

    I2c_read_reg(I2c_adap_dev_TCA9539[ChipID], 
                       TCA9539_CrtlList[ChipID].Device_Addr,regAddr_u8, &regVal_u8);
                       
    if((regVal_u8 & (1<<channelPos))!= 0u)
    {
        InputLevel = STD_HIGH;
    }
    else
    {
        InputLevel = STD_LOW;
    }

    return InputLevel;
    
}


///Notice : Only could be used for port configed for output
Dio_LevelType IoExp_TCA9539_GetChannelOutputSt(TCA9539_ChipID_e_ ChipID, TCA9539_Channel_e_ Channel)
{
    uint8 regVal_u8 = 0;
    Dio_LevelType InputLevel = STD_LOW;
    uint8 channelPos = 0;
    uint8 regAddr_u8 = 0;
    
    if( Channel < IOEXP_TCA9539_P10)   /*PORT 0*/
    {
//        regVal_u8 =  TCA9539_PortInRegVal_u8[ChipId][0];
        channelPos = Channel;
        regAddr_u8 = TCA9539_OUTPUT_REG0;
    }
    else  /* port 1*/
    {
//        regVal_u8 =  TCA9539_PortInRegVal_u8[ChipId][1];
        channelPos = Channel - IOEXP_TCA9539_P10;
        regAddr_u8 = TCA9539_OUTPUT_REG1;
    }

    I2c_read_reg(I2c_adap_dev_TCA9539[ChipID], 
                       TCA9539_CrtlList[ChipID].Device_Addr,regAddr_u8, &regVal_u8);
                       
    if((regVal_u8 & (1<<channelPos))!= 0u)
    {
        InputLevel = STD_HIGH;
    }
    else
    {
        InputLevel = STD_LOW;
    }

    return InputLevel;
    
}
#pragma default_function_attributes = @".iram_func"
void Gpio_TCA9539_ReadValue()
{
	uint8 channel_id =0;//only for input chip 
	uint8  pin_id=0;
    uint8  pin_id_post =0;
	uint8 regVal_u8[2] = {(uint8)0,(uint8)0};
    static uint8 Old_Regval[2] = {(uint8)0,(uint8)0};
    uint8 retrytimes = 3;
    uint8 retrytimes1 = 3;
	Std_ReturnType ret = E_NOT_OK;
	for(channel_id = 0; channel_id < CHANNEL_NUM; channel_id ++)
	{
        //ret = IoExp_TCA9539_GetPortInputValue(channel_id,TCA9539_PORTGROUP0,&regVal_u8[0]);
        #if 1 
        while( (ret = IoExp_TCA9539_GetPortInputValue(channel_id,TCA9539_PORTGROUP0,(uint8*)(&regVal_u8[0])))!= E_OK)
        {
            
            if(retrytimes == 0)
            {
                regVal_u8[0] = Old_Regval[0];
                break;
            }
            else{
                retrytimes--;
            }
        }
        if(ret == E_OK)
        {
            Old_Regval[0] = regVal_u8[0];
        }  
        #endif
        //ret|= IoExp_TCA9539_GetPortInputValue(channel_id,TCA9539_PORTGROUP1,&regVal_u8[1]);
       #if 1
        while((ret = IoExp_TCA9539_GetPortInputValue(channel_id,TCA9539_PORTGROUP1,(uint8*)(&regVal_u8[1]))) != E_OK)
        {
            if(retrytimes1 == 0)
            {
                regVal_u8[1] = Old_Regval[1];
                break;
            }
            else{
                retrytimes1--;
            }
        }
        if(ret == E_OK)
        {
            Old_Regval[1] = regVal_u8[1];
        }
        #endif
		//if(E_NOT_OK== ret) return ;
        for(pin_id =0; pin_id< CHIP_PIN_ID ; pin_id++)
        {
            if(pin_id < IOEXP_TCA9539_P10)
            {
                    Tca9539_IOValue[channel_id][pin_id]= ((regVal_u8[0] & (1<< pin_id))>> pin_id) ;//port0-7
            }
            else 
            {      
                    pin_id_post = pin_id - IOEXP_TCA9539_P10;
                    Tca9539_IOValue[channel_id][pin_id]= ((regVal_u8[1] & (1<< pin_id_post))>> pin_id_post) ;//port10-port17
            }
        }
	}
}
#pragma default_function_attributes =