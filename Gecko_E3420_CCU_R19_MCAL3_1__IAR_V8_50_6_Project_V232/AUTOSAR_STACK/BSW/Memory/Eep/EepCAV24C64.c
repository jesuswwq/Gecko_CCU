/*******************************************************************************
 ** 								includes                                  **
 ******************************************************************************/

#include "I2c.h"
#include "I2c_Cfg.h"
#include "EepCAV24C64.h"

/*======================[I N T E R N A L   D A T A ]==========================*/
I2c_adap_dev_t *I2c2_adap_dev;
uint16 I2C_SLAVE_ADDR_EEP = 0x50;
int timeoutnum = 1000;
static uint8 EEP_SendBuff[EEP_PAGE_SIZE+EEP_SIZE_OF_ADDRESS];
static uint8 eraseBuffer[EEP_PAGE_SIZE];




static uint32 WriteI2C(Eep_62_AddressType RegAddr,const uint8 *data_addr, Eep_62_LengthType len)
{
    Std_ReturnType ret = E_NOT_OK;

    if((RegAddr + len > EEP_MAX_SIZE)|| (len > EEP_PAGE_SIZE ))
	{
		/*parameter error*/
		ret = E_NOT_OK;
	}
	else
	{
    EEP_SendBuff[0] = (RegAddr & 0xFF00) >> 8;
	EEP_SendBuff[1] = (RegAddr & 0xFF);

    for (int i = 0; i < len; i++)
        EEP_SendBuff[i + 2] = data_addr[i];

    ret = I2c_write(I2c2_adap_dev, I2C_SLAVE_ADDR_EEP, EEP_SendBuff, len + 2);
    }
    return ret;
}

static uint32 ReadI2C(Eep_62_AddressType RegAddr, uint8 *data_addr, Eep_62_LengthType len)
{
    Std_ReturnType ret = E_NOT_OK;

    if((RegAddr + len > EEP_MAX_SIZE)|| (0 == len ))
	{
		/*parameter error*/
		ret = E_NOT_OK;
	}
    else
    {
    EEP_SendBuff[0] = (RegAddr & 0xFF00) >> 8;
	EEP_SendBuff[1] = (RegAddr & 0xFF);

    ret = I2c_write_read(I2c2_adap_dev, I2C_SLAVE_ADDR_EEP, EEP_SendBuff, 2, data_addr, len);

    }

    return ret;
}

static uint32 I2c_WaitingBusIdle(void)
{
    int transstate = 0;
    int timeoutcnt = 0;

    transstate = I2c_get_transtate(I2c2_adap_dev);

    while (transstate == I2C_BUSY_STATE) {
        transstate = I2c_get_transtate(I2c2_adap_dev);
        Mcu_udelay(20);
        timeoutcnt++;

        if (timeoutcnt == timeoutnum) {
            break;
        }
    }

    return timeoutcnt;
}

static uint32 I2c_MainfuncPolling(void)
{
    int timeoutcnt = 0;

    while (1) {
        I2c_mainfunction_handling();

        if (I2c_get_transtate(I2cGlobalDev[1]) == I2C_IDLE_STATE)
            break;

        timeoutcnt++;
        Mcu_udelay(1000);

        if (timeoutcnt == timeoutnum)
            break;
    }

    return timeoutcnt;
}

Std_ReturnType Eep_CAV24C64_Write(Eep_62_AddressType writeAddress,const uint8* writeBufferPtr,Eep_62_LengthType writeLength)
{
    int ret = 0;
    int transstate = 0;
    int timeoutcnt = 0;

    timeoutcnt = I2c_WaitingBusIdle(); //use for interrupt mode
    transstate = I2c_get_transtate(I2c2_adap_dev);

    if ((timeoutcnt < timeoutnum) && (transstate != I2C_BUSY_STATE)) {
            // Mcu_udelay(5000);

            ret = WriteI2C(writeAddress, writeBufferPtr, writeLength);

           timeoutcnt = I2c_MainfuncPolling();
    }else{
        timeoutcnt = 0;
    }
    return ret;

}

Std_ReturnType Eep_CAV24C64_Read(Eep_62_AddressType writeAddress,uint8 *readBufferPtr,Eep_62_LengthType writeLength)
{
    int ret = 0;
    int transstate = 0;
    int timeoutcnt = 0;

    timeoutcnt = I2c_WaitingBusIdle();

     if ((timeoutcnt < timeoutnum) && (transstate != I2C_BUSY_STATE)) {
        ret = ReadI2C(writeAddress,readBufferPtr,writeLength);
        timeoutcnt = I2c_MainfuncPolling();
    }else{
        timeoutcnt = 0;
    }
    return ret;
}

static void Eep_CAV24C64_MemSet(uint8* dest, const uint8 source, uint32 length)
{
    while(length >0uL)
	{
		if(dest != NULL_PTR)
		{
			*dest = source;
			dest++;
		}
		else
		{
			break;
		}

		length--;
	}

}

Std_ReturnType Eep_CAV24C64_Erase(Eep_62_AddressType eraseAddress,const uint8 ErasedValue,Eep_62_LengthType eraseLength)
{
	Std_ReturnType sendStatus = E_OK;

	Eep_CAV24C64_MemSet(eraseBuffer, ErasedValue, EEP_62_ERASE_VALUE);

	/* external buffer of IIC */
	sendStatus = Eep_CAV24C64_Write(eraseAddress,eraseBuffer,eraseLength);

	return sendStatus;
}


void I2c_EepInit_Device(void)
{
	I2c2_adap_dev = I2cGlobalDev[1];
 //   IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_B,IOEXP_TCA6424_P03,STD_LOW);

}






