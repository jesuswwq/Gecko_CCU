#ifdef __cplusplus
extern "C" {
#endif

/* All channel is logic channel */
#include "Sent.h"
#include "SchM_Sent.h"
#include "Det.h"
#include "mini_libc.h"

/* Version and Check Begin */
/* Version Info Begin */
#define SENT_C_VENDOR_ID    0x8C
#define SENT_C_AR_RELEASE_MAJOR_VERSION    4
#define SENT_C_AR_RELEASE_MINOR_VERSION    3
#define SENT_C_AR_RELEASE_REVISION_VERSION 1
#define SENT_C_SW_MAJOR_VERSION    1
#define SENT_C_SW_MINOR_VERSION    0
#define SENT_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((SENT_C_AR_RELEASE_MAJOR_VERSION != SENT_H_AR_RELEASE_MAJOR_VERSION)\
    || (SENT_C_AR_RELEASE_MINOR_VERSION != SENT_H_AR_RELEASE_MINOR_VERSION)\
    || (SENT_C_AR_RELEASE_REVISION_VERSION != SENT_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Sent.c and Sent.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((SENT_C_SW_MAJOR_VERSION != SENT_H_SW_MAJOR_VERSION)\
    || (SENT_C_SW_MINOR_VERSION != SENT_H_SW_MINOR_VERSION)\
    || (SENT_C_SW_PATCH_VERSION != SENT_H_SW_PATCH_VERSION))
#error "Opps, Sent.c and Sent.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((SENT_C_AR_RELEASE_MAJOR_VERSION != DET_H_AR_RELEASE_MAJOR_VERSION)\
    || (SENT_C_AR_RELEASE_MINOR_VERSION != DET_H_AR_RELEASE_MINOR_VERSION)\
    || (SENT_C_AR_RELEASE_REVISION_VERSION != DET_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Sent.c and Det.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((SENT_C_SW_MAJOR_VERSION != DET_H_SW_MAJOR_VERSION)\
    || (SENT_C_SW_MINOR_VERSION != DET_H_SW_MINOR_VERSION)\
    || (SENT_C_SW_PATCH_VERSION != DET_H_SW_PATCH_VERSION))
#error "Opps, Sent.c and Det.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((SENT_C_AR_RELEASE_MAJOR_VERSION != SENT_IP_H_AR_RELEASE_MAJOR_VERSION)\
    || (SENT_C_AR_RELEASE_MINOR_VERSION != SENT_IP_H_AR_RELEASE_MINOR_VERSION)\
    || (SENT_C_AR_RELEASE_REVISION_VERSION != SENT_IP_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Sent.c and Sent_Ip_E3.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((SENT_C_SW_MAJOR_VERSION != SENT_IP_H_SW_MAJOR_VERSION)\
    || (SENT_C_SW_MINOR_VERSION != SENT_IP_H_SW_MINOR_VERSION)\
    || (SENT_C_SW_PATCH_VERSION != SENT_IP_H_SW_PATCH_VERSION))
#error "Opps, Sent.c and Sent_Ip_E3.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

/**
 * @enum Sent_StateType
 * @brief Sent current driver status
*/
typedef enum {
    SENT_STATUS_UNINIT = 0,
    SENT_STATUS_INITED
} Sent_StateType;

/**
 * @enum Sent_ChannelStatusType
 * @brief Sent current channel status
*/
typedef enum {
    SENT_STATUS_UNINITIALIZED = 0,
    SENT_STATUS_INITIALIZED = 1,
    SENT_STATUS_RUNNING = 2,
    SENT_STATUS_STOPED = 3,
} Sent_ChannelStatusType;

#define SENT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sent_MemMap.h"

static VAR(Sent_StateType, SENT_VAR) Sent_DriverState;                                 /*! @brief current sent driver init state */
static P2CONST(Sent_ConfigType, AUTOMATIC, SENT_APPL_CONST) Sent_ptrConfig;            /*! @brief local saved Sent config pointer */
static VAR(uint8, SENT_VAR) Phy2LogMap[TIMER_MODULE_NUMBER][LOCAL_CHANNEL_NUMBER];     /*! @brief physical to logic channel map */
static VAR(Sent_ChannelStatusType, SENT_VAR) Sent_ChnStaus[SENT_NUM_CHANNELS];         /*! @brief all Sent channel status */

#define SENT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"

#if (SENT_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_ValidateCommon
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel,
    VAR(uint8, AUTOMATIC) ServiceID
);
#endif /* SENT_DEV_ERROR_DETECT */
LOCAL_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_CheckStartReciever
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel,
    VAR(uint8, AUTOMATIC) ServiceID
);
LOCAL_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_CheckStopReciever
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel,
    VAR(uint8, AUTOMATIC) ServiceID
);
LOCAL_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_CheckDeInit
(
    VAR(uint8, AUTOMATIC) ServiceID
);

#if (SENT_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief Sent_ValidateCommon
 * @details SWS_Sent_00022,check if the driver was initialized.
 * @param[in] Channel The logic channel.
 * @param[in] ServiceID Function ID.
 * @implements Sent_ValidateCommon
 * @return Std_ReturnType
 *   @retval E_OK
 *   @retval E_NOT_OK
 */
LOCAL_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_ValidateCommon
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel,
    VAR(uint8, AUTOMATIC) ServiceID
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    if (SENT_STATUS_UNINIT == Sent_DriverState) {
        (void)Det_ReportError\
        (\
         (uint16)SENT_MODULE_ID, \
         (uint8)SENT_INSTANCE_ID, \
         (uint8)ServiceID, \
         (uint8)SENT_E_UNINIT \
        );
        RetVal = E_NOT_OK;
    } else if (Channel >= SENT_NUM_CHANNELS) {
        (void)Det_ReportError\
        (\
         (uint16)SENT_MODULE_ID, \
         (uint8)SENT_INSTANCE_ID, \
         (uint8)ServiceID, \
         (uint8)SENT_E_PARAM_CHANNEL \
        );
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

#endif /* SENT_DEV_ERROR_DETECT */



LOCAL_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_CheckStartReciever
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel,
    VAR(uint8, AUTOMATIC) ServiceID
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    if (Sent_ChnStaus[Channel] == SENT_STATUS_UNINITIALIZED) {
#if (SENT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)SENT_MODULE_ID, \
         (uint8)SENT_INSTANCE_ID, \
         (uint8)ServiceID, \
         (uint8)SENT_E_PARAM_CHANNEL \
        );
#endif
        RetVal = E_NOT_OK;
    }

    return RetVal;
}


