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
 * @file  Crypto.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Crypto.h"
#include "CryIf_Cbk.h"
#include "Det.h"
#include "Crypto_Ip.h"
#include "Crypto_KeyManagement.h"
#include "Crypto_ShareMem.h"
#include "Crypto_Hsm.h"
#include "mini_libc.h"

/* Version and Check Begin */
/* Version Info Begin */
#define CRYPTO_C_VENDOR_ID                      (0x8C)
#define CRYPTO_C_AR_RELEASE_MAJOR_VERSION       (4)
#define CRYPTO_C_AR_RELEASE_MINOR_VERSION       (3)
#define CRYPTO_C_AR_RELEASE_REVISION_VERSION    (1)
#define CRYPTO_C_SW_MAJOR_VERSION               (1)
#define CRYPTO_C_SW_MINOR_VERSION               (0)
#define CRYPTO_C_SW_PATCH_VERSION               (0)
/* Version Info End */
/* Version and Check End */

#define CRYPTO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

Crypto_DriverStateType Crypto_gDriverState;

#define CRYPTO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

/**
 * internal function, the paramter 'objectId' is the internal array index.
*/
static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Process
(
    VAR(uint32, AUTOMATIC)objectId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
);

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON )
static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_JobPrimitiveVerify
(
    VAR(uint32, AUTOMATIC)objectId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
);
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON )
static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_JobPrimitiveVerify
(
    VAR(uint32, AUTOMATIC)objectId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    uint32 i;
    uint8 x = 0u;
    Crypto_ObjectType *current_crypto_obj;
    Crypto_ContextType *current_context;

    if ((CRYPTO_SECCOUNTERINCREMENT == job->jobPrimitiveInfo->primitiveInfo->service) ||
        (CRYPTO_SECCOUNTERREAD == job->jobPrimitiveInfo->primitiveInfo->service)) {
        return E_OK;
    }

    RetVal = Crypto_Ip_GetCryptoDriverObj(objectId, &current_crypto_obj, &current_context);
    if(RetVal == E_OK){
        for (i = 0UL; i < current_crypto_obj->u32CryptoPrimitivesSize; i++) {
            if ((job->jobPrimitiveInfo->primitiveInfo->service ==
                current_crypto_obj->pCryptoPrimitives[i].eService) &&
                (job->jobPrimitiveInfo->primitiveInfo->algorithm.family ==
                current_crypto_obj->pCryptoPrimitives[i].eFamily) &&
                (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode ==
                current_crypto_obj->pCryptoPrimitives[i].eMode)) {
                x = 1u;
                break;
            }
        }
    }

    if (0x0UL == x) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_PROCESS_JOB_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    }

    return RetVal;
}
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */

static FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Process
(
    VAR(uint32, AUTOMATIC) objectId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    Crypto_ObjectType *current_crypto_obj;
    Crypto_ContextType *current_context;

    RetVal = Crypto_Ip_GetCryptoDriverObj(objectId, &current_crypto_obj, &current_context);

    /*check crypto driver obj support job primitive or not*/

    if(RetVal == E_OK){
        if(current_context->CryptoDriverObjState == CRYPTO_IP_CRYPTODRIVEROBJ_STATE_BUSY){
            /*crypto driver obj is busy*/
            if(CRYPTO_PROCESSING_SYNC == job->jobPrimitiveInfo->processingType){
                /*job type is synchronous*/
                RetVal = CRYPTO_E_BUSY;
            }else{
                /*job type is asynchronous*/
                if((CRYPTO_OPERATIONMODE_UPDATE == job->jobPrimitiveInputOutput.mode)||
                   (CRYPTO_OPERATIONMODE_FINISH == job->jobPrimitiveInputOutput.mode)){
                    RetVal = CRYPTO_E_BUSY;
                }else{
                    /*operateion mode is start, or start update, or start update finish*/
                    /*add job in job queue*/
                    RetVal = Crypto_Ip_JobPushQueue(objectId, job);
                }
            }
        }else{
            /*crypto driver obj is idle*/
            if(current_context->aJobInfo.aJob.jobState == CRYPTO_JOBSTATE_IDLE){
                /*job status is idle*/
                if(current_context->aJobsQueueInfo.u32JobQueueUsedSize == 0){
                    /*job queue is empty*/
                    if((CRYPTO_OPERATIONMODE_UPDATE == job->jobPrimitiveInputOutput.mode)||
                        (CRYPTO_OPERATIONMODE_FINISH == job->jobPrimitiveInputOutput.mode)){
                            if (CRYPTO_IP_AJOB_STATE_CANCEL == current_context->aJobInfo.CurrentaJobState) {
                                RetVal = CRYPTO_E_JOB_CANCELED;
                            } else {
                                RetVal = E_NOT_OK;
                            }
                    }else{
                        if(CRYPTO_PROCESSING_SYNC == job->jobPrimitiveInfo->processingType){
                            /*process start job*/
                            current_context->JobId = job->jobId;
                            RetVal = Crypto_Ip_ProcessJob(objectId, job, current_context);
                        } else {
                            RetVal = Crypto_Ip_JobPushQueue(objectId, job);
                        }
                    }
                }else{
                    /*job queue is not empty*/
                    if(CRYPTO_PROCESSING_SYNC == job->jobPrimitiveInfo->processingType){
                        /*job type is synchronous*/
                        if((CRYPTO_OPERATIONMODE_UPDATE == job->jobPrimitiveInputOutput.mode)||
                            (CRYPTO_OPERATIONMODE_FINISH == job->jobPrimitiveInputOutput.mode)){
                            if (CRYPTO_IP_AJOB_STATE_CANCEL == current_context->aJobInfo.CurrentaJobState) {
                                RetVal = CRYPTO_E_JOB_CANCELED;
                            } else {
                                RetVal = E_NOT_OK;
                            }
                        }else{
                            /*process start job*/
                            current_context->JobId = job->jobId;
                            RetVal = Crypto_Ip_ProcessJob(objectId, job, current_context);
                        }
                    }else{
                        /*job type is asynchronous*/
                        /*add job in job queue*/
                        RetVal = Crypto_Ip_JobPushQueue(objectId, job);
                    }
                }
            }else{
                /*job status is active*/
                if (current_context->JobId == job->jobId && CRYPTO_PROCESSING_SYNC == job->jobPrimitiveInfo->processingType) {
                    /*current job*/
                    RetVal = Crypto_Ip_ProcessJob(objectId, job, current_context);
                }else{
                    /*job is different with current job*/
                    /*add job in job queue*/
                    RetVal = Crypto_Ip_JobPushQueue(objectId, job);
                }

            }
        }

    }
    return RetVal;
}

/**********************************************************************************/
#if ( CRYPTO_VERSION_INFO_API == STD_ON )
/**
 * @brief Get the Crypto module version
 * @details Get version
 * @param[out]  version
 * @return   none
*/
FUNC(void, CRYPTO_CODE) Crypto_GetVersionInfo
(
    P2VAR( Std_VersionInfoType, AUTOMATIC, CRYPTO_APPL_DATA ) pVersioninfo
)
{
    if (NULL != pVersioninfo) {
       pVersioninfo->vendorID = CRYPTO_C_VENDOR_ID;
       pVersioninfo->moduleID = CRYPTO_MODULE_ID;
       pVersioninfo->sw_major_version = CRYPTO_C_SW_MAJOR_VERSION;
       pVersioninfo->sw_minor_version = CRYPTO_C_SW_MINOR_VERSION;
       pVersioninfo->sw_patch_version = CRYPTO_C_SW_PATCH_VERSION;
    } else {
        /* do nothing */
    }
}
#endif  /* CRYPTO_VERSION_INFO_API == STD_ON */

