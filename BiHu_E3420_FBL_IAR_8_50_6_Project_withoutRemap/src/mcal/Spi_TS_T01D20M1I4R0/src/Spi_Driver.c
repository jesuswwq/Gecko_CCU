/*
 * SEMIDRIVE Copyright Statement
 * Copyright (c) SEMIDRIVE. All rights reserved
 *
 * This software and all rights therein are owned by SEMIDRIVE, and are
 * protected by copyright law and other relevant laws, regulations and
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,
 * please do not use this software or any potion thereof in any form or by any
 * means. You may not reproduce, modify or distribute this software except in
 * compliance with the License. Unless required by applicable law or agreed to
 * in writing, software distributed under the License is distributed on
 * an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * You should have received a copy of the License along with this program.
 * If not, see <http://www.semidrive.com/licenses/>.
 */

/**
 * @file  Spi_Driver.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Spi plugins.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dma.h"
#include "Dio.h"
#include "irq.h"
#include "Spi.h"
#include "irq_num.h"
#include "Spi_reg.h"
#include "Spi_Irq.h"
#include "SchM_Spi.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

#ifdef SPI_ENABLE_DMA
extern dma_dev_t dma_sf0[CPU_ID_MAX];
#endif

#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

VAR( struct Spi_Driver_Handler, SPI_VAR) SpiHandler[SPI_CFG_CORES];

#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

/*******************************************************************************
**                    Static Function Definitions                             **
*******************************************************************************/
#define SPI_START_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

static const uint32 Spi_BaseAddr[SPI_TOTAL_HW_COUNT] = {
    APB_SPI1_BASE,
    APB_SPI2_BASE,
    APB_SPI3_BASE,
    APB_SPI4_BASE,
    APB_SPI5_BASE,
    APB_SPI6_BASE,
#ifdef SEMIDRIVE_E3_SERIES
    APB_SPI7_BASE,
    APB_SPI8_BASE
#endif
};

static const uint32 Spi_IrqNum[SPI_TOTAL_HW_COUNT] = {
    SPI1_SPI_INTR_NUM,
    SPI2_SPI_INTR_NUM,
    SPI3_SPI_INTR_NUM,
    SPI4_SPI_INTR_NUM,
    SPI5_SPI_INTR_NUM,
    SPI6_SPI_INTR_NUM,
#ifdef SEMIDRIVE_E3_SERIES
    SPI7_SPI_INTR_NUM,
    SPI8_SPI_INTR_NUM
#endif
};

#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

static inline const Spi_HwUnitConfigType *Get_JobHwUnitConfig(uint8 HwUnitId)
{
    for (uint8 Idx = 0; Idx < SPI_TOTAL_HW_COUNT; Idx++) {
        /* spi HW units init */
        if (HwUnitId == Spi_HwUnitConfig[Idx].HwUnit) {
            return &Spi_HwUnitConfig[Idx];
        }
    }

    return NULL_PTR;
}
#if (SPI_ENABLE_SLAVE == STD_ON)
static sint8 Get_SlaveModeConfigDeviceIdx(uint8 HwUnitId)
{
    const Spi_JobCfgType *PtrJobCfg = Spi_JobConfig;

    for (uint8 JobIdx = 0; JobIdx < SPI_TOTAL_JOB_COUNT; JobIdx++) {
        /* spi HW units init */
        if (HwUnitId == PtrJobCfg[JobIdx].HWUnit) {
            if (PtrJobCfg[JobIdx].DeviceIdx < SPI_TOTAL_DEV_COUNT) {
                return PtrJobCfg[JobIdx].DeviceIdx;
            }
        }
    }

    return -1;
}
#endif
/****************************************************************************************
* Service Name : Spi_BusPrivInit
* Syntax       : static void Spi_BusPrivInit(uint8 BusIdx)
* description  : Init Bus Priv Data init.
*****************************************************************************************/
static void Spi_BusPrivInit(uint8 BusIdx)
{
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];

    PerCoreHandler->SpiBus[BusIdx].Bus_Priv.idle = 0x4;
    PerCoreHandler->SpiBus[BusIdx].Bus_Priv.timeout = 0x4;
    PerCoreHandler->SpiBus[BusIdx].Bus_Priv.slave_nss_p = 0x0;
    PerCoreHandler->SpiBus[BusIdx].Bus_Priv.flags = 0;
#if (SPI_ENABLE_SLAVE == STD_ON || SPI_ENABLE_DMA == STD_ON)
    /* BusIdx is not config order */
    const Spi_HwUnitConfigType *HwUnitConfigPtr =  Get_JobHwUnitConfig(BusIdx);
#endif
#if (SPI_ENABLE_SLAVE == STD_ON)

    /* Slave Mode */
    if (HwUnitConfigPtr != NULL_PTR && HwUnitConfigPtr->HwMode == SPI_SLAVE) {
        PerCoreHandler->SpiBus[BusIdx].Bus_Priv.flags |= SPI_MODE_SLAVE_ENABLE;
    }

#endif
#if (SPI_ENABLE_DMA == STD_ON)

    if (HwUnitConfigPtr != NULL_PTR && HwUnitConfigPtr->HwDMA == TRUE) {
        PerCoreHandler->SpiBus[BusIdx].Bus_Priv.dma = &dma_sf0[Mcu_GetCoreID()];
        PerCoreHandler->SpiBus[BusIdx].Bus_Priv.flags |= SPI_DMA_TX_ENABLE | SPI_DMA_RX_ENABLE;
    } else {
        PerCoreHandler->SpiBus[BusIdx].Bus_Priv.dma = 0;
        PerCoreHandler->SpiBus[BusIdx].Bus_Priv.flags &= (uint32)(~SPI_DMA_TX_ENABLE | SPI_DMA_RX_ENABLE);
    }

#endif
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_1)
    PerCoreHandler->SpiBus[BusIdx].Bus_Priv.flags |= SPI_TX_IRQ_ENABLE | SPI_RX_IRQ_ENABLE |
            SPI_SLV_IRQ_ENABLE;
#endif
    PerCoreHandler->SpiBus[BusIdx].Bus_Priv.dma_ch_rx = NULL_PTR;
    PerCoreHandler->SpiBus[BusIdx].Bus_Priv.dma_ch_tx = NULL_PTR;
    PerCoreHandler->SpiBus[BusIdx].Bus_Priv.dma_err = 0;
}
/****************************************************************************************
* Service Name : Spi_DevicePrivInit
* Syntax       : static void Spi_DevicePrivInit(uint8 DevIdx,const Spi_JobCfgType *JobType)
* description  : Init Device Priv Data init.
*****************************************************************************************/
static void Spi_DevicePrivInit(uint8 DevIdx, const Spi_JobCfgType *JobType)
{
    Spi_clock_mode mode;
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    const  Spi_HwUnitConfigType *HwUnitConfigPtr =  &Spi_HwUnitConfig[JobType->HwUnitIdxCfg];

    /* update clock phase and polarity */
    if (JobType->ShiftClk == HIGH) {
        /* CPOL = 1*/
        if (JobType->ShiftEdge == TRAILING) {
            /* CPOA = 0 mode = 2*/
            mode = SCPO1_SCPH0;
        } else {
            /* CPOA = 1 mode = 3*/
            mode = SCPO1_SCPH1;
        }
    } else {
        /* CPOL = 0 */
        if (JobType->ShiftEdge == TRAILING) {
            /* CPOA = 0 mode = 0*/
            mode = SCPO0_SCPH0;
        } else {
            /* CPOA = 1 mode = 1*/
            mode = SCPO0_SCPH1;
        }
    }

    PerCoreHandler->SpiDevice[DevIdx].Device_Priv.mode = (enum spi_tim_mode)(mode & 0x03);

    /* Slave always highest precision, If HwUnit has no corresponding configuration item, it defaults to Master mode */
    if (HwUnitConfigPtr && HwUnitConfigPtr->HwMode == SPI_SLAVE)
        PerCoreHandler->SpiDevice[DevIdx].Device_Priv.baud_div = 0;
    else
        PerCoreHandler->SpiDevice[DevIdx].Device_Priv.baud_div = JobType->BaudRate;

    PerCoreHandler->SpiDevice[DevIdx].Device_Priv.nss_idx  = JobType->CSPin;
    PerCoreHandler->SpiDevice[DevIdx].Device_Priv.width = JobType->DataWidth;
    PerCoreHandler->SpiDevice[DevIdx].Device_Priv.tim_ctrl = FV_SPI_TIM_CTRL_START_DLY(
                JobType->TimeClkCs);
    PerCoreHandler->SpiDevice[DevIdx].Device_Priv.tim_ctrl |= FV_SPI_TIM_CTRL_END_DLY(
                JobType->TimeClkCsEnd);

    if (JobType->BitOrder == LSB)
        PerCoreHandler->SpiDevice[DevIdx].Device_Priv.flags |= F_DEV_LSB;
    else
        PerCoreHandler->SpiDevice[DevIdx].Device_Priv.flags &= (uint32)(~F_DEV_LSB);

    if (JobType->CSPolarity == HIGH)
        PerCoreHandler->SpiDevice[DevIdx].Device_Priv.flags |= F_DEV_NSS_HIGH;
    else
        PerCoreHandler->SpiDevice[DevIdx].Device_Priv.flags &= (uint32)(~F_DEV_NSS_HIGH);

    if (JobType->SampleDelay) {
        PerCoreHandler->SpiDevice[DevIdx].Device_Priv.flags |= F_DEV_MISO_DELAY;
    } else {
        PerCoreHandler->SpiDevice[DevIdx].Device_Priv.flags &= (uint32)(~F_DEV_MISO_DELAY);
    }

    /* Vio cs cmd will select cs0 as cs */
    if (JobType->CSHandling == CS_VIA_GPIO) {
        PerCoreHandler->SpiDevice[DevIdx].Device_Priv.nss_idx = 0;
        PerCoreHandler->SpiDevice[DevIdx].Device_Priv.flags |= F_DEV_NSS_SOFT;
    } else {
        PerCoreHandler->SpiDevice[DevIdx].Device_Priv.flags &= (uint32)(~F_DEV_NSS_SOFT);
    }

}
/****************************************************************************************
* Service Name : Spi_SchedulerInit
* Syntax       : static void Spi_SchedulerInit(void)
* description  : Init The Sequnce Scheduler
*****************************************************************************************/
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#ifdef SPI_DEBUG_LOG
void Show_SeqNode(struct Spi_SeqNode *Node)
{
    SPI_DBG("---------------------------------------------------------\n");
    SPI_DBG("seq @%p sid:%d Pri:%d Int:%d N:%p P:%p Cur:%p ,CurJId:%d\n",
            Node, Node->SeqId, Node->Priorty, Node->Interruptable,
            GetSeqNode(Node->Node.Next), GetSeqNode(Node->Node.Prev), Node->CurJob, Node->CurJob->JobId
           );
    SPI_DBG("---------------------------------------------------------\n");
}