LOCAL_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_CheckStopReciever
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel,
    VAR(uint8, AUTOMATIC) ServiceID
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    if (Sent_ChnStaus[Channel] != SENT_STATUS_RUNNING) {
#if (SENT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)SENT_MODULE_ID, \
         (uint8)SENT_INSTANCE_ID, \
         (uint8)ServiceID, \
         (uint8)SENT_E_PARAM_CHANNEL \
        );
#endif
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

LOCAL_INLINE FUNC(Std_ReturnType, SENT_CODE) Sent_CheckDeInit
(
    VAR(uint8, AUTOMATIC) ServiceID
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    VAR(Sent_ChannelType, AUTOMATIC) Channel;

    for (Channel = 0; Channel < SENT_NUM_CHANNELS; Channel++) {
        if (Sent_ChnStaus[Channel] == SENT_STATUS_RUNNING) {
#if (SENT_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError\
            (\
             (uint16)SENT_MODULE_ID, \
             (uint8)SENT_INSTANCE_ID, \
             (uint8)ServiceID, \
             (uint8)SENT_E_PARAM_CHANNEL \
            );
#endif
            RetVal = E_NOT_OK;
        }
    }

    return RetVal;
}

/**
 * @brief This function initializes the driver.
 * @details This service is a non reentrant function used for driver initialization.
 * @param[in]  ConfigPtr Pointer to a selected configuration structure
 * @return   void
*/
FUNC(void, SENT_CODE) Sent_Init
(
    P2CONST(Sent_ConfigType, AUTOMATIC, SENT_APPL_CONST) ConfigPtr
)
{
    VAR(Sent_ChannelType, AUTOMATIC) Channel = 0U;

#if (SENT_DEV_ERROR_DETECT == STD_ON)

    if (SENT_STATUS_UNINIT == Sent_DriverState) {
#endif /* SENT_DEV_ERROR_DETECT */
        Sent_ptrConfig = ConfigPtr;
        Sent_Ip_SetBaseAddr();

        for (Channel = 0; Channel < SENT_NUM_CHANNELS; Channel++) {
            Sent_Ip_ChannelInit(Channel, &((*(Sent_ptrConfig->ptrChannelConfig))[Channel]));
            Phy2LogMap[(*(Sent_ptrConfig->ptrChannelConfig))[Channel].SentHwChannelConfig->u8TimerModule]\
            [(*(Sent_ptrConfig->ptrChannelConfig))[Channel].SentHwChannelConfig->u8HwChannel] = Channel;
            Sent_ChnStaus[Channel] = SENT_STATUS_INITIALIZED;
        }

        Sent_DriverState = SENT_STATUS_INITED;
#if (SENT_DEV_ERROR_DETECT == STD_ON)
    } else {
        (void)Det_ReportError\
        (\
         (uint16)SENT_MODULE_ID, \
         (uint8)SENT_INSTANCE_ID, \
         (uint8)SENT_INIT_ID, \
         (uint8)SENT_E_ALREADY_INITIALIZED \
        );
    }

#endif /* SENT_DEV_ERROR_DETECT */
}

