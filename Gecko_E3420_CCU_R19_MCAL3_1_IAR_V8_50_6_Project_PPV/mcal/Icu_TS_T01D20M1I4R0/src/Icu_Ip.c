/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \file     Icu_Ip.c                                                                                   *
 * \brief    This file mainly implements the definition of register operation  interface and data       *
 *           calculation interface                                                                      *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/18     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
/* icu-ip self definition */
#include "Icu_Ip.h"
/* register operation file */
#include "RegHelper.h"
/* etimer resigter address file */
#include "Icu_Register.h"
/* critical section protection file */
#include "SchM_Icu.h"


/********************************************************************************************************
 *                                      Static variables                                                *
 *******************************************************************************************************/

/* memap infomation */
#define ICU_START_SEC_CONST_32
#include "Icu_MemMap.h"

/* etimer module base address information */
#ifndef SEMIDRIVE_E3_LITE_SERIES
static const uint32 Icu_Ip_EtmrBase[TIMER_MODULE_NUMBER] = {APBMUX_ETMR1_BASE,
                                                            APBMUX_ETMR2_BASE,
                                                            APBMUX_ETMR3_BASE,
                                                            APBMUX_ETMR4_BASE};
#else /* SEMIDRIVE_E3_LITE_SERIES */
static const uint32 Icu_Ip_EtmrBase[TIMER_MODULE_NUMBER] = {APBMUX_ETMR1_BASE,
                                                            APBMUX_ETMR2_BASE};
#endif /* SEMIDRIVE_E3_LITE_SERIES */

/* memap infomation */
#define ICU_STOP_SEC_CONST_32
#include "Icu_MemMap.h"

/* memap infomation */
#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Icu_MemMap.h"

/* check if etimer has been configed the clock information */
static boolean Icu_Ip_SetClkInfo[TIMER_MODULE_NUMBER];

#if (STD_ON == ICU_GET_INPUTSTATE_API)
/* channel inpout status in sigmeasurement mode */
static Icu_InputStateType Icu_Ip_ChannelState[TIMER_MODULE_NUMBER][LOCAL_CHANNEL_NUMBER];
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */

#if (STD_ON == ICU_SIGNALMEASUREMENT_API)
/* the channel signal time value */
static uint32 Icu_Ip_SiglDuraVal[TIMER_MODULE_NUMBER][LOCAL_CHANNEL_NUMBER];
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/* the channel signal time value in multi capture mode */
static uint32 Icu_Ip_MulSiglDuraVal[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
/* have captured the channel duty cycle value in multi capture mode */
static boolean Icu_Ip_MulSigDutyOver[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
/* the channel high level time value in multi capture mode */
static uint32 Icu_Ip_MulHighSigTime[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
/* check if the duty cycle information has been read */
static boolean Icu_Ip_HaveReadFlag[TIMER_MODULE_NUMBER][LOCAL_CHANNEL_NUMBER];
/* store the duty cycle value */
static uint32 Icu_Ip_ActiveTime[TIMER_MODULE_NUMBER][LOCAL_CHANNEL_NUMBER];
/* store the period value */
static uint32 Icu_Ip_PeriodTime[TIMER_MODULE_NUMBER][LOCAL_CHANNEL_NUMBER];
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/* check if the duty cycle information has been read in multi capture mode */
static boolean Icu_Ip_MulHaveReadFlag[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
/* store the period value in multi capture mode */
static uint32 Icu_Ip_MulPeriodTime[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */
#endif /* STD_ON == ICU_SIGNALMEASUREMENT_API */

#if (STD_ON == ICU_DMA_SUPPORT)
/* store the dma channel information */
static void* Icu_Ip_ChanDmaPtr[NUM_OF_CHANNEL];
#endif

#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
/* store the dma channel information in multi capture mode */
static void* Icu_Ip_MulDmaPtr[MULTI_CPT_MODULE_NUM][MULT_CPT_DMA_CHAN_NUM];
#endif /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */

/* memap infomation */
#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Icu_MemMap.h"

/********************************************************************************************************
 *                                      Static fcuntion                                                 *
 *******************************************************************************************************/
/* memap infomation */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

static Std_ReturnType Icu_Ip_FilterConfig(uint16 fltLevel, Icu_HwModule tmrModule, Icu_HwChannel hwChannel);
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
static Std_ReturnType Icu_Ip_MultiCptSetupDma(const Icu_ChannelConfigType* channelConfigPtr);
static void Icu_Ip_MultiCptFreeDma(Icu_HwModule tmrModule);
#endif /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */
static void Icu_Ip_MultiCptDmaRegConfig(Icu_HwModule tmrModule, boolean intMode);
static void Icu_Ip_MultiCptSseConfig(Icu_HwModule tmrModule);
static void Icu_Ip_MultiCptEdgeTypeSet(const Icu_ChannelConfigType* channelConfigPtr);
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */

/** *****************************************************************************************************
 * \brief This function set etimer channel filter level
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_FilterConfig(uint16 fltLevel,
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : fltLevel - etimer filter level
 *                                 (bandwidth * sample_interval)
 *                      tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function set etimer channel filter level
 * \endverbatim
 * Traceability       : SW_SM006
 *******************************************************************************************************/
static Std_ReturnType Icu_Ip_FilterConfig(uint16 fltLevel, Icu_HwModule tmrModule, Icu_HwChannel hwChannel)
{
    /* init local varibles */
    Std_ReturnType retVal = E_OK;
    uint16 fltInterval;
    uint16 fltWidth;
    /* max filter level config */
    uint16 maxWidth = 0x0FU;
    uint16 maxInterval = 0xFFU;
    uint16 maxFltLevlel = maxWidth * maxInterval;
    /* #10 both edge need config filter */
    uint32 fltCfg = ICU_CPT_FLT_EN | ICU_CPT_FLT_BOTHEDGE_SEL;
    if ((TIMER_MODULE_NUMBER <= (uint8)tmrModule) || (LOCAL_CHANNEL_NUMBER <= (uint8)hwChannel) )
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /* #20 set filter level */
        if (0U == fltLevel)
        {
            /* set default filter level */
            fltInterval = 0U;
            fltWidth = 1U;
        }
        else if (fltLevel <= maxWidth)
        {
            /* filter level: 0-15 */
            fltInterval = 0U;
            fltWidth = fltLevel;
        }
        else if (fltLevel <= maxFltLevlel)
        {
            /* filter level: 15-3845 */
            fltInterval = fltLevel/maxWidth;
            fltWidth = maxWidth;
        }
        else
        {
            /* filter level out of range: set the max filter level */
            fltInterval = maxInterval;
            fltWidth = maxWidth;
        }
        /* #30 set the filter level to register */
        fltCfg |= ICU_CPT_FLT_SMPL_INTVAL(fltInterval) | ICU_CPT_FLT_POS_BAND_WID(fltWidth) |
                    ICU_CPT_FLT_NEG_BAND_WID(fltWidth);
        REG_WRITE32(fltCfg, ICU_CPT_X0_FLT(tmrModule, hwChannel));
    }
    return retVal;
}


#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
/** *****************************************************************************************************
 * \brief This function setup dma channel information in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptSetupDma(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function setup dma channel information in multi
 *                      capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_205 SWSR_ICU_206
 *******************************************************************************************************/
static Std_ReturnType Icu_Ip_MultiCptSetupDma(const Icu_ChannelConfigType* channelConfigPtr)
{
    boolean dmaRet;
    /* set cptb channel dma cfg */
    Dma_ChannelConfigType *chanbRx;
    Dma_DeviceConfigType dmabConfig;
    Dma_InstanceConfigType dmaConfigDataChnB;
    uint8  dmaChnbRet;
    /* set cptb channel dma cfg */
    Dma_ChannelConfigType *chancRx;
    Dma_DeviceConfigType dmacConfig;
    Dma_InstanceConfigType dmaConfigDataChnC;
    uint8  dmaChncRet;
    boolean dmabSetup = FALSE;
    boolean dmacSetup = FALSE;
    Std_ReturnType retVal = E_NOT_OK;
    Icu_HwModule tmrModule = channelConfigPtr->icuHwChanCfgPtr->timerModule;
    uint8 dmaModuleId = (uint8)tmrModule + (uint8)DMA_ICU_INDEX_ETIMER1;
    /* get channel b dma configuration information */
    /* #10 etimer channel b dma configuration */
    /* PRQA S 4342  1 */
    dmaChnbRet = Dma_GetConfigParams((Dma_PeripheralIdType)dmaModuleId, DMA_ICU_CPT_B,
                                      DMA_MODULE_ETIMER, &dmaConfigDataChnB);
    if (dmaChnbRet == E_OK)
    {
        chanbRx = Dma_RequestChannelWithId(dmaConfigDataChnB.controller, dmaConfigDataChnB.channelId);
        if (NULL_PTR != chanbRx)
        {
            (void)Dma_InitConfigChannel(&dmabConfig);
            /* set dma channel information  */
            /* PRQA S 0314  1 */
            Icu_Ip_MulDmaPtr[tmrModule][MULT_CPT_CHAN_B_INDEX] = (void *)chanbRx;
            chanbRx->irqCallback = NULL_PTR;
            dmabConfig.direction = DMA_DEVICE_TO_MEMORY;
            dmabConfig.flowControl = DMA_DIR_DEVICE_TO_MEMORY;
            /* src addr :fifo_b */
            dmabConfig.srcAddress = ICU_FIFO_ADDR32(tmrModule, ICU_HW_CPT_B);
            /* PRQA S 0306  1 */
            dmabConfig.dstAddress = Mcal_AddressConvert((uint32)(&Icu_MulChanbBuffer[tmrModule][0]));
            dmabConfig.srcBusWidth = DMA_BEAT_SIZE_4_BYTE;
            dmabConfig.dstBusWidth = DMA_BEAT_SIZE_4_BYTE;
            /* set burst len same with wml (value:8U) */
            dmabConfig.srcMaxBurst = DMA_BURST_LENGTH_8;
            dmabConfig.dstMaxBurst = DMA_BURST_LENGTH_8;
            dmabConfig.periodLength = (uint32)MULTI_CPT_BURST_LEN * 0x4UL;
            dmabConfig.srcPortSelect = DMA_PORT_AHB32;
            dmabConfig.dstPortSelect = DMA_PORT_AXI64;
            dmabConfig.srcIncDirection = DMA_BURST_FIXED;
            dmabConfig.dstIncDirection = DMA_BURST_INCREMENTAL;
            dmabConfig.transaction = DMA_CYCLIC;
            dmabConfig.processMode = DMA_INTERRUPT;
            dmabConfig.linkListTriggerMode = DMA_TRIGGER_BY_HARDWARE;
            dmabConfig.loopMode = DMA_LOOP_MODE_1;
            (void)Dma_ConfigChannel(chanbRx, &dmabConfig);
            dmaRet = Dma_PrepareTransmission(chanbRx,
                                            MULTI_CPT_BURST_LEN * 0x4UL * 2U);
#if (STD_OFF == ICU_NON_CACHE_NEEDED)
            /* PRQA S 0306  1 */
            (void)Dma_InvalidateCache((uint32)(&Icu_MulChanbBuffer[tmrModule][0]),
                                MULTI_CPT_BURST_LEN * 0x4UL * 2U);
#endif /* STD_OFF == ICU_NON_CACHE_NEEDED */
            if (dmaRet == E_OK)
            {
                (void)Dma_Start(chanbRx);
                dmabSetup = TRUE;
            } /* else not needed */
        } /* else not needed */
    } /* else not needed */
    /* get channel c dma configuration information */
    /* PRQA S 4342  1 */
    dmaChncRet = Dma_GetConfigParams((Dma_PeripheralIdType)dmaModuleId, DMA_ICU_CPT_C,
                                      DMA_MODULE_ETIMER, &dmaConfigDataChnC);
    if (dmaChncRet == E_OK)
    {
        chancRx = Dma_RequestChannelWithId(dmaConfigDataChnC.controller, dmaConfigDataChnC.channelId);
        if (NULL_PTR != chancRx)
        {
            (void)Dma_InitConfigChannel(&dmacConfig);
            /* set dma channel information  */
            /* PRQA S 0314  1 */
            Icu_Ip_MulDmaPtr[tmrModule][MULT_CPT_CHAN_C_INDEX] = (void *)chancRx;
            /* cpt c don't need callback function cause cpt c is sync with fifo b*/
            /* PRQA S 0311,0314  1 */
            chancRx->context = (void *)channelConfigPtr;
            chancRx->irqCallback = (Dma_IrqHandle)&Icu_MultiCptDmaIrqHandler;
            dmacConfig.direction = DMA_DEVICE_TO_MEMORY;
            dmacConfig.flowControl = DMA_DIR_DEVICE_TO_MEMORY;
            /* src addr :fifo_b */
            dmacConfig.srcAddress = ICU_FIFO_ADDR32(tmrModule, ICU_HW_CPT_C);
            /* PRQA S 0306  1 */
            dmacConfig.dstAddress = Mcal_AddressConvert((uint32)(&Icu_MulChancBuffer[tmrModule][0]));
            dmacConfig.srcBusWidth = DMA_BEAT_SIZE_4_BYTE;
            dmacConfig.dstBusWidth = DMA_BEAT_SIZE_4_BYTE;
            /* set burst len same with wml (value:8U) */
            dmacConfig.srcMaxBurst = DMA_BURST_LENGTH_8;
            dmacConfig.dstMaxBurst = DMA_BURST_LENGTH_8;
            dmacConfig.periodLength = (uint32)MULTI_CPT_BURST_LEN * 0x4UL;
            dmacConfig.srcPortSelect = DMA_PORT_AHB32;
            dmacConfig.dstPortSelect = DMA_PORT_AXI64;
            dmacConfig.srcIncDirection = DMA_BURST_FIXED;
            dmacConfig.dstIncDirection = DMA_BURST_INCREMENTAL;
            dmacConfig.transaction = DMA_CYCLIC;
            dmacConfig.processMode = DMA_INTERRUPT;
            dmacConfig.linkListTriggerMode = DMA_TRIGGER_BY_HARDWARE;
            dmacConfig.loopMode = DMA_LOOP_MODE_1;
            (void)Dma_ConfigChannel(chancRx, &dmacConfig);
            dmaRet = Dma_PrepareTransmission(chancRx,
                                            MULTI_CPT_BURST_LEN * 0x4UL * 2U);
#if (STD_OFF == ICU_NON_CACHE_NEEDED)
            /* PRQA S 0306  1 */
            (void)Dma_InvalidateCache((uint32)(&Icu_MulChancBuffer[tmrModule][0]),
                                MULTI_CPT_BURST_LEN * 0x4UL * 2U);
#endif /* STD_OFF == ICU_NON_CACHE_NEEDED */
            if (dmaRet == E_OK)
            {
                (void)Dma_Start(chancRx);
                dmacSetup = TRUE;
            } /* else not needed */
        } /* else not needed */
    } /* else not needed */
    if ((TRUE == dmabSetup) && (TRUE == dmacSetup))
    {
        retVal = E_OK;
    }
    return retVal;
}

/** *****************************************************************************************************
 * \brief This function free dma channel in multi capture mode
 *
 * \verbatim
 * Syntax             : void Icu_Ip_MultiCptFreeDma(Icu_HwModule tmrModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function free dma channel in multi capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_205 SWSR_ICU_206
 *******************************************************************************************************/
static void Icu_Ip_MultiCptFreeDma(Icu_HwModule tmrModule)
{
    /* PRQA S 0316  2 */
    Dma_ChannelConfigType *chanbRx =
                            (Dma_ChannelConfigType *)Icu_Ip_MulDmaPtr[tmrModule][MULT_CPT_CHAN_B_INDEX];
    /* PRQA S 0316  2 */
    Dma_ChannelConfigType *chancRx =
                            (Dma_ChannelConfigType *)Icu_Ip_MulDmaPtr[tmrModule][MULT_CPT_CHAN_C_INDEX];
    /* #10 free cpt b dma config */
    if (NULL_PTR != chanbRx)
    {
        /* free dma channel */
        (void)Dma_Stop(chanbRx);
        (void)Dma_ReleaseChannel(chanbRx);
        Icu_Ip_MulDmaPtr[tmrModule][MULT_CPT_CHAN_B_INDEX] = NULL_PTR;
    } /* else not needed */
    /* #20 cpt c dma config */
    if (NULL_PTR != chancRx)
    {
        /* free dma channel */
        (void)Dma_Stop(chancRx);
        (void)Dma_ReleaseChannel(chancRx);
        Icu_Ip_MulDmaPtr[tmrModule][MULT_CPT_CHAN_C_INDEX] = NULL_PTR;
    } /* else not needed */
}
#endif /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */

/** *****************************************************************************************************
 * \brief This function set etimer dma registers in multi capture mode
 *
 * \verbatim
 * Syntax             : void Icu_Ip_MultiCptDmaRegConfig(Icu_HwModule tmrModule,
 *                                                       boolean intMode)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      intMode - check if etimer uses interrupt mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function set etimer dma registers in multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_205 SWSR_ICU_206
 *******************************************************************************************************/
static void Icu_Ip_MultiCptDmaRegConfig(Icu_HwModule tmrModule, boolean intMode)
{
    uint8 i;
    Icu_HwChannel chnbIndex = ICU_HW_CPT_B;
    Icu_HwChannel chncIndex = ICU_HW_CPT_C;
    /* set fifo wml */
    uint32 chnWml = REG_READ32(ICU_CHN_DMA_WML(tmrModule));
    /* clear fifo */
    uint32 fifoSta = REG_READ32(ICU_FIFO_STA(tmrModule));
    uint32 fifoEntry;
    /* select the dma block */
    uint32 dmaCtrl = REG_READ32(ICU_CHN_DMA_CTRL(tmrModule));
    /* #10 check if the multi capture support interrupt mode */
    if (FALSE == intMode)
    {
        /* set fifo b wml (value: 8U) */
        chnWml &= ~ICU_FM_DMA_WML_CHN(chnbIndex);
        chnWml |= ICU_FV_DMA_WML_CHN(8U, chnbIndex);
        /* set fifo c wml (value: 8U) */
        chnWml &= ~ICU_FM_DMA_WML_CHN(chncIndex);
        chnWml |= ICU_FV_DMA_WML_CHN(8U, chncIndex);
        REG_WRITE32(chnWml, ICU_CHN_DMA_WML(tmrModule));
    } /* else not needed */
    /* #20 dma control setting */
    /* clear fifo b */
    fifoEntry = ((fifoSta >> ((8U * (uint32)chnbIndex) + 2U)) & 0x1FU);
    for (i = 0U; i < fifoEntry; i++)
    {
        REG_READ32(ICU_FIFO_ADDR32(tmrModule, chnbIndex));
    }
    /* clear fifo c */
    fifoEntry = ((fifoSta >> ((8U * (uint32)chncIndex) + 2U)) & 0x1FU);
    for (i = 0U; i < fifoEntry; i++)
    {
        REG_READ32(ICU_FIFO_ADDR32(tmrModule, chncIndex));
    }
    /* enable dma channel b */
    dmaCtrl |= ICU_BM_CHN_DMA_CTRL_CHN_EN(chnbIndex);
    /* set channel b dma block as capture */
    dmaCtrl &= ~ICU_FM_CHN_DMA_CTRL_CHN_SEL(chnbIndex);
    dmaCtrl |= ICU_FV_CHN_DMA_CTRL_CHN_SEL(1U, chnbIndex);
    /* enable dma channel c */
    dmaCtrl |= ICU_BM_CHN_DMA_CTRL_CHN_EN(chncIndex);
    /* set channel c dma block as capture */
    dmaCtrl &= ~ICU_FM_CHN_DMA_CTRL_CHN_SEL(chncIndex);
    dmaCtrl |= ICU_FV_CHN_DMA_CTRL_CHN_SEL(1U, chncIndex);
    REG_WRITE32(dmaCtrl, ICU_CHN_DMA_CTRL(tmrModule));
}

/** *****************************************************************************************************
 * \brief This function set etimer sse registers in multi capture mode
 *
 * \verbatim
 * Syntax             : void Icu_Ip_MultiCptSseConfig(Icu_HwModule tmrModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function set etimer sse registers in multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_206
 *******************************************************************************************************/
static void Icu_Ip_MultiCptSseConfig(Icu_HwModule tmrModule)
{
    Icu_HwChannel chnbIndex = ICU_HW_CPT_B;
    Icu_HwChannel chncIndex = ICU_HW_CPT_C;
    /* #10 set cpt b sse */
    /* sse b reg : cpt_a0 | cpt_b0 | cpt_c0 | cpt_d0*/
    uint32 sseReg = 0xFFFEFFFEU;
    REG_WRITE32(sseReg, ICU_CPT_SSE_REG_OFF(tmrModule, chnbIndex));
    uint32 sseCtrl = REG_READ32(ICU_CPT_SSE_CTRL_OFF(tmrModule, chnbIndex));
    sseCtrl &= ~ICU_FM_CPT_SSE_CTRL_SSE_MODE;
    /* set cpt b sse1-sse5 mode : all edge mode (value: 0x1F) */
    sseCtrl |= ICU_FV_CPT_SSE_CTRL_SSE_MODE(0x1F);
    /* set cpt b sse1-sse5 edge mode : rising edge (value: 0) */
    sseCtrl &= ~ICU_FM_CPT_SSE_CTRL_EDGE_SEL;
    /* sse cpt b enable */
    sseCtrl |= ICU_BM_CPT_SSE_CTRL_SSE_EN;
    REG_WRITE32(sseCtrl, ICU_CPT_SSE_CTRL_OFF(tmrModule, chnbIndex));
    /* #20 set cpt c sse */
    /* sse c reg : cpt_a0 | cpt_b0 | cpt_c0 | cpt_d0*/
    sseReg = 0xFFFEFFFEU;
    REG_WRITE32(sseReg, ICU_CPT_SSE_REG_OFF(tmrModule, chncIndex));
    sseCtrl = REG_READ32(ICU_CPT_SSE_CTRL_OFF(tmrModule, chncIndex));
    sseCtrl &= ~ICU_FM_CPT_SSE_CTRL_SSE_MODE;
    /* set cpt c sse1-sse5 mode : all edge mode (value: 0x1F) */
    sseCtrl |= ICU_FV_CPT_SSE_CTRL_SSE_MODE(0x1F);
    /* set cpt c sse1-sse5 edge mode : rising edge (value: 0) */
    sseCtrl &= ~ICU_FM_CPT_SSE_CTRL_EDGE_SEL;
    /* sse cpt c enable */
    sseCtrl |= ICU_BM_CPT_SSE_CTRL_SSE_EN;
    REG_WRITE32(sseCtrl, ICU_CPT_SSE_CTRL_OFF(tmrModule, chncIndex));
}

/** *****************************************************************************************************
 * \brief This function set sub channel edge type in multi capture mode
 *
 * \verbatim
 * Syntax             : void Icu_Ip_MultiCptEdgeTypeSet(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function set sub channel edge type in multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_206
 *******************************************************************************************************/
static void Icu_Ip_MultiCptEdgeTypeSet(const Icu_ChannelConfigType* channelConfigPtr)
{
    uint8 i;
    Icu_HwModule tmrModule = channelConfigPtr->icuHwChanCfgPtr->timerModule;
    uint8 mulChanNum = channelConfigPtr->icuHwChanCfgPtr->multiCptChanNum;
    Icu_MeasurementModeType measureType;
    Icu_ActivationType edgeType;
    /* #10 edge type set */
    for (i = 0U; i < mulChanNum; i++)
    {
        measureType = channelConfigPtr->multiCptChanCfgPtr[i].icuMeasurementModeMul;
        if (ICU_MODE_TIMESTAMP == measureType)
        {
            edgeType = channelConfigPtr->multiCptChanCfgPtr[i].Icu_MultiCptTimestamp.tsMulStartEdge;
            Icu_MulEdgeSelect[tmrModule][i] = edgeType;
        }
        else if (ICU_MODE_EDGE_COUNTER == measureType)
        {
            edgeType = channelConfigPtr->multiCptChanCfgPtr[i].Icu_MultiCptEdgeCount.edgeCntMulStartEdge;
            Icu_MulEdgeSelect[tmrModule][i] = edgeType;
        }
        else
        {
            /* do nothing to avoid warning */
        }
    }
}
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */

/********************************************************************************************************
 *                                      Internal Interface                                              *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \brief This function initializes the channel and set the etimer hardware
 *        registers
 *
 * \verbatim
 * Syntax             : void Icu_MultiCptDmaIrqHandler(uint8 dmaTransSta,
 *                                                     void* arg)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function initializes the channel and set the etimer
 *                      hardware registers
 * \endverbatim
 * Traceability       : SWSR_ICU_034 SWSR_ICU_035 SWSR_ICU_037
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_ChannelInit(const Icu_ChannelConfigType* channelConfigPtr)
{
    Std_ReturnType retVal = E_OK;
    uint8 i;
    uint32 clkMon;
    uint32 clkSet;
    uint16 filterLevel;
    uint32 dmaCtrl;
    uint32 pollTime = 0UL;
    uint32 pollUpd;
    uint32 fifoSta;
    uint32 fifoEntry;
#if (STD_ON == ICU_DMA_SUPPORT)
    uint32 chnWml;
#endif /* STD_ON == ICU_DMA_SUPPORT */
    if (NULL_PTR == channelConfigPtr)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        Icu_HwModule tmrModule = channelConfigPtr->icuHwChanCfgPtr->timerModule;
        Icu_HwChannel hwChannel = channelConfigPtr->icuHwChanCfgPtr->timerChannel;

        /* #10 set timer clock and predivider */
        if (FALSE == Icu_Ip_SetClkInfo[tmrModule])
        {
            /* update the clk varible */
            Icu_Ip_SetClkInfo[tmrModule] = TRUE;
            clkMon = ICU_BM_CLK_MON_EN_CMP_SET | ICU_BM_CLK_MON_EN_EN_N;
            /* disable clk mon first */
            REG_WRITE32(clkMon, ICU_CLK_MON_EN(tmrModule));
            /* set clock divider value */
            clkSet = ICU_FV_TIM_CLK_CONFIG_DIV_NUM(channelConfigPtr->icuHwChanCfgPtr->timerPrescaler);
            /* select the clock source */
            clkSet |= ICU_FV_TIM_CLK_CONFIG_SRC_CLK_SEL(channelConfigPtr->icuHwChanCfgPtr->timerClock);
            /* update the timer source information */
            clkSet |= ICU_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD;
            REG_WRITE32(clkSet, ICU_TIM_CLK_CONFIG(tmrModule));
            pollUpd = REG_READ32(ICU_TIM_CLK_CONFIG(tmrModule)) & ICU_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD;
            /* delay a while unitl setting be synced,need (2*etmr_clk+2*apb_clk) */
            while (pollUpd != 0U)
            {
                /* time out control */
                pollUpd = REG_READ32(ICU_TIM_CLK_CONFIG(tmrModule)) & ICU_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD;
                pollTime ++;
                if (pollTime > ICU_POLLING_TIME_OUT)
                {
                    retVal = E_NOT_OK;
                    Icu_Ip_SetClkInfo[tmrModule] = FALSE;
                    break;
                } /* else not needed */
            };
            /* restore the polling time */
            pollTime = 0UL;
            clkMon = ICU_BM_CLK_MON_EN_CMP_SET | ICU_BM_CLK_MON_EN_EN_P;
            /* enable clk mon */
            REG_WRITE32(clkMon, ICU_CLK_MON_EN(tmrModule));

        } /* else not needed*/
        /* #20 set counter register */
        /* set timer counter ovf value 0xffffffff */
        REG_WRITE32(0xFFFFFFFFU, ICU_LOCAL_CNT_OVF_VAL(tmrModule, hwChannel));
        /* update the overflow value flag (value: 1U) */
        REG_RMW32(ICU_LOCAL_CNT_CFG(tmrModule, hwChannel), ICU_CNT_CFG_OVF_UPD_START_BIT, 1U, 1U);

        /* delay a while unitl setting be synced,need (2*etmr_clk+2*apb_clk) */
        pollUpd =
            (REG_READ32(ICU_LOCAL_CNT_CFG(tmrModule, hwChannel)) &
            ((uint32)0x01U << ICU_CNT_CFG_OVF_UPD_START_BIT));
        while (pollUpd != 0U)
        {
            /* time out control */
            pollUpd =
                (REG_READ32(ICU_LOCAL_CNT_CFG(tmrModule, hwChannel)) &
                    ((uint32)0x01U << ICU_CNT_CFG_OVF_UPD_START_BIT));
            pollTime ++;
            if (pollTime > ICU_POLLING_TIME_OUT)
            {
                retVal = E_NOT_OK;
                break;
            } /* else not needed */
        }
        /* restore cnt setting */
        REG_RMW32(ICU_LOCAL_CNT_CFG(tmrModule, hwChannel), ICU_CNT_CFG_CPT0_CLR_EN_START_BIT, 1U, 0U);
        REG_RMW32(ICU_LOCAL_CNT_CFG(tmrModule, hwChannel), ICU_CNT_CFG_CPT1_CLR_EN_START_BIT, 1U, 0U);
        /* enable timer counter */
        REG_WRITE32(1, ICU_LOCAL_CNT_EN(tmrModule, hwChannel));
        /* restore the default mode in init phase */
        REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel), ICU_CPT_CONFIG_DUAL_MODE_BIT, 1U, 0U);
        /* Set the trigger edge */
        REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel), ICU_CPT_CONFIG_CPT0_TRIG_MODE_START_BIT, 2U,
                    channelConfigPtr->icuDefaultStartEdge);
        REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel), ICU_CPT_CONFIG_CPT1_TRIG_MODE_START_BIT, 2U,
                    ICU_RISING_EDGE);

        /* #20 set dma register */
        if (ICU_MODE_TIMESTAMP == channelConfigPtr->icuMeasurementMode)
        {
#if (STD_ON == ICU_DMA_SUPPORT)
            /* set etimer dma register information */
            /* set dma water mark mevel value */
            chnWml = REG_READ32(ICU_CHN_DMA_WML(tmrModule));
            chnWml &= ~ICU_FM_DMA_WML_CHN(hwChannel);
            chnWml |= ICU_FV_DMA_WML_CHN(ICU_RX_FIFO_WML, hwChannel);
            REG_WRITE32(chnWml, ICU_CHN_DMA_WML(tmrModule));
#endif /* STD_ON == ICU_DMA_SUPPORT */
            /* clear fifo value */
            fifoSta = REG_READ32(ICU_FIFO_STA(tmrModule));
            /* fifo entry offset (value: ((8U * (uint32)hwChannel) + 2U)), fifo entry max
                num (value: 0x1FU) */
            fifoEntry = ((fifoSta >> ((8U * (uint32)hwChannel) + 2U)) & 0x1FU);
            for (i = 0U; i < fifoEntry; i++)
            {
                REG_READ32(ICU_FIFO_ADDR32(tmrModule, hwChannel));
            }
            /* enable channel status check */
            REG_WRITE32(0xFFFFFFFFUL, ICU_COR_ERR_STA_ADDR32(tmrModule));
            REG_RMW32(ICU_COR_ERR_STA_EN_ADDR32(tmrModule), ICU_COR_ERR_STA_CHN_EN(hwChannel), 1U, 1U);
            /* Using FIFO if in time stamp mode or signal measurement mode*/
            dmaCtrl = REG_READ32(ICU_CHN_DMA_CTRL(tmrModule));
            /* enable the dma channel */
            dmaCtrl |= ICU_BM_CHN_DMA_CTRL_CHN_EN(hwChannel);
            /* set dma block as capture */
            dmaCtrl |= ICU_FV_CHN_DMA_CTRL_CHN_SEL(1, hwChannel);
            REG_WRITE32(dmaCtrl, ICU_CHN_DMA_CTRL(tmrModule));
        } /* else not needed */
        filterLevel = channelConfigPtr->icuFilterLevel;
        /* set channel filter level */
        retVal |= Icu_Ip_FilterConfig(filterLevel, tmrModule, hwChannel);
        /* set the local timer (value : 2U) as capture counter */
        REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel), ICU_CPT_CONFIG_CNT_SEL_START_BIT, 2U, 2U);
        /* set the capture config (value : 1U) */
        REG_RMW32(ICU_CPT_CTRL(tmrModule), ICU_CPT_CTRL_CONFIG_SET_START_BIT(hwChannel), 1U, 1U);
