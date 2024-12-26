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
**  FILENAME    : DP.c                                                        **
**                                                                            **
**  Created on  :                                                             **
**  Author      :   LONG.ZHU                                                  **
**  Vendor      :                                                             **
**  DESCRIPTION :  data processing	                                          **
**                                                                            **
**  SPECIFICATION(S) :   None							                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* <VERSION> <DATE> <AUTHOR> <REVISION LOG>
*  V1.0.0       20200501     LONG.ZHU       Initial version
*  V1.0.1		20240328	 yaowei.shen	add function Check_date
*  V1.0.2		20240329	 long.zhu		DP_Checkdate  function comment adjustment.
*  V1.0.3       20240424     chunjun.hua    QAC fix
*
*/
/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:DP .<br>
  RuleSorce:puhua-rule2024.rcf 1.0.2

    \li PRQA S 2986  Rule 2.2.<br>
    Reason: This operation appears to be redundant because the right-hand operand can always be used instead.

    \li PRQA S 4303  Rule 10.5.<br>
    Reason: An expression of 'essentially Boolean' type (%1s) is being cast to signed type '%2s'.
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "DP.h"

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               <used to copy data buffer of indirect address.>
 * ServiceId           <NONE>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <source:Data source pointer.
 * 						length:Data source length>
 * Param-Name[out]     <dest:Data target pointer>
 * Param-Name[in/out]  <NONE>
 * Return              <NONE>
 */
/******************************************************************************/
void DP_Memcpy(uint8 * dest, const uint8 *source, uint32 length)
{
    uint8 * destBuffer = dest;
    const uint8 *srcBuffer = source;
    uint32 inputLength = length;
    while (inputLength > 0U)
    {
        if ((destBuffer != NULL_PTR) && (srcBuffer != NULL_PTR))
        {
            *destBuffer = *srcBuffer;
            destBuffer++;
            srcBuffer++;
        }
        else
        {
            break;
        }
        inputLength--;
    }
}
/******************************************************************************/
/*
 * Brief               <uy used  to set data buffer of indirect address.>
 * ServiceId           <NONE>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <source:Data source.
 * 						length:Data target length>
 * Param-Name[out]     <dest:Data target pointer>
 * Param-Name[in/out]  <NONE>
 * Return              <NONE>
 */
/******************************************************************************/
void DP_Memset(uint8 * dest, const uint8 source, uint32 length)
{
    uint8 * destBuffer = dest;
    uint32 inputLength = length;
    while (inputLength > 0U)
    {
        if (destBuffer != NULL_PTR)
        {
            *destBuffer = source;
            destBuffer++;
        }
        else
        {
            break;
        }

        inputLength--;
    }
}

/******************************************************************************/
/**
 * @brief               <memory compare>
 *
 * <compare the dest and source is equal or not .> .
 * @param[in]           <source (IN),dest(IN) length (IN)>
 * @param[out]          <dest (OUT)>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
boolean DP_Memcompare(const uint8* dest, const uint8* source, uint32 length) 
{
    boolean retVal = (boolean)TRUE;
    const uint8 * destBuffer = dest;
    const uint8 *srcBuffer = source;
    uint32 inputLength = length;

    /* compare length should not be zero */
    if ((uint32)0U == length)
    {
        retVal = (boolean)FALSE;
    }
    else
    {
        while (inputLength > (uint32)0U)
        {
            if ((NULL_PTR != destBuffer) && (NULL_PTR != srcBuffer) && (*destBuffer == *srcBuffer))
            {
                destBuffer++;
                srcBuffer++;
            }
            else
            {
                retVal = (boolean)FALSE;
                break;
            }
            inputLength--;
        }
    }
    return retVal;
}
/******************************************************************************/
/**
 * @brief               <get uint32 from data buffer>
 *
 * <get uint32 from data buffer> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <data (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <uint32>
 */
/******************************************************************************/
uint32 DP_Get4Byte(const uint8* data)
{
    uint32 retData;

    retData = (uint32)((uint32)data[0] << 24u);
    retData += (uint32)((uint32)data[1] << 16u);
    retData += (uint32)((uint32)data[2] << 8u);
    retData += (uint32)(uint32)data[3];

    return retData;
}

/******************************************************************************/
/**
 * @brief               <get data buffer from uint32>
 *
 * <get data buffer from uint32> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <data (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <uint32>
 */
/******************************************************************************/
void DP_Set4Byte(const uint32 data, uint8* buffer)
{
    buffer[0u]  = (uint8)(data >> 24u);
    buffer[1u]  = (uint8)(data >> 16u);
    buffer[2u]  = (uint8)(data >> 8u);
    buffer[3u]  = (uint8)(data);

}

