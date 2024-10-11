#include "Gpio_rte.h"
#include "I2c.h"

extern I2c_adap_dev_t *I2c_adap_dev_tca6424[TCA6424_CHIP_NUM];
extern const TCA6424_Ctrl_t TCA6424_CrtlList[TCA6424_CHIP_NUM];
TCA6424_ChipID_e_ tca6424_chipID;
TCA6424_Channel_e_ tca6424_channelID;
uint8 tca6424A[4] = {0x00, 0xC0, 0xFF, 0xFF};
uint8 tca6424B[4] = {0x00, 0x00, 0x1F, 0xF8};
uint8 tca6424C[4] = {0x00, 0xFF, 0xFF, 0xFF};
uint8 tca6424D[4] = {0x00, 0x00, 0xE0, 0x00};
uint8 tca6424E[4] = {0x00, 0x00, 0x00, 0x00};

// 75242
uint8 tle75242A = 0;
uint8 tle75242B = 0;
uint16 tle75004 = 0;
uint16 tle8108 = 0;
#pragma default_function_attributes = @".iram_func"
void Gpio_init(void)
{

}


void Gpio_Run(void)
{
    Gpio_TCA6424A_SetAllPortVal();
    Gpio_TCA6424B_SetAllPortVal();
    Gpio_TCA6424C_SetAllPortVal();
    Gpio_TCA6424D_SetAllPortVal();
    Gpio_TCA6424E_SetAllPortVal();
    Gpio_TLE75242A_8bitDataWrite();
    Gpio_TLE75004_DataWrite();
    Gpio_TLE75242B_8bitDataWrite();
    Gpio_TLE8108_Datawrite();
}

Std_ReturnType Gpio_TCA6424A_SetAllPortVal(void)
{
    Std_ReturnType ret = E_OK;
    static uint8 param_tca6424A1 = 0xC0, param_tca6424A2 = 0xFF, param_tca6424A3 = 0xFF;
    if (tca6424A[1] != param_tca6424A1 || tca6424A[2] != param_tca6424A2 || tca6424A[3] != param_tca6424A3)
    {
        tca6424A[0] = TCA6424A_OUTPUT_REG0 | TCA6424_CMD_WRIRE;
        ret = I2c_write(I2c_adap_dev_tca6424[TCA6424_CHIP_A], TCA6424_CrtlList[TCA6424_CHIP_A].Device_Addr, tca6424A, 4);
        param_tca6424A1 = tca6424A[1];
        param_tca6424A2 = tca6424A[2];
        param_tca6424A3 = tca6424A[3];
    }
    return ret;
}

Std_ReturnType Gpio_TCA6424B_SetAllPortVal(void)
{
    Std_ReturnType ret = E_OK;
    static uint8 param_tca6424B1 = 0x00, param_tca6424B2 = 0x1F, param_tca6424B3 = 0xF8;
    if (tca6424B[1] != param_tca6424B1 || tca6424B[2] != param_tca6424B2 || tca6424B[3] != param_tca6424B3)
    {
        tca6424B[0] = TCA6424A_OUTPUT_REG0 | TCA6424_CMD_WRIRE;
        ret = I2c_write(I2c_adap_dev_tca6424[TCA6424_CHIP_B], TCA6424_CrtlList[TCA6424_CHIP_B].Device_Addr, tca6424B, 4);
        param_tca6424B1 = tca6424B[1];
        param_tca6424B2 = tca6424B[2];
        param_tca6424B3 = tca6424B[3];
    }
    return ret;
}

Std_ReturnType Gpio_TCA6424C_SetAllPortVal(void)
{
    Std_ReturnType ret = E_OK;
    static uint8 param_tca6424C1 = 0xFF, param_tca6424C2 = 0xFF, param_tca6424C3 = 0xFF;
    if (tca6424C[1] != param_tca6424C1 || tca6424C[2] != param_tca6424C2 || tca6424C[3] != param_tca6424C3)
    {
        tca6424C[0] = TCA6424A_OUTPUT_REG0 | TCA6424_CMD_WRIRE;
        ret = I2c_write(I2c_adap_dev_tca6424[TCA6424_CHIP_C], TCA6424_CrtlList[TCA6424_CHIP_C].Device_Addr, tca6424C, 4);
        param_tca6424C1 = tca6424C[1];
        param_tca6424C2 = tca6424C[2];
        param_tca6424C3 = tca6424C[3];
    }
    return ret;
}

Std_ReturnType Gpio_TCA6424D_SetAllPortVal(void)
{
    Std_ReturnType ret = E_OK;
    uint8 regVal_u8[3] = {0};
    static uint8 param_tca6424D1 = 0x0, param_tca6424D2 = 0xF0, param_tca6424D3 = 0x0;
    if (tca6424D[1] != param_tca6424D1 || tca6424D[2] != param_tca6424D2 || tca6424D[3] != param_tca6424D3)
    {
        tca6424D[0] = TCA6424A_OUTPUT_REG0 | TCA6424_CMD_WRIRE;
        ret = I2c_write(I2c_adap_dev_tca6424[TCA6424_CHIP_D], TCA6424_CrtlList[TCA6424_CHIP_D].Device_Addr, tca6424D, 4);
        param_tca6424D1 = tca6424D[1];
        param_tca6424D2 = tca6424D[2];
        param_tca6424D3 = tca6424D[3];
        
    }

 I2c_read_reg(I2c_adap_dev_tca6424[TCA6424_CHIP_D],TCA6424_CrtlList[TCA6424_CHIP_D].Device_Addr,TCA6424A_OUTPUT_REG0, &regVal_u8[0]);
 I2c_read_reg(I2c_adap_dev_tca6424[TCA6424_CHIP_D],TCA6424_CrtlList[TCA6424_CHIP_D].Device_Addr,TCA6424A_OUTPUT_REG1, &regVal_u8[1]);
 I2c_read_reg(I2c_adap_dev_tca6424[TCA6424_CHIP_D],TCA6424_CrtlList[TCA6424_CHIP_D].Device_Addr,TCA6424A_OUTPUT_REG2, &regVal_u8[2]);
    return ret;
}

Std_ReturnType Gpio_TCA6424E_SetAllPortVal(void)
{
    Std_ReturnType ret = E_OK;
    static uint8 param_tca6424E1 = 0x00, param_tca6424E2 = 0x00, param_tca6424E3 = 0x00;
    if (tca6424E[1] != param_tca6424E1 || tca6424E[2] != param_tca6424E2 || tca6424E[3] != param_tca6424E3)
    {
        tca6424E[0] = TCA6424A_OUTPUT_REG0 | TCA6424_CMD_WRIRE;
        ret = I2c_write(I2c_adap_dev_tca6424[TCA6424_CHIP_E], TCA6424_CrtlList[TCA6424_CHIP_E].Device_Addr, tca6424E, 4);
        param_tca6424E1 = tca6424E[1];
        param_tca6424E2 = tca6424E[2];
        param_tca6424E3 = tca6424E[3];
    }
    return ret;
}

Std_ReturnType Gpio_TLE75242A_8bitDataWrite(void)
{
    static uint8 param_tle75242A = 0;
    if (param_tle75242A != tle75242A)
    {
        TLE75242_DataWrite(TLE75242_CHIP_A, tle75242A);
        param_tle75242A = tle75242A;
    }
}

Std_ReturnType Gpio_TLE75242B_8bitDataWrite(void)
{
    static uint8 param_tle75242B = 0;
    if (param_tle75242B != tle75242B)
    {
        TLE75242_DataWrite(TLE75242_CHIP_B, tle75242B);
        param_tle75242B = tle75242B;
    }
}

void Gpio_TLE8108_Datawrite(void)
{
    static uint16 param_tle8108 = 0;
    if (param_tle8108 != tle8108)
    {
        TLE8108EM_read_write_Ext(tle8108);
        param_tle8108 = tle8108;
    }
}

void Gpio_TLE75004_DataWrite(void)
{
    static uint16 param_tle75004 = 0;
    if (param_tle75004 != tle75004)
    {
        TLE75004_Output(tle75004);
        param_tle75004 = tle75004;
    }
}
#pragma default_function_attributes =