void Show_AllSeqNode(void)
{
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    struct Spi_SeqNode *SeqNode = PerCoreHandler->SeqNode;

    for (uint16 Seqid = 0; Seqid < SPI_TOTAL_SEQ_COUNT; Seqid++) {
        Show_SeqNode(&SeqNode[Seqid]);
    }
}

void Show_scheduler(struct Spi_Scheduler *Sche)
{
    struct Spi_SeqNode *Node;
    struct Spi_list *ListNode;
    SPI_DBG("Sche Sta:%d Next:%p Prev:%p HwMask:%02x pendc:%d\n",
            Sche->State,
            GetSeqNode(Sche->SeqQueue.Next),
            GetSeqNode(Sche->SeqQueue.Prev),
            Sche->HwStatusMask,
            Sche->PendingSeqCnt
           );

    ListNode = Sche->SeqQueue.Next;

    for (uint8 i = 0; i < SPI_TOTAL_HW_COUNT; i++)
        SPI_DBG("Hw %d: %p \n", i, Sche->JobCurr[i]);

    while (ListNode && ListNode != &Sche->SeqQueue) {
        Node = GetSeqNode(ListNode);
        Show_SeqNode(Node);
        ListNode = Node->Node.Next;
    }
}

void Show_JobNode(void)
{
    struct Spi_JobNode *JNode;
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    struct Spi_JobNode *JobNode = PerCoreHandler->JobNode;

    for (uint16 nodeid = 0; nodeid < SPI_MAX_JOB; nodeid++) {
        JNode = &JobNode[nodeid];
        SPI_DBG("%d:%d @%p ", JNode->SeqId, JNode->JobId, JNode);

        if (JNode->Node.Next) {
            SPI_DBG("N-->%p \n", GetJobNode(JNode->Node.Next));
        } else {
            SPI_DBG("\n");
        }
    }
}

void Show_Channel(void)
{
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    struct mld_spi_async *SpiChannelCB = PerCoreHandler->SpiChannelCB;

    for (uint16 Ch = 0; Ch < SPI_TOTAL_CH_COUNT; Ch++) {
        SPI_DBG("C:%p N %p\n", &SpiChannelCB[Ch], SpiChannelCB[Ch].next);
        (void)SpiChannelCB;
    }
}
#endif
static struct Spi_list *GetNextJobNode(const Spi_SequenceCfgType *Sequence, \
                                       uint16 SeqJobIndex)
{
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    uint16 JobIdNext = SeqJobIndex + 1;

    if (Sequence->NoOfJobs <= JobIdNext)
        return NULL;

    JobIdNext = Sequence->JobList[JobIdNext];
    return &PerCoreHandler->JobNode[JobIdNext].Node;
}
#endif
/****************************************************************************************
* Service Name : Spi_SchedulerInit
* Syntax       : static void Spi_SchedulerInit(void)
* description  : Init The Sequnce Scheduler
*****************************************************************************************/
static void Spi_SchedulerInit(void)
{
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    struct mld_spi_async *SpiChannelCB = PerCoreHandler->SpiChannelCB;
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
     (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
    struct Spi_SeqNode  *SeqNode = PerCoreHandler->SeqNode;
    struct Spi_JobNode  *JobNode = PerCoreHandler->JobNode;
#endif
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
     (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) || \
     (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON))
    struct Spi_Scheduler *Sche = &PerCoreHandler->Scheduler;
#endif
    const Spi_JobCfgType *PtrJobCfg = Spi_JobConfig;
    const Spi_SequenceCfgType *PtrSequenceCfg = Spi_SequenceConfig;

    for (Spi_SequenceType i = 0; i < SPI_TOTAL_SEQ_COUNT; i++) {
        /* */
        for (uint16 JobIndex = 0 ; JobIndex < PtrSequenceCfg[i].NoOfJobs; JobIndex++) {
            uint16 JobId = PtrSequenceCfg[i].JobList[JobIndex];
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
            JobNode[JobId].Node.Next = GetNextJobNode(&PtrSequenceCfg[i], JobIndex);
            JobNode[JobId].SeqId = i;
            JobNode[JobId].JobId = JobId;
            JobNode[JobId].IsActive = 0;
#endif
            /* Job Channel cnt */
            uint16 JobChannelsCnt = PtrJobCfg[JobId].NoOfChannels;

            for (uint8  Channel = 0; Channel < JobChannelsCnt; Channel++) {
                uint8 ChannelId = PtrJobCfg[JobId].ChannelList[Channel];
                uint8 ChannelIdNext = PtrJobCfg[JobId].ChannelList[Channel + 1];
                SpiChannelCB[ChannelId].next = &SpiChannelCB[ChannelIdNext];
            }

            SpiChannelCB[PtrJobCfg[JobId].ChannelList[JobChannelsCnt - 1]].next = NULL;
        }

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
        SeqNode[i].JobQueue.Next = &JobNode[PtrSequenceCfg[i].JobList[0]].Node;
        SeqNode[i].JobQueue.Prev = NULL;
        SeqNode[i].Node.Next = NULL;
        SeqNode[i].Node.Prev = NULL;
        SeqNode[i].SeqId = i;
        SeqNode[i].CurJob = NULL;
        /* seq priority depends on the highest priority of all jobs*/
        SeqNode[i].Priorty = PtrJobCfg[PtrSequenceCfg[i].JobList[0]].SpiJobPriority;
        SeqNode[i].Interruptable = PtrSequenceCfg[i].InterruptableSequence;
#endif
    }

    /*SyncTransmit parallel */
    PerCoreHandler->SpiSyncSeqActiveCnt = 0;

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))

    for (uint8 i = 0; i < SPI_TOTAL_HW_COUNT; i++) {
        Sche->JobCurr[i] = NULL;
    }

    Sche->State = ASYNC_SCHE_IDLE;
    Sche->SeqQueue.Next = NULL;
    Sche->SeqQueue.Prev = NULL;
    Sche->HwStatusMask = Spi_InstanceMask_Config[CoreId];
    Sche->PendingSeqCnt = 0;
    Sche->ActiveJobCnt = 0;
#if ( SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
    Sche->SchedulerMode = SPI_POLLING_MODE;
#elif ( SPI_LEVEL_DELIVERED == SPI_LEVEL_1)
    Sche->SchedulerMode = SPI_INTERRUPT_MODE;
#endif
#ifdef SPI_DEBUG_LOG
    Show_JobNode();
    Show_AllSeqNode();
    Show_scheduler(Sche);
    Show_Channel();
#endif
#elif (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
    Sche->HwStatusMask = Spi_InstanceMask_Config[CoreId];
#endif
}
#if ( SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || ( SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
static void Spi_Sche_Main(void);