/******************************************************************************/
/**
 * @brief               <get data buffer from uint32>
 *
 * <get data buffer from uint32> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           data   - IN
 * @param[out]          buffer - OUT
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void DP_GetUint32(const uint32 data, uint8* buffer) 
{
    buffer[0] = (uint8)(data >> 24u);
    buffer[1] = (uint8)((data >> 16u) & 0xFFu);
    buffer[2] = (uint8)((data >> 8u) & 0xFFu);
    buffer[3] = (uint8)(data & 0xFFu);
}
/******************************************************************************/
/*
 * Brief               <Find the index of the highest bit which is set in the little endian byte array
 *              		operand.
 *              		This function is time-variant! Function must not be used if the runtime must be
 *              		constant.>
 * ServiceId           <NONE>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <op: The operand to be scanned, in little endian byte array format. Must be
 *                          larger than 0.
 * 						opLength: The length of the operand in bytes, must be larger than 0.
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <NONE>
 * Return              <The bit index of the highest bit which is set to one>
 */
/******************************************************************************/
uint32 DP_Util_U8Op_GetHighestBit(const uint8 *op,const uint32 opLength)
{
    uint32  bitNum;
    uint8   mask;
    uint32  i;

    bitNum = 0U;

    /* Find the first byte that is not equal to zero, rise bit index by 8 for every found byte */
    for (i = 0U; ((i < (opLength - 1U)) && (op[i] == 0U)); i++)
    {
        bitNum += 8U;
    }

    /* In the first byte not equal to zero, find the first bit that is equal to one */
    for (mask = (uint8) 0x80U; (((op[i] & mask) == 0U) && (mask > 0U)); mask >>= 1U)
    {
        bitNum++;
    }

    return bitNum;
}

/**
 * \details Compare two unsigned byte arrays with a constant-time technique and evaluate the
 *          arrays for equality. The result is a uint8 (0U for equal, >0U for not equal).
 *
 * \reqId{500}
 * \req{CompareEqual function}
 * \reqSatisfy{11294}
 *
 * \param[in] op1           Pointer to the first byte array operand1.
 * \param[in] op2           Pointer to the second byte array operand2.
 * \param[in] opLength      Length of the two byte arrays. A zero length is interpreted as equal
 *                          input arrays.
 *
 * \return
 * -  0:        Arrays are equal.
 * - >0:        Arrays are NOT equal.
 */
uint8 DP_Util_U8Op_CompareEqual(const uint8 *op1,const uint8 *op2,uint32 opLength)
{
    uint8   cmpValue = 0U;
    uint32  i;

    /* Loop through the full buffer */
    for (i = 0U; i < opLength; i++)
    {
        cmpValue |= op1[i] ^ op2[i];
    }

    return cmpValue;
}

/**
 * \details Compare two unsigned big-endian byte arrays of the same length using a time-variant
 *          technique. This compare function must not be used to process secret data.
 *
 * \reqId{265}
 * \req{CompareTimeVariant function}
 * \reqSatisfy{11294}
 *
 * \param[in] op1           Pointer to the first byte array operand1.
 * \param[in] op2           Pointer to the second byte array operand2.
 * \param[in] opLength      Length of the two byte arrays. A zero length is interpreted as equal
 *                          input arrays.
 *
 * \return
 * - >0:         The first operand is larger than the second, op1 > op2.
 * -  0:         Both byte arrays have the same value, op1 = op2, or a zero array length was given.
 * - <0:         The second operand is larger than the first array, op1 < op2.
 */
sint32 DP_Util_U8Op_CompareTimeVariant(const uint8 *op1,const uint8 *op2,uint32 opLength)
{
    sint32  result = 0;
    uint32  i;

    /* Searching for the first different byte, starting from the most significant byte */
    for (i = 0; (i < opLength) && (result == 0); i++)
    {
        result = (sint32) op1[i] - (sint32) op2[i];
    }

    return result;
}

/**
 * \details     Compare two unsigned big-endian byte arrays with the same length using a constant-
 *              time technique. This compare function can be used to process secret data.
 *
 * \reqId{877}
 * \req{CompareConstantTime function}
 * \reqSatisfy{11294}
 *
 * \param[in]   op1         Operand #1
 * \param[in]   op2         Operand #2
 * \param[in]   opLength    Length of operands in bytes. Must be greater than zero.
 * \return                  Comparison result:
 *                          -  1  if op1 > op2,
 *                          -  0  if op1 == op2,
 *                          - -1  if op1 < op2
 */
