/*----------------------------------------------------------------------------+
 (c) NXP B.V. 2009-2010. All rights reserved.

 Disclaimer
 1. The NXP Software/Source Code is provided to Licensee "AS IS" without any
    warranties of any kind. NXP makes no warranties to Licensee and shall not
    indemnify Licensee or hold it harmless for any reason related to the NXP
    Software/Source Code or otherwise be liable to the NXP customer. The NXP
    customer acknowledges and agrees that the NXP Software/Source Code is
    provided AS-IS and accepts all risks of utilizing the NXP Software under
    the conditions set forth according to this disclaimer.

 2. NXP EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING,
    BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS
    FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT OF INTELLECTUAL PROPERTY
    RIGHTS. NXP SHALL HAVE NO LIABILITY TO THE NXP CUSTOMER, OR ITS
    SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY FOR ANY DAMAGES,
    INCLUDING WITHOUT LIMITATION, DAMAGES RESULTING OR ALLEGDED TO HAVE
    RESULTED FROM ANY DEFECT, ERROR OR OMMISSION IN THE NXP SOFTWARE/SOURCE
    CODE, THIRD PARTY APPLICATION SOFTWARE AND/OR DOCUMENTATION, OR AS A
    RESULT OF ANY INFRINGEMENT OF ANY INTELLECTUAL PROPERTY RIGHT OF ANY
    THIRD PARTY. IN NO EVENT SHALL NXP BE LIABLE FOR ANY INCIDENTAL,
    INDIRECT, SPECIAL, EXEMPLARY, PUNITIVE, OR CONSEQUENTIAL DAMAGES
    (INCLUDING LOST PROFITS) SUFFERED BY NXP CUSTOMER OR ITS SUBSIDIARIES,
    AFFILIATES, OR ANY OTHER THIRD PARTY ARISING OUT OF OR RELATED TO THE NXP
    SOFTWARE/SOURCE CODE EVEN IF NXP HAS BEEN ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGES.

+-----------------------------------------------------------------------------+
|                                                                             |
|       Project: AES Crypt Module for a 8051 uC                               |
|                                                                             |
+-----------------------------------------------------------------------------+
| Date      | File Version | Comment                                          |
+-----------------------------------------------------------------------------+
|	17-Nov-09 | 1.0 |   		    | Initial Version used for HT-Pro and HT-AES    |
+-----------------------------------------------------------------------------+
| Description                                                                 |
|                                                                             |
|  HT-AES secutity Algorithm Files for 8051 based PJF7992 Evaluation system.  |
|  This file is intended to be linked to the PJF7992 Evaluation project.      |
|                                                                             |
+----------------------------------------------------------------------------*/
#include "Immo_AES128SWEnc.h"
     
//*******************************************************************
// local functions
void CopyKey (BYTE IDATA * pcAESSecretKey, BYTE IDATA * pcAESKey);

void AddRoundKey(BYTE IDATA * pcAESInreg, BYTE IDATA * pcAESKey);
void ByteSub (BYTE IDATA * pcAESInreg);
void ShiftRowMSB (BYTE IDATA * pcAESInreg);
void MixColumnMSB (BYTE IDATA * pcAESInreg);
void KeyScheduleMSB (BYTE IDATA * pcAESKey, unsigned int * piRCON);
//*******************************************************************
// S-Box Table
BYTE XDATA cSBox[256] =
{
  99, 124, 119, 123, 242, 107, 111, 197,  48,   1, 103,  43, 254, 215, 171,
  118, 202, 130, 201, 125, 250,  89,  71, 240, 173, 212, 162, 175, 156, 164,
  114, 192, 183, 253, 147,  38,  54,  63, 247, 204,  52, 165, 229, 241, 113,
  216,  49,  21,  4, 199,  35, 195,  24, 150,   5, 154,   7,  18, 128, 226,
  235,  39, 178, 117,  9, 131,  44,  26,  27, 110,  90, 160,  82,  59, 214,
  179,  41, 227,  47, 132, 83, 209,   0, 237,  32, 252, 177,  91, 106, 203,
  190,  57,  74,  76,  88, 207, 208, 239, 170, 251,  67,  77,  51, 133,  69,
  249,   2, 127,  80,  60, 159, 168, 81, 163,  64, 143, 146, 157,  56, 245,
  188, 182, 218,  33,  16, 255, 243, 210, 205,  12,  19, 236,  95, 151,  68,
  23, 196, 167, 126,  61, 100,  93,  25, 115, 96, 129,  79, 220,  34,  42,
  144, 136,  70, 238, 184,  20, 222,  94,  11, 219, 224,  50,  58,  10,  73,
  6,  36,  92, 194, 211, 172,  98, 145, 149, 228, 121, 231, 200,  55, 109,
  141, 213,  78, 169, 108,  86, 244, 234, 101, 122, 174,   8, 186, 120,  37,
  46,  28, 166, 180, 198, 232, 221, 116,  31,  75, 189, 139, 138, 112,  62,
  181, 102,  72,   3, 246,  14,  97,  53,  87, 185, 134, 193,  29, 158, 225,
  248, 152,  17, 105, 217, 142, 148, 155,  30, 135, 233, 206,  85,  40, 223,
  140, 161, 137,  13, 191, 230,  66, 104,  65, 153,  45,  15, 176,  84, 187,
  22,
};
//*******************************************************************
// local variables
BYTE cAESPointer;
BYTE IDATA cAESInreg[16];

