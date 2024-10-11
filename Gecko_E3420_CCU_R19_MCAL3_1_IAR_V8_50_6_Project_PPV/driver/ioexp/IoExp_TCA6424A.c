#include "IoExp_TCA6424A_Cfg.h"
#include "IoExp_TCA6424A_Api.h"

#include "I2c.h"
#include "I2c_Cfg.h"



extern unsigned char NACK;
I2c_adap_dev_t *I2c_adap_dev_tca6424[TCA6424_CHIP_NUM];
I2c_adap_dev_t *I2c6_adap_dev1;
I2c_adap_dev_t *I2c7_adap_dev1;
uint8 wbuf1[4];
uint8 rbuf1[4];
uint8 PortInRegVal_u8[TCA6424_CHIP_NUM][TCA6424_PORTGROUPNUM];

#define TCA6424_CLEAR_BIT(value,pos) ((value)&=~(1<<(pos)))
#define TCA6424_SET_BIT(value,pos)   ((value)|= (1<<(pos)))


const TCA6424_Ctrl_t TCA6424_CrtlList[TCA6424_CHIP_NUM] = 
{
    {
        .I2C_Channel        = I2cConf_I2cChannel_I2cChannel_I2C1,
//        .I2C_CtrlBlock      = I2c_adap_dev_tca6424[TCA6424_CHIP_A],
        .Device_Addr        = TCA6424A_A_ADDRESS,
        .Port0Dir           = TCA6424_PORTDIRALLOUT,
        .Port1Dir           = TCA6424_PORTDIRALLOUT,
        .Port2Dir           = TCA6424_PORTDIRALLOUT,
        .RstPin             = DioConf_DioChannel_RESET_6424_AC_IN,
    },

    {
        .I2C_Channel        = I2cConf_I2cChannel_I2cChannel_I2C2,
//        .I2C_CtrlBlock      = I2c_adap_dev_tca6424[TCA6424_CHIP_B],
        .Device_Addr        = TCA6424A_B_ADDRESS,
        .Port0Dir           = TCA6424_PORTDIRALLOUT,
        .Port1Dir           = TCA6424_PORTDIRALLOUT,
        .Port2Dir           = TCA6424_PORTDIRALLOUT,
        .RstPin             = DioConf_DioChannel_RESET_6424_BD_9539,
    },

    {
        .I2C_Channel        = I2cConf_I2cChannel_I2cChannel_I2C1,
//        .I2C_CtrlBlock      = I2c_adap_dev_tca6424[TCA6424_CHIP_C],
        .Device_Addr        = TCA6424A_C_ADDRESS,
        .Port0Dir           = TCA6424_C_PORT0DIR,
        .Port1Dir           = TCA6424_C_PORT1DIR,
        .Port2Dir           = TCA6424_C_PORT2DIR,
        .RstPin             = DioConf_DioChannel_RESET_6424_AC_IN,
    },

    {
        .I2C_Channel        = I2cConf_I2cChannel_I2cChannel_I2C2,
//        .I2C_CtrlBlock      = I2c_adap_dev_tca6424[TCA6424_CHIP_D],
        .Device_Addr        = TCA6424A_D_ADDRESS,
        .Port0Dir           = TCA6424_PORTDIRALLOUT,
        .Port1Dir           = TCA6424_PORTDIRALLOUT,
        .Port2Dir           = TCA6424_PORTDIRALLOUT,
        .RstPin             = DioConf_DioChannel_RESET_6424_BD_9539,
    },

    {
        .I2C_Channel        = I2cConf_I2cChannel_I2cChannel_I2C3,
//        .I2C_CtrlBlock      = I2c_adap_dev_tca6424[TCA6424_CHIP_E],
        .Device_Addr        = TCA6424A_E_ADDRESS,
        .Port0Dir           = TCA6424_PORTDIRALLOUT,
        .Port1Dir           = TCA6424_PORTDIRALLOUT,
        .Port2Dir           = TCA6424_PORTDIRALLOUT,
        .RstPin             = DioConf_DioChannel_RESET_6424_BD_9539,
    }
};

