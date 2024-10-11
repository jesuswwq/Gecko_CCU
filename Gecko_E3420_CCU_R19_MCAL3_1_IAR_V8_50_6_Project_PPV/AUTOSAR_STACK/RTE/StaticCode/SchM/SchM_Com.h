/*============================================================================*/
/*  Copyright (C) 2009-2011, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <SchM_Com.h>
 *  @brief      <Briefly describe file(one line)>
 *
 *  <Compiler: Cygwin C Compiler    MCU:--->
 *
 *  @author     <zheng fang>
 *  @date       <2013-5-10>
 */
/*============================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>         <AUTHOR>                    <REVISION LOG>
 *  V1.0.0      20130510        zheng fang                 Initial version
 *  V1.0.1      20150401        dongliang chen             Add COM_AREA_COMPLETE
 */
/*============================================================================*/

/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/
#define SCHM_COM_H_AR_MAJOR_VERSION 1U
#define SCHM_COM_H_AR_MINOR_VERSION 1U
#define SCHM_COM_H_AR_PATCH_VERSION 2U
#define SCHM_COM_H_SW_MAJOR_VERSION 1U
#define SCHM_COM_H_SW_MINOR_VERSION 0U
#define SCHM_COM_H_SW_PATCH_VERSION 0U

#ifndef SCHM_COM_H_
#define SCHM_COM_H_

#define WRITE_PROTECTION_AREA 1U

#define COM_AREA_COMPLETE

/*进入临界区宏函数定义*/
#define SchM_Enter_Com(Instance, AreaId)
/*进入临界区宏函数定义*/
#define SchM_Exit_Com(Instance, AreaId)

#endif /* SCHM_COM_H_ */
