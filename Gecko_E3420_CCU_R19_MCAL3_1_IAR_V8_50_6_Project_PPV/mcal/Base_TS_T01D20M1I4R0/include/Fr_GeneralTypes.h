#ifndef FR_GENERAL_TYPES_H
#define FR_GENERAL_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Platform_Types.h"
#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "Std_Types.h"


/*Macros which can be passed into Fr_ReadCCConfig as parameter Fr_ConfigParamIdx.*/

#define FR_CIDX_GDCYCLE                          0U    /* FrIfGdCycle */
#define FR_CIDX_PMICROPERCYCLE                   1U    /* FrPMicroPerCycle */
#define FR_CIDX_PDLISTENTIMEOUT                  2U    /* FrPdListenTimeout */
#define FR_CIDX_GMACROPERCYCLE                   3U    /* FrIfGMacroPerCycle */
#define FR_CIDX_GDMACROTICK                      4U    /* FrIfGdMacrotick */
#define FR_CIDX_GNUMBEROFMINISLOTS               5U    /* FrIfGNumberOfMinislots */
#define FR_CIDX_GNUMBEROFSTATICSLOTS             6U    /* FrIfGNumberOfStaticSlots */
#define FR_CIDX_GDNIT                            7U    /* FrIfGdNit */
#define FR_CIDX_GDSTATICSLOT                     8U    /* FrIfGdStaticSlot */
#define FR_CIDX_GDWAKEUPRXWINDOW                 9U    /* FrIfGdWakeupRxWindow */
#define FR_CIDX_PKEYSLOTID                      10U    /* FrPKeySlotId */
#define FR_CIDX_PLATESTTX                       11U    /* FrPLatestTx */
#define FR_CIDX_POFFSETCORRECTIONOUT            12U    /* FrPOffsetCorrectionOut */
#define FR_CIDX_POFFSETCORRECTIONSTART          13U    /* FrPOffsetCorrectionStart */
#define FR_CIDX_PRATECORRECTIONOUT              14U    /* FrPRateCorrectionOut */
#define FR_CIDX_PSECONDKEYSLOTID                15U    /* FrPSecondKeySlotId */
#define FR_CIDX_PDACCEPTEDSTARTUPRANGE          16U    /* FrPdAcceptedStartupRange */
#define FR_CIDX_GCOLDSTARTATTEMPTS              17U    /* FrIfGColdStartAttempts */
#define FR_CIDX_GCYCLECOUNTMAX                  18U    /* FrIfGCycleCountMax */
#define FR_CIDX_GLISTENNOISE                    19U    /* FrIfGListenNoise */
#define FR_CIDX_GMAXWITHOUTCLOCKCORRECTFATAL    20U    /* FrIfGMaxWithoutClockCorrectFatal */
#define FR_CIDX_GMAXWITHOUTCLOCKCORRECTPASSIVE  21U    /* FrIfGMaxWithoutClockCorrectPassive */
#define FR_CIDX_GNETWORKMANAGEMENTVECTORLENGTH  22U    /* FrIfGNetworkManagementVectorLength */
#define FR_CIDX_GPAYLOADLENGTHSTATIC            23U    /* FrIfGPayloadLengthStatic */
#define FR_CIDX_GSYNCFRAMEIDCOUNTMAX            24U    /* FrIfGSyncFrameIDCountMax */
#define FR_CIDX_GDACTIONPOINTOFFSET             25U    /* FrIfGdActionPointOffset */
#define FR_CIDX_GDBIT                           26U    /* FrIfGdBit */
#define FR_CIDX_GDCASRXLOWMAX                   27U    /* FrIfGdCasRxLowMax */
#define FR_CIDX_GDDYNAMICSLOTIDLEPHASE          28U    /* FrIfGdDynamicSlotIdlePhase */
#define FR_CIDX_GDMINISLOTACTIONPOINTOFFSET     29U    /* FrIfGdMiniSlotActionPointOffset */
#define FR_CIDX_GDMINISLOT                      30U    /* FrIfGdMinislot */
#define FR_CIDX_GDSAMPLECLOCKPERIOD             31U    /* FrIfGdSampleClockPeriod */
#define FR_CIDX_GDSYMBOLWINDOW                  32U    /* FrIfGdSymbolWindow */
#define FR_CIDX_GDSYMBOLWINDOWACTIONPOINTOFFSET 33U    /* FrIfGdSymbolWindowActionPointOffset */
#define FR_CIDX_GDTSSTRANSMITTER                34U    /* FrIfGdTssTransmitter */
#define FR_CIDX_GDWAKEUPRXIDLE                  35U    /* FrIfGdWakeupRxIdle */
#define FR_CIDX_GDWAKEUPRXLOW                   36U    /* FrIfGdWakeupRxLow */
#define FR_CIDX_GDWAKEUPTXACTIVE                37U    /* FrIfGdWakeupTxActive */
#define FR_CIDX_GDWAKEUPTXIDLE                  38U    /* FrIfGdWakeupTxIdle */
#define FR_CIDX_PALLOWPASSIVETOACTIVE           39U    /* FrPAllowPassiveToActive */
#define FR_CIDX_PCHANNELS                       40U    /* FrPChannels */
#define FR_CIDX_PCLUSTERDRIFTDAMPING            41U    /* FrPClusterDriftDamping */
#define FR_CIDX_PDECODINGCORRECTION             42U    /* rPDecodingCorrection */
#define FR_CIDX_PDELAYCOMPENSATIONA             43U    /* FrPDelayCompensationA */
#define FR_CIDX_PDELAYCOMPENSATIONB             44U    /* FrPDelayCompensationB */
#define FR_CIDX_PMACROINITIALOFFSETA            45U    /* FrPMacroInitialOffsetA */
#define FR_CIDX_PMACROINITIALOFFSETB            46U    /* FrPMacroInitialOffsetB */
#define FR_CIDX_PMICROINITIALOFFSETA            47U    /* FrPMicroInitialOffsetA */
#define FR_CIDX_PMICROINITIALOFFSETB            48U    /* FrPMicroInitialOffsetB */
#define FR_CIDX_PPAYLOADLENGTHDYNMAX            49U    /* FrPPayloadLengthDynMax */
#define FR_CIDX_PSAMPLESPERMICROTICK            50U    /* FrPSamplesPerMicrotick */
#define FR_CIDX_PWAKEUPCHANNEL                  51U    /* FrPWakeupChannel */
#define FR_CIDX_PWAKEUPPATTERN                  52U    /* FrPWakeupPattern */
#define FR_CIDX_PDMICROTICK                     53U    /* FrPdMicrotick */
#define FR_CIDX_GDIGNOREAFTERTX                 54U    /* FrIfGdIgnoreAfterTx */
#define FR_CIDX_PALLOWHALTDUETOCLOCK            55U    /* FrPAllowHaltDueToClock */
#define FR_CIDX_PEXTERNALSYNC                   56U    /* FrPExternalSync */
#define FR_CIDX_PFALLBACKINTERNAL               57U    /* FrPFallBackInternal */
#define FR_CIDX_PKEYSLOTONLYENABLED             58U    /* FrPKeySlotOnlyEnabled */
#define FR_CIDX_PKEYSLOTUSEDFORSTARTUP          59U    /* FrPKeySlotUsedForStartup */
#define FR_CIDX_PKEYSLOTUSEDFORSYNC             60U    /* FrPKeySlotUsedForSync */
#define FR_CIDX_PNMVECTOREARLYUPDATE            61U    /* FrPNmVectorEarlyUpdate */
#define FR_CIDX_PTWOKEYSLOTMODE                 62U    /* FrPTwoKeySlotMode */