// ****************************************************************************
//! @fn          void TCA6424AInitDefault(TCA6424ARegs* Regs)
//! @brief
//!				 Initializes the confRegs structure which is
//!              a local mirror of the TPL7200 config registers
//!              additional TPL7200writeConfigRegisters(confRegs) function call
//! 			 is needed in order to get the TPL7200 registers updated
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6424AInitDefault(TCA6424ARegs* Regs){
	Regs->Output.all = 0x00FFFFFF;
	Regs->PolarityInversion.all = 0x00000000;
	Regs->Config.all = 0x00000000;//all is output
}


// ****************************************************************************
//! @fn          void TCA6424AInitI2CReg(TCA6424ARegs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6424AInitI2CReg(TCA6424ARegs* Regs){
	//I2c_write(3, TCA6424A_A_ADDRESS, TCA6424A_POLARITY_REG0 | 0x80, (unsigned char*)&Regs->PolarityInversion, 0);
	//I2c_write(3, TCA6424A_A_ADDRESS, TCA6424A_CONFIG_REG0 | 0x80, (unsigned char*)&Regs->Config, 0);
	//I2c_write(3, TCA6424A_A_ADDRESS, TCA6424A_OUTPUT_REG0 | 0x80, (unsigned char*)&Regs->Output, 0);

}

// ****************************************************************************
//! @fn          void TCA6424AReadInputReg(TCA6424ARegs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6424AReadInputReg(TCA6424ARegs* Regs)
{
	//I2c_read(3,TCA6424A_A_ADDRESS, TCA6424A_INPUT_REG0 | 0x80, (unsigned char *)&Regs->Input);
}


// ****************************************************************************
//! @fn          void TCA6424AInitI2CReg(TCA6424ARegs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6424AWriteReg(unsigned char regaddress, unsigned char regVal)
{
	//I2c_write_Byte(TCA6424A_A_ADDRESS, regaddress, regVal);
	if(NACK)
	{
		//handle I2C failure later

	}

}

unsigned char TCA6424AReadReg(unsigned char address, unsigned char regaddress)
{
	//return (unsigned char) I2C_Read_Byte(address,regaddress);
}

void TCA6424AWriteConfig(TCA6424ARegs * Regs)
{
	//I2c_write(3, TCA6424A_A_ADDRESS, TCA6424A_CONFIG_REG0 | 0x80, (unsigned char*)&Regs->Config, 0);
}

void TCA6424AWriteOutput(TCA6424ARegs * Regs)
{
	//I2c_write(3, TCA6424A_A_ADDRESS, TCA6424A_OUTPUT_REG0 | 0x80, (unsigned char*)&Regs->Output, 0);
}

void TCA6424AWritePolarity(TCA6424ARegs * Regs)
{
	//I2c_write(3, TCA6424A_A_ADDRESS, TCA6424A_POLARITY_REG0 | 0x80, (unsigned char*)&Regs->PolarityInversion, 0);
}

static void I2c_Init_Device(void)
{
    TCA6424_ChipID_e_ chipid = TCA6424_CHIP_A;

    /*init i2c ctrl block */
    for(chipid = TCA6424_CHIP_A; chipid < TCA6424_CHIP_NUM; chipid++)
    {
//        TCA6424_CrtlList[chipid].I2C_CtrlBlock = I2cGlobalDev[TCA6424_CrtlList[chipid].I2C_Channel];
        I2c_adap_dev_tca6424[chipid] = I2cGlobalDev[TCA6424_CrtlList[chipid].I2C_Channel];
        Dio_WriteChannel(TCA6424_CrtlList[chipid].RstPin,STD_HIGH);
    }
}