static sint8 AsyncTransmit_EB_Check(Spi_SequenceType Sequence)
{
    Spi_ChannelType ChannelId;
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    Spi_ChannelStateType *SpiChannelState = PerCoreHandler->Spi_SpiChannelState;

    const Spi_JobCfgType *PtrJobConfig = NULL_PTR;
    const Spi_SequenceCfgType *PtrSeqConfig = &Spi_SequenceConfig[Sequence];

    for (Spi_JobType i = 0; i < PtrSeqConfig->NoOfJobs; i++) {
        PtrJobConfig = &Spi_JobConfig[PtrSeqConfig->JobList[i]];

        for (Spi_ChannelType ch = 0; ch < PtrJobConfig->NoOfChannels; ch++) {
            ChannelId = PtrJobConfig->ChannelList[ch];

            if (Spi_ChannelConfig[ChannelId].ChannelBufferType == EB && \
                SpiChannelState[ChannelId].Tx_Tag == BUFF_INVALID) {
                /* IB Not write */
                return -1;
            } else if (Spi_ChannelConfig[ChannelId].ChannelBufferType == IB) {
                SpiChannelState[ChannelId].Rx_Tag = DATA_INVALID;
                SPI_DBG("Ch %d RX Buff Invalid\n", ChannelId);
            }
        }
    }

    return 0;
}
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
/****************************************************************************************
* Service Name : GetInsertSeqNode
* Syntax       : static struct Spi_SeqNode *TempSeqNode GetInsertSeqNode
                (struct Spi_Scheduler * Sche,struct Spi_SeqNode * New)
* description  : get new seq insert point.
*****************************************************************************************/
static struct Spi_SeqNode *GetInsertSeqNode(struct Spi_Scheduler *Sche, struct Spi_SeqNode *New)
{
    struct Spi_SeqNode *TempSeqNode = NULL_PTR;
    struct Spi_list   *Node = &Sche->SeqQueue;

    while (Node->Prev != &Sche->SeqQueue && Node->Prev != NULL_PTR) {
        /*PRQA S 2810 2*/
        TempSeqNode = GetSeqNode(Node->Prev);

        if (Spi_SequenceConfig[TempSeqNode->SeqId].SeqHwMask &
            Spi_SequenceConfig[New->SeqId].SeqHwMask) {
            /* The new Seq and the current Seq share the same HwUnit*/
            if (TempSeqNode->Interruptable && TempSeqNode->Priorty < New->Priorty ) {
                /* The current Seq can be interrupted and the priority is lower than the new Seq*/
                return TempSeqNode;
            }
        }

        Node = Node->Prev;
    }

