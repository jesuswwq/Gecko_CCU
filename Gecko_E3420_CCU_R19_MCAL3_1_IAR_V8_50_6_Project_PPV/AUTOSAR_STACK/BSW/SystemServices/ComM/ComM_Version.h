/***********************************************************************************************************************
**                                                                                                                    **
** Copyright (C) iSOFT   (2022)                                                                                       **
**                                                                                                                    **
** All rights reserved.                                                                                               **
**                                                                                                                    **
** This document contains proprietary information belonging to iSOFT.Passing on and copying of this document, and     **
** communication of its contents is not permitted without prior written authorization.                                **
**                                                                                                                    **
************************************************************************************************************************
**                                                                                                                    **
**  @file               : ComM_Version.h                                                                              **
**  @version            : V1.0.0                                                                                      **
**  @author             : darren.zhang                                                                                **
**  @date               : 2022/01/07                                                                                  **
**  @vendor             : isoft                                                                                       **
**  @description        : Communication Manager                                                                       **
**  @specification(s)   : AUTOSAR classic Platform R19-11                                                             **
**                                                                                                                    **
***********************************************************************************************************************/

#ifndef COMM_VERSION_H_
#define COMM_VERSION_H_

/*=================================================[inclusions]=======================================================*/

/*====================================================[macros]========================================================*/

/*------------------------------------------[AUTOSAR vendor identification]-------------------------------------------*/

#if (defined COMM_VENDOR_ID)
#error COMM_VENDOR_ID is already defined
#endif
/** \brief AUTOSAR vendor identification: isoft software */
#define COMM_VENDOR_ID 62u

/*-----------------------------------------[AUTOSAR module identification]--------------------------------------------*/

#if (defined COMM_MODULE_ID)
#error COMM_MODULE_ID already defined
#endif
/** \brief AUTOSAR module identification */
#define COMM_MODULE_ID 12U

#if (defined COMM_INSTANCE_ID)
#error COMM_INSTANCE_ID already defined
#else
#define COMM_INSTANCE_ID 0u
#endif
/*--------------------------------------[AUTOSAR release version identification]--------------------------------------*/

#if (defined COMM_AR_RELEASE_MAJOR_VERSION)
#error COMM_AR_RELEASE_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR release major version */
#define COMM_AR_RELEASE_MAJOR_VERSION 4u

#if (defined COMM_AR_RELEASE_MINOR_VERSION)
#error COMM_AR_RELEASE_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR release minor version */
#define COMM_AR_RELEASE_MINOR_VERSION 5u

#if (defined COMM_AR_RELEASE_REVISION_VERSION)
#error COMM_AR_RELEASE_REVISION_VERSION already defined
#endif
/** \brief AUTOSAR release revision version */
#define COMM_AR_RELEASE_REVISION_VERSION 0u

/*-------------------------------------[AUTOSAR module version identification]----------------------------------------*/

#if (defined COMM_SW_MAJOR_VERSION)
#error COMM_SW_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module major version */
#define COMM_SW_MAJOR_VERSION 2u

#if (defined COMM_SW_MINOR_VERSION)
#error COMM_SW_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module minor version */
#define COMM_SW_MINOR_VERSION 1u

#if (defined COMM_SW_PATCH_VERSION)
#error COMM_SW_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module patch version */
#define COMM_SW_PATCH_VERSION 8u

/*----------------------------------[AUTOSAR config depend on version identification]---------------------------------*/
#if (defined COMM_SW_CFG_DEP_MAJOR_VERSION)
#error COMM_SW_CFG_DEP_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module depend on configure major version */
#define COMM_SW_CFG_DEP_MAJOR_VERSION 2u

#if (defined COMM_SW_CFG_DEP_MINOR_VERSION)
#error COMM_SW_CFG_DEP_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module depend on configure minor version */
#define COMM_SW_CFG_DEP_MINOR_VERSION 1u

#if (defined COMM_SW_CFG_DEP_PATCH_VERSION)
#error COMM_SW_CFG_DEP_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module depend on configure minor patch version */
#define COMM_SW_CFG_DEP_PATCH_VERSION 7u

/*=============================================[type definitions]=====================================================*/

/*========================================[external function declarations]============================================*/

/*=========================================[internal function declarations]===========================================*/

/*==============================================[external constants]==================================================*/

/*==============================================[internal constants]==================================================*/

/*=================================================[external data]====================================================*/

/*=================================================[internal data]====================================================*/

/*==========================================[external function definitions]===========================================*/

/*==========================================[internal function definitions]===========================================*/

#endif /* COMM_VERSION_H_ */