FUNC(void, CRYPTO_CODE) Crypto_Init
(
    void
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    VAR(uint32, AUTOMATIC) i;

    if (CRYPTO_DRIVER_UNINIT == Crypto_gDriverState) {
        RetVal = Crypto_Ip_Init();
        if ((Std_ReturnType)E_OK == RetVal) {
            for (i = 1UL; i <= CRYPTO_DRIVER_OBJ_NUM; i++) {
                Crypto_Ip_InitDriverObjContext(i);
            }

            ShareMem_Init();
            /* After initialization the crypto driver is in IDLE state */
            Crypto_gDriverState = CRYPTO_DRIVER_IDLE;
        }
#if(CRYPTO_DEV_ERROR_DETECT == STD_ON)
        else {
            Det_ReportError( (uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_INIT_ID,
                             (uint8)CRYPTO_E_INIT_FAILED );
        }

#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    }
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_ProcessJob
(
    VAR(uint32, AUTOMATIC) u32ObjectId,
    Crypto_JobType *pJob
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal;

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)

    if (CRYPTO_DRIVER_UNINIT == Crypto_gDriverState) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_PROCESS_JOB_ID, \
         (uint8)CRYPTO_E_UNINIT \
        );
        RetVal = E_NOT_OK;
    } else if (u32ObjectId > CRYPTO_DRIVER_OBJ_NUM) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_PROCESS_JOB_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else if (NULL_PTR == pJob) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_PROCESS_JOB_ID, \
         (uint8)CRYPTO_E_PARAM_POINTER \
        );
        RetVal = E_NOT_OK;
    } else if (E_NOT_OK == Crypto_JobPrimitiveVerify(u32ObjectId, pJob)) {
        RetVal = E_NOT_OK;
    } else {
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
        /*get crypto driver obj*/

        /*process job*/
        RetVal = Crypto_Process(u32ObjectId, pJob);
#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
    }

#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_CancelJob
(
    VAR(uint32, AUTOMATIC) u32ObjectId,
    P2VAR(Crypto_JobInfoType, CSM_VAR, CSM_APPL_CONST) pJob
)
{
    Std_ReturnType RetVal = E_OK;

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)

    if (CRYPTO_DRIVER_UNINIT == Crypto_gDriverState) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_PROCESS_CANCEL_JOB_ID, \
         (uint8)CRYPTO_E_UNINIT \
        );
        RetVal = E_NOT_OK;
    } else if (u32ObjectId > CRYPTO_DRIVER_OBJ_NUM) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_PROCESS_CANCEL_JOB_ID, \
         (uint8)CRYPTO_E_PARAM_HANDLE \
        );
        RetVal = E_NOT_OK;
    } else if (NULL_PTR == pJob) {
        (void)Det_ReportError\
        (\
         (uint16)CRYPTO_MODULE_ID, \
         (uint8)CRYPTO_INSTANCE_ID, \
         (uint8)CRYPTO_PROCESS_CANCEL_JOB_ID, \
         (uint8)CRYPTO_E_PARAM_POINTER \
        );
        RetVal = E_NOT_OK;
    } else {
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    Crypto_QueueNodeType *JobsQueueNode;
    Crypto_QueueNodeType *JobsQueueNode_temp;
    Crypto_ObjectType *current_crypto_obj;
    Crypto_ContextType *current_context;
    uint32 i, size;

    /*get crypto driver obj*/
    RetVal = Crypto_Ip_GetCryptoDriverObj(u32ObjectId, &current_crypto_obj, &current_context);

    if (RetVal == E_OK) {
        /* current job */
        if (current_context->JobId == pJob->jobId) {
            current_context->JobId = 0;
            current_context->CryptoDriverObjState = 0;
            current_context->aJobInfo.nextOpMode = 0;
            current_context->aJobInfo.CurrentaJobState = CRYPTO_IP_AJOB_STATE_CANCEL;
            mini_memclr_s((uint8 *)&(current_context->aJobInfo.aJob), sizeof(Crypto_JobType));
        }

        /* job in queue */
        size = current_context->aJobsQueueInfo.u32JobQueueUsedSize;
        for (i = 0; i < size; i++) {
            /*get use node */
            JobsQueueNode = current_context->aJobsQueueInfo.pHeadUsedJobQueue;
            if (JobsQueueNode == NULL)
                return E_NOT_OK;

            if (JobsQueueNode->aJob.jobId == pJob->jobId) {
                /*update used node list, delet first node*/
                current_context->aJobsQueueInfo.pHeadUsedJobQueue = current_context->aJobsQueueInfo.pHeadUsedJobQueue->pJobQueueNodeNext;

                JobsQueueNode->pJobQueueNodePre->pJobQueueNodeNext = JobsQueueNode->pJobQueueNodeNext;
                JobsQueueNode->pJobQueueNodeNext->pJobQueueNodePre = JobsQueueNode->pJobQueueNodePre;

                /*add job node into emptyqueuelist*/
                JobsQueueNode_temp = current_context->aJobsQueueInfo.pHeadEmptyJobQueue;
                if (JobsQueueNode_temp == NULL_PTR) {
                    /*empty queue is empty*/
                    JobsQueueNode->pJobQueueNodeNext = JobsQueueNode;
                    JobsQueueNode->pJobQueueNodePre = JobsQueueNode;
                } else {
                        /*pre node link*/
                        JobsQueueNode_temp->pJobQueueNodePre->pJobQueueNodeNext = JobsQueueNode;
                        JobsQueueNode->pJobQueueNodePre = JobsQueueNode_temp->pJobQueueNodePre;
                        /*next node link*/
                        JobsQueueNode->pJobQueueNodeNext = JobsQueueNode_temp;
                        JobsQueueNode_temp->pJobQueueNodePre = JobsQueueNode;
                }

                current_context->aJobsQueueInfo.pHeadEmptyJobQueue = JobsQueueNode;
                current_context->aJobsQueueInfo.u32JobQueueUsedSize--;

                if (current_context->aJobsQueueInfo.u32JobQueueUsedSize == 0) {
                    current_context->aJobsQueueInfo.pHeadUsedJobQueue = NULL;
                }
            }
        }
    }
#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
    }