sint32 DP_Util_U8Op_CompareConstantTime(const uint8 *op1,const uint8 *op2,uint32 opLength)
{
    sint32  lt;
    sint32  ht;
    sint32  resultInvert;
    sint32  result = 0;
    uint32  i;

    for (i = 0U; i < opLength; i++)
    {
        /* op1 larger: lt = 0, ht = 1; op2 larger: lt = 1, ht = 0; equal: lt and ht = 0 */
        lt = (sint32) (op1[i] < op2[i]); /* PRQA S 4303 # Rule 10.5. Cast is required for
                                          * constant-time behavior. C90-standard (Sec 3.3.8):
                                          * operator shall yield 0 or 1 */
        ht = (sint32) (op1[i] > op2[i]); /* PRQA S 4303 # Rule 10.5. Cast is required for
                                          * constant-time behavior. C90-standard (Sec 3.3.8):
                                          * operator shall yield 0 or 1 */

        /* op1 larger: (ht-lt) = 1; op2 larger: (ht-lt) = -1; equal: (lt-ht) = 0.
         * If result has already a value != 0, (ht-lt) is set to zero by the multiplication. */
        resultInvert = (sint32) (result == 0); /* PRQA S 4303 # Rule 10.5. Cast is required for
                                                * constant-time behavior. C90-standard (Sec 3.3.8):
                                                * operator shall yield 0 or 1 */
        result += resultInvert * (ht - lt);
    }

    return result;
}

/**
 * \details Compare an unsigned big-endian byte array with an unsigned immediate using a time-
 *          variant technique. This compare function must not be used to process secret data.
 *
 * \reqId{266}
 * \req{CompareImmTimeVariant function}
 * \reqSatisfy{11294}
 *
 * \param[in] op1           Pointer to byte array.
 * \param[in] op1Length     Length of the byte array. Zero is allowed.
 * \param[in] immediate     Immediate for comparison.
 *
 * \return
 * - >0:         The byte array is larger than the immediate, op1 > immediate.
 * -  0:         The byte array is equal to the immediate, op1 == immediate.
 * - <0:         The immediate is larger than the byte array, op1 < immediate.
 */
sint32 DP_Util_U8Op_CompareImmTimeVariant(const uint8 *op1,uint32 op1Length,uint8 immediate)
{
    sint32  result = (sint32) immediate;
    uint32  i;

    if (op1Length > 0U)
    {
        result = 0;
        for (i = 0U; i < (op1Length - 1U); i++)
        {
            if (op1[i] != 0U)
            {
                /* Operand 1 is greater, finished */
                result = 1;
                break;
            }
        }

        if (result != 1)
        {
            /* Compare last byte */
            result = (sint32) op1[op1Length - 1U] - (sint32) immediate;
        }
    }

    return result;
}

/**
 * \details Compare an unsigned big-endian byte array with an unsigned immediate using a constant-
 *          time technique. This compare function can be used to process secret data.
 *
 * \reqId{972}
 * \req{CompareImmConstantTime function}
 * \reqSatisfy{11294}
 *
 * \param[in] op1           Pointer to byte array.
 * \param[in] op1Length     Length of the byte array. Zero is allowed.
 * \param[in] immediate     Immediate for comparison.
 *
 * \return
 * - >0:         The byte array is larger than the immediate, op1 > immediate.
 * -  0:         The byte array is equal to the immediate, op1 == immediate.
 * - <0:         The immediate is larger than the byte array, op1 < immediate.
 */
sint32 DP_Util_U8Op_CompareImmConstantTime(const uint8 *op1,uint32 op1Length,uint8 immediate)
{
    uint8   cmpValue = 0U;
    sint32  result = (sint32) immediate;
    uint32  mask;
    uint32  i;

    if (op1Length > 0U)
    {
        /* Compare all bytes of operand 1 except for last byte */
        for (i = 0U; i < (op1Length - 1U); i++)
        {
            cmpValue |= op1[i];
        }

        /* Comparison predicate: mask is 0xffffffff if any byte is larger than 0, else mask is 0 */
        cmpValue |= 0U - cmpValue;/*PRQA S 2986*/
        cmpValue >>= 7;
        mask = 0U - (uint32) cmpValue;/*PRQA S 2986*/

        /* Compare last byte with immediate and incorporate into mask from previous comparison */
        mask |= (uint32) immediate - (uint32) op1[op1Length - 1U];
        result = -((sint32) mask);
    }

    return result;
}