#if (STD_ON == ICU_GET_INPUTSTATE_API)
        /* set the initial input status */
        Icu_Ip_ChannelState[tmrModule][hwChannel] = ICU_IDLE;
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */
    }
    return retVal;
}

#if (STD_ON == ICU_DEINIT_API)
/** *****************************************************************************************************
 * \brief This function de-initializes the channel and set the etimer hardware
 *        registers
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_ChannelDeInit(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function de-initializes the channel and set the etimer
 *                      hardware registers
 * \endverbatim
 * Traceability       : SWSR_ICU_045 SWSR_ICU_046 SWSR_ICU_047
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_ChannelDeInit(const Icu_ChannelConfigType* channelConfigPtr)
{
    Std_ReturnType retVal = E_OK;
    uint32 pollUpd;
    uint32 pollTime = 0UL;
    uint32 dmaCtrl;
    boolean dmaSupport = FALSE;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
    if (NULL_PTR == channelConfigPtr)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        tmrModule = channelConfigPtr->icuHwChanCfgPtr->timerModule;
        hwChannel = channelConfigPtr->icuHwChanCfgPtr->timerChannel;
#if (STD_ON == ICU_DMA_SUPPORT)
        /* #10 free dma channel information */
        if ((ICU_MODE_TIMESTAMP == channelConfigPtr->icuMeasurementMode))
        {
            dmaSupport = TRUE;
            retVal = Icu_Ip_FreeDma(Icu_PhyToLogMap[tmrModule][hwChannel]);
        } /* else not needed */
#endif
        /* #20 turn off capture channel */
        retVal |= Icu_Ip_TurnOffCapture(tmrModule, hwChannel, dmaSupport);
        /* clean int sta */
        retVal |= Icu_Ip_ClearInterrupt(tmrModule, hwChannel);
        /* restore trigger edge */
        REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel), ICU_CPT_CONFIG_CPT0_TRIG_MODE_START_BIT, 2U, 0U);
        /* restore the counter select */
        REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel), ICU_CPT_CONFIG_CNT_SEL_START_BIT, 2U, 0U);
        /* #30 update capture config information */
        REG_RMW32(ICU_CPT_CTRL(tmrModule), ICU_CPT_CTRL_CONFIG_SET_START_BIT(hwChannel), 1U, 1U);
        if ((ICU_MODE_SIGNAL_MEASUREMENT == channelConfigPtr->icuMeasurementMode) ||
            (ICU_MODE_TIMESTAMP == channelConfigPtr->icuMeasurementMode))
        {
            /* disable channel status check */
            REG_WRITE32(0xFFFFFFFFUL, ICU_COR_ERR_STA_ADDR32(tmrModule));
            REG_RMW32(ICU_COR_ERR_STA_EN_ADDR32(tmrModule), ICU_COR_ERR_STA_CHN_EN(hwChannel), 1U, 0U);
            /* using FIFO if in time stamp mode or signal measurement mode*/
            dmaCtrl = REG_READ32(ICU_CHN_DMA_CTRL(tmrModule));
            /* disable the dma channel */
            dmaCtrl &= ~ICU_BM_CHN_DMA_CTRL_CHN_EN(hwChannel);
            /* restore dma block select */
            dmaCtrl &= ~ICU_FM_CHN_DMA_CTRL_CHN_SEL(hwChannel);
            REG_WRITE32(dmaCtrl, ICU_CHN_DMA_CTRL(tmrModule));
        } /* else not needed */
        /* #40 restore filter config information */
        REG_WRITE32(0x0, ICU_CPT_X0_FLT(tmrModule, hwChannel));
        /* restore varibles in sigmeasurement mode */
#if (STD_ON == ICU_GET_INPUTSTATE_API)
        Icu_Ip_ChannelState[tmrModule][hwChannel] = ICU_IDLE;
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */
#if (STD_ON == ICU_SIGNALMEASUREMENT_API)
        Icu_Ip_SiglDuraVal[tmrModule][hwChannel] = 0U;
#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
        Icu_Ip_PeriodTime[tmrModule][hwChannel] = 0U;
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */
#endif /* STD_ON == ICU_SIGNALMEASUREMENT_API */
        /* restore timer counter ovf value to 0 */
        REG_WRITE32(0U, ICU_LOCAL_CNT_OVF_VAL(tmrModule, hwChannel));
        /* update the overflow information */
        REG_RMW32(ICU_LOCAL_CNT_CFG(tmrModule, hwChannel), ICU_CNT_CFG_OVF_UPD_START_BIT, 1U, 1U);
        /* delay a while unitl setting be synced,need (2*etmr_clk+2*apb_clk) */
        pollUpd = REG_READ32(ICU_LOCAL_CNT_CFG(tmrModule,hwChannel)) &
                ((uint32)0x01U << ICU_CNT_CFG_OVF_UPD_START_BIT);
        while (pollUpd != 0U)
        {
            /* time out control */
            pollUpd = REG_READ32(ICU_LOCAL_CNT_CFG(tmrModule,hwChannel)) &
                    ((uint32)0x01U << ICU_CNT_CFG_OVF_UPD_START_BIT);
            pollTime ++;
            if (pollTime > ICU_POLLING_TIME_OUT)
            {
                retVal = E_NOT_OK;
                break;
            } /* else not needed */
        }
        /* disable timer counter */
        REG_WRITE32(0, ICU_LOCAL_CNT_EN(tmrModule, hwChannel));
        /* restore the clock set information */
        Icu_Ip_SetClkInfo[tmrModule] = FALSE;
    }
    return retVal;
}

#endif /* STD_ON == ICU_DEINIT_API */

/** *****************************************************************************************************
 * \brief This function sets the active edge information
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_SetActivationCondition(
 *                          const Icu_HwChannelConfigType*hwChannelConfigPtr,
 *                          Icu_ActivationType activation)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : hwChannelConfigPtr - pointer to hardware channel
 *                                           configuration
 *                      activation - activation edge information
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function sets the active edge information
 * \endverbatim
 * Traceability       : SWSR_ICU_055
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_SetActivationCondition(const Icu_HwChannelConfigType*hwChannelConfigPtr, Icu_ActivationType activation)
{
    Std_ReturnType retVal = E_OK;
    if (NULL_PTR == hwChannelConfigPtr)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        Icu_HwModule tmrModule = hwChannelConfigPtr->timerModule;
        Icu_HwChannel hwChannel = hwChannelConfigPtr->timerChannel;
        /* #10 set the activation edge information to etimer */
        REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel),
                ICU_CPT_CONFIG_CPT0_TRIG_MODE_START_BIT, 2U, activation);
        REG_RMW32(ICU_CPT_CTRL(tmrModule), ICU_CPT_CTRL_CONFIG_SET_START_BIT(hwChannel), 1U, 1U);
    }
    return retVal;
}

/** *****************************************************************************************************
 * \brief This function gets the interrupt status
 *
 * \verbatim
 * Syntax             : uint32 Icu_Ip_GetInterrupt(Icu_HwModule tmrModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The interrupt status
 *
 * Description        : This function gets the interrupt status
 * \endverbatim
 * Traceability       : SWSR_ICU_190
 *******************************************************************************************************/
uint32 Icu_Ip_GetInterrupt(Icu_HwModule tmrModule)
{
    /* #10 read the interrupt status */
    uint32 intStatus = REG_READ32(ICU_INT_STA_ADDR32(tmrModule));
    return intStatus;
}

/** *****************************************************************************************************
 * \brief This function clear the interrupt status
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_ClearInterrupt(
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function clear the interrupt status
 * \endverbatim
 * Traceability       : SWSR_ICU_190
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_ClearInterrupt(Icu_HwModule tmrModule, Icu_HwChannel hwChannel)
{
    Std_ReturnType retVal = E_OK;
    if ((TIMER_MODULE_NUMBER <= (uint8)tmrModule) || (LOCAL_CHANNEL_NUMBER <= (uint8)hwChannel) )
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /* #10 clear interrupt status */
        REG_WRITE32( 1UL << (uint32)hwChannel, ICU_INT_STA_ADDR32(tmrModule));
    }
    return retVal;

}

/** *****************************************************************************************************
 * \brief This function gets the fifo status
 *
 * \verbatim
 * Syntax             : boolean Icu_Ip_CheckFifoSta(
 *                              Icu_HwModule tmrModule,Icu_HwChannel hwChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The fifo status
 *
 * Description        : This function gets the fifo status
 * \endverbatim
 * Traceability       : SWSR_ICU_190
 *******************************************************************************************************/
boolean Icu_Ip_CheckFifoSta(Icu_HwModule tmrModule,Icu_HwChannel hwChannel)
{
    uint8 i;
    boolean errStatus = FALSE;
    uint32 fifoEntry;
    uint32 fifoCorErr = REG_READ32(ICU_COR_ERR_STA_ADDR32(tmrModule));
    uint32 fifoSta = REG_READ32(ICU_FIFO_STA(tmrModule));
    /* #10 fifo err status check */
    uint32 fifoErr = fifoCorErr & ICU_COR_ERR_STA_CHN_EN(hwChannel);
    /* fifo frror generate : clear fifo */
    fifoEntry = (fifoSta >> ((8U * (uint32)hwChannel) + 2U)) & 0x1FU;
    if (fifoErr > 0U)
    {
        /* #20 reset fifo */
        for (i = 0U; i < fifoEntry; i++)
        {
            REG_READ32(ICU_FIFO_ADDR32(tmrModule, hwChannel));
        }
        /* #30 clear fifo err status */
        REG_RMW32(ICU_COR_ERR_STA_ADDR32(tmrModule), ICU_COR_ERR_STA_CHN_EN(hwChannel), 1U, 1U);
        errStatus = TRUE;
    } /* else not needed */
    /* return fifo error status */
    return errStatus;
}

/** *****************************************************************************************************
 * \brief This function turn on the capture channel
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_TurnOnCapture(
 *                                  Icu_HwModule tmrModule,
 *                                  Icu_HwChannel hwChannel,
 *                                  boolean dmaSupport)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *                      dmaSupport - whether to use the dma mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function turn on the capture channel
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_TurnOnCapture(Icu_HwModule tmrModule, Icu_HwChannel hwChannel, boolean dmaSupport)
{
    Std_ReturnType retVal = E_OK;
    if ((TIMER_MODULE_NUMBER <= (uint8)tmrModule) || (LOCAL_CHANNEL_NUMBER <= (uint8)hwChannel) )
    {
        retVal = E_NOT_OK;
    }
    else
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_03();
        if (FALSE == dmaSupport)
        {
            /* #10 turn on capture interrupt signal */
            REG_RMW32(ICU_INT_STA_EN_ADDR32(tmrModule), (uint32)hwChannel, 1U, 1U);
            REG_RMW32(ICU_INT_SIG_EN_ADDR32(tmrModule), (uint32)hwChannel, 1U, 1U);
        } /* else not needed */
        /* #20 turn on capture channel */
        REG_RMW32(ICU_CPT_CTRL(tmrModule), ICU_CPT_CTRL_CPT_EN_START_BIT(hwChannel), 1U, 1U);
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_03();
    }
    return retVal;
}

