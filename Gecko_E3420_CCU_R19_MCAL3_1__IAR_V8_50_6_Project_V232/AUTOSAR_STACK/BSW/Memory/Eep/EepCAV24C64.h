/*=============================================================================*/
#ifndef _EEPCAV24C64_H_
#define _EEPCAV24C64_H_

#include "Std_Types.h"
#include "I2c.h"
#include "Eep_62_Cfg.h"
/******************************************************************************
*                        Type  definitions                                    *
******************************************************************************/
#define EEP_PAGE_SIZE				32U
#define EEP_SIZE_OF_ADDRESS			2U

#define EEP_MAX_SIZE				8192U

extern Std_ReturnType Eep_CAV24C64_Write(Eep_62_AddressType writeAddress,const uint8* writeBufferPtr,Eep_62_LengthType writeLength);

extern Std_ReturnType Eep_CAV24C64_Read(Eep_62_AddressType writeAddress,uint8* readBufferPtr,Eep_62_LengthType writeLength);

extern void I2c_EepInit_Device(void);                                

extern Std_ReturnType Eep_CAV24C64_Erase(Eep_62_AddressType eraseAddress,const uint8 ErasedValue,Eep_62_LengthType eraseLength);




#endif