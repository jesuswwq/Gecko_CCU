/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_App.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2023-11-24 17:18:56>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>
 *
 */
/*@{*/
#define RTE_APP_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_App.h"
#include "DP.h"
#include "Dcm_Types.h"
#include "Appl_Callout.h"
#include "Rte_Inc.h"
/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
#define RTE_PROGRAM_FLAG_LEN      RTE_CFG_PROGRAM_FLAG_LEN
#define RTE_PROG_REQUEST_RECEIVED RTE_CFG_PROG_REQUEST_RECEIVED
#define RTE_PROG_REQNRSP_RECEIVED RTE_CFG_PROG_REQNRSP_RECEIVED
#define RTE_OTA_REQUEST_RECEIVED RTE_CFG_OTA_REQUEST_RECEIVED
#define RTE_OTA_REQNRSP_RECEIVED RTE_CFG_OTA_REQNRSP_RECEIVED
#define RTE_FACTORY_ENABLE        RTE_CFG_FACTORY_ENABLE
#define RTE_FACTORY_DATA1_LENGTH  RTE_CFG_FACTORY_DATA1_LENGTH
#define RTE_FACTORY_DATA1_BUFFER  RTE_CFG_FACTORY_DATA1_BUFFER
#define RTE_FACTORY_DATA2_LENGTH  RTE_CFG_FACTORY_DATA2_LENGTH
#define RTE_FACTORY_DATA2_BUFFER  RTE_CFG_FACTORY_DATA2_BUFFER
#define RTE_FACTORY_DATA1_ADDRESS RTE_CFG_FACTORY_DATA1_ADDRESS
#define RTE_FACTORY_DATA2_ADDRESS RTE_CFG_FACTORY_DATA2_ADDRESS
#define RTE_FACTORY_VALUE         RTE_DATA_FACTORY_FLAG
/*@}*/
/*=======[Private types]======================================================*/
/*@{*/
/*@}*/
/*=======[Private function prototypes]========================================*/
/*@{*/
/*@}*/
/*=======[Private variables]==================================================*/
/*@{*/
/*@}*/
/*=======[Private functions]==================================================*/
/*@{*/
extern void FL_Init(void);/*PRQA S 3449, 3451*/
extern void Dcm_DspInit(void);/*PRQA S 3449, 3451*/
extern void Appl_EcuReset(void);/*PRQA S 3449, 3451*/
extern void Dcm_StartResetTimer(uint16 timeOut);/*PRQA S 3449, 3451*/
#if (STD_ON == FL_FINGER_PRINT_WRITE_ENABLE)
extern void Dcm_ClearFingerPrintWrittenStatus(void);/*PRQA S 3449, 3451*/
#endif
extern void Dcm_SetSecurityLevel(const Dcm_SecurityType secLev);/*PRQA S 3449, 3451*/
extern void Dcm_ProgramInit(Dcm_SessionType targetSession);/*PRQA S 3449, 3451*/
extern void Dcm_SetSessionMode(const Dcm_SessionType sessMode);/*PRQA S 3449, 3451*/
extern void Dcm_StartP3cTimer(void);/*PRQA S 3449, 3451*/
extern void Dcm_Set_CurPduIdGrp(const PduIdGrpType * cfg);/*PRQA S 3449, 3451*/
/*@}*/
/******************************************************************************/
/**
 * @brief               <DCM module program initialize>
 *
 * <when program boot request is equal to FL_EXT_PROG_REQUEST_RECEIVED,
 *  this API will be called in Appl_FlStartup function, session is initialized
 *  to programming session,and simulate an 10 02 session control service is
 *  received> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_ProgramInitResp(Dcm_SessionType targetSession)
{
    Dcm_ProgramInit(targetSession);
}
/******************************************************************************/
/**
 * @brief               <DCM module program initialize>
 *
 * <when program boot request is equal to FL_EXT_PROG_REQUEST_RECEIVED,
 *  this API will be called in Appl_FlStartup function, session is initialized
 *  to programming session,and simulate an 10 02 session control service is
 *  received> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Dcm_ProgramInitNoResp(Dcm_SessionType targetSession)
{
    /* from boot, then set session to programming session */
    Dcm_SetSessionMode(targetSession);

    if ((uint8)DCM_SESSION_PROGRAMMING == targetSession)
    {
        Dcm_StartP3cTimer();
    }
}
/******************************************************************************/
/**
 * @brief               <check application factory mode>
 *
 * <> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
boolean Rte_Appl_ReadProgrammingFlag(void)
{
    boolean ret = FALSE;
    /* ----------------projectCfg---------------- */
    uint8 ProgSignature[RTE_PROGRAM_FLAG_LEN] = {RTE_PROG_REQUEST_RECEIVED};
    uint8 ProgNrspSig[RTE_PROGRAM_FLAG_LEN] = {RTE_PROG_REQNRSP_RECEIVED};
    uint8 OtaFlag[RTE_PROGRAM_FLAG_LEN] = {RTE_OTA_REQUEST_RECEIVED};
    uint8 OtaNrspFlag[RTE_PROGRAM_FLAG_LEN] = {RTE_OTA_REQNRSP_RECEIVED};
    uint8 ProgReqReadBuf[RTE_PROGRAM_FLAG_LEN] = {0};

    if (FALSE == Rte_isWarmStart())
    {

    }
    else if(FALSE == Rte_Data_Read_PROGRAM_Flag(&ProgReqReadBuf[0]))
    {

    }
    else if (TRUE == DP_Memcompare(ProgSignature, ProgReqReadBuf, RTE_PROGRAM_FLAG_LEN))
    {
        Dcm_Set_CurPduIdGrp(&Dcm_PduID_Cfg[0]);
        Dcm_ProgramInitResp(DCM_SESSION_PROGRAMMING);
        ret = TRUE;
    }
    else if (TRUE == DP_Memcompare(ProgNrspSig, ProgReqReadBuf, RTE_PROGRAM_FLAG_LEN))
    {
        Dcm_Set_CurPduIdGrp(&Dcm_PduID_Cfg[0]);
        Dcm_ProgramInitResp(DCM_SESSION_PROGRAMMING);
/*         app send nrc78,so boot will respon
 *        Dcm_ProgramInitNoResp(DCM_SESSION_PROGRAMMING); 
 */
        ret = TRUE;
    }
    else if (TRUE == DP_Memcompare(OtaFlag, ProgReqReadBuf, RTE_PROGRAM_FLAG_LEN))
    {
        Dcm_Set_CurPduIdGrp(&Dcm_PduID_Cfg[1]);
        Dcm_ProgramInitResp(DCM_SESSION_PROGRAMMING);
        ret = TRUE;
    }
    else if (TRUE == DP_Memcompare(OtaNrspFlag, ProgReqReadBuf, RTE_PROGRAM_FLAG_LEN))
    {
        Dcm_Set_CurPduIdGrp(&Dcm_PduID_Cfg[1]);
        Dcm_ProgramInitResp(DCM_SESSION_PROGRAMMING);
/*         app send nrc78,so boot will respon
 *        Dcm_ProgramInitNoResp(DCM_SESSION_PROGRAMMING); 
 */
        ret = TRUE;
    }
    else
    {
        /*empty*/
    }