/** *****************************************************************************************************
 * \brief This function turn off the capture channel
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_TurnOffCapture(
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel,
 *                              boolean dmaSupport)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *                      dmaSupport - whether to use the dma mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function turn off the capture channel
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_TurnOffCapture(Icu_HwModule tmrModule, Icu_HwChannel hwChannel, boolean dmaSupport)
{
    Std_ReturnType retVal = E_OK;
    uint32 fifoSta;
    uint32 fifoEntry;
    uint8 i;
    if ((TIMER_MODULE_NUMBER <= (uint8)tmrModule) || (LOCAL_CHANNEL_NUMBER <= (uint8)hwChannel) )
    {
        retVal = E_NOT_OK;
    }
    else
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_03();
        if (FALSE == dmaSupport)
        {
            /* #10 turn off capture interrupt */
            REG_RMW32(ICU_INT_STA_EN_ADDR32(tmrModule), (uint32)hwChannel, 1U, 0U);
            REG_RMW32(ICU_INT_SIG_EN_ADDR32(tmrModule), (uint32)hwChannel, 1U, 0U);
            /* #11 clear the interrupt status to avoid interrupt have already occured */
            REG_RMW32(ICU_INT_STA_ADDR32(tmrModule), (uint32)hwChannel, 1U, 1U);
        } /* else not needed */
        /* #20 turn off capture channel */
        REG_RMW32(ICU_CPT_CTRL(tmrModule), ICU_CPT_CTRL_CPT_EN_START_BIT(hwChannel), 1U, 0U);
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_03();
        fifoSta = REG_READ32(ICU_FIFO_STA(tmrModule));
        /* fifo entry offset (value: ((8U * (uint32)hwChannel) + 2U)), fifo entry max
            num (value: 0x1FU) */
        fifoEntry = (fifoSta >> ((8U * (uint32)hwChannel) + 2U)) & 0x1FU;
        for (i = 0U; i < fifoEntry; i++)
        {
            /* #30 clear fifo value */
            REG_READ32(ICU_FIFO_ADDR32(tmrModule, hwChannel));
        }
    }
    return retVal;
}

/** *****************************************************************************************************
 * \brief This function gets the fifo entry number
 *
 * \verbatim
 * Syntax             : uint8 Icu_Ip_GetFifoEntry(Icu_HwModule tmrModule,
 *                                                Icu_HwChannel hwChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The fifo entry number
 *
 * Description        : This function gets the fifo entry number
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
uint8 Icu_Ip_GetFifoEntry(Icu_HwModule tmrModule, Icu_HwChannel hwChannel)
{
    /* #10 get fifo status */
    uint32 fifoSta = REG_READ32(ICU_FIFO_STA(tmrModule));
    /* fifo entry offset (value: ((8U * (uint32)hwChannel) + 2U)), fifo entry max
        num (value: 0x1FU) */
    uint8 fifoEntry = (uint8)((fifoSta >> ((8U * (uint32)hwChannel) + 2U)) & 0x1FU);
    return fifoEntry;
}

/** *****************************************************************************************************
 * \brief This function gets the fifo value
 *
 * \verbatim
 * Syntax             : uint8 Icu_Ip_GetFifoEntry(Icu_HwModule tmrModule,
 *                                                Icu_HwChannel hwChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The fifo value
 *
 * Description        : This function gets the fifo value
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
uint32 Icu_Ip_GetFifoVal(Icu_HwModule tmrModule, Icu_HwChannel hwChannel)
{
    /* #10 get fifo value */
    uint32 fifoValue = REG_READ32(ICU_FIFO_ADDR32(tmrModule, hwChannel));
    return fifoValue;
}

#if (STD_ON == ICU_GET_INPUTSTATE_API)
/** *****************************************************************************************************
 * \brief This function gets input status
 *
 * \verbatim
 * Syntax             : Icu_InputStateType Icu_Ip_GetInputState(
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The input status in sigmeasurement mode
 *
 * Description        : This function gets input status
 * \endverbatim
 * Traceability       : SWSR_ICU_069 SWSR_ICU_071 SWSR_ICU_072 SWSR_ICU_073
 *******************************************************************************************************/
Icu_InputStateType Icu_Ip_GetInputState(Icu_HwModule tmrModule, Icu_HwChannel hwChannel)
{

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_01();
     Icu_InputStateType inputSta = Icu_Ip_ChannelState[tmrModule][hwChannel];
     /* #10 restore the input status */
    Icu_Ip_ChannelState[tmrModule][hwChannel] = ICU_IDLE;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_01();
    return inputSta;
}
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */

#if (STD_ON == ICU_SIGNALMEASUREMENT_API)
/** *****************************************************************************************************
 * \brief This function starts capture in signal measurement mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_StartSignalMeasurement(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function starts capture in signal measurement mode
 * \endverbatim
 * Traceability       : SWSR_ICU_153 SWSR_ICU_155
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_StartSignalMeasurement(const Icu_ChannelConfigType* channelConfigPtr)
{
    Std_ReturnType retVal;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
    Icu_SignalMeasurementPropertyType measureType;
    if (NULL_PTR == channelConfigPtr)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        tmrModule = channelConfigPtr->icuHwChanCfgPtr->timerModule;
        hwChannel = channelConfigPtr->icuHwChanCfgPtr->timerChannel;
        measureType = channelConfigPtr->measureParamPtr->sigMeasureProperty;
        /* #10 set the varibles to initial value */
        Icu_Ip_SiglDuraVal[tmrModule][hwChannel] = 0U;
#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
        Icu_Ip_ActiveTime[tmrModule][hwChannel] = 0U;
        Icu_Ip_PeriodTime[tmrModule][hwChannel] = 0U;
        Icu_Ip_HaveReadFlag[tmrModule][hwChannel] = TRUE;
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */
        /* #20 set capture module as dual mode (value: 1U) */
        REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel), ICU_CPT_CONFIG_DUAL_MODE_BIT, 1U, 1U);
        if (ICU_LOW_TIME == measureType)
        {
            /* set capture0 event activation edge as falling edge */
            REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel),
                        ICU_CPT_CONFIG_CPT0_TRIG_MODE_START_BIT, 2U, ICU_FALLING_EDGE);
            /* set capture1 event activation edge as rising edge */
            REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel),
                        ICU_CPT_CONFIG_CPT1_TRIG_MODE_START_BIT, 2U, ICU_RISING_EDGE);
            /* set capture0 event clear rhe counter value ,then capture1 timestamp
                values is low time value */
            REG_RMW32(ICU_LOCAL_CNT_CFG(tmrModule, hwChannel), ICU_CNT_CFG_CPT0_CLR_EN_START_BIT, 1U, 1U);
        }
        else if (ICU_HIGH_TIME == measureType)
        {
            /* set capture0 event activation edge as rising edge */
            REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel),
                        ICU_CPT_CONFIG_CPT0_TRIG_MODE_START_BIT, 2U, ICU_RISING_EDGE);
            /* set capture1 event activation edge as falling edge */
            REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel),
                        ICU_CPT_CONFIG_CPT1_TRIG_MODE_START_BIT, 2U, ICU_FALLING_EDGE);
            /* set capture0 event clear rhe counter value ,then capture0 timestamp
                values is high time value */
            REG_RMW32(ICU_LOCAL_CNT_CFG(tmrModule, hwChannel), ICU_CNT_CFG_CPT0_CLR_EN_START_BIT, 1U, 1U);
        }
        else
        {
            /* set capture0 event activation edge as falling edge */
            REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel),
                        ICU_CPT_CONFIG_CPT0_TRIG_MODE_START_BIT, 2U, ICU_FALLING_EDGE);
            /* set capture1 event activation edge as rising edge */
            REG_RMW32(ICU_CPT_CONFIG(tmrModule, hwChannel),
                        ICU_CPT_CONFIG_CPT1_TRIG_MODE_START_BIT, 2U, ICU_RISING_EDGE);
            /* set capture1 event clear rhe counter value ,then capture0 timestamp value
                is duty cycle value,capture1 timestamp values is period value */
            REG_RMW32(ICU_LOCAL_CNT_CFG(tmrModule, hwChannel), ICU_CNT_CFG_CPT1_CLR_EN_START_BIT, 1U, 1U);
        }
        REG_RMW32(ICU_CPT_CTRL(tmrModule), ICU_CPT_CTRL_CONFIG_SET_START_BIT(hwChannel), 1U, 1U);

        /* #30 begin to turn on the capture channel */
        retVal = Icu_Ip_TurnOnCapture(tmrModule, hwChannel, FALSE);
    }
    return retVal;
}


/** *****************************************************************************************************
 * \brief This function stops capture in signal measurement mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_StopSignalMeasurement(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function stops capture in signal measurement mode
 * \endverbatim
 * Traceability       : SWSR_ICU_161
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_StopSignalMeasurement(const Icu_ChannelConfigType* channelConfigPtr)
{
    Std_ReturnType retVal;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
    if (NULL_PTR == channelConfigPtr)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        tmrModule = channelConfigPtr->icuHwChanCfgPtr->timerModule;
        hwChannel = channelConfigPtr->icuHwChanCfgPtr->timerChannel;
        /* #10 turn off the capture channel */
        retVal = Icu_Ip_TurnOffCapture(tmrModule, hwChannel, FALSE);

        /* #10 restore the varibles in sigmeasurement mode */
        Icu_Ip_SiglDuraVal[tmrModule][hwChannel] = 0U;
#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
        Icu_Ip_ActiveTime[tmrModule][hwChannel] = 0U;
        Icu_Ip_PeriodTime[tmrModule][hwChannel] = 0U;
        Icu_Ip_HaveReadFlag[tmrModule][hwChannel] = TRUE;
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */
    }
    return retVal;
}

/** *****************************************************************************************************
 * \brief This function calculates the signal time in sigmeasurement mode
 *
 * \verbatim
 * Syntax             : void Icu_Ip_SigMeasurementIrq(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function calculates the signal time in
 *                      sigmeasurement mode
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Icu_Ip_SigMeasurementIrq(const Icu_ChannelConfigType* channelConfigPtr)
{
    /* capture0 value : high time value; capture1 value: period time */
    Icu_HwModule tmrModule = channelConfigPtr->icuHwChanCfgPtr->timerModule;
    Icu_HwChannel hwChannel = channelConfigPtr->icuHwChanCfgPtr->timerChannel;
#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
    Icu_SignalMeasurementPropertyType measureType =
                            channelConfigPtr->measureParamPtr->sigMeasureProperty;
    uint32 actTime;
    uint32 perTime;
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */
    /* #10 get the capture1 value */
    Icu_Ip_SiglDuraVal[tmrModule][hwChannel] =
                                        (uint32)REG_READ32(ICU_CPT1_CNT0_VALUE(tmrModule, hwChannel));
#if (STD_ON == ICU_GET_INPUTSTATE_API)
    Icu_Ip_ChannelState[tmrModule][hwChannel] = ICU_ACTIVE;
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */
#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
    if (ICU_DUTY_CYCLE == measureType)
    {
        actTime = (uint32)REG_READ32(ICU_CPT0_CNT0_VALUE(tmrModule, hwChannel));
        perTime = (uint32)REG_READ32(ICU_CPT1_CNT0_VALUE(tmrModule, hwChannel));
        /* #20 check duty cycle information validity */
        if (perTime > actTime)
        {
            /* store the duty cycle value */
            Icu_Ip_ActiveTime[tmrModule][hwChannel] = actTime;
            /* store the period value */
            Icu_Ip_PeriodTime[tmrModule][hwChannel] = perTime;
            /* the duty cycle information has been updated */
            Icu_Ip_HaveReadFlag[tmrModule][hwChannel] = FALSE;
        } /* else not needed */
    } /* else not needed */
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */
}

