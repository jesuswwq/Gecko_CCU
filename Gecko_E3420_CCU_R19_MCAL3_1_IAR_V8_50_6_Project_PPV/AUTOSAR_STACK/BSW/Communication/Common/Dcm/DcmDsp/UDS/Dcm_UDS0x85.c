/******************************************************************************
**                                                                           **
** Copyright (C) iSOFT   (2022)                                              **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to iSOFT.        **
** Passing on and copying of this document, and communication                **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
**************************************************************************** **
**                                                                           **
**  FILENAME    :                                                            **
**                                                                           **
**  Created on  : 2020/5/6 14:29:43                                          **
**  Author      : tao.yu                                                     **
**  Vendor      :                                                            **
**  DESCRIPTION :                                                            **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                      **
**                                                                           **
**************************************************************************** */
#include "UDS.h"

/****************************************************************
                 UDS:ControlDTCSetting (85 hex) service
 ***************************************************************/
#if (STD_ON == DCM_UDS_SERVICE0X85_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0X85ServiceConditionCheck(
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 MsgCtrlId;
    Std_ReturnType ret = E_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */

    /*if the required protocol is configured,get the index of runtime datum*/
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check,check whether the current session supports the request service*/
    ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_CONTROL_DTC_SETTING);
    if (E_NOT_OK == ret)
    {
        /*the current session does not support the request service,send NRC = 0x7F*/
        *ErrorCode = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
    }
#endif
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*security check,check whether the current security supports the request service*/
        ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_CONTROL_DTC_SETTING);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif

    if ((E_OK == ret) && (Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen < DCM_UDS_REQ_DATA_MINLENGTH))
    {
        /*the length of massage is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
	{
		ret = RTE_PreConditonCheck(Dcm_MsgCtrl[MsgCtrlId].SID,Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData);
		if (E_OK != ret)
		{
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			ret = E_NOT_OK;
		}
	}
    if ((E_OK == ret)
        && ((DCM_UDS0X85_ON != Dcm_MsgCtrl[MsgCtrlId].Subfunction)
            && (DCM_UDS0X85_OFF != Dcm_MsgCtrl[MsgCtrlId].Subfunction)))
    {
        /*the required sub-function is not supported,send NRC 0x12*/
        *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        ret = E_NOT_OK;
    }

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*session check,check whether the current session supports the request service*/
        ret = DsdInternal_SubSesCheck(ProtocolCtrlId, SID_CONTROL_DTC_SETTING);
        if (E_NOT_OK == ret)
        {
            /*the current session does not support the request sub service,send NRC = 0x7E*/
            *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
        }
    }