    return NULL_PTR;
}
#endif
/****************************************************************************************
* Service Name : Spi_ScheOneSequence
* Syntax       : static void Spi_ScheOneSequence(Spi_SequenceType SequenceId)
* description  : Service to send the Sequence data
*****************************************************************************************/
static Std_ReturnType Spi_ScheOneSequence(Spi_SequenceType SequenceId)
{
    Std_ReturnType ret = E_OK;
    struct Spi_SeqNode *InsertSeqNode;
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    struct Spi_Scheduler *Sche = &PerCoreHandler->Scheduler;
    struct Spi_SeqNode *SeqNode = PerCoreHandler->SeqNode;
    const Spi_SequenceCfgType *PtrSeqConfig = &Spi_SequenceConfig[SequenceId];

    /* Make sure EB Buff was Setuped,and clr olb IB Buff status */
    if (AsyncTransmit_EB_Check(SequenceId) != 0) {
        ret = E_NOT_OK;
    }

    if ((PtrSeqConfig->SeqHwMask & Spi_InstanceMask_Config[CoreId]) != PtrSeqConfig->SeqHwMask) {
        ret = E_NOT_OK;
    }

    if (ret == E_OK) {
        if (Sche->PendingSeqCnt == 0) {
            Sche->SeqQueue.Next = &SeqNode[SequenceId].Node;
            SeqNode[SequenceId].Node.Prev =  &Sche->SeqQueue;
            SeqNode[SequenceId].Node.Next = &Sche->SeqQueue;
            Sche->SeqQueue.Prev = Sche->SeqQueue.Next;
            Sche->PendingSeqCnt++;
        } else {
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
            /*
                Find the insertion point,if the return is NULL Insert To Tail.
            */
            InsertSeqNode = GetInsertSeqNode(Sche, &SeqNode[SequenceId]);

            if (InsertSeqNode != NULL_PTR) {
                /* interupt curr seq */
                SeqNode[SequenceId].Node.Next = &InsertSeqNode->Node;
                SeqNode[SequenceId].Node.Prev = InsertSeqNode->Node.Prev;
                InsertSeqNode->Node.Prev->Next = &SeqNode[SequenceId].Node;
                InsertSeqNode->Node.Prev = &SeqNode[SequenceId].Node;
                Sche->PendingSeqCnt++;
                SPI_DBG("Insert Seq %d to Seq prev.\n", SequenceId, InsertSeqNode->SeqId);
            } else {
#endif
                /* add to tail */
                /* SeqQueue.prev point to last Seq queue item */
                /* set the taill seq  next to new seq */
                Sche->SeqQueue.Prev->Next = &SeqNode[SequenceId].Node;
                /* new seq link to old tail */
                SeqNode[SequenceId].Node.Prev = Sche->SeqQueue.Prev;
                /* new seq loop to sche node  */
                SeqNode[SequenceId].Node.Next = &Sche->SeqQueue;
                /* update the tail ptr */
                Sche->SeqQueue.Prev =  &SeqNode[SequenceId].Node;
                /* Tail update to current seq item */
                Sche->PendingSeqCnt++;
                SPI_DBG("Add Seq %d to queue Tail.\n", SequenceId);
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
            }

#endif
        }

        SeqNode[SequenceId].SeqInQueue = TRUE;
#ifdef SPI_DEBUG_LOG
        Show_scheduler(Sche);
#endif
    }

    return ret;
}
/****************************************************************************************
* Service Name : Spi_ScheOneJob
* Syntax       : static uint32 Spi_ScheOneJob(Spi_JobType JobId)
* description  : Service to send One Job in LSB first
*****************************************************************************************/
static Std_ReturnType Spi_StartScheJob(struct Spi_JobNode *JobNode)
{
    uint32  Length;
    uint16  ChannelId;
    sint32   mld_ret = -1;
    Spi_DataBufferType *pCurrentTxBuffer;
    Spi_DataBufferType *pCurrentRxBuffer;
    Std_ReturnType ret = E_OK;
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    const Spi_JobCfgType *PtrJobCfg = &Spi_JobConfig[JobNode->JobId];
    const Spi_ChannelCfgType *PtrChannelConfig;
    struct mld_spi_device *dev = &PerCoreHandler->SpiDevice[PtrJobCfg->DeviceIdx].Device;
#if (SPI_ENABLE_SLAVE == STD_ON)
    struct mld_spi_module *bus = &PerCoreHandler->SpiBus[PtrJobCfg->HWUnit].Bus;
#endif
    /* HwUnitConfigPtr == NULL is not possibility */
    const Spi_HwUnitConfigType *HwUnitConfigPtr =  &Spi_HwUnitConfig[PtrJobCfg->HwUnitIdxCfg];

    for (uint16 Channel = 0; Channel < PtrJobCfg->NoOfChannels; Channel++) {
        ChannelId = PtrJobCfg->ChannelList[Channel];
        PtrChannelConfig = &(Spi_ChannelConfig[ChannelId]);

        if (PtrChannelConfig->ChannelBufferType == IB) {
            pCurrentRxBuffer = (Spi_DataBufferType *)PtrChannelConfig->ReadBufferIndex;
            pCurrentTxBuffer = (Spi_DataBufferType *)PtrChannelConfig->WriteBufferIndex;
            Length = PtrChannelConfig->BufferSize;
        } else {
            pCurrentRxBuffer = (Spi_DataBufferType *)PerCoreHandler->ExtBuff[ChannelId].DesDataBufferPtr;
            pCurrentTxBuffer = (Spi_DataBufferType *)PerCoreHandler->ExtBuff[ChannelId].SrcDataBufferPtr;
            Length = PerCoreHandler->ExtBuff[ChannelId].Length;
        }

        PerCoreHandler->SpiChannelCB[ChannelId].len = Length;
        PerCoreHandler->SpiChannelCB[ChannelId].ptxdata.val = (uint32)pCurrentTxBuffer;

        if ( PtrChannelConfig->DataWidth < 0x9u )
            PerCoreHandler->SpiChannelCB[ChannelId].width_type = SPI_DATA_WIDTH_BYTE;
        else if (PtrChannelConfig->DataWidth < 0x11U)
            PerCoreHandler->SpiChannelCB[ChannelId].width_type = SPI_DATA_WIDTH_HALF_WORD;
        else
            PerCoreHandler->SpiChannelCB[ChannelId].width_type = SPI_DATA_WIDTH_WORD;

        if (PtrJobCfg->EnableRx == TRUE)
            PerCoreHandler->SpiChannelCB[ChannelId].prxdata.val = (uint32)pCurrentRxBuffer;
        else
            PerCoreHandler->SpiChannelCB[ChannelId].prxdata.val = 0;
    }

    ChannelId = PtrJobCfg->ChannelList[0];

    if (HwUnitConfigPtr->HwMode == SPI_MASTER ) {
        if (PtrJobCfg->CSHandling == CS_VIA_GPIO) {
            if (PtrJobCfg->CSFunc == TRUE) {
                /* set pad as GPIO ,to avoid Chip Selecting Multiple Slaves*/
                Port_SetPinMode((Port_PinType)PtrJobCfg->PortPinId, MUX_0);
            }

            mld_set_soft_cs_id(dev->bus, PtrJobCfg->GPIOCsPin);
        }
    }

    /* transmit */
    if (HwUnitConfigPtr->HwMode == SPI_MASTER) {
        if (HwUnitConfigPtr->HwDMA == TRUE) {
            SPI_DBG("J:%d Job Start to process DMA mode\n", JobNode->JobId);
            mld_ret = mld_spi_vector_transmit_receive_dma(dev->bus, dev,
                      &PerCoreHandler->SpiChannelCB[ChannelId]);
        } else {
            SPI_DBG("J:%d Job Start to process IRQ mode\n", JobNode->JobId);
            mld_ret = mld_spi_vector_transmit_receive_irq(dev->bus, dev,
                      &PerCoreHandler->SpiChannelCB[ChannelId]);
        }
    }

#if (SPI_ENABLE_SLAVE == STD_ON)
    else {
        if (HwUnitConfigPtr->HwDMA == TRUE) {
            mld_ret = mld_spi_vector_transmit_receive_dma(bus, NULL_PTR,
                      &PerCoreHandler->SpiChannelCB[ChannelId]);
            SPI_DBG("J:%d Job Start to process Slave DMA\n", JobNode->JobId);
        } else {
            mld_ret = mld_spi_vector_transmit_receive_irq(bus, NULL_PTR,
                      &PerCoreHandler->SpiChannelCB[ChannelId]);
            SPI_DBG("J:%d Job Start to process Slave IRQ\n", JobNode->JobId);
        }
    }

#endif

    if (mld_ret < 0) {
        SPI_DBG("Oops:%s %d %p %p %d\n", __FUNCTION__, __LINE__, dev->bus, dev, ChannelId);
        ret = E_NOT_OK;
    }

    return ret;
}
#if (SPI_CANCEL_API == STD_ON && SPI_ENABLE_SLAVE == STD_ON)
void Spi_SlaveSeqCancel(Spi_SequenceType SeqId)
{
    uint8 CoreId = Spi_GetCoreID(), HwUnitId;
    const  Spi_JobCfgType *JobCfg = Spi_JobConfig;
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    struct Spi_Scheduler *Sche = &PerCoreHandler->Scheduler;
    struct Spi_SeqNode *SeqItem = &PerCoreHandler->SeqNode[SeqId];
    const  Spi_SequenceCfgType *SequenceCfg = Spi_SequenceConfig;

    if (PerCoreHandler->SeqResult[SeqItem->SeqId] == SPI_SEQ_PENDING) {
        /*
            cancel seq remove all jobs of Seq from queue.
        */
        if (SeqItem->SeqInQueue) {
            SeqItem->Node.Next->Prev = SeqItem->Node.Prev;
            SeqItem->Node.Prev->Next = SeqItem->Node.Next;
            SeqItem->SeqInQueue = FALSE;
            Sche->PendingSeqCnt--;
        }

        if (SeqItem->CurJob && SeqItem->CurJob->IsActive) {
            SeqItem->CurJob->IsActive = 0;
            Sche->ActiveJobCnt--;
            HwUnitId = JobCfg[SeqItem->CurJob->JobId].HWUnit;
            mld_spi_stop(&PerCoreHandler->SpiBus[HwUnitId].Bus);
            Sche->JobCurr[HwUnitId] = NULL_PTR;
            SeqItem->CurJob = NULL_PTR;

            if (0 == Sche->ActiveJobCnt)
                PerCoreHandler->Spi_HandlerAsyncStatus = SPI_IDLE;
        }

        PerCoreHandler->SeqResult[SeqItem->SeqId] = SPI_SEQ_CANCELLED;
        /* free controller */
        Sche->HwStatusMask |= SequenceCfg[SeqId].SeqHwMask;
    }
}
#endif
/****************************************************************************************
* Service Name : Spi_Sche_Main
* Syntax       : static void Spi_Sche_Main(void)
* description  : Called When One Job Finish.This function will be called by interrupted and
                 non-interrupted parts of the code, need to critical section protection
*****************************************************************************************/
static void Spi_Sche_Main(void)
{
    uint8 HwUnitId;
    struct Spi_SeqNode *SeqItem;
    struct Spi_list  *QueueNode;
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    struct Spi_Scheduler *Sche = &PerCoreHandler->Scheduler;
    const Spi_JobCfgType *PtrJobCfg = Spi_JobConfig;

    /* scheduler is ready to  process */
    if (Sche->State  !=  ASYNC_SCHE_UNINIT ) {
        /*
            HwStatusMask may never be 0 in multi-core,at this time, depending on Sche->PendingSeqCnt > 0
            and Next does not point to the queue head, that is, the queue is not empty, the Job under Seq
            will be processed.
            when has unprocessed seq or has Controller is idle or linked list is empty.Some risk points
            here are that when the queue is very large, it will cause the interrupt masking time to be too long.
        */
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
        QueueNode = Sche->SeqQueue.Next;

        while (Sche->PendingSeqCnt && Sche->HwStatusMask &&
               QueueNode != &Sche->SeqQueue && QueueNode) {
            /*PRQA S 2810 2*/
            SeqItem = GetSeqNode(QueueNode);
#if (SPI_CANCEL_API == STD_ON)

            if (PerCoreHandler->SeqCancel[SeqItem->SeqId] == TRUE) {
                /*
                    cancel seq remove all jobs of Seq from queue.
                    Seq Canceled ,other job not execute ,state keek queued
                */
                if (SeqItem->SeqInQueue) {
                    SeqItem->Node.Next->Prev = SeqItem->Node.Prev;
                    SeqItem->Node.Prev->Next = SeqItem->Node.Next;
                    SeqItem->SeqInQueue = FALSE;
                    Sche->PendingSeqCnt--;
                }

                if (SeqItem->CurJob) {
                    SeqItem->CurJob->IsActive = 0;
                    SeqItem->CurJob = NULL_PTR;
                }

                PerCoreHandler->SeqResult[SeqItem->SeqId] = SPI_SEQ_CANCELLED;
                PerCoreHandler->SeqCancel[SeqItem->SeqId] = FALSE;
                SPI_DBG("S:%d Seq Canceled.\n", SeqItem->SeqId);
            } else
#endif
            {
                SPI_DBG("The Seq@%p Id:%d CJ:%p\n", SeqItem, SeqItem->SeqId, SeqItem->CurJob);

                /* seq is not start scheduled */
                if (SeqItem->CurJob == NULL) {
                    /* Get first Job to do */
                    if (SeqItem->JobQueue.Next) {
                        /*PRQA S 2810 2*/
                        SeqItem->CurJob = GetJobNode(SeqItem->JobQueue.Next);
                    } else {
                        /* Seq not have Job remove  Seq form Seq Queue */
                        QueueNode->Prev->Next = QueueNode->Next;
                        QueueNode->Next->Prev = QueueNode->Prev;
                        SeqItem->SeqInQueue = FALSE;
                        Sche->PendingSeqCnt--;
                        SPI_DBG("None Job in the Seq.\n");
                    }
                } else {
                    /* Has been updated by the Job handler to the next Job */
                }

                /*
                    if run L:680 the SeqItem->CurJob == NULL
                */
                if (SeqItem->CurJob != NULL_PTR) {
                    /* Get Hwidex cached it  */
                    HwUnitId = PtrJobCfg[SeqItem->CurJob->JobId].HWUnit;

                    /*
                        SeqItem->CurJob->IsActive Job Busy.
                        Spi_GetHWStatus(HwUnitId) Sync HwUint Busy.
                        Sche->HwStatusMask Async HwUnit Busy.
                    */
                    if ((SeqItem->CurJob->IsActive == FALSE) && \
                        (Spi_GetHWStatus(HwUnitId) == SPI_IDLE) && \
                        (Sche->HwStatusMask & (0x01 << HwUnitId))) {
                        /*
                            This part of the code needs to be placed here when
                        critical protection is not added. After adding critical protection,
                        it can be moved to the branch of Job OK..
                        */
                        if (Spi_StartScheJob(SeqItem->CurJob) != E_OK) {
                            /*
                                Start Exception;Remove all Seq Jobs from queue
                            */
                            SeqItem->Node.Next->Prev = SeqItem->Node.Prev;
                            SeqItem->Node.Prev->Next = SeqItem->Node.Next;
                            SeqItem->SeqInQueue = FALSE;
                            Sche->PendingSeqCnt--;
                            Sche->JobCurr[HwUnitId] = NULL_PTR;
                            Sche->HwStatusMask |= 0x01 << HwUnitId;
                            SeqItem->CurJob->IsActive = 0;

                            PerCoreHandler->SeqResult[SeqItem->CurJob->SeqId] = SPI_SEQ_FAILED;
                            PerCoreHandler->JobResult[SeqItem->CurJob->JobId] = SPI_JOB_FAILED;

                            for (Spi_ChannelType ch = 0; ch < PtrJobCfg[SeqItem->CurJob->JobId].NoOfChannels; ch++) {
                                Spi_ChannelType ChannelId = PtrJobCfg[SeqItem->CurJob->JobId].ChannelList[ch];

                                if (Spi_ChannelConfig[ChannelId].ChannelBufferType == EB) {
                                    PerCoreHandler->Spi_SpiChannelState[ChannelId].Tx_Tag = BUFF_INVALID;
                                    SPI_DBG("Ch %d TX Buff Invalid\n", ChannelId);
                                }
                            }

                            SPI_DBG("S:%d J:%d Job Start Fail\n", SeqItem->CurJob->SeqId, SeqItem->CurJob->JobId);
                            SeqItem->CurJob = NULL_PTR;
                        } else {
                            /* Start Job Pass */
                            Sche->JobCurr[HwUnitId] = SeqItem->CurJob;
                            Sche->HwStatusMask &= (uint32)(~(0x01 << HwUnitId));
                            SeqItem->CurJob->IsActive = 1;
                            Sche->ActiveJobCnt++;
                            PerCoreHandler->Spi_HandlerAsyncStatus = SPI_BUSY;
                            PerCoreHandler->JobResult[SeqItem->CurJob->JobId] = SPI_JOB_PENDING;

                            SPI_DBG("S:%d J:%d Job Start on Spi%d\n", SeqItem->CurJob->SeqId, SeqItem->CurJob->JobId,
                                    PtrJobCfg[SeqItem->CurJob->JobId].HWUnit + 1);
                        }
                    } else {
                        SPI_DBG("The Spi%d is Busy or Job%d is Busy.\n", HwUnitId + 1, SeqItem->CurJob->JobId);
                    }
                }
            }

            QueueNode =  QueueNode->Next;
        }

        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
    } else {
        SPI_DBG("Sche is not Inited \n");
    }
}
/****************************************************************************************
* Service Name : Spi_JobHandleFuntion
* Syntax       : static uint32 Spi_JobHandleFuntion(uint8 HwUnitId)
* description  : Called When One Job Finish
*****************************************************************************************/
static void Spi_JobHandleFuntion(uint8 HwUnitId)
{
    struct Spi_JobNode *JobItem;
    const Spi_JobCfgType *PtrJobCfg;
    boolean need_seq_notification = FALSE;
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    struct Spi_Scheduler *Sche = &PerCoreHandler->Scheduler;
    const Spi_SequenceCfgType *Sequence = Spi_SequenceConfig;
    const Spi_HwUnitConfigType *HwUnitConfigPtr;
    struct Spi_SeqNode  *SeqNode = PerCoreHandler->SeqNode;
    SPI_DBG("%s Spi%d \n", __FUNCTION__, HwUnitId + 1);

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();

    if (PerCoreHandler->Spi_HandlerAsyncStatus == SPI_BUSY) {
        /* Job finish */
        JobItem = Sche->JobCurr[HwUnitId];

        if (JobItem) {
            PtrJobCfg = &Spi_JobConfig[JobItem->JobId];
            /* HwUnitConfigPtr == NULL is not possibility */
            HwUnitConfigPtr =  &Spi_HwUnitConfig[PtrJobCfg->HwUnitIdxCfg];
            SPI_DBG("J @%p S:%d J:%d Job finished.\n", JobItem, JobItem->SeqId, JobItem->JobId);

            if (HwUnitConfigPtr->HwMode == SPI_MASTER) {
                if (PtrJobCfg->CSHandling == CS_VIA_GPIO) {
                    if (PtrJobCfg->CSFunc == TRUE ) {
                        /* Resotry PinMux configure  */
                        Port_SetPinMode((Port_PinType)PtrJobCfg->PortPinId, (Port_PinModeType)PtrJobCfg->PinMux);
                    }

                    if (PtrJobCfg->CSPolarity == LOW)
                        Dio_WriteChannel(PtrJobCfg->GPIOCsPin, STD_HIGH);
                    else
                        Dio_WriteChannel(PtrJobCfg->GPIOCsPin, STD_LOW);
                }
            }

            /* free controller */
            Sche->HwStatusMask |= (0x01 << PtrJobCfg->HWUnit);

            /*
                Except err ,seq end ,or canceled seq.JobItem->Node.Next is const
                do not need critical protection.The large critical section is used
                here to protect when Sche->State = ASYNC_SCHE_IDLE and then
                SeqNode[JobItem->SeqId].CurJob is updated and JobItem->SeqId is not
                pending, if the asynchronous transfer of JobItem->SeqId is called again ,
                which will affect the enqueuing behavior and introduce uncertainty.
            */
            if ((PerCoreHandler->SpiBus[PtrJobCfg->HWUnit].Bus.state & SPI_STATE_ERR_END) || \
                JobItem->Node.Next == NULL_PTR ) {
                if (PerCoreHandler->SpiBus[PtrJobCfg->HWUnit].Bus.state & SPI_STATE_ERR_END) {
                    /* Job Failed */
                    PerCoreHandler->JobResult[JobItem->JobId] = SPI_JOB_FAILED;
                    PerCoreHandler->SeqResult[JobItem->SeqId] = SPI_SEQ_FAILED;
                    PerCoreHandler->SpiBus[PtrJobCfg->HWUnit].Bus.state &= (uint32)(~SPI_STATE_ERR_END);
                    need_seq_notification = TRUE;
                    /* Tx FIFO UDR,RX OVR,DMA Error will report here  */
                    Det_ReportRuntimeError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_ASYNCTRANSMIT_SID,
                                           SPI_E_ASYNC_ERROR);
                    SPI_DBG("J @%p S:%d J:%d Job Fail.\n", JobItem, JobItem->SeqId, JobItem->JobId);
                } else {
                    /*
                        Seq Transmit Finished or Canceled by Spi_Cancel Call.
                    */
                    PerCoreHandler->JobResult[JobItem->JobId] = SPI_JOB_OK;

                    for (uint8 ch = 0; ch < PtrJobCfg->NoOfChannels; ch++) {
                        uint8 ChannelId = PtrJobCfg->ChannelList[ch];

                        if (Spi_ChannelConfig[ChannelId].ChannelBufferType == IB) {
                            PerCoreHandler->Spi_SpiChannelState[ChannelId].Rx_Tag = DATA_VALID;
                            SPI_DBG("Ch %d RX Buff valid\n", ChannelId);
                        } else {
                            PerCoreHandler->Spi_SpiChannelState[ChannelId].Tx_Tag = BUFF_INVALID;
                            SPI_DBG("Ch %d TX Buff Invalid\n", ChannelId);
                        }
                    }

                    if (JobItem->Node.Next == NULL_PTR) {
                        /*
                            Even though the seq has been canceled, the last Job ended successfully,
                            so this seq is still executed successfully. Any Job fail will set curser status to Fail
                        */
                        if (PerCoreHandler->SeqResult[JobItem->SeqId] == SPI_SEQ_PENDING ) {
                            PerCoreHandler->SeqResult[JobItem->SeqId] = SPI_SEQ_OK;
                        }

                        need_seq_notification = TRUE;
                    }
                }

                SeqNode[JobItem->SeqId].CurJob = NULL_PTR;

                if (SeqNode[JobItem->SeqId].SeqInQueue) {
                    SeqNode[JobItem->SeqId].Node.Next->Prev = SeqNode[JobItem->SeqId].Node.Prev;
                    SeqNode[JobItem->SeqId].Node.Prev->Next = SeqNode[JobItem->SeqId].Node.Next;
                    SeqNode[JobItem->SeqId].SeqInQueue = FALSE;
                    Sche->PendingSeqCnt--;
                }

                SPI_DBG("S:%d Seq End.\n", JobItem->SeqId);

            } else {
                PerCoreHandler->JobResult[JobItem->JobId] = SPI_JOB_OK;
                /* Move to next Job */
                /*PRQA S 2810 2*/
                SeqNode[JobItem->SeqId].CurJob = GetJobNode(JobItem->Node.Next);

                for (uint8 ch = 0; ch < PtrJobCfg->NoOfChannels; ch++) {
                    uint8 ChannelId = PtrJobCfg->ChannelList[ch];

                    if (Spi_ChannelConfig[ChannelId].ChannelBufferType == IB) {
                        PerCoreHandler->Spi_SpiChannelState[ChannelId].Rx_Tag = DATA_VALID;
                        SPI_DBG("Ch %d RX Buff valid\n", ChannelId);
                    } else {
                        PerCoreHandler->Spi_SpiChannelState[ChannelId].Tx_Tag = BUFF_INVALID;
                        SPI_DBG("Ch %d TX Buff Invalid\n", ChannelId);
                    }
                }
            }

            /*
                Note:Update the state machine before Notifaction to avoid exceptions
                when calling asynchronous transfers in Notifaction.
            */
            Sche->ActiveJobCnt--;
            /* finish curr job */
            JobItem->IsActive = 0;
            /* avoid polling mode Notification multi called */
            Sche->JobCurr[HwUnitId] = NULL_PTR;
            /* Notification cannot be called in critical section */

            /*
                Here Sche->PendingSeqCnt may be 0, if (Sche->PendingSeqCnt)
                should be placed after Notifaction to support starting a new
                asynchronous transfer in Notifaction.
            */
            if (PtrJobCfg->JobEndNotification) {
                PtrJobCfg->JobEndNotification();
                SPI_DBG("S:%d J:%d Job Finish Notification.\n", JobItem->SeqId, JobItem->JobId);
            }

            if (need_seq_notification && Sequence[JobItem->SeqId].SequenceEndNotification) {
                Sequence[JobItem->SeqId].SequenceEndNotification();
                SPI_DBG("S:%d Seq Finish Notification.\n", JobItem->SeqId);
            }

            /* Have seq need sche */
            if (Sche->PendingSeqCnt) {
                Spi_Sche_Main();
            } else {
                /*
                    HwStatusMask will modify by Synctransmit so Sche->HwStatusMask != HW_ALL_FREE_MASK
                    Asyntransfers may also be idle .
                */
            }

            if (0 == Sche->ActiveJobCnt) {
                PerCoreHandler->Spi_HandlerAsyncStatus = SPI_IDLE;
            }
        } else {
            /* Poling mode this case will happen */
        }
    } else {
        SPI_DBG("AS:%d SS:%d\n", PerCoreHandler->Spi_HandlerAsyncStatus, PerCoreHandler->Spi_HandlerStatus);
    }

    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
}
#endif
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/** @brief Spi_InitData
 **
 ** Initialise global  data.
 **
 ** @param [out] NONE
 */
