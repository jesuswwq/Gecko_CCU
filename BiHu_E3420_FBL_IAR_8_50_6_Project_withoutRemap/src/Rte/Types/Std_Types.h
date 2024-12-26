#ifndef STD_TYPES_H
#define STD_TYPES_H
#ifdef __cplusplus
extern "C" {
#endif
#include "Platform_Types.h"
#include "Compiler.h"
#define STD_HIGH    0x01
#define STD_LOW     0x00
#define STD_ACTIVE  0x01
#define STD_IDLE    0x00
#define STD_ON      0x01
#define STD_OFF     0x00
#define E_NOT_OK    0x01
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED

#define E_OK      0x00
typedef unsigned char StatusType;
#endif
typedef uint8 Std_ReturnType;
typedef struct
{
    VAR(uint16, LIN_VAR)  vendorID;
    VAR(uint16, LIN_VAR)  moduleID;
    VAR(uint8, LIN_VAR)   sw_major_version;
    VAR(uint8, LIN_VAR)   sw_minor_version;
    VAR(uint8, LIN_VAR)   sw_patch_version;
} Std_VersionInfoType;
#ifdef __cplusplus
}
#endif
#endif