typedef enum
{
    FR_TRANSMITTED = 0U,  /* No LPdu transmission is pending, LSdu has been transmitted.*/
    FR_NOT_TRANSMITTED,    /* An LPdu transmission is pending, LSdu has not been transmitted.*/
    FR_TRANSMITTED_CONFLICT    /* A transmission conflict has occurred. */
} Fr_TxLPduStatusType;

typedef enum
{
    FR_RECEIVED = 0U,                /* LSdu has been received.*/
    FR_NOT_RECEIVED,                 /* LSdu has not been received.*/
    FR_RECEIVED_MORE_DATA_AVAILABLE  /* LSdu has been received. More instances of this LPdu are
                                        available (FIFO usage ) */
} Fr_RxLPduStatusType;


typedef enum
{
    /* POC:Config - controller can be configured.  */
    FR_POCSTATE_CONFIG = 0U,
    /* POC:Default Config - controller is initialized and needs to be configured.*/
    FR_POCSTATE_DEFAULT_CONFIG,
    /* POC:Halt - controller is stopped.*/
    FR_POCSTATE_HALT,
    /* POC:Normal Active - controller is connected to the FlexRay cluster.*/
    FR_POCSTATE_NORMAL_ACTIVE,
    /* POC:Normal Passive - controller has problems with synchronization to the cluster.*/
    FR_POCSTATE_NORMAL_PASSIVE,
    /* POC:Ready - controller is configured and ready to communicate.*/
    FR_POCSTATE_READY,
    /* POC:Startup - controller is starting up the cluster or integrating to the cluster.*/
    FR_POCSTATE_STARTUP,
    /* POC:Wakeup - controller initiate Wakeup procedure.*/
    FR_POCSTATE_WAKEUP
} Fr_POCStateType;

typedef enum
{
    FR_SLOTMODE_KEYSLOT = 0U,  /* FlexRay controller is transmitting only in single slot
                                 (key slot) */
    FR_SLOTMODE_ALL_PENDING,  /* After end of the cycle controller will change slot mode to
                                 <b>FR_SLOTMODE_ALL</b>*/
    FR_SLOTMODE_ALL           /* FlexRay controller transmits in all configured slots */
} Fr_SlotModeType;

#define FR_SLOTMODE_SINGLE (FR_SLOTMODE_KEYSLOT)


typedef enum
{
    FR_ERRORMODE_ACTIVE = 0U,  /* Controller is synchronized to FlexRay cluster.
                                  Synchronization has not been lost more than
                                  gMaxWithoutClockCorrectionPassive cycles.*/
    FR_ERRORMODE_PASSIVE,      /* Controller has lost synchronization for less than
                                  gMaxWithoutClockCorrectionFatal cycles.*/
    FR_ERRORMODE_COMM_HALT    /* FlexRay controller was stoped due to loss of synchronization.*/
} Fr_ErrorModeType;

typedef enum
{
    FR_WAKEUP_UNDEFINED = 0U,     /* Unknown state - the controller has not been in POC:Wakeup
                                     state since it was in POC:Default Config.*/
    FR_WAKEUP_RECEIVED_HEADER,    /* Frame header was received during initial listen phase.*/
    FR_WAKEUP_RECEIVED_WUP,       /* Valid WUP was received during initial listen phase.*/
    FR_WAKEUP_COLLISION_HEADER,   /* Collision with frame header during WUP transmission.*/
    FR_WAKEUP_COLLISION_WUP,      /* Collision with another wakeup during WUP transmission.*/
    FR_WAKEUP_COLLISION_UNKNOWN,  /* Unknown collision during WUP transmission.*/
    FR_WAKEUP_TRANSMITTED         /* WUP has been successfully transmitted.*/
} Fr_WakeupStateType;

typedef enum
{
    FR_STARTUP_UNDEFINED = 0U,                 /* Unknown state - controller has not been in the
                                                  POC:Startup state since POC:Default Config
                                                  state.*/
    FR_STARTUP_COLDSTART_LISTEN,               /* Controller listens before it initiates CAS
                                                  transmission.*/
    FR_STARTUP_INTEGRATION_COLDSTART_CHECK,    /* Node is synchronizing to leading coldstarter.*/
    FR_STARTUP_COLDSTART_JOIN,                 /* Controller has joined the leading coldstarter
                                                  in transmission of startup frames.*/
    FR_STARTUP_COLDSTART_COLLISION_RESOLUTION, /* Leading coldstarter transmits startup frames.*/
    FR_STARTUP_COLDSTART_CONSISTENCY_CHECK,    /* Leading coldstarter checks if another node
                                                  transmits startup frames.*/
    FR_STARTUP_INTEGRATION_LISTEN,             /* Integrating node (non-coldstarter) listens.*/
    FR_STARTUP_INITIALIZE_SCHEDULE,            /* Schedule is being initialized.*/
    FR_STARTUP_INTEGRATION_CONSISTENCY_CHECK,  /* Controller looks for 4 pairs of startup frames
                                                  to integrate into cluster.*/
    FR_STARTUP_COLDSTART_GAP,                  /* Pause between two attempts of coldstart.*/

    FR_STARTUP_EXTERNAL_STARTUP
} Fr_StartupStateType;

