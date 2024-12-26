/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : DP.h                                                        **
**                                                                            **
**  Created on  :                                                             **
**  Author      :  LONG.ZHU                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION :  data processing¡£	                                          **
**                                                                            **
**  SPECIFICATION(S) :  None							                      **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>   	 <AUTHOR>   	 <REVISION LOG>
 *  V1.0.0       2023-07-20  LONG.ZHU    	  Initial version.
 *
 */

#ifndef DP_H_
#define DP_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/**
 * \brief   Get uint16 in big-endian format from two uint8 values.
 *
 * \details Convert two bytes of an input message to an unsigned 16-bit integer using big-endian
 *          coding.
 *
 * \param[in]   ptr     Pointer to an uint8 array with at least two bytes.
 * \return              Unsigned 16-bit integer
 *
 */
/* *INDENT-OFF* */
#define DP_UTIL_U8OP_CONSTRUCT_U16(ptr)    \
    ( ((uint16) ((ptr)[0]) << 8)                \
    | ((uint16) ((ptr)[1])))

/**
 * \brief   Get uint32 in big-endian format from four uint8 values.
 *
 * \details Convert four bytes of an input message to an unsigned 32-bit integer using big-endian
 *          coding.
 *
 * \param[in]   ptr     Pointer to an uint8 array with at least four bytes.
 * \return              Unsigned 32-bit integer
 *
 */
#define DP_UTIL_U8OP_CONSTRUCT_U32(ptr)    \
    ( ((uint32) ((ptr)[0]) << 24)               \
    | ((uint32) ((ptr)[1]) << 16)               \
    | ((uint32) ((ptr)[2]) << 8)                \
    | ((uint32) ((ptr)[3])))

/**
 * \brief   Get uint64 in big-endian format from eight uint8 values.
 *
 * \details Convert eight bytes of an input message to an unsigned 64-bit integer using big-endian
 *          coding.
 *
 * \param[in]   ptr     Pointer to an uint8 array with at least eight bytes.
 * \return              Unsigned 64-bit integer
 *
 */
#define DP_UTIL_U8OP_CONSTRUCT_U64(ptr)    \
    ( ((uint64) ((ptr)[0]) << 56)               \
    | ((uint64) ((ptr)[1]) << 48)               \
    | ((uint64) ((ptr)[2]) << 40)               \
    | ((uint64) ((ptr)[3]) << 32)               \
    | ((uint64) ((ptr)[4]) << 24)               \
    | ((uint64) ((ptr)[5]) << 16)               \
    | ((uint64) ((ptr)[6]) << 8)                \
    | ((uint64) ((ptr)[7])))

/**
 * \brief   Get uint32 in little-endian format from four uint8 values.
 *
 * \details Convert four bytes of an input message to an unsigned 32-bit integer using little-
 *          endian coding.
 *
 * \param[in]   ptr     Pointer to an uint8 array with at least four bytes.
 * \return              Unsigned 32-bit integer
 *
 */
#define DP_UTIL_U8OP_CONSTRUCT_U32_LE(ptr) \
    ( ((uint32) ((ptr)[0]))                     \
    | ((uint32) ((ptr)[1]) << 8)                \
    | ((uint32) ((ptr)[2]) << 16)               \
    | ((uint32) ((ptr)[3]) << 24))

/**
 * \brief   Get uint64 in little-endian format from eight uint8 values.
 *
 * \details Convert eight bytes of an input message to an unsigned 64-bit integer using little-
 *          endian coding.
 *
 * \param[in]   ptr     Pointer to an uint8 array with at least eight bytes.
 * \return              Unsigned 64-bit integer
 *
 */
#define DP_UTIL_U8OP_CONSTRUCT_U64_LE(ptr) \
    ( ((uint64) ((ptr)[0]))                     \
    | ((uint64) ((ptr)[1]) << 8)                \
    | ((uint64) ((ptr)[2]) << 16)               \
    | ((uint64) ((ptr)[3]) << 24)               \
    | ((uint64) ((ptr)[4]) << 32)               \
    | ((uint64) ((ptr)[5]) << 40)               \
    | ((uint64) ((ptr)[6]) << 48)               \
    | ((uint64) ((ptr)[7]) << 56))