static void IoExp_TCA6242_InitPortDir(void)
{
    TCA6424_ChipID_e_ chipid = TCA6424_CHIP_A;
    uint8 buf_w[4];

    /* Init chip port direction register */
    for(chipid = TCA6424_CHIP_A; chipid < TCA6424_CHIP_NUM; chipid++)
    {
        /* clear contrl REG at first to set all port not output */
        buf_w[0] = TCA6424A_OUTPUT_REG0 | TCA6424_CMD_WRIRE;
        buf_w[1] = 0x00;
    	buf_w[2] = 0x00;
    	buf_w[3] = 0x00;
        if(chipid == TCA6424_CHIP_D)
        {
            buf_w[3] = 0x80;
        }
        I2c_write(I2c_adap_dev_tca6424[chipid], 
                 TCA6424_CrtlList[chipid].Device_Addr, buf_w, 4);

        /* Config port direction */
        buf_w[0] = TCA6424A_CONFIG_REG0 | TCA6424_CMD_WRIRE;
        buf_w[1] =  TCA6424_CrtlList[chipid].Port0Dir;
        buf_w[2] =  TCA6424_CrtlList[chipid].Port1Dir;
        buf_w[3] =  TCA6424_CrtlList[chipid].Port2Dir;
        
        I2c_write(I2c_adap_dev_tca6424[chipid], 
                 TCA6424_CrtlList[chipid].Device_Addr, buf_w, 4);
    }
}

void TCA6424_Init(void)
{
    I2c_Init_Device();
    IoExp_TCA6242_InitPortDir();
}

Std_ReturnType IoExp_TCA6424_SetChannelOutLevel(TCA6424_ChipID_e_ ChipID, 
                                                                TCA6424_Channel_e_ ChannelNum, Dio_LevelType OutLevel)
{
    Std_ReturnType ret = E_OK;
    uint8 regVal_u8 = 0;
    uint8 regAddr_u8 = 0;
    uint8 channelPos = 0;
    TCA6424_PortGoup_e_ portId;
    uint8 regbuf_w[2] = {0};

    if(ChannelNum < IOEXP_TCA6424_PORT_NUM)
    {
        /*get channel position*/
        if( ChannelNum < IOEXP_TCA6424_P10)   /*PORT 0*/
        {
//            regVal_u8 =  PortInRegVal_u8[ChipID][TCA6424_PORTGROUP0];
            channelPos = ChannelNum;
            regAddr_u8 = TCA6424A_OUTPUT_REG0;
            portId = TCA6424_PORTGROUP0;
        }
        else if(ChannelNum <IOEXP_TCA6424_P20 )  /* port 1*/
        {
//            regVal_u8 =  PortInRegVal_u8[ChipID][TCA6424_PORTGROUP1];
            channelPos = ChannelNum - IOEXP_TCA6424_P10;
            regAddr_u8 = TCA6424A_OUTPUT_REG1;
            portId = TCA6424_PORTGROUP1;
        }
        else                                   /*port 2*/
        {
//            regVal_u8 =  PortInRegVal_u8[ChipID][TCA6424_PORTGROUP2];
            channelPos = ChannelNum - IOEXP_TCA6424_P20;
            regAddr_u8 = TCA6424A_OUTPUT_REG2;
            portId = TCA6424_PORTGROUP2;
        }

        /* Read current port status */
//        regVal_u8 = IoExp_TCA6424_GetPortInputValue(ChipID,portId);
        I2c_read_reg(I2c_adap_dev_tca6424[ChipID], 
                             TCA6424_CrtlList[ChipID].Device_Addr,regAddr_u8, &regVal_u8);

        if(OutLevel == STD_LOW)
        {
            TCA6424_CLEAR_BIT(regVal_u8,channelPos);
        }
        else
        {
            TCA6424_SET_BIT(regVal_u8,channelPos);
        }
        
        regbuf_w[0] = regAddr_u8 | TCA6424_CMD_WRIRE;
        regbuf_w[1] = regVal_u8;
        ret = I2c_write(I2c_adap_dev_tca6424[ChipID], TCA6424_CrtlList[ChipID].Device_Addr, regbuf_w, 2);
        // ret = I2c_write_reg(I2c_adap_dev_tca6424[chipid], 
        //                      TCA6424_CrtlList[ChipID].Device_Addr, regAddr_u8 | TCA6424_CMD_WRIRE, regVal_u8);
        if(ret == E_OK)
        {
            PortInRegVal_u8[ChipID][portId] = regVal_u8;
        }
    }
    else
    {
        ret = E_NOT_OK;
    }
   
    return ret;
}