#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */

    return RetVal;
}

/*asynchronous job process*/
FUNC(void, CRYPTO_CODE) Crypto_MainFunction
(
    void
)
{
    VAR(uint32, AUTOMATIC) i;
    Crypto_ObjectType *current_crypto_obj;
    Crypto_ContextType *current_context;
    Crypto_JobType job;
    Std_ReturnType RetVal = E_OK;
    uint32 res = 0;

    if (CRYPTO_DRIVER_UNINIT == Crypto_gDriverState) {
        /* crypto is uninit */
    }else{
        mini_memclr_s((uint8 *)&job, sizeof(Crypto_JobType));
        /* check all obj */
        for (i = 1UL; i <=CRYPTO_DRIVER_OBJ_NUM; i++) {
            /* check obj is busy */
            RetVal = Crypto_Ip_GetCryptoDriverObj(i, &current_crypto_obj, &current_context);

            /*check crypto driver obj support job primitive or not*/

            if(RetVal == E_OK){
                if((current_context->CryptoDriverObjState == CRYPTO_IP_CRYPTODRIVEROBJ_STATE_BUSY)||
                (current_context->aJobInfo.aJob.jobId != 0)){
                    /*crypto obj on busy state or job on active state*/
                    continue;
                }else{
                    res = Crypto_Check_Response();
                    if (CRYPTO_HSM_BUSY != res && CRYPTO_HSM_IDLE != res) {
                        /* get result */
                        CryIf_CallbackNotification(&job, RetVal);
                    } else if (CRYPTO_HSM_BUSY == res) {
                        /* crypto is working */
                        break;
                    }
                    /* get job from jobqueue */
                    while(Crypto_Ip_JobPopQueue(i, &job) == E_OK)
                    {
                        /* process job*/
                        if((CRYPTO_OPERATIONMODE_UPDATE == job.jobPrimitiveInputOutput.mode)||
                           (CRYPTO_OPERATIONMODE_FINISH == job.jobPrimitiveInputOutput.mode)){

                        }else{
                            /*process start job, update context info*/
                            current_context->JobId = job.jobId;
                        }
                        RetVal = Crypto_Ip_ProcessJob(i, &job, current_context);
                        CryIf_CallbackNotification(&job, RetVal);
                    }
                    mini_memclr_s((uint8 *)&job, sizeof(Crypto_JobType));
                }
            }
        }
    }
}

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif
