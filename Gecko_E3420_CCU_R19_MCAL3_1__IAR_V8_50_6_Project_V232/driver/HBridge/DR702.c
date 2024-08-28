#include "DR702.h"
#include "Dio.h"
#include "IoExp_TCA6424A_Api.h"

typedef enum
{
    DR702_PIN_DIO,
    DR702_PIN_IOEXP,

    DR702_PIN_TYPENUM
}DR702_Dio_CtrlPinType_e;

typedef struct 
{
    DR702_Dio_CtrlPinType_e   PinType;
    uint16                    DioChannel;
    uint8                     ChipId;
}DR702_CtrlPin_t;

DR702_CtrlPin_t nSLEEP_Pin[DR702_CHIP_NUM] = 
{
    { DR702_PIN_IOEXP, IOEXP_TCA6424_P14, TCA6424_CHIP_E },
    { DR702_PIN_IOEXP, IOEXP_TCA6424_P04, TCA6424_CHIP_E }
};

DR702_CtrlPin_t MODE_Pin[DR702_CHIP_NUM] = 
{
    { DR702_PIN_IOEXP, IOEXP_TCA6424_P02, TCA6424_CHIP_E },
    { DR702_PIN_IOEXP, IOEXP_TCA6424_P02, TCA6424_CHIP_C }
};	

DR702_CtrlPin_t DR702_nFAULT_Pin[DR702_CHIP_NUM] = 
{
    {DR702_PIN_IOEXP, IOEXP_TCA6424_P03, TCA6424_CHIP_C },
    {DR702_PIN_IOEXP, IOEXP_TCA6424_P01, TCA6424_CHIP_C }
};

DR702_CtrlPin_t DR702_IN1_PH[DR702_CHIP_NUM] = 
{
    {DR702_PIN_IOEXP, IOEXP_TCA6424_P13, TCA6424_CHIP_E },
    {DR702_PIN_IOEXP, IOEXP_TCA6424_P05, TCA6424_CHIP_E }
};

DR702_CtrlPin_t DR702_IN2_EN[DR702_CHIP_NUM] = 
{
    {DR702_PIN_IOEXP, IOEXP_TCA6424_P03, TCA6424_CHIP_E },
    {DR702_PIN_IOEXP, IOEXP_TCA6424_P12, TCA6424_CHIP_E }
};

static void DR702_CtrlPin_Status(DR702_CtrlPin_t Pin, Dio_LevelType DioSt);


/***************************************User Function******************************************/
void DR702_Init(void)
{
    DR702_ChipSelect_e chipid = DR702_CHIP_C;

    for(chipid = DR702_CHIP_C; chipid<DR702_CHIP_NUM; chipid++)
    {
        //set chip at half bridge mode
        DR702_SetChipMode(chipid,DR702_MODE_HALF_BRIDGE);

        //set DR702 to normal operate
        DR702_CtrlPin_Status(nSLEEP_Pin[chipid], STD_HIGH);
    }
}

void DR702_SwitchToSleepMode(DR702_ChipSelect_e Chip)
{
    //SET nSLEEP_Pin low
    DR702_CtrlPin_Status(nSLEEP_Pin[Chip], STD_LOW);
}

//select mode must be called in DR702_Init(), could no be changed anymore
void DR702_SetChipMode(DR702_ChipSelect_e Chip, DR702_Mode_e ChipMode)
{
    switch(ChipMode)
    {
        case DR702_MODE_H_BRIDGE:
            DR702_CtrlPin_Status(MODE_Pin[Chip], STD_LOW);
            break;

        case DR702_MODE_HALF_BRIDGE:
            DR702_CtrlPin_Status(MODE_Pin[Chip], STD_HIGH);
            break;

        default:
            break;
    }
}

//H-Bridge driver
void DR702_HBridge_CtrlOutputOff(DR702_ChipSelect_e Chip)
{
    DR702_CtrlPin_Status(DR702_IN2_EN[Chip], STD_LOW);
}

void DR702_HBridge_CtrlOutputOn(DR702_ChipSelect_e Chip, DR702_HBridgeDir_e OutputDir)
{
    DR702_CtrlPin_Status(DR702_IN2_EN[Chip], STD_HIGH);

    if(OutputDir == DR702_DIR_SH2TOSH1)
    {
        //Reverse (current SH2 to SH1)
        DR702_CtrlPin_Status(DR702_IN1_PH[Chip], STD_LOW);
    }
    else
    {
        //Forward (current SH1 to SH2)
        DR702_CtrlPin_Status(DR702_IN1_PH[Chip], STD_HIGH);
    }
}

//Half-Bridge driver
void DR702_HalfBridge_CtrlOutputChOn(DR702_ChipSelect_e Chip, DR702_HalfBridgeCh_e OutCh)
{
    if(OutCh == DR702_HalfBridgeCh_HS1)
    {
        DR702_CtrlPin_Status(DR702_IN1_PH[Chip], STD_HIGH);
    }
    else if(OutCh == DR702_HalfBridgeCh_LS1)
    {
        DR702_CtrlPin_Status(DR702_IN1_PH[Chip], STD_LOW);
    }
    else if(OutCh == DR702_HalfBridgeCh_HS2)
    {
        DR702_CtrlPin_Status(DR702_IN2_EN[Chip], STD_HIGH);
    }
    else if(OutCh == DR702_HalfBridgeCh_LS2)
    {
        DR702_CtrlPin_Status(DR702_IN2_EN[Chip], STD_LOW);
    }
    else
    {

    }
}

boolean DR702_DiagChipAtFault(DR702_ChipSelect_e Chip)
{
    Dio_LevelType fault_level = STD_HIGH;
    boolean result = FALSE;

    fault_level = IoExp_TCA6424_GetChannelInputLevel(TCA6424_CHIP_C, DR702_nFAULT_Pin[Chip].DioChannel);

    if(fault_level == STD_HIGH)
    {
        result = FALSE;
    }
    else
    {
        result = TRUE;
    }

    return result;
}

static void DR702_CtrlPin_Status(DR702_CtrlPin_t Pin, Dio_LevelType DioSt)
{
    IoExp_TCA6424_SetChannelOutLevel(Pin.ChipId, Pin.DioChannel, DioSt);
}