typedef enum
{
    FR_CHANNEL_A = 0x01U,  /* Channel A only */
    FR_CHANNEL_B = 0x02U,       /* Channel B only */
    FR_CHANNEL_AB = 0x03U       /* Both A and B channels */
} Fr_ChannelType;


typedef enum
{
	/* Module Interrupt Enable */
 	FR_MODULEIE = 0x0U,
	/* Protocol Interrupt Enable */
 	FR_PROTOCOLIE,
	/* CHI Interrupt Enable */
 	FR_CHIIE,
	/* Wakeup Interrupt Enable */
	FR_WAKEUPIE,
	/* Receive FIFO Channel B Not Empty Interrupt Enable */
 	FR_FIFOBIE,
	/* Receive FIFO Channel A Not Empty Interrupt Enable */
 	FR_FIFOAIE,
	/* Receive Buffer Interrupt Enable */
 	FR_RECEIVEIE,
	/* Transmit Buffer Interrupt Enable */
 	FR_TRANSMITIE
} GlobalInterruptType;


typedef struct
{
    boolean CHIHaltRequest;            /* TRUE means that there is pending halt request.*/
    boolean ColdstartNoise;            /* TRUE means that noise detected on bus during startup.*/
    Fr_ErrorModeType ErrorMode;        /* Contains FlexRay controller error mode.*/
    boolean Freeze;                    /* TRUE means that internal error causing transition to
                                          the POC:Halt state or FREEZE command occurred.*/
    Fr_SlotModeType SlotMode;          /* Contains FlexRay controller slot mode.*/
    Fr_StartupStateType StartupState;  /* Contains FlexRay controller startup state.*/
    Fr_POCStateType State;             /* Contains FlexRay controller POC state.*/
    Fr_WakeupStateType WakeupState;   /* Contains FlexRay controller wakeup status.*/
    boolean CHIReadyRequest;

} Fr_POCStatusType;

typedef struct
{
    uint8 Cycle;                        /*Cycle in which the frame is transmitted or received*/
    uint16 SlotId;                      /*Slot ID of a frame*/
    Fr_ChannelType channelId;           /*Channel of the frame*/

} Fr_SlotAssignmentType;


typedef enum
{
    FR_FIFOA_BUFFER = 0U,  /* Receive FIFO A */
    FR_FIFOB_BUFFER,       /* Receive FIFO B */
    FR_TRANSMIT_BUFFER,    /* Individual transmit message buffer */
    FR_RECEIVE_BUFFER      /* individual receive message buffer */
} Fr_BufferType;

typedef enum
{
    FR_ACCEPTANCE = 0U,  /* Filter is set to accept selected IDs */
    FR_REJECTION         /* Filter is set to reject selected IDs */
} Fr_CCFifoRangeFilterModeType;

typedef enum
{
    FR_RECEIVE_FIFOA = 0U,  /* Receive FIFO A */
    FR_RECEIVE_FIFOB        /* Receive FIFO B */
} Fr_CCFifoChannelType;


typedef void Fr_ConfigType;

typedef struct
{
    /* Base address of the FlexRay module */
    const uint32 CCBaseAddress;
    /* Base address of the FlexRay memory */
    const uint8* const CCFlexRayMemoryBaseAddress;
    /* Channel to which the node is connected */
    const Fr_ChannelType Channels;
    /* Enabling of single channel mode (FALSE - dual channel mode) */
    const boolean SingleChannelModeEnabled;     /* nonstandard */
    /* Channel Bit Rate selection */
    const uint8 Bitrate;                        /* nonstandard */
    /* Timeout value in the MCR reg. */
    const uint8 Timeout;                        /* nonstandard */
    /* Offset for sync frame tables */
    const uint16 SyncFrameTableOffset;
    /* Second absolute timer enable/disable */
    const boolean EnableSecondaryAbsTimer;
} Fr_CCHardwareConfigType;