#endif
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*security check,check whether the current security supports the request service*/
        ret = DsdInternal_SubSecurityCheck(ProtocolCtrlId, SID_CONTROL_DTC_SETTING);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif
    if (E_OK == ret)
    {
        if ((Dcm_DspCfg.pDcmDspControlDTCSetting != NULL_PTR)
            && (TRUE == Dcm_DspCfg.pDcmDspControlDTCSetting->DcmSupportDTCSettingControlOptionRecord))
        {
            if ((0u != ((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen - DCM_UDS0X85_REQ_DATA_MINLENGTH) % 3u))
                || (Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen < DCM_UDS0X85_REQ_DATA_DTC_MINLENGTH))
            {
                /*the length of massage is not correct,send NRC 0x13*/
                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                ret = E_NOT_OK;
            }
        }
        else
        {
            if ((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen) != DCM_UDS0X85_REQ_DATA_MINLENGTH)
            {
                /*the length of massage is not correct,send NRC 0x13*/
                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                ret = E_NOT_OK;
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE)
Dcm_UDS0x85(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 MsgCtrlId;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 subFunc;
    uint32 Offset;
    uint32 groupOfDTC;
    uint32 index;
    Std_ReturnType ret;
    Dem_ReturnControlDTCSettingType returnCtrlDtcSetting = DEM_CONTROL_DTC_SETTING_OK;
    uint32 numOfDTC;

    DCM_UNUSED(OpStatus);
    ret = Dcm_Uds0X85ServiceConditionCheck(ProtocolCtrlId, ErrorCode);

    if (E_OK == ret)
    {
        /*get the sub-function*/
        MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
        subFunc = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1];

        /*the request message does not contain DTCSettingControlOptionRecord*/
        if (DCM_UDS0X85_REQ_DATA_MINLENGTH == Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)
        {
            /*check the sub-function*/
            if (DCM_UDS0X85_ON == subFunc)
            {
                /*invoke the corresponding API provided by DEM*/
                returnCtrlDtcSetting = Dem_DcmEnableDTCSetting(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);
                if (DEM_CONTROL_DTC_SETTING_OK == returnCtrlDtcSetting)
                {
                    SchM_Switch_DcmControlDTCSetting(RTE_MODE_DcmControlDTCSetting_ENABLEDTCSETTING);
                }
            }
            if (DCM_UDS0X85_OFF == subFunc)
            {
                /*invoke the corresponding API provided by DEM*/
                returnCtrlDtcSetting = Dem_DcmDisableDTCSetting(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);
            }
        }
        else if (0u == ((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen - DCM_UDS0X85_REQ_DATA_MINLENGTH) % 3u))
        {
            /*the request message contains DTCSettingControlOptionRecord*/
            numOfDTC = (Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen - 2UL) / 3UL;
            /*check the sub-function*/
            if (DCM_UDS0X85_ON == subFunc)
            {
                /*get and assemble DTC, high byte first*/
                for (index = 0; (index < numOfDTC) && (DEM_CONTROL_DTC_SETTING_OK == returnCtrlDtcSetting); index++)
                {
                    groupOfDTC = (((uint32)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u + (3u * index)])) << 16u)
                                 | (((uint32)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3u + (3u * index)])) << 8u)
                                 | ((uint32)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4u + (3u * index)]));
                    /*invoke the corresponding API provided by DEM*/
                    returnCtrlDtcSetting = Dem_DcmEnableDTCSetting(groupOfDTC, DEM_DTC_KIND_ALL_DTCS);
                }
            }
            /*get and assemble DTC, high byte first*/
            for (index = 0; (index < numOfDTC) && (DCM_UDS0X85_OFF == subFunc)
                            && (DEM_CONTROL_DTC_SETTING_OK == returnCtrlDtcSetting);
                 index++)
            {
                groupOfDTC = (((uint32)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u + (3u * index)])) << 16u)
                             | (((uint32)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3u + (3u * index)])) << 8u)
                             | ((uint32)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4u + (3u * index)]));
                /*invoke the corresponding API provided by DEM*/
                returnCtrlDtcSetting = Dem_DcmDisableDTCSetting(groupOfDTC, DEM_DTC_KIND_ALL_DTCS);
                if (DEM_CONTROL_DTC_SETTING_OK == returnCtrlDtcSetting)
                {
                    SchM_Switch_DcmControlDTCSetting(RTE_MODE_DcmControlDTCSetting_DISABLEDTCSETTING);
                }
            }
        }
        else
        {
            /*Nothing to do ,shall never in*/
        }
        switch (returnCtrlDtcSetting)
        {
        case DEM_CONTROL_DTC_SETTING_OK:
            /*the processing is successful,assemble positive response*/
            TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
            TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
            Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
            /* check tx data length */
            if ((0x02u) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
            {
                /*Pdu length is bigger than buffer size,ignore the request message */
                *ErrorCode = DCM_E_RESPONSETOOLONG;
                ret = E_NOT_OK;
            }
            else
            {
                SchM_Enter_Dcm(Dcm_Channel);
                Dcm_Channel[Offset] = 0xC5;         /*response SID*/
                Dcm_Channel[Offset + 1u] = subFunc; /*echo of 0 - 6 bits of sub-function*/
                SchM_Exit_Dcm(Dcm_Channel);
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = 0x02;
                Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = 0x02;
                Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
                SchM_Exit_Dcm(Dcm_MsgCtrl);
                DsdInternal_ProcessingDone(ProtocolCtrlId);
            }
            break;
        case DEM_CONTROL_DTC_SETTING_N_OK:
            /*the processing is not successful,send NRC 0x22*/
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
            break;
        case DEM_CONTROL_DTC_WRONG_DTCGROUP:
        default:
            /*DTCSettingControlOptionRecord error,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
            break;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