#if (SENT_DEINIT_API == STD_ON)
/**
 * @brief This function de-initializes the SENT module.
 * @details This service is a Non reentrant function used for SENT De-Initialization
 * @return   none
*/
FUNC(void, SENT_CODE) Sent_DeInit
(
    void
)
{
    VAR(Sent_ChannelType, AUTOMATIC) Channel = 0U;

    if (SENT_STATUS_INITED == Sent_DriverState && E_OK == Sent_CheckDeInit(SENT_DEINIT_ID)) {
        for (Channel = 0; Channel < SENT_NUM_CHANNELS; Channel++) {
            Sent_Ip_ChannelDeInit(Channel, &((*(Sent_ptrConfig->ptrChannelConfig))[Channel]));
            Phy2LogMap[(*(Sent_ptrConfig->ptrChannelConfig))[Channel].SentHwChannelConfig->u8TimerModule]\
            [(*(Sent_ptrConfig->ptrChannelConfig))[Channel].SentHwChannelConfig->u8HwChannel] = 0u;
            Sent_ChnStaus[Channel] = SENT_STATUS_UNINITIALIZED;
        }

        Sent_ptrConfig = NULL_PTR;
        Sent_DriverState = SENT_STATUS_UNINIT;
    }
    
}
#endif /* SENT_DEINIT_API == STD_ON */


/**
 * @brief This function start the sent reciever.
 * @param[in] Channel The logic channel.
 * @implements Sent_StartReciever
 * @return none
 */
FUNC(void, SENT_CODE) Sent_StartReciever
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel
)
{
    if (E_OK == Sent_CheckStartReciever(Channel, SENT_START_RECIEVER_ID)) {
#if (SENT_DEV_ERROR_DETECT == STD_ON)

        if (E_OK == Sent_ValidateCommon(Channel, SENT_START_RECIEVER_ID)) {
#endif /* SENT_DEV_ERROR_DETECT == STD_ON */
            Sent_Ip_StartReciever(Channel, (*(Sent_ptrConfig->ptrChannelConfig))[Channel].SentHwChannelConfig);
            Sent_ChnStaus[Channel] = SENT_STATUS_RUNNING;
#if (SENT_DEV_ERROR_DETECT == STD_ON)
        }

#endif /* SENT_DEV_ERROR_DETECT == STD_ON */
    }
}