typedef struct
{
    /* Buffer type */
    const Fr_BufferType BufferType;
    /* Reference to buffer configuration structure */
    const void* const BufferConfigPtr;
    /* Individual Message Buffer Number */
    const uint16 MessageBufferNumber;
    /* Buffer should be used for the initialization? */
    const boolean FirstInitialization;
    /* Buffer is Reconfigurable */
    const boolean Reconfigurable;
} Fr_CCLpduInfoType;

typedef struct
{
    uint8* const MbDataAddrPtr;
    /* Address pointer of the message buffer data field */
} Fr_CCBufferAddressType;

typedef struct
{
    const uint16 DataOffset16;
    /* Offset value of the message buffer data field */
}Fr_CCBufferOffset16Type;

typedef struct
{
    /* Reference to configuration information of one message buffer configuration set */
    const Fr_CCLpduInfoType* const LPduInfoPtr;
    /* Initial MB offsets 32-bit */
    const Fr_CCBufferAddressType* const BufferAddressTable;
    /* Initial MB offsets 16-bit */
    const Fr_CCBufferOffset16Type* const BufferOffsetTable;
    /* The number of items in the configuration structure of the type Fr_CCLpduInfoType - i.e. the
    the number of virtual resources */
    const uint16 BuffersConfiguredCount;
    /* Data size - segment 1 */
    const uint8 MessageBufferSegment1DataSize;
    /* Data size - segment 2 */
    const uint8 MessageBufferSegment2DataSize;
    /* Last MB in segment 1 (Number of MB in Segment1 - 1) */
    const uint16 LastMBSEG1;
    /* Last individual MB;(Number of MB in Segment1 + Number of MB in Segment2 - 1) */
    const uint16 LastMBUTIL;
     /* Ch A, seg 1 - the initial index of the MB header field */
    const uint16 RSBIR_A1BufferIndexInit;
    /* Ch B, seg 1 - the initial index of the MB header field */
    const uint16 RSBIR_B1BufferIndexInit;
    /* Ch A, seg 2 - the initial index of the MB header field */
    const uint16 RSBIR_A2BufferIndexInit;
    /* Ch B, seg 2 - the initial index of the MB header field */
    const uint16 RSBIR_B2BufferIndexInit;

} Fr_CCBufferConfigSetType;


typedef struct
{
    const uint16 RegPCR0;
    const uint16 RegPCR1;
    const uint16 RegPCR2;
    const uint16 RegPCR3;
    const uint16 RegPCR4;
    const uint16 RegPCR5;
    const uint16 RegPCR6;
    const uint16 RegPCR7;
    const uint16 RegPCR8;
    const uint16 RegPCR9;
    const uint16 RegPCR10;
    const uint16 RegPCR11;
    const uint16 RegPCR12;
    const uint16 RegPCR13;
    const uint16 RegPCR14;
    const uint16 RegPCR15;
    const uint16 RegPCR16;
    const uint16 RegPCR17;
    const uint16 RegPCR18;
    const uint16 RegPCR19;
    const uint16 RegPCR20;
    const uint16 RegPCR21;
    const uint16 RegPCR22;
    const uint16 RegPCR23;
    const uint16 RegPCR24;
    const uint16 RegPCR25;
    const uint16 RegPCR26;
    const uint16 RegPCR27;
    const uint16 RegPCR28;
    const uint16 RegPCR29;
    const uint16 RegPCR30;

    //const uint16 RegPCR[31];

    /* FlexRay parameter gNumberoftaticslots */
    const uint16 gNumberOfStaticSlots;
    /* FlexRay parameter gNetworkManagementVectorLength */
    const uint8 gNetworkManagementVectorLength;
    /* pPayloadLengthDynMax */
    const uint8 pPayloadLengthDynMax;
    /* gPayloadLengthStatic */
    const uint8 gPayloadLengthStatic;
} Fr_CCLowLevelConfigSetType;