/* *INDENT-ON* */

/**
 * \brief   Get the bit value for a given uint8 array and given bit position.
 *
 * \param[in]   buffer      The uint8 array to scan.
 * \param[in]   bitNum      The bit position.
 * \return                  The bit value.
 */
#define DP_UTIL_U8OP_GET_BIT(buffer, bitNum)   \
    ((((buffer)[(bitNum) >> (3U)]) >> ((7U) - ((bitNum) & (7U)))) & (1U))

/*!
 * \brief Mask value for uint8
 *
 * This definition can be used to mask out an unsigned 8-bit integer value from a larger type.
 * It also serves as the maximum unsigned 8-bit integer value.
 *
 */
#define DP_UTIL_U8OP_MASK  (0xffU)

/**
 * \brief       Get maximum of two uint32 operands
 *
 * \details     Get the maximum of two uint32 operands.
 *
 * \param[in]   op1     Operand 1
 * \param[in]   op2     Operand 2
 * \return              The maximum of op1 and op2
 */
#define DP_UTIL_U32OP_MAX(op1, op2) (((op1) > (op2)) ? (op1) : (op2))

/**
 * \brief       Get minimum of two uint32 operands
 *
 * \details     Get the minimum of two uint32 operands.
 *
 * \param[in]   op1     Operand 1
 * \param[in]   op2     Operand 2
 * \return              The minimum of op1 and op2
 */
#define DP_UTIL_U32OP_MIN(op1, op2)        (((op1) < (op2)) ? (op1) : (op2))

/**
 * \brief       Get byte 3 from uint32
 *
 * \details     Get 4th byte of 32-bit word in big-endian byte order.
 *
 * \param[in]   x       32-bit integer
 * \return              Unsigned 8-bit integer
 */
#define DP_UTIL_U32OP_GET_BYTE3(x)         ((uint8) ((x) >> 24))

/**
 * \brief       Get byte 2 from uint32
 *
 * \details     Get 3rd byte of 32-bit word in big-endian byte order.
 *
 * \param[in]   x       32-bit integer
 * \return              Unsigned 8-bit integer
 */
#define DP_UTIL_U32OP_GET_BYTE2(x)         ((uint8) ((x) >> 16))

/**
 * \brief       Get byte 1 from uint32
 *
 * \details     Get 2nd byte of 32-bit word in big-endian byte order.
 *
 * \param[in]   x       32-bit integer
 * \return              Unsigned 8-bit integer
 */
#define DP_UTIL_U32OP_GET_BYTE1(x)         ((uint8) ((x) >> 8))

/**
 * \brief       Get byte 0 from uint32
 *
 * \details     Get 1st byte of 32-bit word in big-endian byte order.
 *
 * \param[in]   x       32-bit integer
 * \return              Unsigned 8-bit integer
 */
#define DP_UTIL_U32OP_GET_BYTE0(x)         ((uint8) ((x)))

/**
 * \brief       Get byte from uint32
 *
 * \details     Get nth byte of 32-bit word in big-endian byte order.
 *
 * \param[in]   x       32-bit integer
 * \param[in]   n       Byte index (0, 1, 2, or 3)
 * \return              Unsigned 8-bit integer
 */
#define DP_UTIL_U32OP_GET_BYTE(x, n)       ((uint8) ((x) >> ((n) * 8U)))

/**
 * \brief       Rotate left of uint32
 *
 * \details     Perform left rotation of an unsigned 32-bit integer.
 *
 * \param[in]   x       Value to be rotated left
 * \param[in]   n       Amount of bits to be rotated (0 < n < 32)
 * \return              Unsigned 32-bit integer
 */
#define DP_UTIL_U32OP_ROTATE_LEFT(x, n)    (((x) << (n)) | ((x) >> ((32U) - (n))))

