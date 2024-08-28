#include "IoExp_TCA6408_Cfg.h"
#include "IoExp_TCA6408_Api.h"
#include "IoExp_TCA6424A_Api.h"

#include "I2c.h"
#include "I2c_Cfg.h"



extern unsigned char NACK;
I2c_adap_dev_t *I2c6_adap_dev_TCA6408;

uint8 TCA6408_wbuf1[3];

#define TCA6408_CLEAR_BIT(value,pos) ((value)&=~(1<<(pos)))
#define TCA6408_SET_BIT(value,pos)   ((value)|= (1<<(pos)))


const TCA6408_Ctrl_t TCA6408_CrtlList[TCA6408_CHIP_NUM] = 
{
    {
        .I2C_Channel        = I2cConf_I2cChannel_I2cChannel_I2C1,
//        .I2C_CtrlBlock      = I2c_adap_dev_TCA6408[TCA6408_CHIP_A],
        .Device_Addr        = TCA6408_ADDRESS,
        .PortDir            = TCA6408_PORTDIRALLIN,
        .RstPin             = IOEXP_TCA6424_P05,
    }
};

// ****************************************************************************
//! @fn          void TCA6408InitDefault(TCA6408Regs* Regs)
//! @brief
//!				 Initializes the confRegs structure which is
//!              a local mirror of the TPL7200 config registers
//!              additional TPL7200writeConfigRegisters(confRegs) function call
//! 			 is needed in order to get the TPL7200 registers updated
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6408InitDefault(TCA6408Regs* Regs){
	Regs->Output.all = 0x00FFFFFF;
	Regs->PolarityInversion.all = 0x00000000;
	Regs->Config.all = 0x00000000;//all is output
}


// ****************************************************************************
//! @fn          void TCA6408InitI2CReg(TCA6408Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6408InitI2CReg(TCA6408Regs* Regs){
	//I2c_write(3, TCA6408_A_ADDRESS, TCA6408_POLARITY_REG | 0x80, (unsigned char*)&Regs->PolarityInversion, 0);
	//I2c_write(3, TCA6408_A_ADDRESS, TCA6408_CONFIG_REG | 0x80, (unsigned char*)&Regs->Config, 0);
	//I2c_write(3, TCA6408_A_ADDRESS, TCA6408_OUTPUT_REG | 0x80, (unsigned char*)&Regs->Output, 0);

}

// ****************************************************************************
//! @fn          void TCA6408ReadInputReg(TCA6408Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6408ReadInputReg(TCA6408Regs* Regs)
{
	//I2c_read(3,TCA6408_A_ADDRESS, TCA6408_INPUT_REG | 0x80, (unsigned char *)&Regs->Input);
}


// ****************************************************************************
//! @fn          void TCA6408InitI2CReg(TCA6408Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6408WriteReg(unsigned char regaddress, unsigned char regVal)
{
	//I2c_write_Byte(TCA6408_A_ADDRESS, regaddress, regVal);
	if(NACK)
	{
		//handle I2C failure later

	}

}

unsigned char TCA6408ReadReg(unsigned char address, unsigned char regaddress)
{
	//return (unsigned char) I2C_Read_Byte(address,regaddress);
}

void TCA6408WriteConfig(TCA6408Regs * Regs)
{
	//I2c_write(3, TCA6408_A_ADDRESS, TCA6408_CONFIG_REG | 0x80, (unsigned char*)&Regs->Config, 0);
}

void TCA6408WriteOutput(TCA6408Regs * Regs)
{
	//I2c_write(3, TCA6408_A_ADDRESS, TCA6408_OUTPUT_REG | 0x80, (unsigned char*)&Regs->Output, 0);
}

void TCA6408WritePolarity(TCA6408Regs * Regs)
{
	//I2c_write(3, TCA6408_A_ADDRESS, TCA6408_POLARITY_REG | 0x80, (unsigned char*)&Regs->PolarityInversion, 0);
}

static void I2c_Init_Device(void)
{
    /*init i2c ctrl block */
    I2c6_adap_dev_TCA6408 = I2cGlobalDev[I2cConf_I2cChannel_I2cChannel_I2C1];

    //release reset pin
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_A,IOEXP_TCA6424_P05,STD_LOW);
}

static void IoExp_TCA6408_InitPortDir(void)
{
    TCA6408_ChipID_e_ chipid = TCA6408_CHIP_A;
    uint8 buf_w[2];

    /* Init chip port direction register */
    for(chipid = TCA6408_CHIP_A; chipid < TCA6408_CHIP_NUM; chipid++)
    {
         /* clear contrl REG at first to set all port not output */
        buf_w[0] = TCA6408_OUTPUT_REG;
        buf_w[1] = 0x00;
        I2c_write(I2c6_adap_dev_TCA6408, 
                 TCA6408_CrtlList[chipid].Device_Addr, buf_w, 2);

        /* Config port direction */         
        buf_w[0] = TCA6408_CONFIG_REG;
        buf_w[1] = TCA6408_PORTDIR;
        
        I2c_write(I2c6_adap_dev_TCA6408, 
                 TCA6408_CrtlList[chipid].Device_Addr, buf_w, 2);
    }
}

void TCA6408_Init(void)
{
    I2c_Init_Device();
    IoExp_TCA6408_InitPortDir();
}

