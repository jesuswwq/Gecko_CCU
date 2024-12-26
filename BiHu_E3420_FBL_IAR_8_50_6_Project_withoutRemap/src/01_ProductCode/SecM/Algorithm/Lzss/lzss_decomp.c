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
**  FILENAME    : lzss_decomp.c                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      :  long.zhu                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION : lzss decomp.                                                **
**                                                                            **
**  SPECIFICATION(S) :  NONE                       		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *    V1.0.0    20191025   long.zhu		 Init Version
 *    V1.0.1    20200629   Lianren Wu	 modify state of CanTp for the function
 *    V1.0.2    20200629   long.zhu	     modify Function and variable naming
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "lzss_decomp.h"

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/


/*Number of bits allocated to indices into the text window*/
#define LZSS_INDEX_BIT_COUNT 	10u

/*Number of bits allocated for the length of an encode phrase*/
#define LZSS_LENGTH_BIT_COUNT 	4u

/*Size of the sliding window*/
#define LZSS_WINDOW_SIZE		(1u << LZSS_INDEX_BIT_COUNT)

/*Number of bytes to encode a byte array.Used to calculate if compression should be done or not*/
#define LZSS_BREAK_EVEN			((1u + LZSS_INDEX_BIT_COUNT + LZSS_LENGTH_BIT_COUNT) / 9u)

/*End of stream indicator*/
#define LZSS_END_OF_STREAM   	0u

/*Arithmetic modulo to get the correct index in the sliding window*/
#define LZSS_MOD_WINDOW(a) 		((a) & (LZSS_WINDOW_SIZE - 1u))

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static boolean Lzss_InputBit(BIT_BUFF * bitbuff);

static uint32 Lzss_InputBits(BIT_BUFF *bitbuff,uint32 bit_count);

static void Lzss_OutputByte(uint8 buffer, BIT_BUFF *byte);

static void Lzss_ExpandStreamData(BIT_BUFF *inBuf, BIT_BUFF *outBuf, uint32 length);

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*The sliding window used by the decompression algorithm*/
static uint8 LZSS_window[LZSS_WINDOW_SIZE];

static uint8 decompbuff[COMP_BUFFER_LEN * 15];

static BIT_BUFF compp;

static uint16 winPos = 1;

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <Init Decomp.>
 *
 * 						<init Decomp variable.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Lzss_InitDecomp(void)
{
	/** Current window position */
	winPos = 1;
	compp.lastreaminbit = 0;
	compp.lastreaminbitlength = 0;
}