/**
 * \details Copy the given value in the destination buffer for the specified length.
 *
 * \reqId{514}
 * \req{SetMemory function}
 * \reqSatisfy{11294}
 *
 * \param[in]   value   Value that must be set in the given array.
 * \param[in]   length  Length of buffer till which the given value must be set.
 * \param[out]  dst     Pointer to byte array.
 *
 * \return None
 */
void DP_Util_U8Op_SetMemory(uint8 value,uint32 length,uint8 *dst)
{
    uint32 i;

    for (i = 0U; i < length; i++)
    {
        dst[i] = value;
    }
}

/**
 * \details Copy the given source byte array in the destination buffer for the specified length.
 *
 *          Overlapping of the two buffers are only allowed in the way that the dst buffer must have
 *          an address which is smaller or equal than the source buffer (dst <= src).
 *          For performance reasons, this condition is not checked!
 *
 * \reqId{536}
 * \req{CopyMemory function}
 * \reqSatisfy{11294}
 *
 * \param[in]   src             Pointer to byte array that must be copied into the given dst array.
 * \param[in]   srcLength       Length of the source buffer which is copied into the dst array.
 * \param[out]  dst             Pointer to destination buffer. Must have a length of at least
 *                              'srcLength' bytes.
 *
 * \return None
 */
void DP_Util_U8Op_CopyMemory(const uint8 *src,uint32 srcLength,uint8 *dst)
{
    uint32 i;

    for (i = 0U; i < srcLength; i++)
    {
        dst[i] = src[i];
    }
}

/**
 * \details Xor two byte arrays (Op1 and Op2) and store the result in Op2.
 *
 *          Overlapping of the two buffers are only allowed in the way that the dst buffer must have
 *          an address which is smaller or equal than the source buffer (Op2 <= Op1).
 *          For performance reasons, this condition is not checked!
 *
 * \reqId{589}
 * \req{XorMemory function}
 * \reqSatisfy{11294}
 *
 * \param[in]     op1           Pointer to Op1 byte array that is xored to the Op2 array.
 * \param[inout]  op2           Pointer to Op2 byte array. Must have a length of at least
 *                              'opLength' bytes.
 * \param[in]     opLength      Length of the Op1 and Op2 buffers which is xored to the dst array.
 *
 * \return None
 */
void DP_Util_U8Op_XorMemory(const uint8 *op1,uint8 *op2,uint32 opLength)
{
    uint32 i;

    for (i = 0U; i < opLength; i++)
    {
        op2[i] ^= op1[i];
    }
}

/**
 * \details Function to swap the endianness of the byte array.
 *
 * \reqId{828}
 * \req{ReverseBytes function}
 * \reqSatisfy{11294}
 *
 * \param[in]     input         Pointer to input byte array to be converted.
 * \param[out]    output        Pointer to store the converted array. Must not be same as input.
 * \param[in]     length        Length of the byte array to be converted.
 *
 * \return None
 */
void DP_Util_U8Op_ReverseBytes(const uint8 *input,uint8 *output,uint32 length)
{
    uint32 i;

    for (i = 0U; i < length; i++)
    {
        output[i] = input[(length - 1U) - i];
    }
}
/******************************************************************************/
/*
 * Brief               <used to delay operate.>
 * ServiceId           <NONE>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <i:control delay time
 * 						j:control delay time>
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <NONE>
 * Return              <NONE>
 */
/******************************************************************************/
void DP_Delay(uint32 i, uint32 j)
{
	uint32 k = 0,m = 0;

	for(;k<i;k++)
    {
        for(;m<j;m++)
        {
            ;
        }
    }
}
/******************************************************************************/
/*
 * Brief               <used to check date.>
 * ServiceId           <NONE>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <w_year:year
 * 						w_month:month
 * 						w_date:date>
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <NONE>
 * Return              <NONE>
 */
/******************************************************************************/
boolean DP_Checkdate(uint16 w_year, uint8 w_month, uint8 w_date)
{
	boolean ret;

    uint8 Month_buf[12] = {31u,28u,31u,30u,31u,30u,31u,31u,30u,31u,30u,31u};   //month for date
     /*Run February plus 1*/
	if (w_month == 2u)
	{
		if((((w_year%4u) == 0u) && ((w_year%100u) != 0u)) || ((w_year%400u) == 0u))
        {
            Month_buf[1] += 1u;
        }
	}
	/*check the month date is right*/
    if (((w_month > 12u) || (w_month < 1u)) || ((w_date > Month_buf[w_month - 1u]) || (w_date < 1u)))
    {
    	ret = FALSE;
    }
    else
    {
    	ret = TRUE;
    }

    return ret;
}
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


