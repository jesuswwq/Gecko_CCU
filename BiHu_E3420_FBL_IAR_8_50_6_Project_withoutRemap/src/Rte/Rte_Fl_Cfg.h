/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Fl_Cfg.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_Fl_Cfg Module>
 *
 *  @author     <your Name>
 *  @date       <2023-12-04>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_FL_CFG_H
#define RTE_FL_CFG_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
/*
 * #define RTE_FL_CFG_C
 */
/*@}*/
#ifndef RTE_FL_CFG_C
#define RTE_FL_CFG_EXPT extern
#else
#define RTE_FL_CFG_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
/*=======[ Exported define ]==================================================*/
/* CUSTOM DEFINE Start address,
 * the start code of APP.
 * @type:uint32
 */
/*      PFLASH                            INFO                                          */
#define RTE_PFLASH_BASE_ADDR             (FL_APP_START_ADDR)
#define RTE_PFLASH_MAX_SIZE              (0x400000UL)
#define RTE_PFLASH_SECTOR_SIZE           (0x40000UL)
#define RTE_PFLASH_PAGE_SIZE             (256UL)
#define RTE_PFLASH_READ_PAGE_SIZE        (1UL)
/*      DFLASH                            INFO                                          */
#define RTE_DFLASH_BASE_ADDR              (FeeBlockConfiguration_NvmInfo)
#define RTE_DFLASH_MAX_SIZE               (FeeBlockConfiguration_FingerPrintB)
#define RTE_DFLASH_SECTOR_SIZE            (0x10UL)
#define RTE_DFLASH_PAGE_SIZE              (0x8UL)
#define RTE_DFLASH_READ_PAGE_SIZE         (0x8UL)
/*      APP                               CFG                                           */
#define RTE_CFG_APP_START_FLASH_OFFSET    (0x700000UL)
#define RTE_CFG_APP_START_FLASH_ADDR      (RTE_PFLASH_BASE_ADDR)
#define RTE_CFG_APP_START_FLASH_END       (RTE_PFLASH_MAX_SIZE+RTE_PFLASH_BASE_ADDR)
#define RTE_CFG_APP_START_RAM_ADDR        (0UL)
#define RTE_CFG_APP_START_RAM_END         (0UL)
/*      DFLASH                            DATA                                          CFG*/
#define RTE_DATA_NVMINFO_ADDR             (FeeBlockConfiguration_NvmInfo)
#define RTE_DATA_NVMINFO_LEN              (sizeof(Rte_FL_NvmInfoType))
#define RTE_DATA_PROGRAM_COUNTER_ADDR     (FeeBlockConfiguration_ProgramAttempt)
#define RTE_DATA_PROGRAM_COUNTER_LEN      (2UL)
#define RTE_DATA_PROGRAM_SUC_COUNTER_ADDR (FeeBlockConfiguration_ProgramSuccess)
#define RTE_DATA_PROGRAM_SUC_COUNTER_LEN  (2UL)
#define RTE_DATA_SEC_ERR_COUNTER_ADDR     (FeeBlockConfiguration_SecurityAccess)
#define RTE_DATA_SEC_ERR_COUNTER_LEN      (2UL)
#define RTE_DATA_FINGER_ADDR              (FeeBlockConfiguration_FingerPrint)
#define RTE_DATA_FINGER_LEN               (FL_FINGER_PRINT_LENGTH)
#define RTE_DATA_FACTORY_ADDR             (FeeBlockConfiguration_Factory)
#define RTE_DATA_FACTORY_LEN              (1UL)
#define RTE_DATA_CLIENT_ERR_ADDR          (0UL)
#define RTE_DATA_CLIENT_ERR_LEN           (0UL)
#define RTE_DATA_PROGRAM_FLAG_ADDR        (0x10000)
#define RTE_DATA_PROGRAM_FLAG_LEN         (0x8UL)
#define RTE_DATA_RESET_JUMP_FLAG_ADDR     (0x10008)
#define RTE_DATA_RESET_JUMP_FLAG_LEN      (0x8UL)
#define RTE_DATA_VECTOR_APP_ADDR          (0x10010)
#define RTE_DATA_VECTOR_APP_LEN           (0x8UL)
#define RTE_DATA_FORC_SWAP_TCM_ADDR       (0x10018)
#define RTE_DATA_FORC_SWAP_TCM_len        (0x8UL)
#define RTE_DATA_FINGER_TO_ACT_TCM_ADDR   (0x10020)
#define RTE_DATA_FINGER_TO_ACT_TCM_LEN    (0x10UL)
#define RTE_DATA_FINGER_TO_IACT_TCM_ADDR  (0x10030)
#define RTE_DATA_FINGER_TO_IACT_TCM_LEN   (0x10UL)

#define RTE_DATA_RESETCAUSE_TCM_ADDR  (0x10040)
#define RTE_DATA_RESETCAUSE_TCM_LEN   (0x8UL)