#ifdef PROJECT_SPECIAL
    if (TRUE == ret)
    {
        Dcm_StartSecurityTimer(0,0u);
    }
#endif
#if 0
    if (TRUE == ret)
#endif    
    {
        DP_Memset(&ProgReqReadBuf[0], 0, RTE_PROGRAM_FLAG_LEN);
        Rte_Data_Write_PROGRAM_Flag(&ProgReqReadBuf[0]);
    }
    /* ----------------projectCfg end---------------- */

    return ret;
}
/******************************************************************************/
/**
 * @brief               <check application factory mode>
 *
 * <> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
FL_ResultType Rte_Appl_CheckConsistency(void)
{
    FL_ResultType retVal = (FL_ResultType)FL_FAILED;
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    /* If abpartition is enabled, information is read from
    another partition by default, so switch the flag first
    so that it can be read from the current partition and
    switch back to the flag when the current partition
    information is not needed */
    Rte_ABSwap_SwitchBankFlag();
    Rte_BlkM_InitBlockInfo();
#endif
    /* check if application software is consistency */
    if (FL_OK == Rte_BlkM_CheckCompatibility())
    {
        /* geely startup check ProgDependencies */
#if 0
        Rte_BlkM_SetIfAppValid();
#endif

        if(TRUE == Rte_BlkM_GetAppValid())
        {
            retVal = FL_OK;
        }
    }
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    /* If abpartition is enabled, information is read from
    another partition by default, so switch the flag first
    so that it can be read from the current partition and
    switch back to the flag when the current partition
    information is not needed */
    Rte_ABSwap_SwitchBankFlag();
    Rte_BlkM_InitBlockInfo();