Std_ReturnType IoExp_TCA6424_SetAllPortHigh(TCA6424_ChipID_e_ ChipID)
{
    Std_ReturnType ret = E_OK;
    uint8 regVal_u8 = 0xff;

    wbuf1[0] =TCA6424A_OUTPUT_REG0 | TCA6424_CMD_WRIRE;
    wbuf1[1] = 0xFF;
	wbuf1[2] = 0xFF;
	wbuf1[3] = 0xFF;
    
    ret = I2c_write(I2c_adap_dev_tca6424[ChipID], TCA6424_CrtlList[ChipID].Device_Addr, wbuf1, 4);

//    if(ret == E_OK)
//    {
//        PortInRegVal_u8[ChipID][0] = wbuf1[1];
//        PortInRegVal_u8[ChipID][1] = wbuf1[2];
//        PortInRegVal_u8[ChipID][2] = wbuf1[3];
//    }
    
    return ret;
}

Std_ReturnType IoExp_TCA6424_SetAllPortLow(TCA6424_ChipID_e_ ChipID)
{
    Std_ReturnType ret = E_OK;
    
    wbuf1[0] =TCA6424A_OUTPUT_REG0 | TCA6424_CMD_WRIRE;
    wbuf1[1] = 0x00;
	wbuf1[2] = 0x00;
	wbuf1[3] = 0x00;
    
    ret = I2c_write(I2c_adap_dev_tca6424[ChipID], 
                                    TCA6424_CrtlList[ChipID].Device_Addr, wbuf1, 4);

//    if(ret == E_OK)
//    {
//        PortInRegVal_u8[ChipID][0] = wbuf1[1];
//        PortInRegVal_u8[ChipID][1] = wbuf1[2];
//        PortInRegVal_u8[ChipID][2] = wbuf1[3];
//    }

    return ret;
}

/* Notice : Only could be used for port configed for input */
uint8 IoExp_TCA6424_GetPortInputValue(TCA6424_ChipID_e_ ChipID, TCA6424_PortGoup_e_ PortIdx)
{
    uint8 regVal_u8 = 0;
    uint8 regAddr_u8 = 0;
    
//    regVal_u8 =  PortInRegVal_u8[ChipID][PortIdx];
    if(TCA6424_PORTGROUP0 == PortIdx)
    {
        regAddr_u8 = TCA6424A_INPUT_REG0;
    }
    else if(TCA6424_PORTGROUP1 == PortIdx)
    {
        regAddr_u8 = TCA6424A_INPUT_REG1;
    }
    else
    {
        regAddr_u8 = TCA6424A_INPUT_REG2;
    }
        
    I2c_read_reg(I2c_adap_dev_tca6424[ChipID], 
                             TCA6424_CrtlList[ChipID].Device_Addr,regAddr_u8, &regVal_u8);


    return regVal_u8;
    
}