#define RTE_DATA_A_PART_COUNT_ADDR        (FeeBlockConfiguration_A_Counter)
#define RTE_DATA_A_PART_COUNT_LEN         (1)
#define RTE_DATA_B_PART_COUNT_ADDR        (FeeBlockConfiguration_B_Counter)
#define RTE_DATA_B_PART_COUNT_LEN         (1)
#define RTE_DATA_FORC_SWAP_ADDR           (FeeBlockConfiguration_ForcSwap)
#define RTE_DATA_FORC_SWAP_LEN            (1)
#define RTE_DATA_NVMINFO_B_ADDR           (FeeBlockConfiguration_NvmInfoB)
#define RTE_DATA_NVMINFO_B_LEN            (sizeof(Rte_FL_NvmInfoType))
#define RTE_DATA_FINGERB_ADDR             (FeeBlockConfiguration_FingerPrintB)
#define RTE_DATA_FINGERB_LEN              (FL_FINGER_PRINT_LENGTH)
/*      DFLASH                            DID                                           CFG*/
#define RTE_DATA_DIDF15A_ADDR             (RTE_DATA_FINGER_ADDR)
#define RTE_DATA_DIDF15A_LEN              (RTE_DATA_FINGER_LEN)
#define RTE_DATA_DIDF15B_ADDR             (RTE_DATA_FINGERB_ADDR)
#define RTE_DATA_DIDF15B_LEN              (RTE_DATA_FINGERB_LEN)
/*      DFLASH                            DATA                                          INFO  CFG*/
#define RTE_CFG_JUMP_APP_RESET_ENABLE     STD_ON
#define RTE_CFG_JUMP_APP_REQUEST_RECEIVED 'J','U','M','P','F','l','a',0xA
#define RTE_CFG_JUMP_APPBACK_REQUEST_RECEIVED 'J','U','M','P','F','l','a',0xB
#define RTE_CFG_JUMP_APP_ADDR             (RTE_DATA_RESET_JUMP_FLAG_ADDR)
#define RTE_CFG_JUMP_APP_SIZE             (RTE_DATA_RESET_JUMP_FLAG_LEN)
#define RTE_CFG_PROG_REQUEST_RECEIVED     'P','r','o','g','F','l','a','g'
#define RTE_CFG_PROG_REQNRSP_RECEIVED     'P','r','o','g','N','r','s','p'
#define RTE_CFG_OTA_REQUEST_RECEIVED      'O','t','a','_','F','l','a','g'
#define RTE_CFG_OTA_REQNRSP_RECEIVED      'O','t','a','_','N','r','s','p'
#define RTE_CFG_PROGRAM_FLAG_ADDR         (RTE_DATA_PROGRAM_FLAG_ADDR)
#define RTE_CFG_PROGRAM_FLAG_LEN          (RTE_DATA_PROGRAM_FLAG_LEN)

#define RTE_DCM_P2E_PEND_TIME             (DCM_P2SMAX_TIME/2u)
#define FL_FLASH_ERASE_SECTOR_MAX_SIZE    FL_MAX_SECTORS_PER_ERASE
#define FL_FLASH_ERASE_SECTOR_SIZE        RTE_PFLASH_SECTOR_SIZE
#define FL_FLASH_ERASE_SECTOR_TIME        128UL
#define FL_FLASH_ERASE_PENDING_TIME       ((DCM_P2SMAX_TIME-RTE_DCM_P2E_PEND_TIME))
#define FL_FLASH_ERASE_PENDING_SEND_PERIOD ((FL_FLASH_ERASE_PENDING_TIME)/\
                                            ((FL_FLASH_ERASE_SECTOR_MAX_SIZE/FL_FLASH_ERASE_SECTOR_SIZE)\
                                            *FL_FLASH_ERASE_SECTOR_TIME))

#define RTE_CFG_FACTORY_ENABLE           STD_ON
#define RTE_DATA_FACTORY_FLAG            0x5AUL
#define RTE_FACTORY_CHECK_CONTENT        STD_OFF
#define RTE_CFG_FACTORY_DATA1_LENGTH     4UL
#define RTE_CFG_FACTORY_DATA1_BUFFER     0x1UL,0x2UL,0x3UL,0x4UL
#define RTE_CFG_FACTORY_DATA2_LENGTH     4UL
#define RTE_CFG_FACTORY_DATA2_BUFFER     0x3UL,0x2UL,0x3UL,0x4UL
#define RTE_CFG_FACTORY_DATA1_ADDRESS    RTE_CFG_APP_START_FLASH_ADDR
#define RTE_CFG_FACTORY_DATA2_ADDRESS    RTE_CFG_APP_START_FLASH_ADDR

#define RTE_PARTITION_SWAP_ON            STD_OFF
#define RTE_ALWAYSJUMP_APP_ON            STD_OFF

/*      SECM                                       CFG                  */
#define RTE_CFG_FLASHDRIVER_INTEGRITY              STD_ON
#define RTE_CFG_SEC_STORAGE                        STD_OFF
/*      VERSION                                    CFG                  */
#define RTE_CFG_VERSION_LEN                        4UL
/*      CHECK                                      SEGMENT              CFG      */
#define RTE_CFG_FL_SEGEMENT_CHECKSUM               STD_ON
#define RTE_CFG_CHECKSUM_CRC                       1UL
#define RTE_CFG_CHECKSUM_SHA256_EVERY_SEGEMENT     2UL
#define RTE_CFG_CHECKSUM_SELECT                    RTE_CFG_CHECKSUM_CRC
/*      CHECK                                      BLKM                 CFG      */
#define RTE_CFG_BLK_STORAGE_SIGNATURE              STD_OFF
#define RTE_CFG_BLK_STORAGE_ERASE_STATUS           STD_OFF
#define RTE_CFG_BLK_ERASE_BLOCK_SUPPORT_CROSS_ZONE STD_OFF
/*      CHECK                                      SEED                 Generate CFG */
#define RTE_CFG_AG_RAMDOM_SAVE                     STD_OFF
#define RTE_CFG_AG_ADC_RANDOM                      STD_OFF
#define RTE_CFG_AG_DRBG_USED                       STD_OFF
/*      CHECK                                      AttemptCounter       CFG      */
#define RTE_CFG_PROG_COUNTER_ONECE                 STD_OFF
/*=======[ Exported types ]===================================================*/
/*=======[ Exported variables ]===============================================*/
/*=======[ Exported functions ]===============================================*/
#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