#endif
    return retVal;
}
/******************************************************************************/
/**
 * @brief               <check application factory mode>
 *
 * <> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
void Rte_Appl_InitNvmInfo(void)
{
	NvMemInit();
    
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    Rte_ABSwap_Init();
    Rte_Data_Write_Fingerprint_to_App();
#endif    
    Rte_ProgCounter_Init();
    Rte_SecM_InitSecurityCounter();
    Rte_BlkM_InitBlockInfo();
}
/******************************************************************************/
/**
 * @brief               <check application factory mode>
 *
 * <> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
void Rte_Appl_CheckFactoryMode (void)
{
#if (RTE_FACTORY_ENABLE == STD_ON)
    boolean ret = FALSE;
    uint8 flag = 0;
    uint8 i;
    /* ----------------projectCfg---------------- */
    if ((TRUE == Rte_Data_Read_Factory(&flag)) && (RTE_FACTORY_VALUE == flag))
    {
        ; /* The factory mode has been set  */
    }
    else
    {
#if (RTE_FACTORY_CHECK_CONTENT== STD_ON)
        const uint8 FactoryMode_Data_1[RTE_FACTORY_DATA1_LENGTH] =
        {
            RTE_FACTORY_DATA1_BUFFER
        };
        const uint8 FactoryMode_Data_2[RTE_FACTORY_DATA2_LENGTH] =
        {
            RTE_FACTORY_DATA2_BUFFER
        };

        if (FALSE == DP_Memcompare(FactoryMode_Data_1, (const uint8 *)RTE_FACTORY_DATA1_ADDRESS, RTE_FACTORY_DATA1_LENGTH))
        {
            ; /* not find flag FBL */
        }
        else if (FALSE == DP_Memcompare(FactoryMode_Data_2, (const uint8 *)RTE_FACTORY_DATA2_ADDRESS, RTE_FACTORY_DATA2_LENGTH))
        {
            ; /* not find flag App */
        }
        /* ----------------projectCfg end---------------- */
        else
        {
            ret = TRUE;
        }

        if(TRUE == ret)
        {
            ret = Rte_BlkM_ActiveBlockInfo();
#if (RTE_PARTITION_SWAP_ON == STD_ON)
            /* If abpartition is enabled, information is read from
            another partition by default, so switch the flag first
            so that it can be read from the current partition and
            switch back to the flag when the current partition
            information is not needed */
            Rte_ABSwap_SwitchBankFlag();
            Rte_BlkM_InitBlockInfo();
            ret = Rte_BlkM_ActiveBlockInfo();
            /* If abpartition is enabled, information is read from
            another partition by default, so switch the flag first
            so that it can be read from the current partition and
            switch back to the flag when the current partition
            information is not needed */
            Rte_ABSwap_SwitchBankFlag();
            Rte_BlkM_InitBlockInfo();
#endif
        }

        // if (TRUE == ret)
#endif
        {
            for(i =0;i<DCM_SECURITY_NUM;i++)
            {
                (void)Rte_Data_Write_SecurityAccess(i,0);
                Dcm_StartSecurityTimer(i, APPL_START_SECURITY_TIME);
            }
            (void)Rte_Data_Write_ProgramAttemptCounter(0);
            (void)Rte_Data_Write_ProgramSuccessCounter(0);
            (void)Rte_Data_Write_Factory(RTE_FACTORY_VALUE);
        }
    }

#endif
}
/******************************************************************************/
/**
 * @brief               <flashloader initialize>
 *
 * <This routine shall be called by the flash loader to initialize the software
 *  environment needed for ECU reprogramming (after the decision to switch to
 *  flash loader mode).> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
void Rte_Appl_Swtich_Session(uint8 lastSession)
{
    Dcm_DspInit();
    Dcm_SetSecurityLevel((uint8)DCM_SECURITY_LOCKED);
#if (STD_ON == FL_FINGER_PRINT_WRITE_ENABLE)
    Dcm_ClearFingerPrintWrittenStatus();
#endif
    if (Dcm_GetSessionMode() == DCM_SESSION_EXTEND)
    {
    }
    else
    {
        FL_Init();

        /* if request session is default session */
        if ((Dcm_GetSessionMode() == DCM_SESSION_DEFAULT) && (lastSession == DCM_SESSION_PROGRAMMING))
        {
            Dcm_StartResetTimer(10);
        }
        /* if request session is default session */
        else if ((Dcm_GetSessionMode() == DCM_SESSION_DEFAULT) && (lastSession == DCM_SESSION_EXTEND))
        {
            // Dcm_StartResetTimer(10);
        }
		else
		{
		    /*nothing*/
		}

#ifdef PROJECT_APP
        else if (Dcm_GetSessionMode() == DCM_SESSION_PROGRAMMING)
        {
            uint8 ProgSignature[RTE_DATA_PROGRAM_FLAG_LEN] = {RTE_PROG_REQUEST_RECEIVED};
            Rte_Data_Write_PROGRAM_Flag((uint8*)ProgSignature);
            /* start reset timer*/
            Appl_EcuReset();
        }
#endif
    }
}
/******************************************************************************/
/**
 * @brief               <flashloader initialize>
 *
 * <This routine shall be called by the flash loader to initialize the software
 *  environment needed for ECU reprogramming (after the decision to switch to
 *  flash loader mode).> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
void Rte_Appl_P3ClientTimout(void)
{
    FL_Init();
    Dcm_DspInit();
    Dcm_SetSecurityLevel((uint8)DCM_SECURITY_LOCKED);
#if (STD_ON == FL_FINGER_PRINT_WRITE_ENABLE)
    Dcm_ClearFingerPrintWrittenStatus();
#endif
    if (Dcm_GetSessionMode() == DCM_SESSION_PROGRAMMING)
    {
        Appl_EcuReset();
    }
    else if (Dcm_GetSessionMode() == DCM_SESSION_EXTEND)
    {
        Appl_EcuReset();
    }
    else
    {
	/*nothing*/
    }
}

/*=======[E N D   O F   F I L E]==============================================*/