/******************************************************************************/
/**
 * @brief               <Lzss algorithm decomp.>
 *
 * 						<Lzss algorithm decomp.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Lzss_Decomp(uint8 *Buf, uint32 Length, BIT_BUFF *outBuf)
{
	compp.pacifier_counter = 0;
	compp.mask = 0x80;
	compp.buff = Buf;
	compp.PcCount = 0;

	outBuf->buff = decompbuff;
	outBuf->PcCount = 0;
	Lzss_ExpandStreamData(&compp,outBuf,Length);
	compp.lastreaminbit = outBuf->lastreaminbit;
	compp.lastreaminbitlength = outBuf->lastreaminbitlength;
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <lzss expand Stream data.>
 *
 * <* This routine expands data from an in buffer with the LZSS algorithm.
 * The routine read in flag bits to decide whether to read in an uncompressed
 * character or an index/length pair and expands the data stream to an out
 * buffer.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           < param inBuf Input data buffer with bit access,param outBuf Output data buffer with byte access
 * param length Input data buffer bit length>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
static void Lzss_ExpandStreamData(BIT_BUFF *inBuf, BIT_BUFF *outBuf, uint32 length)
{
	/** Index var. for loop */
	uint8 i;
	/** Byte to write to output buffer */
	uint8 outByte = 0;
	/** Length of the data match found */
	uint8 matchLen = 0;
	/** Position in the window of the data match */
	uint16 matchPos = 0;
	/** Indicator of End Of Stream reached */
	boolean eosReached = FALSE;
	/** Length of the bit */
	uint32 bitlength = length * 8u;

	uint16 lastreamindata = 0;

	while ( eosReached == FALSE )
	{
		if(inBuf->lastreaminbitlength > 0u)
		{
			/* If next bit is 1, next byte is uncompressed*/
			if ( (inBuf->lastreaminbit >> (inBuf->lastreaminbitlength-1u)) == 1u)
			{
				for(i = 0; i < (inBuf->lastreaminbitlength - 1u); i++ )
				{
					lastreamindata += (uint16)1u << i;
				}
				/* Get remain uncompressed byte */
				lastreamindata = inBuf->lastreaminbit & lastreamindata;
				lastreamindata = lastreamindata << (8u - inBuf->lastreaminbitlength + 1u);
				/* Get uncompressed byte */
				outByte = (uint8) Lzss_InputBits( inBuf, (uint32)(8uL - inBuf->lastreaminbitlength + 1u));
				outByte += (uint8)lastreamindata;

				/* If next bit is 1,use (8-inBuf->lastreaminbitlength + 1) bit data*/
				bitlength = bitlength - (8uL - inBuf->lastreaminbitlength + 1u);

				/* Output byte*/
				Lzss_OutputByte(outByte, outBuf);
				/* Add byte in window */
				LZSS_window[ winPos ] = outByte;
				/* Increase window position */
				winPos = LZSS_MOD_WINDOW( winPos + 1u );
				/*clear lastreamindatat*/
				lastreamindata = 0;
				/*clear lastreaminbitlength*/
				inBuf->lastreaminbitlength = 0;
			}
			else
			{
				/*if lastreaminbitlength <= LZSS_INDEX_BIT_COUNT + 1*/
				if(inBuf->lastreaminbitlength <= (LZSS_INDEX_BIT_COUNT + 1u))
				{
					lastreamindata = 0;
					for(i = 0; i < (inBuf->lastreaminbitlength-1u);i++ )
					{
						lastreamindata += (uint16)1u << i;
					}
					/* Get remain uncompressed byte */
					lastreamindata = inBuf->lastreaminbit & lastreamindata;
					lastreamindata = lastreamindata << (LZSS_INDEX_BIT_COUNT - inBuf->lastreaminbitlength+1u);
					if((LZSS_INDEX_BIT_COUNT - inBuf->lastreaminbitlength+1u) != 0u)
					{
						/* Get compressed data as window position of match*/
						matchPos = (uint16) Lzss_InputBits( inBuf, LZSS_INDEX_BIT_COUNT - (uint32)inBuf->lastreaminbitlength + 1uL );
						/* If next bit is 0,use 15 bit data*/
						bitlength = bitlength - (LZSS_INDEX_BIT_COUNT - (uint32)inBuf->lastreaminbitlength + 1uL );
					}
					matchPos += lastreamindata;
					/* Get length of string match */
					matchLen = (uint8) Lzss_InputBits( inBuf, LZSS_LENGTH_BIT_COUNT );

					bitlength = bitlength - LZSS_LENGTH_BIT_COUNT;

					/*clear lastreamindatat*/
					lastreamindata = 0;
					/*clear lastreaminbitlength*/
					inBuf->lastreaminbitlength = 0;
				}
				else
				{
					lastreamindata = 0;
					for(i = inBuf->lastreaminbitlength-LZSS_INDEX_BIT_COUNT-1u; i < (inBuf->lastreaminbitlength-1u);i++ )
					{
						lastreamindata += (uint16)1u<<i;
					}
					/* Get remain uncompressed byte */
					lastreamindata = inBuf->lastreaminbit & lastreamindata;
					matchPos = lastreamindata>>(inBuf->lastreaminbitlength-LZSS_INDEX_BIT_COUNT-1u);

					lastreamindata = 0;
					for(i = 0; i < (inBuf->lastreaminbitlength-LZSS_INDEX_BIT_COUNT-1u);i++ )
					{
						lastreamindata += (uint16)1u<<i;
					}
					lastreamindata = inBuf->lastreaminbit & lastreamindata;
					lastreamindata = lastreamindata << (LZSS_LENGTH_BIT_COUNT - ((uint32)inBuf->lastreaminbitlength - LZSS_INDEX_BIT_COUNT - 1uL));
					/* Get length of string match */
					matchLen = (uint8) Lzss_InputBits(inBuf, LZSS_LENGTH_BIT_COUNT - ((uint32)inBuf->lastreaminbitlength - LZSS_INDEX_BIT_COUNT - 1uL));
					matchLen += (uint8)lastreamindata;
					bitlength = bitlength - (LZSS_LENGTH_BIT_COUNT - ((uint32)inBuf->lastreaminbitlength - LZSS_INDEX_BIT_COUNT - 1uL));

					/*clear lastreamindatat*/
					lastreamindata = 0;
					/*clear lastreaminbitlength*/
					inBuf->lastreaminbitlength = 0;
				}
				/* Add break even + 1 to get the correct length. Length zero and
				* the break even value are subtracted from the length during
				* compression to save space. */
				matchLen = matchLen + (LZSS_BREAK_EVEN +1u);
				/* For every byte in match */
				for ( i = 0 ; i < matchLen ; i++ )
				{
					/* Get matching byte from window */
					outByte = LZSS_window[ LZSS_MOD_WINDOW( matchPos + i ) ];
					/* Output byte */
					Lzss_OutputByte(outByte, outBuf);
					/* Add matched byte to current window position */
					LZSS_window[ winPos ] = outByte;
					/* Increase window position */
					winPos = LZSS_MOD_WINDOW( winPos + 1u );
				}
			}
		}
		else
		{
			/* If next bit is 1, next byte is uncompressed*/
			if ( Lzss_InputBit( inBuf ) == 1u)
			{
				if(bitlength < 9u)
				{
					/*Get the remaining bits*/
					outBuf->lastreaminbit = (uint16)Lzss_InputBits( inBuf, (uint32)bitlength -1u );
					outBuf->lastreaminbit += (uint16)1u << ((uint8)bitlength -1u);
					/*Get the remaining bits length*/
					outBuf->lastreaminbitlength =(uint8) bitlength;
					break;
				}

				/* If next bit is 1,use 9 bit data*/
				bitlength = bitlength - 9u;
				/* Get uncompressed byte */
				outByte = (uint8) Lzss_InputBits( inBuf, (uint8)8 );
				/* Output byte*/
				Lzss_OutputByte(outByte, outBuf);
				/* Add byte in window */
				LZSS_window[ winPos ] = outByte;
				/* Increase window position */
				winPos = LZSS_MOD_WINDOW( winPos + 1u );
			}
			/* If next bit is 0, compressed data follows */
			else
			{
				if(bitlength < 15u)
				{
					/*Get the remaining bits*/
					outBuf->lastreaminbit = (uint16)Lzss_InputBits( inBuf, (uint32)bitlength-1u );
					/*Get the remaining bits length*/
					outBuf->lastreaminbitlength = (uint8) bitlength;
					break;
				}

				/* If next bit is 0,use 15 bit data*/
				bitlength = bitlength - 15u;
				/* Get compressed data as window position of match*/
				matchPos = (uint16) Lzss_InputBits( inBuf, LZSS_INDEX_BIT_COUNT );
				/* If end of stream, exit */
				if ( matchPos == LZSS_END_OF_STREAM )
				{
					eosReached = TRUE;
				}
				else
				{
					/* Get length of string match */
					matchLen = (uint8) Lzss_InputBits( inBuf, LZSS_LENGTH_BIT_COUNT );
					/* Add break even + 1 to get the correct length. Length zero and
					* the break even value are subtracted from the length during
					* compression to save space. */
					matchLen = matchLen + (LZSS_BREAK_EVEN +1u);
					/* For every byte in match */
					for ( i = 0 ; i < matchLen ; i++ )
					{
						/* Get matching byte from window */
						outByte = LZSS_window[ LZSS_MOD_WINDOW( matchPos + i ) ];
						/* Output byte */
						Lzss_OutputByte(outByte, outBuf);
						/* Add matched byte to current window position */
						LZSS_window[ winPos ] = outByte;
						/* Increase window position */
						winPos = LZSS_MOD_WINDOW( winPos + 1u );
					}
				}
			}
		}
	}
}