typedef struct
{
    /* Enable/Disable reporting of DEM messages */
    const uint32 state;
    /* ID of DEM message */
    const uint32 id;
} Fr_DemErrorType;

typedef struct
{
    /* Controller index of the FlexRay module */
    const uint32 CtrlIdx;
    /* Reference to array of the Hardware Configuration structures */
    const Fr_CCHardwareConfigType* const CCHardwareConfigPtr;
    /* Reference to array of Buffer Configuration structures */
    const Fr_CCBufferConfigSetType* const BufferConfigSetPtr;
    /* Reference to array of Low Level Configuration structures */
    const Fr_CCLowLevelConfigSetType* LowLevelConfigSetPtr;
    /* Reference to array of FlexRay POC Configuration parameters */
    const uint32* const  CCReadBackConfigSetPtr;
    /* Referece to FrDemCtrlTestResult */
    const Fr_DemErrorType* const FrDemCtrlTestResultPtr;
} Fr_CtrlCfgType;


typedef struct
{
    /* Transmit frame ID */
    const uint16 TxFrameID;
    /* Header CRC */
    const uint16 HeaderCRC;
    /* Payload length [in Words] */
    const uint8 TxPayloadLength;
    /* Transmission mode */
    const boolean TxChannelAEnable;
    /* Transmit channel B enable */
    const boolean TxChannelBEnable;
    /* Payload preamble */
    const boolean PayloadPreamble;
     /* Transmit cycle counter filter enable */
    const boolean TxCycleCounterFilterEnable;
    /* Transmit cycle counter filter value */
    const uint8 TxCycleCounterFilterValue;
    /* Transmit cycle counter filter mask */
    const uint8 TxCycleCounterFilterMask;
    /* Value of the FrIfAllowDynamicLSduLength parameter */
    const boolean AllowDynamicLength;
    /* DemEventId */
    const uint16 DemFTSlotStatus;
    /* DemFTSlotSTatusRefExist exist */
    const boolean DemFTSlotSTatusRefExist;
} Fr_CCTxBufferConfigType;


typedef struct
{
    /* Receive frame ID */
    const uint16 RxFrameID;
    /* Maximum payload length [in Words] - only for checking */
    const uint8 RxPayloadLength;
    /* Receive channel A enable */
    const boolean RxChannelAEnable;
    /* Receive channel B enable */
    const boolean RxChannelBEnable;
    /* Receive cycle counter filter enable */
    const boolean RxCycleCounterFilterEnable;
    /* Receive cycle counter filter value */
    const uint8 RxCycleCounterFilterValue;
    /* Receive cycle counter filter mask */
    const uint8 RxCycleCounterFilterMask;
    /* DemEventId */
    const uint16 DemFTSlotStatus;
    /* DemFTSlotSTatusRefExist exist */
    const boolean DemFTSlotSTatusRefExist;
} Fr_CCRxBufferConfigType;


typedef struct
{
    /* TRUE - Range Filter is enabled */
    const boolean RangeFilterEnable;
    /* Acceptance or Rejection mode */
    const Fr_CCFifoRangeFilterModeType RangeFilterMode;
     /* SID0 - Slot ID - Lower interval boundary */
    const uint16 RangeFilterLowerInterval;
    /* SID1 - Slot ID - Upper interval boundary */
    const uint16 RangeFilterUpperInterval;
} Fr_CCFifoRangeFiltersType;


typedef struct
{
    /* Selects the receive FIFO (FIFO A, FIFO B). */
    const Fr_CCFifoChannelType FIFOChannel;
    /* Configures the index of the first FIFO message buffer.*/
    const uint16 FIFOStartIndex;
    /* Configures the FIFO depth. */
    const uint8 FIFODepth;
    /* Configures the FIFO entry size [in Words]. */
    const uint8 FIFOEntrySize;
    /* Message ID filter mask value */
    const uint16 MessageIDFilterMask;
    /* Message ID filter match value */
    const uint16 MessageIDFilterMatch;
    /* Contains range filters configuration. */
    const Fr_CCFifoRangeFiltersType FIFORangeFiltersConfig[4];
} Fr_CCFifoConfigType;

#ifdef __cplusplus
}
#endif

#endif /* FR_GENERAL_TYPES_H */