#if (STD_ON == ICU_GET_TIMEELAPSED_API)
/** *****************************************************************************************************
 * \brief This function gets signal time in signal measurement mode
 *
 * \verbatim
 * Syntax             : Icu_ValueType Icu_Ip_GetTimeElapsed(
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The signal time value
 *
 * Description        : This function gets signal time in signal measurement
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_168 SWSR_ICU_169 SWSR_ICU_170 SWSR_ICU_171
 *                      SWSR_ICU_172 SWSR_ICU_173
 *******************************************************************************************************/
Icu_ValueType Icu_Ip_GetTimeElapsed(Icu_HwModule tmrModule, Icu_HwChannel hwChannel)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_02();
    Icu_ValueType signalTime = Icu_Ip_SiglDuraVal[tmrModule][hwChannel];
    /* #10 restore the signal time value */
    Icu_Ip_SiglDuraVal[tmrModule][hwChannel] = 0UL;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_02();
    return signalTime;
}
#endif /* STD_ON == ICU_GET_TIMEELAPSED_API */

#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
/** *****************************************************************************************************
 * \brief This function gets dutycycle value in signal measurement mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_GetDutyCycle(
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel,
 *                              Icu_DutyCycleType* dutyCyclePtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      hwChannel - etimer hardware channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : dutyCyclePtr - pointer to a buffer where the results
 *
 * Return value       : The result status
 *
 * Description        : This function gets dutycycle value in signal measurement
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_180 SWSR_ICU_181 SWSR_ICU_182 SWSR_ICU_183
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_GetDutyCycle(Icu_HwModule tmrModule, Icu_HwChannel hwChannel, Icu_DutyCycleType* dutyCyclePtr)
{
    Std_ReturnType retVal = E_OK;
    if ((TIMER_MODULE_NUMBER <= (uint8)tmrModule) || (LOCAL_CHANNEL_NUMBER <= (uint8)hwChannel) )
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /* #10 critical section protection */
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00();
        /* #20 check the data has been read before */
        if (FALSE == Icu_Ip_HaveReadFlag[tmrModule][hwChannel])
        {
            dutyCyclePtr->ActiveTime = Icu_Ip_ActiveTime[tmrModule][hwChannel];
            dutyCyclePtr->PeriodTime = Icu_Ip_PeriodTime[tmrModule][hwChannel];
            /* #30 restore the read flag */
            Icu_Ip_HaveReadFlag[tmrModule][hwChannel] = TRUE;
        }
        else
        {
            dutyCyclePtr->ActiveTime = 0UL;
            dutyCyclePtr->PeriodTime = 0UL;
        }
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00();
    }
    return retVal;

}
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */
#endif /* STD_ON == ICU_SIGNALMEASUREMENT_API */

#if (STD_ON == ICU_DMA_SUPPORT)
/** *****************************************************************************************************
 * \brief This function setup dma channel information
 *
 * \verbatim
 * Syntax             : boolean Icu_Ip_SetupDma(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function setup dma channel information
 * \endverbatim
 * Traceability       : SWSR_ICU_205
 *******************************************************************************************************/
boolean Icu_Ip_SetupDma(const Icu_ChannelConfigType* channelConfigPtr)
{
    /* set the setup result */
    boolean dmaSetup = FALSE;
    boolean dmaRet;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
    uint8 logicChan;
    Dma_ChannelConfigType *chanRx;
    Dma_DeviceConfigType dmaConfig;
    Dma_InstanceConfigType dmaConfigChnTs;
    uint8  dmaConfigRet;
    uint8 dmaModuleId;
    if (NULL_PTR != channelConfigPtr)
    {
        /* #10 get the channel configuration information */
        tmrModule = channelConfigPtr->icuHwChanCfgPtr->timerModule;
        hwChannel = channelConfigPtr->icuHwChanCfgPtr->timerChannel;
        dmaModuleId = (uint8)tmrModule + (uint8)DMA_ICU_INDEX_ETIMER1;
        /* #20 set dma channel configuration */
        /* get the logic channel information */
        logicChan = Icu_PhyToLogMap[tmrModule][hwChannel];
        /* PRQA S 4342,4394  3 */
        dmaConfigRet = Dma_GetConfigParams((Dma_PeripheralIdType)dmaModuleId,
                                (Dma_SubIdType)((uint8)hwChannel + (uint8)DMA_ICU_CPT_A),
                                DMA_MODULE_ETIMER, &dmaConfigChnTs);
        if (E_OK == dmaConfigRet)
        {
            chanRx = Dma_RequestChannelWithId(dmaConfigChnTs.controller, dmaConfigChnTs.channelId);
            if (NULL_PTR != chanRx)
            {
                (void)Dma_InitConfigChannel(&dmaConfig);
                /* dma channel config result */
                /* PRQA S 0314  1 */
                Icu_Ip_ChanDmaPtr[logicChan] = (void *)chanRx;
                /* PRQA S 0311,0314  1 */
                chanRx->context = (void *)channelConfigPtr;
                chanRx->irqCallback = (Dma_IrqHandle)&Icu_DmaIrqHandler;
                dmaConfig.direction = DMA_DEVICE_TO_MEMORY;
                dmaConfig.flowControl = DMA_DIR_DEVICE_TO_MEMORY;
                /* src addr :fifo_address */
                dmaConfig.srcAddress = ICU_FIFO_ADDR32(tmrModule, hwChannel);
                /* PRQA S 0306  1 */
                dmaConfig.dstAddress = Mcal_AddressConvert((uint32)(&Icu_ChanRxBuffer[logicChan][0]));
                dmaConfig.srcBusWidth = DMA_BEAT_SIZE_4_BYTE;
                dmaConfig.dstBusWidth = DMA_BEAT_SIZE_4_BYTE;
                /* dma srcMaxBurst value = (fifo_wml - 1) */
                /* PRQA S 4342  2 */
                dmaConfig.srcMaxBurst = (Dma_BurstLengthType)(ICU_RX_FIFO_WML - 1U);
                dmaConfig.dstMaxBurst = (Dma_BurstLengthType)(ICU_RX_FIFO_WML - 1U);
                dmaConfig.periodLength = (uint32)ICU_RX_BURST_LEN * 0x4UL;
                dmaConfig.srcPortSelect = DMA_PORT_AHB32;
                dmaConfig.dstPortSelect = DMA_PORT_AXI64;
                dmaConfig.srcIncDirection = DMA_BURST_FIXED;
                dmaConfig.dstIncDirection = DMA_BURST_INCREMENTAL;
                dmaConfig.transaction = DMA_CYCLIC;
                dmaConfig.processMode = DMA_INTERRUPT;
                dmaConfig.linkListTriggerMode = DMA_TRIGGER_BY_HARDWARE;
                dmaConfig.loopMode = DMA_LOOP_MODE_1;
                (void)Dma_ConfigChannel(chanRx, &dmaConfig);
                dmaRet = Dma_PrepareTransmission(chanRx,
                                                ICU_RX_BURST_LEN * 0x4UL * 2U);
#if (STD_OFF == ICU_NON_CACHE_NEEDED)
                /* PRQA S 0306  1 */
                (void)Dma_InvalidateCache((uint32)(&Icu_ChanRxBuffer[logicChan][0]),
                                    ICU_RX_BURST_LEN * 0x4UL * 2U);
#endif /* STD_OFF == ICU_NON_CACHE_NEEDED */
                if (dmaRet == E_OK)
                {
                    (void)Dma_Start(chanRx);
                    dmaSetup = TRUE;
                } /* else not needed */
            } /* else not needed */
        } /* else not needed */
    } /* else not needed */
    return dmaSetup;
}

/** *****************************************************************************************************
 * \brief This function free dma channel information
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_FreeDma(uint8 logicChannel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : logicChannel - logic channel index
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function free dma channel information
 * \endverbatim
 * Traceability       : SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_FreeDma(uint8 logicChannel)
{
    Std_ReturnType retVal = E_OK;
    if (logicChannel >= NUM_OF_CHANNEL)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /* get dma channel information */
        /* PRQA S 0316  1 */
        Dma_ChannelConfigType *chanRx = (Dma_ChannelConfigType *)Icu_Ip_ChanDmaPtr[logicChannel];
        if (NULL_PTR != chanRx)
        {
            (void)Dma_Stop(chanRx);
            (void)Dma_ReleaseChannel(chanRx);
            Icu_Ip_ChanDmaPtr[logicChannel] = NULL_PTR;
        } /* else not needed */
    }
    return retVal;

}
#endif /* ICU_DMA_SUPPORT */