FUNC(void, SPI_CODE)
Spi_InitData(VAR(void, AUTOMATIC))
{
    uint8 CoreId = Spi_GetCoreID();
    const Spi_JobCfgType *PtrJobCfg = Spi_JobConfig;
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];

    /* Initialise  Every Hw bus Unit  Private data*/
    for (uint8 hwid = 0; hwid < SPI_TOTAL_HW_COUNT; hwid++) {
        Spi_BusPrivInit(hwid);
    }

    /* Initialise  Every Device  Private data */
    for (Spi_JobType JobIdx = 0; JobIdx < SPI_TOTAL_JOB_COUNT; JobIdx++) {
        Spi_DevicePrivInit(PtrJobCfg[JobIdx].DeviceIdx, &PtrJobCfg[JobIdx]);
    }

    /* Initialise Job result Array */
    for (Spi_JobType JobIdx = 0; JobIdx < SPI_TOTAL_JOB_COUNT; JobIdx++) {
        PerCoreHandler->JobResult[JobIdx] = SPI_JOB_OK;
    }

    for (Spi_SequenceType i = 0; i < SPI_TOTAL_SEQ_COUNT; i++) {
        /* Initialise Sequence result Array */
        PerCoreHandler->SeqResult[i] = SPI_SEQ_OK;
#if SPI_CANCEL_API == STD_ON
        PerCoreHandler->SeqCancel[i] = FALSE;
#endif
    }

    for (Spi_ChannelType i = 0; i < SPI_MAX_CHANNEL; i++) {
        PerCoreHandler->Spi_SpiChannelState[i].Rx_Tag = DATA_INVALID;
        PerCoreHandler->Spi_SpiChannelState[i].Tx_Tag = BUFF_INVALID;
    }

    /* Init Scheduer Dependent Parameter*/
    Spi_SchedulerInit();
}
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
/****************************************************************************************
* Service Name : Spi_AsyncModeSet
* Syntax       : void Spi_AsyncModeSet(uint32 mode)
* description  : Setup Spi Async mode.
*****************************************************************************************/
void Spi_AsyncModeSet(Spi_AsyncModeType mode)
{
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    struct Spi_Scheduler *Sche = &PerCoreHandler->Scheduler;

    for (uint8 HwIdx = 0; HwIdx < SPI_TOTAL_HW_COUNT; HwIdx++) {
        if (Spi_InstanceMask_Config[CoreId] & (0x01 << HwIdx)) {
            if (SPI_POLLING_MODE == mode) {
                PerCoreHandler->SpiBus[HwIdx].Bus_Priv.flags &= (uint32)(~(SPI_TX_IRQ_ENABLE | SPI_RX_IRQ_ENABLE |
                        SPI_SLV_IRQ_ENABLE));
            } else {
                PerCoreHandler->SpiBus[HwIdx].Bus_Priv.flags |= SPI_TX_IRQ_ENABLE | SPI_RX_IRQ_ENABLE |
                        SPI_SLV_IRQ_ENABLE;
            }
        }
    }

    Sche->SchedulerMode = mode;
}
#endif
/** @brief Spi_HWInit
 **
 ** This service initializes the HW Unit
 **
 ** @param [in] NONE
 */

