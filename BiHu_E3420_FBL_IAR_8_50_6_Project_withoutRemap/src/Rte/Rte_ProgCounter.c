/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_ProgCounter.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2024-01-04 14:58:39>
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
#define RTE_PROGCOUNTER_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_ProgCounter.h"
#include "Appl_Cfg.h"
#include "Rte_Inc.h"
/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
#define RTE_PROG_COUNTER_ONECE RTE_CFG_PROG_COUNTER_ONECE
/*@}*/
/*=======[Private types]======================================================*/
/*@{*/
typedef struct
{
    uint16 Attempt;
    uint16 Success;
    boolean AttemptChanged;
    boolean SuccessChanged;
} Rte_ProgC_InfoType;
/*@}*/
/*=======[Private function prototypes]========================================*/
/*@{*/
static Rte_ProgC_InfoType progCounter;
/*@}*/
/*=======[Private variables]==================================================*/
/*@{*/
/*@}*/
/*=======[Private functions]==================================================*/
/*@{*/
/*@}*/
/******************************************************************************/
/*
 * @brief              [Rte_ProgCounter_Init description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_ProgCounter_Init()
{
    progCounter.AttemptChanged = FALSE;
    progCounter.SuccessChanged = FALSE;

    if (FALSE == Rte_Data_Read_ProgramSuccessCounter(&progCounter.Success))
    {
        progCounter.Success = APPL_MAX_PROGATTEMPT;
    }

    if (FALSE == Rte_Data_Read_ProgramAttemptCounter(&progCounter.Attempt))
    {
        progCounter.Attempt = APPL_MAX_PROGATTEMPT;
    }
}
/******************************************************************************/
/*
 * @brief              [Rte_ProgSuccessAdd description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
FL_ResultType Rte_ProgSuccessAdd(void)
{
    FL_ResultType ret = FL_OK;

    if(FALSE == progCounter.SuccessChanged)
    {
#if (RTE_PROG_COUNTER_ONECE == STD_ON )       
        progCounter.SuccessChanged = TRUE;
#endif
#if (APPL_MAX_PROGATTEMPT > 0u)
        if(progCounter.Success < APPL_MAX_PROGATTEMPT)
        {
#endif
            progCounter.Success++;

            if(TRUE != Rte_Data_Write_ProgramSuccessCounter(progCounter.Success))
            {
                ret = FL_ERR_MEMORY;
            }
#if (APPL_MAX_PROGATTEMPT > 0)
        }
        else
        {
            ret = FL_CONDITIONS_NOT_CORRECT;
        }
#endif
    }

    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_ProgAttemptAdd description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
FL_ResultType Rte_ProgAttemptAdd(void)
{
    FL_ResultType ret = FL_OK;

    if(FALSE == progCounter.AttemptChanged)
    {
#if (RTE_PROG_COUNTER_ONECE == STD_ON )       
        progCounter.AttemptChanged = TRUE;
#endif        

#if (APPL_MAX_PROGATTEMPT > 0u)
        if(progCounter.Attempt < APPL_MAX_PROGATTEMPT)
        {
#endif
            progCounter.Attempt++;

            if(TRUE != Rte_Data_Write_ProgramAttemptCounter(progCounter.Attempt))
            {
                ret = FL_ERR_MEMORY;
            }
#if (APPL_MAX_PROGATTEMPT > 0u)
        }
        else
        {
            ret = FL_CONDITIONS_NOT_CORRECT;
        }
#endif
    }

    return ret;
}
#if (RTE_PROG_COUNTER_ONECE == STD_ON )
/******************************************************************************/
/*
 * @brief              [Rte_ProgAttemptOneceClear description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_ProgAttemptOneceClear(void)
{
    progCounter.AttemptChanged = FALSE;
}
/******************************************************************************/
/*
 * @brief              [Rte_ProgSuccessOneceClear description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_ProgSuccessOneceClear(void)
{
    progCounter.SuccessChanged = FALSE;
}
#endif
/*=======[E N D   O F   F I L E]==============================================*/