//*******************************************************************
void AESInit (BYTE IDATA * pcAESInbuf)
/******************************************************************************
*                                                                             *
* Description: Copy inbuf data to local inreg once during authentication.     *
*              inreg keeps the result AES string after calculation. Thus      *
*              this operation prevents from later output feedback copy.       *
*              For HT-Pro, inbuf contains of SI, IDE and Challenge.           *
*                                                                             *
* Parameters:  pcAESInbuf   pointer to AES in-buffer, delivered via Authent   *
*                                                                             *
* Result:      None                                                           *
*                                                                             *
******************************************************************************/
{
  BYTE i;
  // copy data to AESInreg once to prevent later output feedback operation
  for (i=0; i<16; i++)
  {
    cAESInreg[i] = pcAESInbuf[i];          
  }
} 
//*******************************************************************
void AESCrypt (BYTE IDATA * pcAESData, BYTE cAESLen)
/******************************************************************************
*                                                                             *
* Description: Encrypt or decrypt given data bytes by XORing it with AES      *
*              data in local inreg buffer. Update global aes_pointer to       *
*              mark next unused AES data in inreg.                            *
*                                                                             *
* Parameters:  pcAESData   pointer to data to be encrypted or decrypted       *
*              cAESLen     number of bytes to be XORed, max. less than 16     *
*                                                                             *
* Result:      None                                                           *
*                                                                             *
******************************************************************************/
{
  BYTE i;        

  for (i=0; i<cAESLen; i++)
  {
    if ((cAESPointer + i) < 16)
    {
      pcAESData[i] = pcAESData[i] ^ cAESInreg[cAESPointer + i];       // encrypt or decrypt data
    }
  }
  if (cAESPointer + cAESLen < 16)
  {
    cAESPointer = cAESPointer + cAESLen;
  }
}
//*******************************************************************
void AES128Enc (BYTE IDATA * pcAESSecretKey)
/******************************************************************************
*                                                                             *
* Description: Main routine to calculate new AES data. Deliver original       *
*              secret key, because it is defined in main.c, in case of        *
*              convenience reasons for users.                                 *
*                                                                             *
* Parameters:  pcAESSecretKey   pointer to secret key defined in main.c       *
*                                                                             *
* Result:      None                                                           *
*                                                                             *
******************************************************************************/
{
  BYTE cCount;
  unsigned int iRCON;
  BYTE IDATA cAESKey[16];

  //**************************************
  cCount = 9;    // number of calculation rounds
  iRCON = 1;     // RCON seed value
  
  CopyKey (pcAESSecretKey, cAESKey);      // rescue secret key
  
  AddRoundKey (cAESInreg, cAESKey);
  
  while (cCount > 0)
  {  
    ByteSub (cAESInreg);
    
    ShiftRowMSB (cAESInreg);
   
    MixColumnMSB (cAESInreg);
  
    KeyScheduleMSB (cAESKey, &iRCON);
    
    AddRoundKey (cAESInreg, cAESKey);

    cCount--;
  }

  // final round
  ByteSub (cAESInreg);
  ShiftRowMSB (cAESInreg);
  KeyScheduleMSB (cAESKey, &iRCON);
  AddRoundKey (cAESInreg, cAESKey);

  cAESPointer = 0;        // reset aes pointer
}
//*******************************************************************
void CopyKey (BYTE IDATA * pcAESSecretKey, BYTE IDATA * pcAESKey)
/******************************************************************************
*                                                                             *
* Description: Copy original secret key from main.c to local global           *
*              secret key variable. This data is overwritten during           *
*              calculation. Thus the data must be restored before             *
*              next calculation round.                                        *
*                                                                             *
* Parameters:  pcAESSecretKey   pointer to secret key defined in main.c       *
*              pcAESKey         pointer to local global secret key            *
*                                                                             *
* Result:      None                                                           *
*                                                                             *
******************************************************************************/
{
  BYTE i;

  // restore key for next round
  for (i=0; i<16; i++)
  {
    pcAESKey[i] = pcAESSecretKey[i];
  }
}

//*******************************************************************