FUNC(Std_ReturnType, SPI_CODE)
Spi_HWInit(void)
{
    uint8 HwUnit, DeviceIdx, CoreId = Spi_GetCoreID();
    const Spi_JobCfgType *PtrJobCfg = Spi_JobConfig;
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];


    /* initialize HW units */
    for (uint8 HwIdx = 0; HwIdx < SPI_TOTAL_HW_COUNT; HwIdx++) {
        mld_spi_bus_create(&PerCoreHandler->SpiBus[HwIdx].Bus, \
                           Spi_BaseAddr[HwIdx], Spi_IrqNum[HwIdx], \
                           (struct mld_spi_ops *)&semidrive_spi_bus_ops);
#if (SPI_ENABLE_SLAVE == STD_ON)
        sint8 DevPrivIdx = Get_SlaveModeConfigDeviceIdx(HwIdx);

        if (PerCoreHandler->SpiBus[HwIdx].Bus_Priv.flags & SPI_MODE_SLAVE_ENABLE) {
            if ((DevPrivIdx < 0)) {
                return E_NOT_OK;
            }

            /* config params attach */
            mld_spi_bus_set_privdata(&PerCoreHandler->SpiBus[HwIdx].Bus, \
                                     &PerCoreHandler->SpiBus[HwIdx].Bus_Priv, \
                                     &PerCoreHandler->SpiDevice[DevPrivIdx].Device_Priv);
            SPI_DBG("The Bus %d is Slave.\n", HwIdx);
        } else
#endif
        {
            /* config params attach */
            mld_spi_bus_set_privdata(&PerCoreHandler->SpiBus[HwIdx].Bus, \
                                     &PerCoreHandler->SpiBus[HwIdx].Bus_Priv, NULL);
        }

        PerCoreHandler->SpiBus[HwIdx].Bus.idx = HwIdx;

        /* Not alloc this controller */
        if (Spi_InstanceMask_Config[CoreId] & (0x01 << HwIdx)) {
            if (mld_spi_init(&PerCoreHandler->SpiBus[HwIdx].Bus) < 0)
                return E_NOT_OK;
        }
    }

    for (uint8 DevIdx = 0; DevIdx < SPI_TOTAL_DEV_COUNT; DevIdx++) {
        PerCoreHandler->SpiDevice[DevIdx].Device.priv = 0;
        PerCoreHandler->SpiDevice[DevIdx].Device.bus = 0;
    }

    /* Initialize and add Job to HW units*/
    for (uint8 JobIdx = 0; JobIdx < SPI_TOTAL_JOB_COUNT; JobIdx++) {
        /* spi HW units init */
        HwUnit = PtrJobCfg[JobIdx].HWUnit;
        DeviceIdx = PtrJobCfg[JobIdx].DeviceIdx;

        if ((PerCoreHandler->SpiDevice[DeviceIdx].Device.priv && \
             PerCoreHandler->SpiDevice[DeviceIdx].Device.priv !=
             &PerCoreHandler->SpiDevice[DeviceIdx].Device_Priv) || \
            (PerCoreHandler->SpiDevice[DeviceIdx].Device.bus && \
             PerCoreHandler->SpiDevice[DeviceIdx].Device.bus != &PerCoreHandler->SpiBus[HwUnit].Bus)) {
            return E_NOT_OK;
        }

        /* spi device init */
        mld_spi_dev_init(&PerCoreHandler->SpiDevice[DeviceIdx].Device, \
                         &PerCoreHandler->SpiDevice[DeviceIdx].Device_Priv);
        /*
            spi device attach spi ,There will set the cs polarity;
            the upper layer should prevent that different devices
            on the same bus use the same cs signal.
        */
        mld_spi_dev_attach_bus(&PerCoreHandler->SpiDevice[DeviceIdx].Device, \
                               &PerCoreHandler->SpiBus[HwUnit].Bus);
    }

    return E_OK;
}