#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/** *****************************************************************************************************
 * \brief This function initilized icu channel in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptChannelInit(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function initilized icu channel in multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_034 SWSR_ICU_035 SWSR_ICU_037
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptChannelInit(const Icu_ChannelConfigType* channelConfigPtr)
{
    Std_ReturnType retVal = E_OK;
    uint32 pollUpd;
    uint32 pollTime = 0U;
    uint32 scrCfg;
    uint32 clkMon;
    uint32 clkSet;
    Icu_HwChannel chnbIndex = ICU_HW_CPT_B;
    Icu_HwChannel chncIndex = ICU_HW_CPT_C;
    Icu_HwModule tmrModule;
    if (NULL_PTR == channelConfigPtr)
    {
        retVal = E_NOT_OK;
    }
    else if (MULTI_CPT_MODULE_NUM <= (uint8)channelConfigPtr->icuHwChanCfgPtr->timerModule)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        tmrModule = channelConfigPtr->icuHwChanCfgPtr->timerModule;
        /* #10 set timer clock and predivider */
        if (FALSE == Icu_Ip_SetClkInfo[tmrModule])
        {
            Icu_Ip_SetClkInfo[tmrModule] = TRUE;
            /* disable clock monitor first */
            clkMon = ICU_BM_CLK_MON_EN_CMP_SET | ICU_BM_CLK_MON_EN_EN_N;
            REG_WRITE32(clkMon, ICU_CLK_MON_EN(tmrModule));
            /* set clk info */
            clkSet = ICU_FV_TIM_CLK_CONFIG_DIV_NUM(channelConfigPtr->icuHwChanCfgPtr->timerPrescaler);
            /* multi cpt must select same clk source with xtrg */
            clkSet |= ICU_FV_TIM_CLK_CONFIG_SRC_CLK_SEL(ICU_SEL_AHF_CLK);
            clkSet |= ICU_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD;
            REG_WRITE32(clkSet, ICU_TIM_CLK_CONFIG(tmrModule));
            /* delay a while unitl setting be synced,need (2*etmr_clk+2*apb_clk) */
            pollUpd = REG_READ32(ICU_TIM_CLK_CONFIG(tmrModule)) & ICU_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD;
            while (pollUpd != 0U)
            {
                pollUpd = REG_READ32(ICU_TIM_CLK_CONFIG(tmrModule)) & ICU_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD;
                pollTime++;
                if (pollTime > ICU_POLLING_TIME_OUT)
                {
                    Icu_Ip_SetClkInfo[tmrModule] = FALSE;
                    retVal = E_NOT_OK;
                    break;
                } /* else not needed */
            };
            pollTime = 0U;
            /* enable clock monitor */
            clkMon = ICU_BM_CLK_MON_EN_CMP_SET | ICU_BM_CLK_MON_EN_EN_P;
            REG_WRITE32(clkMon, ICU_CLK_MON_EN(tmrModule));
        } /* else not needed */

#ifndef SEMIDRIVE_E3_LITE_SERIES
        /* #20 set scr multi cpt mux enable */
        scrCfg = REG_READ32(APBMUX_SCR_SF_BASE + ICU_MULTI_ETMR_SCR_CFG_ADDR(tmrModule));
        /* bit1 : mux cpt en */
        scrCfg |= 0x2U;
        REG_WRITE32(scrCfg, APBMUX_SCR_SF_BASE + ICU_MULTI_ETMR_SCR_CFG_ADDR(tmrModule));
#else
        /* set scr multi cpt mux enable */
        scrCfg = REG_READ32(APBMUX_SCR_SF_BASE + ICU_MULTI_ETMR_SCR_CFG_ADDR);
        scrCfg |= (0x1 << tmrModule);
        REG_WRITE32(scrCfg, APBMUX_SCR_SF_BASE + ICU_MULTI_ETMR_SCR_CFG_ADDR);
#endif

#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
        /* #30 setup multi cpt dma channel config */
        retVal |= Icu_Ip_MultiCptSetupDma(channelConfigPtr);
        /* set etimer dma reg */
        Icu_Ip_MultiCptDmaRegConfig(tmrModule, FALSE);
#else /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */
        Icu_Ip_MultiCptDmaRegConfig(tmrModule, TRUE);
#endif /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */

        /* #40 set etimer sse reg */
        Icu_Ip_MultiCptSseConfig(tmrModule);
        /* set initial edge type information */
        Icu_Ip_MultiCptEdgeTypeSet(channelConfigPtr);
        /* set local counter c ovf value 0xffffffff */
        REG_WRITE32(0xFFFFFFFFUL, ICU_LOCAL_CNT_OVF_VAL(tmrModule, 2));
        REG_RMW32(ICU_LOCAL_CNT_CFG(tmrModule, 2), ICU_CNT_CFG_OVF_UPD_START_BIT, 1U, 1U);

        /* delay a while unitl setting be synced,need (2*etmr_clk+2*apb_clk) */
        pollUpd = REG_READ32(ICU_LOCAL_CNT_CFG(tmrModule, chncIndex)) &
                ((uint32)0x1U << ICU_CNT_CFG_OVF_UPD_START_BIT);
        while (pollUpd != 0U)
        {
            /* time out comntrol */
            pollUpd = REG_READ32(ICU_LOCAL_CNT_CFG(tmrModule, chncIndex)) &
                        ((uint32)0x1U << ICU_CNT_CFG_OVF_UPD_START_BIT);
            pollTime ++;
            if (pollTime > ICU_POLLING_TIME_OUT)
            {
                retVal |= E_NOT_OK;
                break;
            } /* else not needed */
        }
        /* enable timer local counter c */
        REG_WRITE32(1, ICU_LOCAL_CNT_EN(tmrModule, chncIndex));

        /* #50 set cpt config */
        /* Set the cpt b triggered edge : for multi cpt , 3 means multi cpt level mode */
        REG_RMW32(ICU_CPT_CONFIG(tmrModule, chnbIndex), ICU_CPT_CONFIG_CPT0_TRIG_MODE_START_BIT, 2U, 3U);
        /* set the local timer as cpt b counter */
        REG_RMW32(ICU_CPT_CONFIG(tmrModule, chnbIndex), ICU_CPT_CONFIG_CNT_SEL_START_BIT, 2U, 2U);
        REG_RMW32(ICU_CPT_CTRL(tmrModule), ICU_CPT_CTRL_CONFIG_SET_START_BIT(chnbIndex), 1U, 1U);
        /* Set the cpt c triggered edge : for multi cpt , 3 means multi cpt level mode */
        REG_RMW32(ICU_CPT_CONFIG(tmrModule, chncIndex), ICU_CPT_CONFIG_CPT0_TRIG_MODE_START_BIT, 2U, 3U);
        /* set the local timer as cpt c counter */
        REG_RMW32(ICU_CPT_CONFIG(tmrModule, chncIndex), ICU_CPT_CONFIG_CNT_SEL_START_BIT, 2U, 2U);
        REG_RMW32(ICU_CPT_CTRL(tmrModule), ICU_CPT_CTRL_CONFIG_SET_START_BIT(chncIndex), 1U, 1U);
    }
    return retVal;

}

#if (STD_ON == ICU_DEINIT_API)
/** *****************************************************************************************************
 * \brief This function de-initilized icu channel in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptChannelDeInit(
 *                              const Icu_ChannelConfigType* channelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : channelConfigPtr - pointer to icu channel configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function de-initilized icu channel in multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_034 SWSR_ICU_035 SWSR_ICU_037
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptChannelDeInit(const Icu_ChannelConfigType* channelConfigPtr)
{
    Std_ReturnType retVal;
    uint32 scrCfg;
    uint32 dmaCtrl;
    uint32 sseCtrl;
    Icu_HwChannel chnbIndex = ICU_HW_CPT_B;
    Icu_HwChannel chncIndex = ICU_HW_CPT_C;
    Icu_HwModule tmrModule;
#if (STD_ON == ICU_SIGNALMEASUREMENT_API)
    uint8 i;
#endif /* STD_ON == ICU_SIGNALMEASUREMENT_API */
    if (NULL_PTR == channelConfigPtr)
    {
        retVal = E_NOT_OK;
    }
    else if (MULTI_CPT_MODULE_NUM <= (uint8)channelConfigPtr->icuHwChanCfgPtr->timerModule)
    {
        retVal = E_NOT_OK;
    }
    else
    {

        tmrModule = channelConfigPtr->icuHwChanCfgPtr->timerModule;
#ifndef SEMIDRIVE_E3_LITE_SERIES
        /* #10 disable set scr multi cpt mux */
        scrCfg =
        REG_READ32(APBMUX_SCR_SF_BASE + ICU_MULTI_ETMR_SCR_CFG_ADDR(tmrModule));
        /* bit1 : mux cpt en */
        scrCfg &= ~((uint32)0x2UL);
        REG_WRITE32(scrCfg, APBMUX_SCR_SF_BASE + ICU_MULTI_ETMR_SCR_CFG_ADDR(tmrModule));
#else
        /* #20 disable set scr multi cpt mux */
        scrCfg =
        REG_READ32(APBMUX_SCR_SF_BASE + ICU_MULTI_ETMR_SCR_CFG_ADDR);
        scrCfg &= ~(0x1 << tmrModule);
        REG_WRITE32(scrCfg, APBMUX_SCR_SF_BASE + ICU_MULTI_ETMR_SCR_CFG_ADDR);
#endif

#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
        /* #30 setup multi cpt dma config */
        Icu_Ip_MultiCptFreeDma(tmrModule);
#endif /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */
        /* #40 select the dma block */
        dmaCtrl = REG_READ32(ICU_CHN_DMA_CTRL(tmrModule));
        /* disable dma channel b */
        dmaCtrl &= ~ICU_BM_CHN_DMA_CTRL_CHN_EN(chnbIndex);
        /* disable dma channel c */
        dmaCtrl &= ~ICU_BM_CHN_DMA_CTRL_CHN_EN(chncIndex);
        REG_WRITE32(dmaCtrl, ICU_CHN_DMA_CTRL(tmrModule));

        /* disable sse b */
        sseCtrl = REG_READ32(ICU_CPT_SSE_CTRL_OFF(tmrModule, chnbIndex));
        sseCtrl &= ~ICU_BM_CPT_SSE_CTRL_SSE_EN;
        REG_WRITE32(sseCtrl, ICU_CPT_SSE_REG_OFF(tmrModule, chnbIndex));
        /* disable sse c */
        sseCtrl = REG_READ32(ICU_CPT_SSE_CTRL_OFF(tmrModule, chncIndex));
        sseCtrl &= ~ICU_BM_CPT_SSE_CTRL_SSE_EN;
        REG_WRITE32(sseCtrl, ICU_CPT_SSE_REG_OFF(tmrModule, chncIndex));

        /* #50 turn off capture module */
#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
        retVal = Icu_Ip_MultiCptTurnOffCapture(tmrModule, FALSE);
#else /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */
        retVal = Icu_Ip_MultiCptTurnOffCapture(tmrModule, TRUE);
#endif /* ICU_MULTI_CAPTURE_DMA_MODE */
        /* clean cpt_c int sta */
        retVal |= Icu_Ip_ClearInterrupt(tmrModule, chncIndex);
        /* disable timer local counter c */
        REG_WRITE32(0, ICU_LOCAL_CNT_EN(tmrModule, chncIndex));

#if (STD_ON == ICU_SIGNALMEASUREMENT_API)
        /* restore varibles in multi capture mode */
        for (i = 0U; i < MULTI_CPT_MAX_IO_NUM; i++)
        {
            Icu_Ip_MulSiglDuraVal[tmrModule][i] = 0U;
            Icu_Ip_MulSigDutyOver[tmrModule][i] = FALSE;
            Icu_Ip_MulHighSigTime[tmrModule][i] = 0U;
#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
            Icu_Ip_MulHaveReadFlag[tmrModule][i] = TRUE;
            Icu_Ip_MulPeriodTime[tmrModule][i] = 0U;
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */
        }
#endif /* STD_ON == ICU_SIGNALMEASUREMENT_API */
        /* restore clock set information */
        Icu_Ip_SetClkInfo[tmrModule] = FALSE;
    }
    return retVal;

}
#endif /* STD_ON == ICU_DEINIT_API */

/** *****************************************************************************************************
 * \brief This function turns on etimer capture in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptTurnOnCapture(
 *                                      Icu_HwModule tmrModule, boolean intMode)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      intMode - check if etimer uses interrupt mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function turns on etimer capture in multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptTurnOnCapture(Icu_HwModule tmrModule, boolean intMode)
{
    Std_ReturnType retVal = E_OK;
    uint32 multiCptEn;
    if (MULTI_CPT_MODULE_NUM <= (uint8)tmrModule)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        if (TRUE == intMode)
        {
            /* #10 turn on channel C capture interrupt */
            REG_RMW32(ICU_INT_STA_EN_ADDR32(tmrModule), 2U, 1U, 1U);
            REG_RMW32(ICU_INT_SIG_EN_ADDR32(tmrModule), 2U, 1U, 1U);
        } /* else not needed */
        /* bit1-cpt b en bit2-cpt c en */
        multiCptEn = REG_READ32(ICU_CPT_CTRL(tmrModule));
        multiCptEn |= 0x6UL;
        /* #20 enable capture channel */
        REG_WRITE32(multiCptEn, ICU_CPT_CTRL(tmrModule));
    }
    return retVal;
}