void AddRoundKey(BYTE IDATA * pcAESInreg, BYTE IDATA * pcAESKey)
/******************************************************************************
*                                                                             *
* Description: The inreg data is XORed with the secret key data and written   *
*              back to inreg for next calculation steps.                      *
*                                                                             *
* Parameters:  pcAESInreg   pointer to current inreg data                     *
*              pcAESKey     pointer to local global secret key                *
*                                                                             *
* Result:      None                                                           *
*                                                                             *
******************************************************************************/
{
  BYTE i;
  // calculate ([AESInreg] xor [AESKey]) for all elements
  for (i=0; i<16; i++)
  {
    pcAESInreg[i] = pcAESInreg[i] ^ pcAESKey[i];
  }
}
//*******************************************************************
void ByteSub (BYTE IDATA * pcAESInreg)
/******************************************************************************
*                                                                             *
* Description: Replace inreg data with data extracted from S-Box ,            *
*              use AESInreg[i] as index to S-Box table.                       *
*                                                                             *
* Parameters:  pcAESInreg   pointer to current inreg data                     *
*                                                                             *
* Result:      None                                                           *
*                                                                             *
******************************************************************************/
{
  BYTE i;
  
  for (i=0; i<16; i++)
  {
    pcAESInreg[i] = cSBox[cAESInreg[i]];
  }
}
//*******************************************************************
void ShiftRowMSB (BYTE IDATA * pcAESInreg)
/******************************************************************************
*                                                                             *
* Description: Interpret data in inreg array as column table,                 *
*              shift the table rows using a special shifting scheme.          *
*                                                                             *
* Parameters:  AESInreg   pointer to current inreg data                       *
*                                                                             *
* Result:      None                                                           *
*                                                                             *
*                                                                             *
******************************************************************************/
{
  BYTE i, j;     

  BYTE IDATA cOut[16];

  /*
  Shift Algorithm for inreg array as column matrix:
  ---------------------------------------------------------
  in0   in4   in8   in12  | << 1 |  in4   in8   in12  in0
  in1   in5   in9   in13  | << 2 |  in9   in13  in1   in5
  in2   in6   in10  in14  | << 3 |  in14  in2   in6   in10
  in3   in7   in11  in15  | << 0 |  in3   in7   in11  in15
  ---------------------------------------------------------
  Index notation according to shift distance:
     <<1         <<2         <<3         <<0
  0  <-  4    1  <-  9    2  <-  14   3  <-  3
  4  <-  8    5  <-  13   6  <-  2    7  <-  7
  8  <-  12   9  <-  1    10 <-  6    11 <-  11
  12 <-  0    13 <-  5    14 <-  10   15 <-  15

  Index calculation:
  ind_a gives the index position in the result array,
  ind_b gives the index position in the current inreg array.

  ind_a: j=0: [0,4,8,12], j=1: [1,5,9,13], j=2: [2,6,10,14], j=3: [3,7,11,15]
  ind_b: j=0: [4,8,12,0], j=1: [9,13,1,5], j=2: [14,2,6,10], j=3: [3,7,11,15]

  Remark: due to optimization reasons these variables are replaced, index is calculated directly 
  */

  for (j=0; j<4; j++)
  {
    for (i=0; i<4; i++)
    {
      //ind_a = (i*4)+j;
      //ind_b = (((i+1+j)*4)+j)%16;
      //out[ind_a] = AESInreg[ind_b];
      cOut[(i*4)+j] = pcAESInreg[(((i+1+j)*4)+j)%16];
    }
  }
  // move result of shifting in [out] back to [AESInreg]
  for (i=0; i<16; i++)
  {
    pcAESInreg[i] = cOut[i];
  }
}
//*******************************************************************
void MixColumnMSB (BYTE IDATA * pcAESInreg)
/******************************************************************************
*                                                                             *
* Description: Extract rows of data from inreg array, calculate               *
*              a result using a special algorithm and write back              *
*              data to the same inreg position.                               *
*                                                                             *
* Parameters:  pcAESInreg   pointer to current inreg data                     *
*                                                                             *
* Result:      None                                                           *
*                                                                             *
*                                                                             *
******************************************************************************/
{
  BYTE k;
  BYTE n=0;     
  int i;                // int necessary because of negativ lower limit (-1)!
  BYTE j;       
  BYTE IDATA cTemp[4];

  unsigned int iResult;

  BYTE cAll;

  for (j=0; j<4; j++)
  {
    k=0;    // index for temp

    /*
    extract data from [AESInreg]: temp[k], in[i]
    --------------+-----+------+------+
    round j:   0  |  1  |  2   |  3   |
    --------------+-----+------+------+
      temp0 = in3 | in7 | in11 | in15 |
      temp1 = in2 | in6 | in10 | in14 |
      temp2 = in1 | in5 | in9  | in13 |
      temp3 = in0 | in4 | in8  | in12 |

    */
    for (i=3; i>-1; i--)
    {
      cTemp[k++] = pcAESInreg[j*4+i];  // get 4 bytes from AESInreg [n,n-1,n-2,n-3], n={3,7,11,15}
    }
   
    cAll = (cTemp[0] ^ cTemp[1] ^ cTemp[2] ^ cTemp[3]);    // overall xor for one column

    n = 3;  // index-offset for out array

    for (i=0; i<4; i++)
    {
      /* calculate:
         (temp0 xor temp1) << 1
         (temp1 xor temp2) << 1
         (temp2 xor temp3) << 1
         (temp3 xor temp0) << 1        ensure index wrap around by modulo operation

         the shift operation is already part of xtime
      */
      iResult = (unsigned int)((cTemp[i] ^ cTemp[(i+1)%4]) << 1);   // cast to int to observe overflow later

      // xtime (result)
      if (iResult > 255)         // if overflow
        iResult = iResult ^ 0x1B;

      /*
        write back data to AESInreg use n=[3:0], j=[0:3] as index offset

        in3 = in3 xor xtime(in3 xor in2) xor (in0 xor in1 xor in2 xor in3)
        in2 = in2 xor xtime(in2 xor in1) xor (in0 xor in1 xor in2 xor in3)
        in1 = in1 xor xtime(in1 xor in0) xor (in0 xor in1 xor in2 xor in3)
        in0 = in0 xor xtime(in0 xor in3) xor (in0 xor in1 xor in2 xor in3)

        in7 = ...etc.
      */      
      pcAESInreg[j*4+n] = ((BYTE)iResult) ^ cAll ^ cTemp[i];   // sort output to correct order
 
      n--;    // decrement index
    }
  }
}
//*******************************************************************
void KeyScheduleMSB (BYTE IDATA * pcAESKey, unsigned int * piRCON)
/******************************************************************************
*                                                                             *
* Description: Interpret secret key array as column matrix.                   *
*              a result using a special algorithm and write back              *
*              data to same inreg position.                                   *
*                                                                             *
* Parameters:  pcAESKey   pointer to current secret key data                  *
*              piRCON     pointer to RCON value                               *
*                                                                             *
* Result:      None                                                           *
*                                                                             *
*                                                                             *
******************************************************************************/
/* KeyScheduleMSB

     original key, interpreted as column matrix:

     key0   key4   key8   key12
     key1   key5   key9   key13
     key2   key6   key10  key14
     key3   key7   key11  key15
   -----------------------------
      w0     w1     w2      w3

  calculate:
  w3 = w3 xor rot(S(w0)) xor RCON[1]
  w2 = w2 xor w3
  w1 = w1 xor w2
  w0 = w0 xor w1

  S(w0) = index access to S-Box table

       | a |   | d |                     | S[key3] |
       | b |   | a |                     | S[key0] |
   rot | c | = | b |   =>  rot (S(w0)) = | S[key1] |
       | d |   | c |                     | S[key2] |

            |   0     |
            |   0     |
  RCON[i] = |   0     | and RCON(i) = xtime(RCON(i-1)), the initial value RCON(1) = 0x01
            | RCON(i) |

  ergo:

  w3:                                       w2:
  key12 = key12 xor S[key3]                 key8  = key8  xor key12
  key13 = key13 xor S[key0]                 key9  = key9  xor key13
  key14 = key14 xor S[key1]                 key10 = key10 xor key14
  key15 = key15 xor S[key2] xor RCON(i)     key11 = key11 xor key15

  w1:                                       w0:
  key4 = key4 xor key8                      key0 = key0 xor key4
  key5 = key5 xor key9                      key1 = key1 xor key5
  key6 = key6 xor key10                     key2 = key2 xor key6
  key7 = key7 xor key11                     key3 = key3 xor key7

  */
{
  BYTE i;       

  pcAESKey[15] = pcAESKey[15] ^ cSBox[pcAESKey[2]] ^ *piRCON;
  pcAESKey[14] = pcAESKey[14] ^ cSBox[pcAESKey[1]];
  pcAESKey[13] = pcAESKey[13] ^ cSBox[pcAESKey[0]];
  pcAESKey[12] = pcAESKey[12] ^ cSBox[pcAESKey[3]];

  for (i=15; i>3; i--)
  {
    pcAESKey[i-4] = pcAESKey[i-4] ^ pcAESKey[i];
  }
  
  // xtime (RCON)
  *piRCON = *piRCON << 1;

  if (*piRCON > 255)
    *piRCON = *piRCON ^ 0x1B;   // if overflow

  *piRCON = *piRCON & 0xFF;     // mask to 8 bit to cut possible overflow
}
