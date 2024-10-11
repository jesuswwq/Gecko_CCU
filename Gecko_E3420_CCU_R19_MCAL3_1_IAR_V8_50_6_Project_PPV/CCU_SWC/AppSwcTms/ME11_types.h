/*
 * File: ME11_types.h
 *
 * Code generated for Simulink model 'ME11'.
 *
 * Model version                  : 1.2188
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Oct  8 16:29:54 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ME11_types_h_
#define RTW_HEADER_ME11_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_FaultStatus_
#define DEFINED_TYPEDEF_FOR_FaultStatus_

typedef uint8 FaultStatus;

/* enum FaultStatus */
#define Normal                         ((FaultStatus)0U)         /* Default value */
#define Ground                         ((FaultStatus)1U)
#define Power                          ((FaultStatus)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_PwrModes_
#define DEFINED_TYPEDEF_FOR_PwrModes_

/* 电源模式 */
typedef uint8 PwrModes;

/* enum PwrModes */
#define PwrOff                         ((PwrModes)0U)            /* Default value */
#define Standby                        ((PwrModes)1U)
#define HVNormal                       ((PwrModes)2U)
#define ACChrg                         ((PwrModes)3U)
#define DCChrg                         ((PwrModes)4U)
#define PTReady                        ((PwrModes)5U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_BatModes_
#define DEFINED_TYPEDEF_FOR_BatModes_

/* /+
   0x0:OFF；
   0x1:Cool
   0x2:thermal storage
   0x3:motor heat battary
   0x4:Balancec
   0x5:LTR
   0x6:Heat
   +/ */
typedef uint8 BatModes;

/* enum BatModes */
#define Off                            ((BatModes)0U)            /* Default value */
#define Cool                           ((BatModes)1U)
#define ThermalHeat                    ((BatModes)2U)
#define MotorHeatBat                   ((BatModes)3U)
#define Balance                        ((BatModes)4U)
#define BatLTR                         ((BatModes)5U)
#define BatHeat                        ((BatModes)6U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_CabinMode_
#define DEFINED_TYPEDEF_FOR_CabinMode_

/* cabin mode state */
typedef uint8 CabinMode;

/* enum CabinMode */
#define CabinMode_MD_Off               ((CabinMode)0U)           /* Default value */
#define CabinMode_MD1_CLM              ((CabinMode)1U)
#define CabinMode_MD2_DHMD1            ((CabinMode)2U)
#define CabinMode_MD3_DHMD2            ((CabinMode)3U)
#define CabinMode_MD4_HP               ((CabinMode)4U)
#define CabinMode_VENT                 ((CabinMode)6U)
#define CabinMode_STANDBY              ((CabinMode)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_WaterModes_
#define DEFINED_TYPEDEF_FOR_WaterModes_

/* /+
   0x0:default
   0x1:LTR散热(（电池+电驱）)
   0x2:电驱LTR+电池制冷/加热
   0x3:电驱余热回收+电池均温
   0x4:电驱LTR+电池均温
   0x5:电机加热电池
   0x6:（电机+电池）余热回收
   +/ */
typedef uint8 WaterModes;

/* enum WaterModes */
#define WaterOff                       ((WaterModes)0U)          /* Default value */
#define WaterLTR                       ((WaterModes)1U)
#define LTRAndCoolOrHeat               ((WaterModes)2U)
#define RecAndBal                      ((WaterModes)3U)
#define LTRAndBal                      ((WaterModes)4U)
#define Water_MotorHeatBat             ((WaterModes)5U)
#define WasteHeatRec                   ((WaterModes)6U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_RefModes_
#define DEFINED_TYPEDEF_FOR_RefModes_

/* Refrigerant mode */
typedef uint8 RefModes;

/* enum RefModes */
#define RefModes_Ref_Off               ((RefModes)0U)            /* Default value */
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

/* blower mode */
typedef uint8 BlowerModes;

/* enum BlowerModes */
#define BlowerModes_FaceMode           ((BlowerModes)5U)         /* Default value */
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

/* ac work status */
typedef uint8 ACEconMode;

/* enum ACEconMode */
#define ACEconMode_Comfort             ((ACEconMode)0U)          /* Default value */
#define ACEconMode_Economy             ((ACEconMode)1U)
#define ACEconMode_FanOnly             ((ACEconMode)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Defog_
#define DEFINED_TYPEDEF_FOR_Defog_

/* defrost flag */
typedef uint8 Defog;

/* enum Defog */
#define Inactive                       ((Defog)0U)               /* Default value */
#define Active                         ((Defog)1U)
#endif
#endif                                 /* RTW_HEADER_ME11_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
