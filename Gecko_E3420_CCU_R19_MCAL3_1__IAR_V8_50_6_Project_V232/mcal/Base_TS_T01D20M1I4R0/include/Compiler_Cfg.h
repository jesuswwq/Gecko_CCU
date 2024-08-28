/**
 *   @file    Compiler_Cfg.h
 *
 *   @brief   Module specific memory and pointer classes
 *   @details ptrclass and memclass macro definitions for all modules
 */

/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

#ifdef __cplusplus
#define BEGIN_C_DECLS         extern "C" {
#define END_C_DECLS           }
#else
#define BEGIN_C_DECLS
#define END_C_DECLS
#endif

#ifdef __cplusplus
extern "C" {
#endif
/* Version and Check Begin */
/* Version Info Begin */
#define COMPILER_CFG_H_VENDOR_ID    0x8C
#define COMPILER_CFG_H_AR_RELEASE_MAJOR_VERSION    4
#define COMPILER_CFG_H_AR_RELEASE_MINOR_VERSION    3
#define COMPILER_CFG_H_AR_RELEASE_REVISION_VERSION 1
#define COMPILER_CFG_H_SW_MAJOR_VERSION    1
#define COMPILER_CFG_H_SW_MINOR_VERSION    0
#define COMPILER_CFG_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */

/**
 * @brief Memory and pointer classes for all the modules.
 */

#define MCU_CODE
#define MCU_CONST
#define MCU_APPL_DATA
#define MCU_APPL_CONST
#define MCU_APPL_CODE
#define MCU_CALLOUT_CODE
#define MCU_VAR_NOINIT
#define MCU_VAR_POWER_ON_INIT
#define MCU_VAR_FAST
#define MCU_VAR

#define DET_CODE
#define DET_CONST
#define DET_APPL_DATA
#define DET_APPL_CONST
#define DET_APPL_CODE
#define DET_CALLOUT_CODE
#define DET_VAR_NOINIT
#define DET_VAR_POWER_ON_INIT
#define DET_VAR_FAST
#define DET_VAR

#define PORT_CODE
#define PORT_CONST
#define PORT_APPL_DATA
#define PORT_APPL_CONST
#define PORT_APPL_CODE
#define PORT_CALLOUT_CODE
#define PORT_VAR_NOINIT
#define PORT_VAR_POWER_ON_INIT
#define PORT_VAR_FAST
#define PORT_VAR

#define DIO_CODE
#define DIO_CONST
#define DIO_APPL_DATA
#define DIO_APPL_CONST
#define DIO_APPL_CODE
#define DIO_CALLOUT_CODE
#define DIO_VAR_NOINIT
#define DIO_VAR_POWER_ON_INIT
#define DIO_VAR_FAST
#define DIO_VAR

#define GPT_CODE
#define GPT_CONST
#define GPT_APPL_DATA
#define GPT_APPL_CONST
#define GPT_APPL_CODE
#define GPT_CALLOUT_CODE
#define GPT_VAR_NOINIT
#define GPT_VAR_POWER_ON_INIT
#define GPT_VAR_FAST
#define GPT_VAR

#define WDG_CODE
#define WDG_CONST
#define WDG_APPL_DATA
#define WDG_APPL_CONST
#define WDG_APPL_CODE
#define WDG_CALLOUT_CODE
#define WDG_VAR_NOINIT
#define WDG_VAR_POWER_ON_INIT
#define WDG_VAR_FAST
#define WDG_VAR

#define PPC_CODE
#define PPC_CONST
#define PPC_APPL_DATA
#define PPC_APPL_CONST
#define PPC_APPL_CODE
#define PPC_CALLOUT_CODE
#define PPC_VAR_NOINIT
#define PPC_VAR_POWER_ON_INIT
#define PPC_VAR_FAST
#define PPC_VAR

#define FIREWALL_CODE
#define FIREWALL_CONST
#define FIREWALL_APPL_DATA
#define FIREWALL_APPL_CONST
#define FIREWALL_APPL_CODE
#define FIREWALL_CALLOUT_CODE
#define FIREWALL_VAR_NOINIT
#define FIREWALL_VAR_POWER_ON_INIT
#define FIREWALL_VAR_FAST
#define FIREWALL_VAR

#define LIN_CODE
#define LIN_CONST
#define LIN_APPL_DATA
#define LIN_APPL_CONST
#define LIN_APPL_CODE
#define LIN_CALLOUT_CODE
#define LIN_VAR_NOINIT
#define LIN_VAR_POWER_ON_INIT
#define LIN_VAR_FAST
#define LIN_VAR

#define CAN_CODE
#define CAN_CONST
#define CAN_APPL_DATA
#define CAN_APPL_CONST
#define CAN_APPL_CODE
#define CAN_CALLOUT_CODE
#define CAN_VAR_NOINIT
#define CAN_VAR_POWER_ON_INIT
#define CAN_VAR_FAST
#define CAN_VAR

#define CANIF_CODE
#define CANIF_CONST
#define CANIF_APPL_DATA
#define CANIF_APPL_CONST
#define CANIF_APPL_CODE
#define CANIF_CALLOUT_CODE
#define CANIF_VAR_NOINIT
#define CANIF_VAR_POWER_ON_INIT
#define CANIF_VAR_FAST
#define CANIF_VAR

#define ICU_CODE
#define ICU_CONST
#define ICU_APPL_DATA
#define ICU_APPL_CONST
#define ICU_APPL_CODE
#define ICU_CALLOUT_CODE
#define ICU_VAR_NOINIT
#define ICU_VAR_POWER_ON_INIT
#define ICU_VAR_FAST
#define ICU_VAR

#define SENT_CODE
#define SENT_CONST
#define SENT_APPL_DATA
#define SENT_APPL_CONST
#define SENT_APPL_CODE
#define SENT_CALLOUT_CODE
#define SENT_VAR_NOINIT
#define SENT_VAR_POWER_ON_INIT
#define SENT_VAR_FAST
#define SENT_VAR

#define I2C_CODE
#define I2C_CONST
#define I2C_APPL_DATA
#define I2C_APPL_CONST
#define I2C_APPL_CODE
#define I2C_CALLOUT_CODE
#define I2C_VAR_NOINIT
#define I2C_VAR_POWER_ON_INIT
#define I2C_VAR_FAST
#define I2C_VAR

#define DMA_CODE
#define DMA_CONST
#define DMA_APPL_DATA
#define DMA_APPL_CONST
#define DMA_APPL_CODE
#define DMA_CALLOUT_CODE
#define DMA_VAR_NOINIT
#define DMA_VAR_POWER_ON_INIT
#define DMA_VAR_FAST
#define DMA_VAR

#define SPI_CODE
#define SPI_CONST
#define SPI_APPL_DATA
#define SPI_APPL_CONST
#define SPI_APPL_CODE
#define SPI_CALLOUT_CODE
#define SPI_VAR_NOINIT
#define SPI_VAR_POWER_ON_INIT
#define SPI_VAR_FAST
#define SPI_VAR

#define FLS_CODE
#define FLS_CONST
#define FLS_APPL_DATA
#define FLS_APPL_CONST
#define FLS_APPL_CODE
#define FLS_CALLOUT_CODE
#define FLS_VAR_NOINIT
#define FLS_VAR_POWER_ON_INIT
#define FLS_VAR_FAST
#define FLS_VAR

#define ADC_CODE
#define ADC_CONST
#define ADC_APPL_DATA
#define ADC_APPL_CONST
#define ADC_APPL_CODE
#define ADC_CALLOUT_CODE
#define ADC_VAR_NOINIT
#define ADC_VAR_POWER_ON_INIT
#define ADC_VAR_FAST
#define ADC_VAR

#define PWM_CODE
#define PWM_CONST
#define PWM_APPL_DATA
#define PWM_APPL_CONST
#define PWM_APPL_CODE
#define PWM_CALLOUT_CODE
#define PWM_VAR_NOINIT
#define PWM_VAR_POWER_ON_INIT
#define PWM_VAR_FAST
#define PWM_VAR
#define IRAMC_CODE
#define IRAMC_CONST
#define IRAMC_APPL_DATA
#define IRAMC_APPL_CONST
#define IRAMC_VAR

#define SEM_CODE
#define SEM_CONST
#define SEM_APPL_DATA
#define SEM_APPL_CONST
#define SEM_VAR

#define FUSE_CODE
#define FUSE_CONST
#define FUSE_APPL_DATA
#define FUSE_APPL_CONST
#define FUSE_VAR

#define EIC_CODE
#define EIC_CONST
#define EIC_APPL_DATA
#define EIC_APPL_CONST
#define EIC_VAR

#define FUNCSAFETYPKG_CODE
#define FUNCSAFETYPKG_CONST
#define FUNCSAFETYPKG_APPL_DATA
#define FUNCSAFETYPKG_APPL_CONST
#define FUNCSAFETYPKG_VAR
#define SDPE_CODE
#define SDPE_CONST
#define SDPE_APPL_DATA
#define SDPE_APPL_CONST
#define SDPE_APPL_CODE
#define SDPE_CALLOUT_CODE
#define SDPE_VAR_NOINIT
#define SDPE_VAR_POWER_ON_INIT
#define SDPE_VAR_FAST
#define SDPE_VAR

#define CSM_CODE
#define CSM_CONST
#define CSM_APPL_DATA
#define CSM_APPL_CONST
#define CSM_APPL_CODE
#define CSM_CALLOUT_CODE
#define CSM_VAR_NOINIT
#define CSM_VAR_POWER_ON_INIT
#define CSM_VAR_FAST
#define CSM_VAR

#define CRYPTO_CODE
#define CRYPTO_CONST
#define CRYPTO_APPL_DATA
#define CRYPTO_APPL_CONST
#define CRYPTO_APPL_CODE
#define CRYPTO_CALLOUT_CODE
#define CRYPTO_VAR_NOINIT
#define CRYPTO_VAR_POWER_ON_INIT
#define CRYPTO_VAR_FAST
#define CRYPTO_VAR

#define IPC_CODE
#define IPC_CONST
#define IPC_APPL_DATA
#define IPC_APPL_CONST
#define IPC_APPL_CODE
#define IPC_CALLOUT_CODE
#define IPC_VAR_NOINIT
#define IPC_VAR_POWER_ON_INIT
#define IPC_VAR_FAST
#define IPC_VAR


#define ETH_CODE
#define ETH_CONST
#define ETH_APPL_DATA
#define ETH_APPL_CONST
#define ETH_APPL_CODE
#define ETH_CALLOUT_CODE
#define ETH_VAR_NOINIT
#define ETH_VAR_POWER_ON_INIT
#define ETH_VAR_FAST
#define ETH_VAR


#define ETHTRCV_CODE
#define ETHTRCV_CONST
#define ETHTRCV_APPL_DATA
#define ETHTRCV_APPL_CONST
#define ETHTRCV_APPL_CODE
#define ETHTRCV_CALLOUT_CODE
#define ETHTRCV_VAR_NOINIT
#define ETHTRCV_VAR_POWER_ON_INIT
#define ETHTRCV_VAR_FAST
#define ETHTRCV_VAR

#define REBOOT_CODE
#define REBOOT_CONST
#define REBOOT_APPL_DATA
#define REBOOT_APPL_CONST
#define REBOOT_APPL_CODE
#define REBOOT_CALLOUT_CODE
#define REBOOT_VAR_NOINIT
#define REBOOT_VAR_POWER_ON_INIT
#define REBOOT_VAR_FAST
#define REBOOT_VAR

/* LinIf */
#define LINIF_CODE
#define LINIF_VAR
#define LINIF_APPL_CONST
#define LINIF_APPL_DATA
#define LINIF_CONST
#define LINIF_DATA

/* det */
#define DET_CODE

/* LinSM */
#define LINSM_CODE
#define LINSM_VAR_POWER_ON_INIT
#define LINSM_VAR
#define LINSM_CONST
#define LINSM_CONST_PBCFG
#define LinSM_APPL_DATA

/* cantp */
#define CANTP_VAR_POWER_ON_INIT
#define CANTP_CODE
#define CANTP_CONST
#define CANTP_APPL_CONST
#define CANTP_APPL_DATA
#define CANTP_APPL_CODE
#define CANTP_VAR_NOINIT
#define CANTP_VAR

/* dcm */
#define DCM_VAR_POWER_ON_INIT
#define DCM_CODE
#define DCM_CONST_PBCFG
#define DCM_VAR
#define DCM_APPL_CODE
#define DCM_CONST
#define DCM_VAR_NOINIT
#define DCM_APPL_CONST
#define DCM_APPL_DATA

/* Det */
#define DET_VAR_POWER_ON_INIT
#define DET_CODE
#define DET_CONST_PBCFG
#define DET_VAR
#define DET_APPL_CODE
#define DET_CONST
#define DET_VAR_NOINIT
#define DET_APPL_CONST
#define DET_APPL_DATA

/* WdgIf */
#define WDGIF_VAR_POWER_ON_INIT
#define WDGIF_CODE
#define WDGIF_CONST_PBCFG
#define WDGIF_VAR
#define WDGIF_APPL_CODE
#define WDGIF_CONST
#define WDGIF_VAR_NOINIT
#define WDGIF_APPL_CONST
#define WDGIF_APPL_DATA

/* nvm */
#define NVM_CODE
#define NVM_VAR
#define NVM_CONST
#define NVM_VAR_NOINIT
#define NVM_APPL_DATA
#define NVM_VAR_POWER_ON_INIT
#define NVM_APPL_CODE

/* MemIf */
#define MEMIF_CODE
#define MEMIF_VAR
#define MEMIF_CONST
#define MEMIF_VAR_NOINIT
#define MEMIF_APPL_DATA
#define MEMIF_VAR_POWER_ON_INIT
#define MEMIF_APPL_CODE
/* EA */
#define EA_CODE
#define EA_VAR
#define EA_CONST
#define EA_VAR_NOINIT
#define EA_APPL_DATA
#define EA_VAR_POWER_ON_INIT
#define EA_APPL_CODE


/* dem */
#define DEM_CODE
#define DEM_CONST
#define DEM_VAR
#define DEM_CONST_PBCFG
#define DEM_APPL_DATA

/* fim */
#define FIM_VAR_INIT_8
#define FIM_APPL_DATA
#define FIM_VAR_NO_INIT_UNSPECIFIED
#define FIM_CODE

/* canif */
#define CANIF_VAR_POWER_ON_INIT
#define CANIF_CONST
#define CANIF_VAR
#define CANIF_CODE
#define CANIF_APPL_DATA
#define CANIF_CONST_PBCFG
#define CANIF_APPL_CONST
#define CANIF_APPL_CODE

/* com */
#define COM_VAR_POWER_ON_INIT
#define COM_VAR
#define COM_CODE
#define COM_APPL_CONST
#define COM_APPL_DATA
#define COM_CONST_PBCFG
#define COM_CONST
#define COM_APPL_CODE

/* comm */
#define COMM_VAR_POWER_ON_INIT
#define COMM_APPL_CONST
#define COMM_APPL_DATA
#define COMM_CODE
#define COMM_COM_CODE
#define COMM_DCM_CODE
#define COMM_ECUM_USED
#define COMM_CONST
#define COMM_VAR
#define COMM_NM_CODE
#define ComM_CONFIG_DATA

/*nm*/
#define NM_CODE
#define NM_APPL_DATA
#define NM_VAR_CLEARED_BOOLEAN
#define NM_VAR_NO_INIT_UNSPECIFIED

/*cannm*/
#define CANNM_APPL_CONST
#define CANNM_APPL_DATA
#define CANNM_CODE
#define CANNM_VAR
#define CANNM_VAR_POWER_ON_INIT

/*cansm*/
#define CANNM_VAR_POWER_ON_INIT
#define CANSM_CONFIG_DATA
#define CANSM_VAR
#define CANSM_CODE
#define CANSM_COMM_CODE
#define CANSM_ECUM_CODE
#define CANSM_CONTROLLERBUSOFF_CODE
#define CANSM_CONTROLLERNODEINDICATION_CODE
#define CANSM_TRANSCEIVERMODEINDICATION_CODE
#define CANSM_CLEARTRCVWUFFLAGINDICATION_CODE
#define CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CODE
#define CANSM_CONFIRMPNAVAILABILITY_CODE
#define CANSM_CURRENTICOMCONFIGURATION_CODE
#define CANSM_TXTIMEOUTEXCEPTION_CODE

/*crc*/
#define CRC_CODE
#define CRC_APPL_CONST

/*e2e*/
#define E2E_APPL_DATA
#define E2E_CODE

/* EcuM  */
#define ECUM_CONFIG_DATA
#define ECUM_DETERMINEPBCONFIGURATION_CODE

/**
* @brief Define for ComStack Data.
*/
#define AUTOSAR_COMSTACKDATA

#ifdef __cplusplus
}
#endif

#endif /* #ifndef COMPILER_CFG_H */