/** @brief Spi_HWDeInit
 **
 ** This service de-initializes the HW Unit
 **
 ** @param [in] None
 */

FUNC(Std_ReturnType, SPI_CODE)
Spi_HWDeInit(void)
{
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];

    for (uint8 BusIdx = 0; BusIdx < SPI_TOTAL_HW_COUNT; BusIdx++) {
        if (Spi_InstanceMask_Config[CoreId] & (0x01 << BusIdx))
            mld_spi_deinit(&PerCoreHandler->SpiBus[BusIdx].Bus);
    }

    return E_OK;
}
/** @brief Spi_JobSyncTransmit
 **
 ** Transmit a Job in Synchronous sequence
 **
 ** @param [in] LddJobIndex - Index of the Job in Job config Array
 **             LddSequence - Sequence Index ID
 */
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
static FUNC(Std_ReturnType, SPI_CODE) Spi_JobSyncTransmit(Spi_JobType JobId,
        const Spi_JobCfgType *PtrJobConfig)
{
    sint32 ret = -1;
    uint16  Length;
    uint16  ChannelId;
    uint8 CoreId = Spi_GetCoreID();
    Std_ReturnType ReturnValue = E_OK;
    Spi_DataBufferType *pCurrentTxBuffer;
    Spi_DataBufferType *pCurrentRxBuffer;
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    const Spi_ChannelCfgType *PtrChannelConfig;
    struct mld_spi_device *dev = &PerCoreHandler->SpiDevice[PtrJobConfig->DeviceIdx].Device;
    const Spi_HwUnitConfigType *HwUnitConfigPtr =  &Spi_HwUnitConfig[PtrJobConfig->HwUnitIdxCfg];

    for (Spi_ChannelType ch = 0; ch < PtrJobConfig->NoOfChannels && ReturnValue == E_OK; ch++) {
        ChannelId = PtrJobConfig->ChannelList[ch];
        PtrChannelConfig = &(Spi_ChannelConfig[ChannelId]);

        if (PtrChannelConfig->ChannelBufferType == EB && \
            PerCoreHandler->Spi_SpiChannelState[ChannelId].Tx_Tag == BUFF_INVALID) {
            /* IB Not write */
            ReturnValue = E_NOT_OK;
        } else if (PtrChannelConfig->ChannelBufferType == IB) {
            PerCoreHandler->Spi_SpiChannelState[ChannelId].Rx_Tag = DATA_INVALID;
            SPI_DBG("Ch %d TX Buff invalid\n", ChannelId);
        }
    }

    if (ReturnValue == E_OK) {
        /* Set the Job status result */
        PerCoreHandler->JobResult[JobId] = SPI_JOB_PENDING;

        /* CS pin setup */
        if (HwUnitConfigPtr->HwMode == SPI_MASTER ) {
            if (PtrJobConfig->CSHandling == CS_VIA_GPIO) {
                if (PtrJobConfig->CSFunc == TRUE) {
                    /* set port state befor tramsmit data */
                    Port_SetPinMode((Port_PinType)PtrJobConfig->PortPinId, MUX_0);
                }

                mld_set_soft_cs_id(dev->bus, PtrJobConfig->GPIOCsPin);
            }
        }

        /* Send the Data configured for the channels with in the Job */
        for (Spi_ChannelType ch = 0; ch < PtrJobConfig->NoOfChannels; ch++) {
            ChannelId = PtrJobConfig->ChannelList[ch];
            PtrChannelConfig = &(Spi_ChannelConfig[ChannelId]);

            if (PtrChannelConfig->ChannelBufferType == IB) {
                pCurrentRxBuffer = (Spi_DataBufferType *)PtrChannelConfig->ReadBufferIndex;
                pCurrentTxBuffer = (Spi_DataBufferType *)PtrChannelConfig->WriteBufferIndex;
                Length = (uint16)PtrChannelConfig->BufferSize;
            } else {
                pCurrentRxBuffer = (Spi_DataBufferType *)PerCoreHandler->ExtBuff[\
                                   ChannelId].DesDataBufferPtr;

                pCurrentTxBuffer = (Spi_DataBufferType *)PerCoreHandler->ExtBuff[\
                                   ChannelId].SrcDataBufferPtr;
                Length = PerCoreHandler->ExtBuff[PtrJobConfig->ChannelList[ch]].Length;
            }

            PerCoreHandler->SpiChannelCB[ChannelId].len = Length;
            PerCoreHandler->SpiChannelCB[ChannelId].ptxdata.val = (uint32)pCurrentTxBuffer;

            if ( PtrChannelConfig->DataWidth < 0x9u )
                PerCoreHandler->SpiChannelCB[ChannelId].width_type = SPI_DATA_WIDTH_BYTE;
            else if (PtrChannelConfig->DataWidth < 0x11U)
                PerCoreHandler->SpiChannelCB[ChannelId].width_type = SPI_DATA_WIDTH_HALF_WORD;
            else
                PerCoreHandler->SpiChannelCB[ChannelId].width_type = SPI_DATA_WIDTH_WORD;

            if (PtrJobConfig->EnableRx == TRUE)
                PerCoreHandler->SpiChannelCB[ChannelId].prxdata.val = (uint32)pCurrentRxBuffer;
            else
                PerCoreHandler->SpiChannelCB[ChannelId].prxdata.val = 0;

        }

        ChannelId = PtrJobConfig->ChannelList[0];

        if (HwUnitConfigPtr->HwMode == SPI_MASTER) {
            ret = mld_spi_vector_transmit_receive(dev->bus, dev, &PerCoreHandler->SpiChannelCB[ChannelId]);
        }

#if (SPI_ENABLE_SLAVE == STD_ON)
        else {
            struct mld_spi_module *bus = &PerCoreHandler->SpiBus[PtrJobConfig->HwUnitIdxCfg].Bus;
            ret = mld_spi_vector_transmit_receive(bus, NULL_PTR, &PerCoreHandler->SpiChannelCB[ChannelId]);
        }

#endif

        if (ret < 0) {
            ReturnValue = E_NOT_OK;
        }

        if (HwUnitConfigPtr->HwMode == SPI_MASTER) {
            if (PtrJobConfig->CSHandling == CS_VIA_GPIO) {

                if (PtrJobConfig->CSFunc == TRUE) {
                    Port_SetPinMode((Port_PinType)PtrJobConfig->PortPinId,
                                    (Port_PinModeType)PtrJobConfig->PinMux);
                }

                if (PtrJobConfig->CSPolarity == LOW)
                    Dio_WriteChannel(PtrJobConfig->GPIOCsPin, STD_HIGH);
                else
                    Dio_WriteChannel(PtrJobConfig->GPIOCsPin, STD_LOW);
            }
        }

        /* Set the Job status result */
        if (ReturnValue == E_OK) {
            PerCoreHandler->JobResult[JobId] = SPI_JOB_OK;

            for (Spi_ChannelType ch = 0; ch < PtrJobConfig->NoOfChannels; ch++) {
                ChannelId = PtrJobConfig->ChannelList[ch];
                PtrChannelConfig = &(Spi_ChannelConfig[ChannelId]);

                if (PtrChannelConfig->ChannelBufferType == IB) {
                    PerCoreHandler->Spi_SpiChannelState[ChannelId].Rx_Tag = DATA_VALID;
                    SPI_DBG("Ch %d RX Buff valid\n", ChannelId);
                } else {
                    PerCoreHandler->Spi_SpiChannelState[ChannelId].Tx_Tag = BUFF_INVALID;
                    SPI_DBG("Ch %d TX Buff Invalid\n", ChannelId);
                }
            }

        } else {
            PerCoreHandler->JobResult[JobId] = SPI_JOB_FAILED;

            for (Spi_ChannelType ch = 0; ch < PtrJobConfig->NoOfChannels; ch++) {
                ChannelId = PtrJobConfig->ChannelList[ch];
                PtrChannelConfig = &(Spi_ChannelConfig[ChannelId]);

                if (PtrChannelConfig->ChannelBufferType == EB) {
                    PerCoreHandler->Spi_SpiChannelState[ChannelId].Tx_Tag = BUFF_INVALID;
                    SPI_DBG("Ch %d TX Buff Invalid\n", ChannelId);
                }
            }
        }

        if (PtrJobConfig->JobEndNotification) {
            PtrJobConfig->JobEndNotification();
        }
    }

    return ReturnValue;
}
#endif