/* Notice : Only could be used for port configed for input */
Dio_LevelType IoExp_TCA6424_GetChannelInputLevel(TCA6424_ChipID_e_ ChipID, TCA6424_Channel_e_ Channel)
{
    uint8 regVal_u8 = 0;
    Dio_LevelType InputLevel = STD_LOW;
    uint8 channelPos = 0;
    uint8 regAddr_u8 = 0;
    
    if( Channel < IOEXP_TCA6424_P10)   /*PORT 0*/
    {
//        regVal_u8 =  PortInRegVal_u8[ChipID][0];
        channelPos = Channel;
        regAddr_u8 = TCA6424A_INPUT_REG0;
    }
    else if(Channel <IOEXP_TCA6424_P20 )  /* port 1*/
    {
//        regVal_u8 =  PortInRegVal_u8[ChipID][1];
        channelPos = Channel - IOEXP_TCA6424_P10;
        regAddr_u8 = TCA6424A_INPUT_REG1;
    }
    else                                   /*port 2*/
    {
//        regVal_u8 =  PortInRegVal_u8[ChipID][2];
        channelPos = Channel - IOEXP_TCA6424_P20;
        regAddr_u8 = TCA6424A_INPUT_REG2;
    }

    I2c_read_reg(I2c_adap_dev_tca6424[ChipID], 
                             TCA6424_CrtlList[ChipID].Device_Addr,regAddr_u8, &regVal_u8);

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

/* Notice : Only could be used for port configed for OUTPUT */
Dio_LevelType IoExp_TCA6424_GetChannelOutputSt(TCA6424_ChipID_e_ ChipID, TCA6424_Channel_e_ Channel)
{
    uint8 regVal_u8 = 0;
    Dio_LevelType InputLevel = STD_LOW;
    uint8 channelPos = 0;
    uint8 regAddr_u8 = 0;
    
    if( Channel < IOEXP_TCA6424_P10)   /*PORT 0*/
    {
//        regVal_u8 =  PortInRegVal_u8[ChipID][0];
        channelPos = Channel;
        regAddr_u8 = TCA6424A_OUTPUT_REG0;
    }
    else if(Channel <IOEXP_TCA6424_P20 )  /* port 1*/
    {
//        regVal_u8 =  PortInRegVal_u8[ChipID][1];
        channelPos = Channel - IOEXP_TCA6424_P10;
        regAddr_u8 = TCA6424A_OUTPUT_REG1;
    }
    else                                   /*port 2*/
    {
//        regVal_u8 =  PortInRegVal_u8[ChipID][2];
        channelPos = Channel - IOEXP_TCA6424_P20;
        regAddr_u8 = TCA6424A_OUTPUT_REG2;
    }

    I2c_read_reg(I2c_adap_dev_tca6424[ChipID], 
                             TCA6424_CrtlList[ChipID].Device_Addr,regAddr_u8, &regVal_u8);

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

Std_ReturnType AD4067_IoExp_TCA6424_SetPort0(TCA6424_ChipID_e_ ChipID, uint8 Channel)
{

    Std_ReturnType ret = E_OK;
    uint8 regVal_u8 = 0;
    uint8 regAddr_u8 = TCA6424A_OUTPUT_REG0;
    uint8 regbuf_w[2] = {0};
    uint8 channel_pos = Channel;

    I2c_read_reg(I2c_adap_dev_tca6424[ChipID],
                    TCA6424_CrtlList[ChipID].Device_Addr,regAddr_u8, &regVal_u8);
    regVal_u8 &= ~(0xf << 1);
    switch (channel_pos)
    {
    case 0:
        regVal_u8 &= ~(0xf << 1);
        break;
    case 1:
        regVal_u8 |= (1 << 3);
        break;
    case 2:
        regVal_u8 |= (1 << 4);
        break;
    case 3:
        regVal_u8 |= (3 << 3);
        break;
    case 4:
        regVal_u8 |= (1 << 2);
        break;
    case 5:
        regVal_u8 |= (3 << 2);
        break;
    case 6:
        regVal_u8 |= (5 << 2);
        break;
    case 7:
        regVal_u8 |= (7 << 2);
        break;
    case 8:
        regVal_u8 |= (1 << 1);
        break;
    case 9:
        regVal_u8 |= (5 << 1);
        break;
    case 10:
        regVal_u8 |= (9 << 1);
        break;
    case 11:
        regVal_u8 |= (0xD << 1);
        break;
    case 12:
        regVal_u8 |= (3 << 1);
        break;
    case 13:
        regVal_u8 |= (7 << 1);
        break;
    case 14:
        regVal_u8 |= (0xB << 1);
        break;
    case 15:
        regVal_u8 |= (0xf << 1);
        break;
    default:
        break;
    }

    regbuf_w[0] = regAddr_u8 | TCA6424_CMD_WRIRE;
    regbuf_w[1] = regVal_u8;

    ret = I2c_write(I2c_adap_dev_tca6424[ChipID], TCA6424_CrtlList[ChipID].Device_Addr, regbuf_w, 2);

    return ret;
}

Std_ReturnType AD4067_IoExp_TCA6424_SetPort2(TCA6424_ChipID_e_ ChipID, uint8 Channel)
{

    Std_ReturnType ret = E_OK;
    uint8 regVal_u8 = 0;
    uint8 regAddr_u8 = TCA6424A_OUTPUT_REG2;
    uint8 regbuf_w[2] = {0};
    uint8 channel_pos = Channel;

    I2c_read_reg(I2c_adap_dev_tca6424[ChipID],
                    TCA6424_CrtlList[ChipID].Device_Addr,regAddr_u8, &regVal_u8);
    regVal_u8 &= ~(0xf);
    regVal_u8 |= channel_pos;
    regbuf_w[0] = regAddr_u8 | TCA6424_CMD_WRIRE;
    regbuf_w[1] = regVal_u8;

    ret = I2c_write(I2c_adap_dev_tca6424[ChipID], TCA6424_CrtlList[ChipID].Device_Addr, regbuf_w, 2);

    return ret;
}

void I2c_CanTcv_Ctr(void)
{
    int ret = 0;
	// Regs->Output.all = 0x00FFFFFF;
	// Regs->PolarityInversion.all = 0x00000000;
	// Regs->Config.all = 0x00000000;//all is output
	wbuf1[0] =TCA6424A_CONFIG_REG0 | 0x80;
    wbuf1[1] = 0x00;
	wbuf1[2] = 0x00;
	wbuf1[3] = 0x00;
    ret = I2c_write(I2c6_adap_dev1, TCA6424A_A_ADDRESS, wbuf1, 4);

	wbuf1[0] =TCA6424A_POLARITY_REG0 | 0x80;
    wbuf1[1] = 0x00;
	wbuf1[2] = 0x00;
	wbuf1[3] = 0x00;
    ret = I2c_write(I2c6_adap_dev1, TCA6424A_A_ADDRESS, wbuf1, 4);

	wbuf1[0] =TCA6424A_OUTPUT_REG0 | 0x80;
    wbuf1[1] = 0xFF;
	wbuf1[2] = 0xFF;
	wbuf1[3] = 0xFF;
    ret = I2c_write(I2c6_adap_dev1, TCA6424A_A_ADDRESS, wbuf1, 4);

}

void I2c_6424_C_Ctr(void)
{
    int ret = 0;
	// Regs->Output.all = 0x00FFFFFF;
	// Regs->PolarityInversion.all = 0x00000000;
	// Regs->Config.all = 0x00000000;//all is output, BIT=1 is input
	wbuf1[0] =TCA6424A_CONFIG_REG0 | 0x80;
	//bit 1 3 4 is input
	//P07 P06 P05 P04 P03 P02 P01 P00
	// 0   0   0   1    1   0   1  0
	//P17 P16 P15 P14 P13 P12 P11 P10
	// 0   0   0   0    0   1   0  0
	//P27 P26 P25 P24 P23 P22 P21 P20
	// 1   1   1   1    1   0   0  0
    wbuf1[1] = 0x1A;
	wbuf1[2] = 0x04;
	wbuf1[3] = 0xF8;
    ret = I2c_write(I2c6_adap_dev1, TCA6424A_C_ADDRESS, wbuf1, 4);

	wbuf1[0] =TCA6424A_POLARITY_REG0 | 0x80;
    wbuf1[1] = 0x00;
	wbuf1[2] = 0x00;
	wbuf1[3] = 0x00;
    ret = I2c_write(I2c6_adap_dev1, TCA6424A_C_ADDRESS, wbuf1, 4);

	wbuf1[0] =TCA6424A_OUTPUT_REG0 | 0x80;
    wbuf1[1] = 0xFF;
	wbuf1[2] = 0xFF;
	wbuf1[3] = 0xFF;
    ret = I2c_write(I2c6_adap_dev1, TCA6424A_C_ADDRESS, wbuf1, 4);

}

void I2c_6424_B_Ctr(void)
{
    int ret = 0;
	// Regs->Output.all = 0x00FFFFFF;
	// Regs->PolarityInversion.all = 0x00000000;
	// Regs->Config.all = 0x00000000;//all is output
	wbuf1[0] =TCA6424A_CONFIG_REG0 | 0x80;
    wbuf1[1] = 0x00;
	wbuf1[2] = 0x00;
	wbuf1[3] = 0x00;
    ret = I2c_write(I2c7_adap_dev1, TCA6424A_B_ADDRESS, wbuf1, 4);

	wbuf1[0] =TCA6424A_POLARITY_REG0 | 0x80;
    wbuf1[1] = 0x00;
	wbuf1[2] = 0x00;
	wbuf1[3] = 0x00;
    ret = I2c_write(I2c7_adap_dev1, TCA6424A_B_ADDRESS, wbuf1, 4);

	wbuf1[0] =TCA6424A_OUTPUT_REG0 | 0x80;
    wbuf1[1] = 0xFF;
	wbuf1[2] = 0xFF;
	wbuf1[3] = 0xFF;
    ret = I2c_write(I2c7_adap_dev1, TCA6424A_B_ADDRESS, wbuf1, 4);

	rbuf1[0] = TCA6424A_INPUT_REG0;
	I2c_read(I2c7_adap_dev1,TCA6424A_B_ADDRESS,rbuf1,4);
    I2c_read_reg(I2c7_adap_dev1,TCA6424A_B_ADDRESS,rbuf1[0],rbuf1);
}

void I2c_6424_D_Ctr(void)
{
    int ret = 0;
	// Regs->Output.all = 0x00FFFFFF;
	// Regs->PolarityInversion.all = 0x00000000;
	// Regs->Config.all = 0x00000000;//all is output
	wbuf1[0] =TCA6424A_CONFIG_REG0 | 0x80;
    wbuf1[1] = 0x00;
	wbuf1[2] = 0x00;
	wbuf1[3] = 0x00;
    ret = I2c_write(I2c7_adap_dev1, TCA6424A_D_ADDRESS, wbuf1, 4);

	wbuf1[0] =TCA6424A_POLARITY_REG0 | 0x80;
    wbuf1[1] = 0x00;
	wbuf1[2] = 0x00;
	wbuf1[3] = 0x00;
    ret = I2c_write(I2c7_adap_dev1, TCA6424A_D_ADDRESS, wbuf1, 4);

	wbuf1[0] =TCA6424A_OUTPUT_REG0 | 0x80;
    wbuf1[1] = 0xFF;
	wbuf1[2] = 0xFF;
	wbuf1[3] = 0xFF;
    ret = I2c_write(I2c7_adap_dev1, TCA6424A_D_ADDRESS, wbuf1, 4);

}

Std_ReturnType Set_WakeUp_To_HIGH(TCA6424_ChipID_e_ ChipID)
{
    Std_ReturnType ret = E_OK;
    uint8 regVal_u8 = 0xff;

    wbuf1[0] =TCA6424A_OUTPUT_REG0 | TCA6424_CMD_WRIRE;
    wbuf1[1] |= (0x3 << 6);
	wbuf1[2] |= (0x7 << 0);
	wbuf1[3] &= 0xFF;
    
    ret = I2c_write(I2c_adap_dev_tca6424[TCA6424_CrtlList[ChipID].I2C_Channel], TCA6424_CrtlList[ChipID].Device_Addr, wbuf1, 4);  
    return ret;
    
}

Std_ReturnType Set_WakeUp_To_LOW(TCA6424_ChipID_e_ ChipID)
{
    Std_ReturnType ret = E_OK;
    uint8 regVal_u8 = 0xff;

    wbuf1[0] =TCA6424A_OUTPUT_REG0 | TCA6424_CMD_WRIRE;
    wbuf1[1] &= ~(0x3 << 6);
	wbuf1[2] &= ~(0x7 << 0);
	wbuf1[3] &= 0xFF;
    
    ret = I2c_write(I2c_adap_dev_tca6424[TCA6424_CrtlList[ChipID].I2C_Channel], TCA6424_CrtlList[ChipID].Device_Addr, wbuf1, 4);  
    return ret;
    
}

Std_ReturnType Set_TCA1043_To_Normal(TCA6424_ChipID_e_ ChipID)
{
    Std_ReturnType ret = E_OK;
    uint8 regVal_u8 = 0xff;

    wbuf1[0] =TCA6424A_OUTPUT_REG0 | TCA6424_CMD_WRIRE;
    wbuf1[1] &= 0xFF;
	wbuf1[2] |= (0x1F << 3);//STB:H
	wbuf1[3] |= (0x1F << 1);//EN:H
    
    ret = I2c_write(I2c_adap_dev_tca6424[TCA6424_CrtlList[ChipID].I2C_Channel], TCA6424_CrtlList[ChipID].Device_Addr, wbuf1, 4);  
    return ret;
}

bool WakeUp_Flag;

Std_ReturnType Set_TCA1043_To_GoToSleep(TCA6424_ChipID_e_ ChipID)
{
    WakeUp_Flag = TRUE;

    Std_ReturnType ret = E_OK;
    uint8 regVal_u8 = 0;
    uint8 regVal_u8_1 = 0;
    uint8 regAddr_u8 = TCA6424A_OUTPUT_REG1;
    uint8 regAddr_u8_1 = TCA6424A_OUTPUT_REG0;
    uint8 regbuf_w[2] = {0};
    uint8 regbuf_w1[2] = {0};
    //uint8 channel_pos = Channel;

    I2c_read_reg(I2c_adap_dev_tca6424[ChipID],
    TCA6424_CrtlList[ChipID].Device_Addr,regAddr_u8, &regVal_u8);
    I2c_read_reg(I2c_adap_dev_tca6424[ChipID],
    TCA6424_CrtlList[ChipID].Device_Addr,regAddr_u8_1, &regVal_u8_1);
    regVal_u8 = 0; 
    regVal_u8_1 &= 0x3f; 
    
    regbuf_w[0] =TCA6424A_OUTPUT_REG1 | TCA6424_CMD_WRIRE;
    regbuf_w[1] = regVal_u8;
    regbuf_w1[0] = TCA6424A_OUTPUT_REG0 | TCA6424_CMD_WRIRE;
    regbuf_w1[1] = regVal_u8_1;
    ret = I2c_write(I2c_adap_dev_tca6424[ChipID], TCA6424_CrtlList[ChipID].Device_Addr, regbuf_w, 2); 
    ret = I2c_write(I2c_adap_dev_tca6424[ChipID], TCA6424_CrtlList[ChipID].Device_Addr, regbuf_w1, 2); 
    return ret;
}