/**
 * \brief       Rotate right of uint32
 *
 * \details     Perform right rotation of an unsigned 32-bit integer.
 *
 * \param[in]   x       Value to be rotated
 * \param[in]   n       Amount of bits to be rotated (0 < n < 32)
 * \return              Unsigned 32-bit integer
 */
#define DP_UTIL_U32OP_ROTATE_RIGHT(x, n)   (((x) >> (n)) | ((x) << (32U - (n))))

/*!
 * \brief Mask value for uint32
 *
 * This definition can be used to mask out an unsigned 32-bit integer value from a larger type.
 * It also serves as the maximum unsigned 32-bit integer value.
 *
 */
#define DP_UTIL_U32OP_MASK  (0xffffffffU)

/**
 * \brief       Rotate right of uint64
 * \details     Perform right rotation of an unsigned 64-bit integer.
 *
 * \param[in]   x       Unsigned 64-bit value to be rotated
 * \param[in]   n       Amount of bits to be rotated (0 < n < 64)
 * \return              Unsigned 64-bit integer
 */
#define DP_UTIL_U64OP_ROTATE_RIGHT(x, n)   (((x) >> (n)) | ((x) << (64U - (n))))

/**
 * \brief       Rotate left of uint64
 * \details     Perform left rotation of an unsigned 64-bit integer.
 *
 * \param[in]   x       Unsigned 64-bit value to be rotated
 * \param[in]   n       Amount of bits to be rotated (0 < n < 64)
 * \return              Unsigned 64-bit integer
 */
#define DP_UTIL_U64OP_ROTATE_LEFT(x, n)    (((x) << (n)) | ((x) >> (64U - (n))))

/**
 * \brief       Get byte from uint64
 *
 * \details     Get nth byte of 64-bit word in big-endian byte order.
 *
 * \param[in]   x       64-bit integer
 * \param[in]   n       Byte index (0..7)
 * \return              Unsigned 8-bit integer
 */
#define DP_UTIL_U64OP_GET_BYTE(x, n)       ((uint8) ((x) >> ((n) * 8U)))

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
extern void DP_Memcpy(uint8 * dest, const uint8 *source, uint32 length);
extern void DP_Memset(uint8 * dest, const uint8 source, uint32 length);
extern boolean DP_Memcompare(const uint8* dest, const uint8* source, uint32 length);
extern uint32 DP_Get4Byte(const uint8* data);
extern void DP_Set4Byte(const uint32 data, uint8* buffer);
extern void DP_GetUint32(const uint32 data, uint8* buffer);
extern uint32 DP_Util_U8Op_GetHighestBit(const uint8 *op,const uint32 opLength);
extern uint8 DP_Util_U8Op_CompareEqual(const uint8 *op1,const uint8 *op2,uint32 opLength);
extern sint32 DP_Util_U8Op_CompareTimeVariant(const uint8 *op1,const uint8 *op2,uint32 opLength);
extern sint32 DP_Util_U8Op_CompareConstantTime(const uint8 *op1,const uint8 *op2,uint32 opLength);
extern sint32 DP_Util_U8Op_CompareImmTimeVariant(const uint8 *op1,uint32 op1Length,uint8 immediate);
extern sint32 DP_Util_U8Op_CompareImmConstantTime(const uint8 *op1,uint32 op1Length,uint8 immediate);
extern void DP_Util_U8Op_SetMemory(uint8 value,uint32 length,uint8 *dst);
extern void DP_Util_U8Op_CopyMemory(const uint8 *src,uint32 srcLength,uint8 *dst);
extern void DP_Util_U8Op_XorMemory(const uint8 *op1,uint8 *op2,uint32 opLength);
extern void DP_Util_U8Op_ReverseBytes(const uint8 *input,uint8 *output,uint32 length);
extern void DP_Delay(uint32 i, uint32 j);
extern boolean DP_Checkdate(uint16 w_year, uint8 w_month, uint8 w_date);
#endif /*DP_H_*/
