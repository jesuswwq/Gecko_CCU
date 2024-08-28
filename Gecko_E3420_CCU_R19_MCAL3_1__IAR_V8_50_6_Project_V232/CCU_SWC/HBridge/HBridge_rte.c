#include "HBridge_rte.h"
//#include "MPQ6612A.h"
//#include "Dio.h"
//#include "IoExp_TCA9539_Api.h"
//#include "IoExp_TCA6424A_Api.h"

void HBridge_MPQ6612A_Ctrl(MPQ6612A_ChipSelect_e Chip,uint8 Pin1,uint8 Pin2)
{
    HBridge_MPQ6612A(Chip,Pin1,Pin2);
}
