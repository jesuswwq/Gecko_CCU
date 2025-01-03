#ifndef RTW_HEADER_ME11_types_h_
#define RTW_HEADER_ME11_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_FaultStatus_
#define DEFINED_TYPEDEF_FOR_FaultStatus_

typedef uint8 FaultStatus;

#define Normal                         ((FaultStatus)0U)
#define Ground                         ((FaultStatus)1U)
#define Power                          ((FaultStatus)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_PwrModes_
#define DEFINED_TYPEDEF_FOR_PwrModes_

typedef uint8 PwrModes;

#define PwrOff                         ((PwrModes)0U)
#define Standby                        ((PwrModes)1U)
#define HVNormal                       ((PwrModes)2U)
#define ACChrg                         ((PwrModes)3U)
#define DCChrg                         ((PwrModes)4U)
#define PTReady                        ((PwrModes)5U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_BatModes_
#define DEFINED_TYPEDEF_FOR_BatModes_

typedef uint8 BatModes;

#define Off                            ((BatModes)0U)
#define Cool                           ((BatModes)1U)
#define ThermalHeat                    ((BatModes)2U)
#define MotorHeatBat                   ((BatModes)3U)
#define Balance                        ((BatModes)4U)
#define BatLTR                         ((BatModes)5U)
#define BatHeat                        ((BatModes)6U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_CabinMode_
#define DEFINED_TYPEDEF_FOR_CabinMode_

typedef uint8 CabinMode;

#define CabinMode_MD_Off               ((CabinMode)0U)
#define CabinMode_MD1_CLM              ((CabinMode)1U)
#define CabinMode_MD2_DHMD1            ((CabinMode)2U)
#define CabinMode_MD3_DHMD2            ((CabinMode)3U)
#define CabinMode_MD4_HP               ((CabinMode)4U)
#define CabinMode_VENT                 ((CabinMode)6U)
#define CabinMode_STANDBY              ((CabinMode)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_WaterModes_
#define DEFINED_TYPEDEF_FOR_WaterModes_

typedef uint8 WaterModes;

#define WaterOff                       ((WaterModes)0U)
#define WaterLTR                       ((WaterModes)1U)
#define LTRAndCoolOrHeat               ((WaterModes)2U)
#define RecAndBal                      ((WaterModes)3U)
#define LTRAndBal                      ((WaterModes)4U)
#define Water_MotorHeatBat             ((WaterModes)5U)
#define WasteHeatRec                   ((WaterModes)6U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_RefModes_
#define DEFINED_TYPEDEF_FOR_RefModes_

typedef uint8 RefModes;

#define RefModes_Ref_Off               ((RefModes)0U)
#define RefModes_CoolCabin             ((RefModes)1U)
#define RefModes_CoolBat               ((RefModes)2U)
#define RefModes_CoolDouble            ((RefModes)3U)
#define RefModes_HeatCabin             ((RefModes)4U)
#define RefModes_HeatBat               ((RefModes)5U)
#define RefModes_HeatDouble            ((RefModes)6U)
#define RefModes_SerDeh_LCC            ((RefModes)7U)
#define RefModes_SerDeh_EVAP           ((RefModes)8U)
#define RefModes_ParDeh                ((RefModes)9U)
#define RefModes_Def                   ((RefModes)10U)
#define RefModes_Defrosting            ((RefModes)11U)
#define RefModes_CoolCabinAHeatBat     ((RefModes)12U)
#define RefModes_CoolBatAHeatCabin     ((RefModes)13U)
#define RefModes_DehAndBatCool         ((RefModes)14U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_BlowerModes_
#define DEFINED_TYPEDEF_FOR_BlowerModes_

typedef uint8 BlowerModes;

#define BlowerModes_FaceMode           ((BlowerModes)5U)
#define BlowerModes_FaceHeaterMode     ((BlowerModes)4U)
#define BlowerModes_HeaterMode         ((BlowerModes)2U)
#define BlowerModes_HeaterDeforstMode  ((BlowerModes)3U)
#define BlowerModes_DeforstMode        ((BlowerModes)1U)
#define BlowerModes_OffMode            ((BlowerModes)0U)
#define BlowerModes_AutoMode           ((BlowerModes)8U)
#define BlowerModes_FaceDeforstMode    ((BlowerModes)6U)
#define BlowerModes_FaceHeaterDeforstMode ((BlowerModes)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_ACEconMode_
#define DEFINED_TYPEDEF_FOR_ACEconMode_

typedef uint8 ACEconMode;

#define ACEconMode_Comfort             ((ACEconMode)0U)
#define ACEconMode_Economy             ((ACEconMode)1U)
#define ACEconMode_FanOnly             ((ACEconMode)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Defog_
#define DEFINED_TYPEDEF_FOR_Defog_

typedef uint8 Defog;

#define Inactive                       ((Defog)0U)
#define Active                         ((Defog)1U)
#endif
#endif