/******************************************************************************/
/**
 * @brief               <Input Bit.>
 *
 * <Input Bit.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <param inBuf Input data buffer with bit access>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <return the bit is ok or not >
 */
/******************************************************************************/
static boolean Lzss_InputBit(BIT_BUFF * bitbuff)
{
	uint32 value;
	boolean ret;
	if ( bitbuff->mask == 0x80u )
	{
		bitbuff->rack = *(bitbuff->buff+bitbuff->PcCount);
		bitbuff->PcCount++;
		bitbuff->pacifier_counter++;
	}
	value = bitbuff->rack & bitbuff->mask;
	bitbuff->mask >>= 1u;
	if ( bitbuff->mask == 0u )
	{
		bitbuff->mask = 0x80u;
	}

	/* if value not zero ,return 1 */
	if(value != 0u)
	{
		ret = 1u;
	}
	else
	{
		ret = 0u;
	}
	return ret;
}

/******************************************************************************/
/**
 * @brief               <Input Bits.>
 *
 * <Input Bit.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <param inBuf Input data buffer with bit access>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static uint32 Lzss_InputBits(BIT_BUFF *bitbuff,uint32 bit_count)
{
	uint32 mask;
	uint32 return_value;
	mask = 1uL << ( bit_count - 1u );
	return_value = 0;
	while ( mask != 0u)
	{
		if ( bitbuff->mask == 0x80u )
		{
			bitbuff->rack = *(bitbuff->buff + bitbuff->PcCount);
			bitbuff->PcCount++;
			bitbuff->pacifier_counter++;
		}
		if ( (bitbuff->rack & bitbuff->mask) != 0u )
		{
			return_value |=mask;
		}
		mask >>= 1u;
		bitbuff->mask >>= 1u;
		if ( bitbuff->mask == 0u )
		{
			bitbuff->mask = 0x80u;
		}
	}
	return( return_value );
}

/******************************************************************************/
/**
 * @brief               <Output Bits.>
 *
 * <Input Bit.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <param output Input data buffer with bit access>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Lzss_OutputByte(uint8 buffer, BIT_BUFF *byte)
{
	*(byte->buff+byte->PcCount) = buffer;
	byte->PcCount++;
}
