#include "VNH5200.h"
#include "Dio.h"
#include "IoExp_TCA6424A_Api.h"

typedef enum
{
    VNH5200_PIN_DIO,
    VNH5200_PIN_IOEXP,

    VNH5200_PIN_TYPENUM
}VNH5200_Dio_CtrlPinType_e;

typedef struct 
{
    VNH5200_Dio_CtrlPinType_e   PinType;
    uint16                    DioChannel;
    uint8                     ChipId;
}VNH5200_CtrlPin_t;

VNH5200_CtrlPin_t VNH5200_EN_DIAGx_Pin[VNH5200_OUTCH_NUM] = 
{
    {VNH5200_PIN_IOEXP, IOEXP_TCA6424_P05, TCA6424_CHIP_C },    //EN/DIAG_A
    {VNH5200_PIN_IOEXP, IOEXP_TCA6424_P06, TCA6424_CHIP_C }     //EN/DIAG_B
};

VNH5200_CtrlPin_t VNH5200_INx_Pin[VNH5200_OUTCH_NUM] = 
{
    {VNH5200_PIN_IOEXP, IOEXP_TCA6424_P07, TCA6424_CHIP_C },    //INA
    {VNH5200_PIN_IOEXP, IOEXP_TCA6424_P10, TCA6424_CHIP_C }     //INB
};

VNH5200_HBridgeDir_e VNH5200_OutChannelSt[VNH5200_OUTCH_NUM] = {VNH5200_DIR_LSON, VNH5200_DIR_LSON};

static void VNH5200_CtrlPin_Status(VNH5200_CtrlPin_t Pin, Dio_LevelType DioSt);

/***************************************User Function******************************************/
void VNH5200_Init(void)
{
    VNH5200_Channel_e outch = VNH5200_OUT_A;

    for(outch = VNH5200_OUT_A; outch < VNH5200_OUTCH_NUM; outch++)
    {
        //set VNH5200 EN/DIAG_x normal operate:enable output
        VNH5200_CtrlPin_Status(VNH5200_EN_DIAGx_Pin[outch], STD_HIGH);
    }
}

void VNH5200_HBridge_CtrlOutput(VNH5200_Channel_e channel, VNH5200_HBridgeDir_e OutputDir)
{
    if(OutputDir == VNH5200_DIR_LSON)
    {
        //output low
        VNH5200_CtrlPin_Status(VNH5200_INx_Pin[channel], STD_LOW);
    }
    else
    {
        //output high
        VNH5200_CtrlPin_Status(VNH5200_INx_Pin[channel], STD_HIGH);
    }
    VNH5200_OutChannelSt[channel] = OutputDir;
}

void VNH5200_HBridge_ClearChannelErr(VNH5200_Channel_e channel)
{
    if(VNH5200_OutChannelSt[channel] == VNH5200_DIR_LSON)
    {
        VNH5200_CtrlPin_Status(VNH5200_INx_Pin[channel], STD_HIGH);
        VNH5200_CtrlPin_Status(VNH5200_INx_Pin[channel], STD_LOW);
    }
    else
    {
        VNH5200_CtrlPin_Status(VNH5200_INx_Pin[channel], STD_LOW);
        VNH5200_CtrlPin_Status(VNH5200_INx_Pin[channel], STD_HIGH);
    }
}

static void VNH5200_CtrlPin_Status(VNH5200_CtrlPin_t Pin, Dio_LevelType DioSt)
{

    if(Pin.ChipId == TCA6424_CHIP_C)
    {
        
        IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_C, Pin.DioChannel, DioSt);
    }
    else
    {

    }
}