/** *****************************************************************************************************
 * \brief This function turns off etimer capture in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptTurnOffCapture(
 *                                      Icu_HwModule tmrModule, boolean intMode)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      intMode - check if etimer uses interrupt mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function turns off etimer capture in multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptTurnOffCapture(Icu_HwModule tmrModule, boolean intMode)
{
    Std_ReturnType retVal = E_OK;
    uint8 i;
    uint32 fifoSta;
    uint32 fifoEntry;
    Icu_HwChannel chnbIndex = ICU_HW_CPT_B;
    Icu_HwChannel chncIndex = ICU_HW_CPT_C;
    /* bit1 -cpt b en bit2 - cpt c en */
    uint32 multiCptEn;
    if (MULTI_CPT_MODULE_NUM <= (uint8)tmrModule)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        multiCptEn = 0UL;
        multiCptEn &= ~((uint32)0x6UL);
        /* #10 disable capture channel */
        REG_WRITE32(multiCptEn, ICU_CPT_CTRL(tmrModule));
        if (TRUE == intMode)
        {
            /* turn off channel C Capture interrupt */
            REG_RMW32(ICU_INT_STA_EN_ADDR32(tmrModule), 2U, 1U, 0U);
            REG_RMW32(ICU_INT_SIG_EN_ADDR32(tmrModule), 2U, 1U, 0U);
        } /* else not needed */
        /* #20 clear fifo */
        fifoSta = REG_READ32(ICU_FIFO_STA(tmrModule));
        fifoEntry = (fifoSta >> ((8U * (uint32)chnbIndex) + 2U)) & 0x1FU;
        /* clear fifo b */
        for (i = 0U; i < fifoEntry; i++)
        {
            REG_READ32(ICU_FIFO_ADDR32(tmrModule, chnbIndex));
        }
        fifoEntry = (fifoSta >> ((8U * (uint32)chncIndex) + 2U)) & 0x1FU;
        /* clear fifo c */
        for (i = 0U; i < fifoEntry; i++)
        {
            REG_READ32(ICU_FIFO_ADDR32(tmrModule, chncIndex));
        }
    }
    return retVal;
}

#if (STD_ON == ICU_SIGNALMEASUREMENT_API)
/** *****************************************************************************************************
 * \brief This function starts capture signal time in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptStartSignalMeasurement(
 *                                        Icu_HwModule tmrModule, uint8 ioChan)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      ioChan - sub channel index in multi capture mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function starts capture signal time in multi
 *                      capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_153 SWSR_ICU_155
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptStartSignalMeasurement(Icu_HwModule tmrModule, uint8 ioChan)
{
    Std_ReturnType retVal = E_OK;
    if (MULTI_CPT_MODULE_NUM <= (uint8)tmrModule)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /* #10 set initial varibles in multi capture mode */
        Icu_Ip_MulSiglDuraVal[tmrModule][ioChan] = 0U;
        Icu_Ip_MulSigDutyOver[tmrModule][ioChan] = FALSE;
        Icu_Ip_MulHighSigTime[tmrModule][ioChan] = 0U;
#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
        Icu_Ip_MulPeriodTime[tmrModule][ioChan] = 0U;
        Icu_Ip_MulHaveReadFlag[tmrModule][ioChan] = TRUE;
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */
    }
    return retVal;
}

/** *****************************************************************************************************
 * \brief This function starts capture signal time in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptStopSignalMeasurement(
 *                                        Icu_HwModule tmrModule, uint8 ioChan)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      ioChan - sub channel index in multi capture mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : This function starts capture signal time in multi
 *                      capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_161
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptStopSignalMeasurement(Icu_HwModule tmrModule, uint8 ioChan)
{
    Std_ReturnType retVal = E_OK;
    if (MULTI_CPT_MODULE_NUM <= (uint8)tmrModule)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /* #10 restore varibles in multi capture mode */
        Icu_Ip_MulSiglDuraVal[tmrModule][ioChan] = 0U;
        Icu_Ip_MulSigDutyOver[tmrModule][ioChan] = FALSE;
        Icu_Ip_MulHighSigTime[tmrModule][ioChan] = 0U;
#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
        Icu_Ip_MulPeriodTime[tmrModule][ioChan] = 0U;
        Icu_Ip_MulHaveReadFlag[tmrModule][ioChan] = TRUE;
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */
    }
    return retVal;
}

/** *****************************************************************************************************
 * \brief This function calculates the signal time in multi capture mode
 *
 * \verbatim
 * Syntax             : boolean Icu_Ip_MultiCptSigMeasurementIrq(
 *                             Icu_HwModule tmrModule, uint8 ioChan,
 *                             Icu_SignalMeasurementPropertyType sigMeasureType,
 *                             Icu_MultiCptEdgeChangeType edgeChange,
 *                              uint32 timeSpend)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      ioChan - sub channel index in multi capture mode
 *                      sigMeasureType - sub mode of sigmeasurement mode
 *                      edgeChange - edge change type
 *                      timeSpend - time information of the level last
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The calculate result
 *
 * Description        : This function calculates the signal time in multi
 *                      capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_206
 *******************************************************************************************************/
boolean Icu_Ip_MultiCptSigMeasurementIrq(Icu_HwModule tmrModule, uint8 ioChan, Icu_SignalMeasurementPropertyType sigMeasureType, Icu_MultiCptEdgeChangeType edgeChange, uint32 timeSpend)
{
    boolean calcResult = FALSE;
    switch (sigMeasureType)
    {
    case ICU_LOW_TIME:
        if (edgeChange == ICU_MULTI_CPT_RISING_EDGE)
        {
            /* #10 update the signal time value */
            Icu_Ip_MulSiglDuraVal[tmrModule][ioChan] = timeSpend;
            calcResult = TRUE;
        } /* else not needed */
        break;

    case ICU_HIGH_TIME:
        if (edgeChange == ICU_MULTI_CPT_FALLING_EDGE)
        {
            /* #20 update the high level time value */
            Icu_Ip_MulHighSigTime[tmrModule][ioChan] = timeSpend;
            /* update the signal time value */
            Icu_Ip_MulSiglDuraVal[tmrModule][ioChan] = timeSpend;
            calcResult = TRUE;
        } /* else not needed */
        break;

    case ICU_PERIOD_TIME:
        if (edgeChange == ICU_MULTI_CPT_FALLING_EDGE)
        {
            Icu_Ip_MulSigDutyOver[tmrModule][ioChan] = TRUE;
            /* #30 update the high level time value */
            Icu_Ip_MulHighSigTime[tmrModule][ioChan] = timeSpend;
        }
        else
        {
            if (TRUE == Icu_Ip_MulSigDutyOver[tmrModule][ioChan])
            {
                /* #40 update the signal time value */
                Icu_Ip_MulSiglDuraVal[tmrModule][ioChan] =
                    Icu_Ip_MulHighSigTime[tmrModule][ioChan] + timeSpend;
                Icu_Ip_MulSigDutyOver[tmrModule][ioChan] = FALSE;
                calcResult = TRUE;
            } /* else not needed */
        }
        break;

    case ICU_DUTY_CYCLE:
        if (edgeChange == ICU_MULTI_CPT_FALLING_EDGE)
        {
            Icu_Ip_MulSigDutyOver[tmrModule][ioChan] = TRUE;
            /* #50 update the high level time value */
            Icu_Ip_MulHighSigTime[tmrModule][ioChan] = timeSpend;
        }
        else
        {
            if (TRUE == Icu_Ip_MulSigDutyOver[tmrModule][ioChan])
            {
                /* #60 update the period time value */
                Icu_Ip_MulPeriodTime[tmrModule][ioChan] =
                    Icu_Ip_MulHighSigTime[tmrModule][ioChan] + timeSpend;
                Icu_Ip_MulSigDutyOver[tmrModule][ioChan] = FALSE;
                Icu_Ip_MulHaveReadFlag[tmrModule][ioChan] = FALSE;
                calcResult = TRUE;
            } /* else not needed */
        }
        break;

    default:
        {
            /* do nothing */
            break;
        }
    }
    return calcResult;
}

#if (STD_ON == ICU_GET_TIMEELAPSED_API)
/** *****************************************************************************************************
 * \brief This function gets signal time in multi capture mode
 *
 * \verbatim
 * Syntax             : Icu_ValueType  Icu_Ip_MultiCptGetTimeElapsed(
 *                                      Icu_HwModule tmrModule, uint8 ioChan)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      ioChan - sub channel index in multi capture mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The signal time value
 *
 * Description        : This function gets signal time in multi capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_168 SWSR_ICU_169 SWSR_ICU_170 SWSR_ICU_171
 *                      SWSR_ICU_172 SWSR_ICU_173
 *******************************************************************************************************/
Icu_ValueType  Icu_Ip_MultiCptGetTimeElapsed(Icu_HwModule tmrModule, uint8 ioChan)
{
    Icu_ValueType timeElapse;
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_02();
    /* #10 get signal time */
    timeElapse = Icu_Ip_MulSiglDuraVal[tmrModule][ioChan];
    /* restore signal time varible */
    Icu_Ip_MulSiglDuraVal[tmrModule][ioChan] = 0UL;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_02();
    return timeElapse;
}
#endif /* STD_ON == ICU_GET_TIMEELAPSED_API */

#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
/** *****************************************************************************************************
 * \brief This function gets dutycycle value in multi capture mode
 *
 * \verbatim
 * Syntax             : Std_ReturnType Icu_Ip_MultiCptGetDutyCycle(
 *                                      Icu_HwModule tmrModule, uint8 ioChan,
 *                                      Icu_DutyCycleType* dutyCyclePtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module
 *                      ioChan - sub channel index in multi capture mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : dutyCyclePtr - pointer to duty cycle information buffer
 *
 * Return value       : The setting result
 *
 * Description        : This function gets dutycycle value in in multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_180 SWSR_ICU_181 SWSR_ICU_182 SWSR_ICU_183
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Icu_Ip_MultiCptGetDutyCycle(Icu_HwModule tmrModule, uint8 ioChan, Icu_DutyCycleType* dutyCyclePtr)
{
    Std_ReturnType retVal = E_OK;
    if (MULTI_CPT_MODULE_NUM <= (uint8)tmrModule)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /* #10 critical section protection */
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00();
        /* #20 check the value has been read before */
        if (FALSE == Icu_Ip_MulHaveReadFlag[tmrModule][ioChan])
        {
            dutyCyclePtr->ActiveTime = Icu_Ip_MulHighSigTime[tmrModule][ioChan];
            dutyCyclePtr->PeriodTime = Icu_Ip_MulPeriodTime[tmrModule][ioChan];
            Icu_Ip_MulHaveReadFlag[tmrModule][ioChan] = TRUE;
        }
        else
        {
            dutyCyclePtr->ActiveTime = 0U;
            dutyCyclePtr->PeriodTime = 0U;
        }
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00();
    }
    return retVal;
}
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */
#endif /*STD_ON == ICU_SIGNALMEASUREMENT_API */
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */

/* memap infomation */
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