Std_ReturnType IoExp_TCA6408_SetChannelOutLevel(TCA6408_Channel_e_ ChannelNum, Dio_LevelType OutLevel)
{
    Std_ReturnType ret = E_OK;
    uint8 regVal_u8 = 0;
    uint8 regAddr_u8 = 0;
    uint8 channelPos = 0;
    uint8 regbuf_w[2] = {0};

    if(ChannelNum < IOEXP_TCA6408_PORT_NUM)
    {
        /*get channel position*/
        channelPos = ChannelNum;
        regAddr_u8 = TCA6408_OUTPUT_REG;

        /* Read current port status */
        ret = I2c_read_reg(I2c6_adap_dev_TCA6408, 
                       TCA6408_CrtlList[TCA6408_CHIP_A].Device_Addr,regAddr_u8, &regVal_u8);
                       
        if(ret == E_OK)
        {
            if(OutLevel == STD_LOW)
            {
                TCA6408_CLEAR_BIT(regVal_u8,channelPos);
            }
            else
            {
                TCA6408_SET_BIT(regVal_u8,channelPos);
            }
            
           regbuf_w[0] = regAddr_u8;
           regbuf_w[1] = regVal_u8;

            // ret = I2c_write_reg(I2c6_adap_dev_TCA6408, 
            //                                 TCA6408_CrtlList[TCA6408_CHIP_A].Device_Addr, regAddr_u8, regVal_u8);
           ret = I2c_write(I2c6_adap_dev_TCA6408, 
                                         TCA6408_CrtlList[TCA6408_CHIP_A].Device_Addr, regbuf_w, 2);
        }
        
    }
    else
    {
        ret = E_NOT_OK;
    }
   
    return ret;
}

Std_ReturnType IoExp_TCA6408_SetAllPortHigh(void)
{
    Std_ReturnType ret = E_OK;
    uint8 regVal_u8 = 0xff;

    TCA6408_wbuf1[0] =TCA6408_OUTPUT_REG;
    TCA6408_wbuf1[1] = 0xFF;
    
    ret = I2c_write(I2c6_adap_dev_TCA6408, 
                    TCA6408_CrtlList[TCA6408_CHIP_A].Device_Addr, TCA6408_wbuf1, 2);
    
    return ret;
}

Std_ReturnType IoExp_TCA6408_SetAllPortLow(void)
{
    Std_ReturnType ret = E_OK;
    
    TCA6408_wbuf1[0] =TCA6408_OUTPUT_REG;
    TCA6408_wbuf1[1] = 0x00;
    
    ret = I2c_write(I2c6_adap_dev_TCA6408, TCA6408_CrtlList[TCA6408_CHIP_A].Device_Addr, TCA6408_wbuf1, 2);

    return ret;
}

///Notice : Only could be used for port configed for output
Dio_LevelType IoExp_TCA6408_GetChannelOutputSt(TCA6408_Channel_e_ Channel)
{
    uint8 regVal_u8 = 0;
    Dio_LevelType InputLevel = STD_LOW;
    uint8 channelPos = 0;
    uint8 regAddr_u8 = 0;
    
    if(Channel < IOEXP_TCA6408_PORT_NUM)
    {
        channelPos = Channel;
        regAddr_u8 = TCA6408_OUTPUT_REG;

        I2c_read_reg(I2c6_adap_dev_TCA6408, 
                        TCA6408_CrtlList[TCA6408_CHIP_A].Device_Addr,regAddr_u8, &regVal_u8);
                        
        if((regVal_u8 & (1<<channelPos))!= 0u)
        {
            InputLevel = STD_HIGH;
        }
        else
        {
            InputLevel = STD_LOW;
        }
    }

    return InputLevel;
    
}

///Notice : Only could be used for port configed for input
uint8 IoExp_TCA6408_GetPortInputValue(void)
{
    uint8 regVal_u8 = 0;
    uint8 regAddr_u8 = 0;
    Std_ReturnType ret = E_NOT_OK;
    
    regAddr_u8 = TCA6408_INPUT_REG;
        
    ret = I2c_read_reg(I2c6_adap_dev_TCA6408, 
                       TCA6408_CrtlList[TCA6408_CHIP_A].Device_Addr,regAddr_u8, &regVal_u8);
                       
                       
    return regVal_u8;
}

///Notice : Only could be used for port configed for input
Dio_LevelType IoExp_TCA6408_GetChannelInputLevel(TCA6408_Channel_e_ Channel)
{
    uint8 regVal_u8 = 0;
    Dio_LevelType InputLevel = STD_LOW;
    uint8 channelPos = 0;
    uint8 regAddr_u8 = 0;
    
    if(Channel < IOEXP_TCA6408_PORT_NUM)
    {
        channelPos = Channel;
        regAddr_u8 = TCA6408_INPUT_REG;

        I2c_read_reg(I2c6_adap_dev_TCA6408, 
                        TCA6408_CrtlList[TCA6408_CHIP_A].Device_Addr,regAddr_u8, &regVal_u8);
                        
        if((regVal_u8 & (1<<channelPos))!= 0u)
        {
            InputLevel = STD_HIGH;
        }
        else
        {
            InputLevel = STD_LOW;
        }
    }

    return InputLevel;
    
}