/** @brief Spi_SeqSyncTransmit
 **
 ** To transmits the sequence
 **
 ** @param [in] NONE
 ** @param [out] Std_ReturnType
 */
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
FUNC(Std_ReturnType, SPI_CODE)
Spi_SeqSyncTransmit(Spi_SequenceType SequenceId, const Spi_SequenceCfgType *PtrSeqConfig)
{
    uint8 CoreId = Spi_GetCoreID();
    Std_ReturnType ReturnValue = E_OK;
    const Spi_JobCfgType *tmpPtrJobConfig = NULL_PTR;
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];

    /* Change sequence status to Pending */
    PerCoreHandler->SeqResult[SequenceId] = SPI_SEQ_PENDING;

    for (Spi_JobType i = 0; (i < (PtrSeqConfig->NoOfJobs) && ReturnValue == E_OK); i++) {
        tmpPtrJobConfig = &Spi_JobConfig[PtrSeqConfig->JobList[i]];
        ReturnValue = Spi_JobSyncTransmit(PtrSeqConfig->JobList[i], tmpPtrJobConfig);
    }

    if (E_OK == ReturnValue)
        /* Change sequence status to OK */
        PerCoreHandler->SeqResult[SequenceId] = SPI_SEQ_OK;
    else
        PerCoreHandler->SeqResult[SequenceId] = SPI_SEQ_FAILED;

    if (PtrSeqConfig->SequenceEndNotification)
        PtrSeqConfig->SequenceEndNotification();

    return ReturnValue;
}
#endif
/** @brief Spi_GetHWStatus
 **
 ** This function reads the HW status from  DW_SSI_SR register
 **
 ** @param [in] NONE
 ** @param [out] Std_ReturnType
 */
FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWStatus(Spi_HWUnitType HwUnit)
{
    Spi_StatusType ret;
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    struct mld_spi_module *bus = &PerCoreHandler->SpiBus[HwUnit].Bus;

    if (!(bus->state & SPI_STATE_INITED))
        ret = SPI_UNINIT;
    else if (bus->state & BUS_BUSY_MASK)
        ret = SPI_BUSY;
    else
        ret = SPI_IDLE;

    return ret;
}
/*********************************************************************************
* Functions
**********************************************************************************/

/**************************************************
*  Service name        : Spi_HwGetJobResult
*  Syntax              : Std_ReturnType Spi_HwGetJobResult( Spi_JobType Job )
*  Parameters (in)     : Job - Job ID.
*  Description         : This service Specifies the last transmission request of the Job.
**********************************************************/
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
Spi_JobResultType Spi_HwGetJobResult(Spi_JobType Job)
{
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    /*Return the Job result*/
    return PerCoreHandler->JobResult[Job];
}
#endif
/**************************************************************************************************
*  Service name        : Spi_HwAsyncTransmit
*  Syntax              : Std_ReturnType Spi_HwAsyncTransmit( Spi_SequenceType Sequence )
*  Parameters (in)     : Sequence - Sequence ID.
*  Parameters (in-out) : None
*  Parameters (out)    : None
*  Return value        : E_OK: Transmission command has been accepted
                         E_NOT_OK: Transmission command has not been accepted
*  Description         : Service to transmit data on the SPI bus.
*****************************************************************************************************/
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
Std_ReturnType Spi_HwAsyncTransmit(Spi_SequenceType Sequence)
{
    uint8 CoreId = Spi_GetCoreID();
    Std_ReturnType ReturnValue = E_OK;
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    struct Spi_Scheduler *Sche = &PerCoreHandler->Scheduler;
    const Spi_SequenceCfgType *SeqConfigPtr = &Spi_SequenceConfig[Sequence];
    SPI_DBG("%s call param %d \n", __FUNCTION__, Sequence);

    /* Async scheduler not init */
    if (Sche->State == ASYNC_SCHE_UNINIT) {
        /*  error handle */
        ReturnValue =  E_NOT_OK;
    } else {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_014();

        /* Check whether the sequence is already running or not */
        if (PerCoreHandler->SeqResult[Sequence] == SPI_SEQ_PENDING) {
            Det_ReportRuntimeError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_ASYNCTRANSMIT_SID,
                                   SPI_E_SEQ_PENDING);
            /* busy seq */
            ReturnValue =  E_NOT_OK;
        } else {
            /* enqueue to queue */
            if (Spi_ScheOneSequence(Sequence) != E_OK) {
                ReturnValue =  E_NOT_OK;
            } else {
                /* [SWS_Spi_00020] The function Spi_AsyncTransmit shall take over the given parameter,
                    initiate a transmission,set the sequence result to SPI_SEQ_PENDING */
                PerCoreHandler->SeqResult[Sequence] = SPI_SEQ_PENDING;

                /* [SWS_Spi_00194]When the function Spi_AsyncTransmit is called,
                    shall take over the given parameter and set the Job status to SPI_JOB_QUEUED,*/
                for (Spi_JobType JobIdx = 0; JobIdx < SeqConfigPtr->NoOfJobs; JobIdx++) {
                    Spi_JobType Job = SeqConfigPtr->JobList[JobIdx];
                    PerCoreHandler->JobResult[Job] = SPI_JOB_QUEUED;
                }

                /*  trigger schedule running */
                Spi_Sche_Main();
            }
        }

        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_014();
    }

    return ReturnValue;
}
#endif

/**********************************************************************************
*  Service name        : Spi_LocalParametersCheck
*  Syntax              : void Spi_LocalParametersCheck(boolean expression,
                                                        uint8 API_ID,
                                                        uint8 ERROR_ID,
                                                        Std_ReturnType *ReturnValue)
*  Description         : .
***********************************************************************************/
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
void Spi_LocalParametersCheck(boolean expression,
                              uint8 API_ID,
                              uint8 ERROR_ID,
                              Std_ReturnType *ReturnValue)
{
    /*validate the expression*/
    if ((TRUE == expression) && (E_OK == *ReturnValue)) {
        /*Report development errors to Det*/
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, API_ID, ERROR_ID);
#endif

        *ReturnValue = E_NOT_OK;
    }
}
#endif

/**********************************************************************************
*  Service name        : Spi_HwGetJobResult
*  Syntax              : Std_ReturnType Spi_HwGetJobResult( Spi_JobType Job )
*  Parameters (in)     : Job - Job ID.
*  Description         : This service Specifies the last transmission request of the Job.
***********************************************************************************/
FUNC(void, SPI_CODE) Spi_HwMainFunctionHandling(uint8 Hwidx)
{
#if ( SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || ( SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
    uint8 CoreId = Spi_GetCoreID();

    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    sint32 ret = mld_spi_async_polling(&PerCoreHandler->SpiBus[Hwidx].Bus);

    if (!ret)
        /* transmit finished */
        Spi_JobHandleFuntion(Hwidx);

#endif
} /* end of Spi_HwMainFunctionHandling */

#if (SPI_DEV_ERROR_DETECT == STD_ON)
uint32 GetSpiChannelAssignCoreId(Spi_ChannelType Channel)
{
    /*Default assign to sf core */
    uint32 CoreId = 0;

    for (uint16 JobIdx = 0; JobIdx < SPI_TOTAL_JOB_COUNT; JobIdx++) {
        for (uint16 Chan = 0; Chan < Spi_JobConfig[JobIdx].NoOfChannels; Chan++) {
            if (Spi_JobConfig[JobIdx].ChannelList[Chan] == Channel) {
                for (uint8 Core = 0; Core < SPI_MAX_CORES; Core++) {
                    if (Spi_InstanceMask_Config[Core] & (0x01 << Spi_JobConfig[JobIdx].HWUnit)) {
                        CoreId = Core;
                        return CoreId;
                    }
                }
            }
        }
    }

    return CoreId;
}

uint32 GetSpiJobAssignCoreId(Spi_JobType JobId)
{
    /*Default assign to sf core */
    uint32 CoreId = 0;

    for (uint8 Core = 0; Core < SPI_MAX_CORES; Core++) {
        if (Spi_InstanceMask_Config[Core] & (0x01 << Spi_JobConfig[JobId].HWUnit)) {
            CoreId = Core;
            break;
        }
    }

    return CoreId;
}

uint32 GetSpiSequenceAssignCoreId(Spi_SequenceType Sequence)
{
    return GetSpiJobAssignCoreId(Spi_SequenceConfig[Sequence].JobList[0]);
}
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif
