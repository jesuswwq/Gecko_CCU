/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dcm.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2023-12-13 17:03:53>
 */
/*============================================================================*/

#ifndef RTEDCM_H
#define RTEDCM_H

#include "Dcm_Types.h"
//#include "Uhf_Fml.h"

extern uint8 CheckRoutineFlag;

/* PRAQ S 0777,0779++ */ /* MISRA Rule 5.1,Rule 1.3 */
extern  Std_ReturnType  Dcm_DcmDslCallbackDCMRequestService_0_StartProtocol;
extern  Std_ReturnType  Dcm_DcmDslCallbackDCMRequestService_0_StopProtocol;

/***************************Security Part****************************************/
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Level1_CompareKey( const  uint8*  Key,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Level5_CompareKey( const  uint8*  Key,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );

extern  Std_ReturnType  Rte_GetSecurityAttemptCounter_Level1( Dcm_OpStatusType  OpStatus,  uint8*  AttemptCounter );
extern  Std_ReturnType  Rte_GetSecurityAttemptCounter_Level5( Dcm_OpStatusType  OpStatus,  uint8*  AttemptCounter );

extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Level1_GetSeed(
        Dcm_OpStatusType OpStatus,uint8* Seed,Dcm_NegativeResponseCodeType* ErrorCode);
extern  Std_ReturnType  Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Level5_GetSeed(
        Dcm_OpStatusType OpStatus,uint8* Seed,Dcm_NegativeResponseCodeType* ErrorCode);

extern  Std_ReturnType  Rte_SetSecurityAttemptCounter_Level1( Dcm_OpStatusType  OpStatus,  uint8  AttemptCounter );
extern  Std_ReturnType  Rte_SetSecurityAttemptCounter_Level5( Dcm_OpStatusType  OpStatus,  uint8  AttemptCounter );
/***************************Did Part****************************************/

extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F197_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F18A_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F191_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F187_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F188_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F180_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F18B_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F18C_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F190_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F15B_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F192_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F194_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F101_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F157_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F158_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F080_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F081_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F084_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F085_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3231_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3232_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3232_1_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3232_2_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3232_3_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3232_4_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F163_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F1AA_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F1AB_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F1AC_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F1AD_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F1AE_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F1AF_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13A_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13B_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13C_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13D_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13E_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF200H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF201H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF202H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF203H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF204H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF205H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF206H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF251H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF252H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF253H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF254H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF255H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF256H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF257H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF258H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF259H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF25AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF25BH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF25CH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF25DH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF25EH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF25FH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF210H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF211H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF212H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF213H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF214H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF215H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF216H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF217H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF218H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF219H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF21AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF21BH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF21CH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF21DH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF21EH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF21FH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF220H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF221H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF222H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF223H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF224H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF225H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF226H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF227H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF228H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF229H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF22AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF22BH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF22CH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF230H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF231H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF232H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF233H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF234H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF235H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF236H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF237H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF238H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF239H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF23AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF23BH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF23CH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF23DH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF23EH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF23FH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF240H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_0xF241H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3237_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F260H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F261H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F262H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F263H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F264H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F265H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F266H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F267H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F268H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F269H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F26AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F26BH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F26CH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F26DH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F26EH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F26FH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F270H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F271H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F272H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F273H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F274H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F275H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F276H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F277H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F278H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F279H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F27AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F27BH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F27CH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F27DH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F27EH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F27FH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F280H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F281H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F282H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F15E_ConditionCheckRead( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F283H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F284H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataConditionCheck_F285H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );

extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F197_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F18A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F191_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F187_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F188_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F180_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F18B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F18C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F190_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F15B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F192_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F194_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F101_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F157_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F158_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F080_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F081_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F084_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F085_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3231_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3232_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3233_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3234_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3235_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3236_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F163_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F1AA_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F1AB_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F1AC_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F1AD_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F1AE_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F1AF_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13A_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13B_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13C_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13D_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13E_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF200H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF201H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF202H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF203H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF204H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF205H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF206H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF251H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF252H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF253H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF254H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF255H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF256H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF257H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF258H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF259H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF25AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF25BH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF25CH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF25DH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF25EH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF25FH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF210H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF211H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF212H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF213H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF214H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF215H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF216H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF217H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF218H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF219H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF21AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF21BH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF21CH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF21DH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF21EH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF21FH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF220H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF221H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF222H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF223H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF224H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF225H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF226H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF227H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF228H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF229H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF22AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF22BH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF22CH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF230H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF231H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF232H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF233H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF234H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF235H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF236H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF237H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF238H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF239H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF23AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF23BH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF23CH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF23DH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF23EH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF23FH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF240H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_0xF241H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3237_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3238_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F260H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F261H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F262H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F263H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F264H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F265H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F266H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F267H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F268H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F269H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F26AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F26BH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F26CH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F26DH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F26EH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F26FH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F270H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F271H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F272H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F273H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F274H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F275H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F276H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F277H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F278H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F279H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F27AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F27BH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F27CH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F27DH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F27EH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F27FH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F280H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F281H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F282H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F15E_ReadData( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F283H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F284H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_DataRead_F285H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );

extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3231_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3232_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3233_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3234_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3235_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3236_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3237_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3238_ReturnControlToECU(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3231_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3232_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3233_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3234_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3235_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3236_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3237_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_3238_ShortTermAdjustment(
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8,AUTOMATIC,DCM_VAR)ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F190_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F101_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F157_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F158_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13A_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13B_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13C_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13D_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
extern  Std_ReturnType  Rte_Call_Dcm_CSDataServices_DcmDspData_F13E_WriteData( const  uint8*  Data,uint16  DataLength,Dcm_OpStatusType  OpStatus,Dcm_NegativeResponseCodeType*  ErrorCode );
/***************************Routine Part****************************************/
extern  Std_ReturnType  Rte_DcmDspRequestRoutineResultsFnc_0xF159(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmDspRequestRoutineResultsFnc_5231(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmDspRequestRoutineResultsFnc_5234(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmDspRequestRoutineResultsFnc_5232(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmDspRequestRoutineResultsFnc_5235(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmDspRequestRoutineResultsFnc_0xF1B0(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmDspRequestRoutineResultsFnc_5236(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xFF02_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF159_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmRoutineStart_0x5231(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmRoutineStart_0x5234(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmRoutineStart_0x5232(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmRoutineStart_0x5235(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmRoutineStart_0xF015(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmRoutineStart_F1AD(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmRoutineStart_F1AE(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmRoutineStart_F1AF(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmRoutineStart_F1B0(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmRoutineStart_F1B1(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
extern  Std_ReturnType  Rte_DcmRoutineStart_0x5236(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8,AUTOMATIC,DCM_VAR)InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

/*******function for Protocol Start and stop***********/
extern  Std_ReturnType  DcmDslCallbackDCMRequestService_0_StartProtocol(Dcm_ProtocolType  ProtocolID);
extern  Std_ReturnType  DcmDslCallbackDCMRequestService_0_StopProtocol(Dcm_ProtocolType  ProtocolID);

/********* PreConditon Check ***********************/
extern Std_ReturnType Dcm_Rte_PreConditonCheck;
extern Std_ReturnType RTE_PreConditonCheck(uint8 SID, uint8* ReqDataPtr);

extern Std_ReturnType SchM_PerformReset(Rte_ModeType_DcmEcuReset Reset);

#endif /*RTEDCM_H*/

