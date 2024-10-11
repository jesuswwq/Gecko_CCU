// ------------------------------------------------------------------------------
// (c) NXP B.V. All rights reserved.
//
// Disclaimer
// 1. The NXP Software/Source Code is provided to Licensee "AS IS" without any
//    warranties of any kind. NXP makes no warranties to Licensee and shall not
//    indemnify Licensee or hold it harmless for any reason related to the NXP
//    Software/Source Code or otherwise be liable to the NXP customer. The NXP
//    customer acknowledges and agrees that the NXP Software/Source Code is
//    provided AS-IS and accepts all risks of utilizing the NXP Software under
//    the conditions set forth according to this disclaimer.
//
// 2. NXP EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING,
//    BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS
//    FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT OF INTELLECTUAL PROPERTY
//    RIGHTS. NXP SHALL HAVE NO LIABILITY TO THE NXP CUSTOMER, OR ITS
//    SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY FOR ANY DAMAGES,
//    INCLUDING WITHOUT LIMITATION, DAMAGES RESULTING OR ALLEGED TO HAVE
//    RESULTED FROM ANY DEFECT, ERROR OR OMISSION IN THE NXP SOFTWARE/SOURCE
//    CODE, THIRD PARTY APPLICATION SOFTWARE AND/OR DOCUMENTATION, OR AS A
//    RESULT OF ANY INFRINGEMENT OF ANY INTELLECTUAL PROPERTY RIGHT OF ANY
//    THIRD PARTY. IN NO EVENT SHALL NXP BE LIABLE FOR ANY INCIDENTAL,
//    INDIRECT, SPECIAL, EXEMPLARY, PUNITIVE, OR CONSEQUENTIAL DAMAGES
//    (INCLUDING LOST PROFITS) SUFFERED BY NXP CUSTOMER OR ITS SUBSIDIARIES,
//    AFFILIATES, OR ANY OTHER THIRD PARTY ARISING OUT OF OR RELATED TO THE NXP
//    SOFTWARE/SOURCE CODE EVEN IF NXP HAS BEEN ADVISED OF THE POSSIBILITY OF
//    SUCH DAMAGES.
//
// 3. NXP reserves the right to make changes to the NXP Software/Sourcecode any
//    time, also without informing customer.
//
// 4. Licensee agrees to indemnify and hold harmless NXP and its affiliated
//    companies from and against any claims, suits, losses, damages,
//    liabilities, costs and expenses (including reasonable attorney's fees)
//    resulting from Licensee's and/or Licensee customer's/licensee's use of the
//    NXP Software/Source Code.
// ------------------------------------------------------------------------------

#include "nxpMath.h"


// ------------------------------------------------------------------------------
// Definitions
// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------
// Variables
// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------
// Function definition
// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------
// Function implementation
// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------
// Convert NXP-format float (24-bit, 3 bytes) to IEEE standard float
// ------------------------------------------------------------------------------
float NXPFloat24_to_IEEEFloat( uint8_t * pu8_Float24 )
// ------------------------------------------------------------------------------
{
  union Trans {
    float FloatValue;                   // IEEE float value (single precision)
    uint8_t ByteValue[4];                  // Bytes of FloatValue
  } FloatTrans;
  uint8_t real_exp;

  if ( pu8_Float24[2] == 0x82 )
  {
    // real_exp = 0;                    // Exponent in IEEE-754 float
    FloatTrans.ByteValue[0] = ( pu8_Float24[0] & 0x01 ) ? 0x80 : 0x00;
    FloatTrans.ByteValue[1] = ( pu8_Float24[0] >> 1 )|( ( pu8_Float24[1] & 0x01 ) ? 0x80:0x00 );
    // Set bit m22=1, m21=m14, ...
    FloatTrans.ByteValue[2] = ( (pu8_Float24[1] & 0x7F) >> 1 ) | 0x40;
    FloatTrans.ByteValue[3] = ( pu8_Float24[1] & 0x80 ); // Sign bit and exp.=0
  }
  else if ( pu8_Float24[2] == 0x81 )
  {
    // real_exp = 0;	                  // Exponent in IEEE-754 float
    FloatTrans.ByteValue[0] = ( pu8_Float24[0] & 0x3 ) << 6 ;
    FloatTrans.ByteValue[1] = ( pu8_Float24[0] >> 2 ) | ( ( pu8_Float24[1] & 0x03 ) << 6 );
    // Set bit m22=0, m21=1, m20=m14, ...
    FloatTrans.ByteValue[2] = ( (pu8_Float24[1] & 0x7F) >> 2 ) | 0x20;
    FloatTrans.ByteValue[3] = ( pu8_Float24[1] & 0x80 );
  }
  else if( (pu8_Float24[2] == 0x80) )
  {
    if ( ( pu8_Float24[0] == 0 ) && ( ( pu8_Float24[1] & 0x7F ) == 0 ) )
    {
      // Mantissa = min, exp = min means value is zero!
      FloatTrans.FloatValue = 0.0;
    }
    else
    {
      // real_exp = 0;				          // Exponent in IEEE-754 float
      FloatTrans.ByteValue[0] = ( pu8_Float24[0] & 0x7 ) << 5 ;
      FloatTrans.ByteValue[1] = ( pu8_Float24[0] >> 3 ) | ( ( pu8_Float24[1] & 0x07 ) << 5 );
      // Set bit m22=m21=0, m20=1, m19=m14, ...
      FloatTrans.ByteValue[2] = ( (pu8_Float24[1] & 0x7F) >> 3 ) | 0x10;
      FloatTrans.ByteValue[3] = (  pu8_Float24[1] & 0x80 );
    }
  }
  else
  {
    // Normalized number in IEEE format
    real_exp = pu8_Float24[2] - 0x82;	  // or equiv.: real_exp = pu8_Float24[2] + 0x7E;
    FloatTrans.ByteValue[0] = 0;
    FloatTrans.ByteValue[1] = pu8_Float24[0];
    FloatTrans.ByteValue[2] = ( pu8_Float24[1] & 0x7F ) | ( (real_exp & 0x01) ? 0x80 : 0);
    FloatTrans.ByteValue[3] = ( real_exp /2 ) | ( pu8_Float24[1] & 0x80 );
  }
  return FloatTrans.FloatValue;
}