/**
 * @brief This function stop the sent reciever.
 * @param[in] Channel The logic channel.
 * @implements Sent_StopReciever
 * @return none
 */
FUNC(void, SENT_CODE) Sent_StopReciever
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel
)
{
    if (E_OK == Sent_CheckStopReciever(Channel, SENT_STOP_RECIEVER_ID)) {
#if (SENT_DEV_ERROR_DETECT == STD_ON)

        if (E_OK == Sent_ValidateCommon(Channel, SENT_STOP_RECIEVER_ID)) {
#endif /* SENT_DEV_ERROR_DETECT == STD_ON */
            Sent_Ip_StopReciever(Channel, (*(Sent_ptrConfig->ptrChannelConfig))[Channel].SentHwChannelConfig);
            Sent_ChnStaus[Channel] = SENT_STATUS_STOPED;
#if (SENT_DEV_ERROR_DETECT == STD_ON)
        }
#endif /* SENT_DEV_ERROR_DETECT == STD_ON */
    }
}

/**
 * @brief This function get the frame status.
 * @param[in] Channel The logic channel.
 * @implements Sent_GetFrameInfo
 * @return TRUE:is newest message; FALSE:is already read or not update data
 */
FUNC(boolean, SENT_CODE) Sent_GetFrameInfo
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel,
    P2VAR(Sent_ErrType, AUTOMATIC, SENT_APPL_DATA) pError,
    P2VAR(Sent_Frame, AUTOMATIC, SENT_APPL_DATA) pFrameInfo
)
{
    VAR(boolean, AUTOMATIC) RetVal = FALSE;

#if (SENT_DEV_ERROR_DETECT == STD_ON)

    if (E_OK == Sent_ValidateCommon(Channel, SENT_GET_FRAME_INFO_ID)) {
#endif /* SENT_DEV_ERROR_DETECT == STD_ON */

        /* check the channel status */
        if (Sent_ChnStaus[Channel] != SENT_STATUS_RUNNING) 
            return RetVal;

        SchM_Enter_Sent_SENT_EXCLUSIVE_AREA_00();

        RetVal = Sent_FrameInfo[Channel].bReadFlag;
        if (NULL_PTR != pError)
            *pError = Sent_FrameInfo[Channel].eError;

        if (NULL_PTR != pFrameInfo)
            memcpy(pFrameInfo, &Sent_FrameInfo[Channel].FrameInfo, sizeof(Sent_Frame));
        Sent_FrameInfo[Channel].bReadFlag = FALSE;

        SchM_Exit_Sent_SENT_EXCLUSIVE_AREA_00();

#if (SENT_DEV_ERROR_DETECT == STD_ON)
    }

#endif /* SENT_DEV_ERROR_DETECT == STD_ON */
    return RetVal;
}


/**
 * @brief Sent_IrqCommon
 * @details Handle all of the channel interrupt.
 * @implements Sent_IrqCommon
 * @return none
 */
FUNC(void, SENT_CODE) Sent_IrqCommon
(
    VAR(uint8, AUTOMATIC) eModule
)
{
    VAR(uint32, AUTOMATIC) Irq_Status;
    VAR(uint8, AUTOMATIC) j;
    VAR(uint8, AUTOMATIC) HwChannel;
    VAR(uint8, AUTOMATIC) Channel;
    Irq_Status = Sent_Ip_GetInterrupt(eModule);

    for (j = 0u; j < 4u; j++) {
        /* check dma req interrupt */
        if (((Irq_Status >> (20 + j)) & 0x1u) > 0u) {

            Sent_Ip_ClearInterrupt(eModule, (20 + j));
            HwChannel = j;
            Channel = Phy2LogMap[eModule][HwChannel];
            Sent_Ip_Parse_Massage(Channel, &(*(Sent_ptrConfig->ptrChannelConfig))[Channel]);
        }
    }
}

#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif

