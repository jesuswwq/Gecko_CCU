/*
* SEMIDRIVE Copyright Statement
* Copyright (c) SEMIDRIVE. All rights reserved
*
* This software and all rights therein are owned by SEMIDRIVE, and are
* protected by copyright law and other relevant laws, regulations and
* protection. Without SEMIDRIVE's prior written consent and/or related rights,
* please do not use this software or any potion thereof in any form or by any
* means. You may not reproduce, modify or distribute this software except in
* compliance with the License. Unless required by applicable law or agreed to
* in writing, software distributed under the License is distributed on
* an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
*
* You should have received a copy of the License along with this program.
* If not, see <http://www.semidrive.com/licenses/>.
*/

#ifdef __cplusplus
extern "C" {
#endif

#include "ring.h"
#include <mini_libc.h>
// #include <stddef.h>

#define min(a,b) ( (a) < (b) )? (a):(b)

#define LIB_START_SEC_CODE
#include "Lib_MemMap.h"

/**
  * @brief  Initialize an empty ring buffer
  *
  * @note   Here size is a buffer of size 2^size bytes.
  *
  * @param  r ring buffer control block
  * @param  mem points to a memory block
  * @param  size The size of the memory block.
  *
  * @retval -1 error
  *         -0 pass
  */
int ring_buf_create(ring_buf_t *r, unsigned char *buf, unsigned int size)
{
    if (r && buf) {
        r->buf = buf;
        r->size = (0x00000001 << size);
        r->front = r->rear = 0;
    } else {
        return 1;
    }

    return 0;
}
/**
  * @brief  clear ring buffer
  *
  * @param  r Ring buffer control block
  *
  * @retval None
  */
void ring_buf_clr(ring_buf_t *r)
{
    r->front = r->rear = 0;
}
/**
  * @brief  Get ring buffer capacity (byte)
  *
  * @param  r Ring buffer control block
  *
  * @retval Number of valid bytes in buffer
  */
unsigned int ring_buf_len(ring_buf_t *r)
{
    return (unsigned int)(r->rear - r->front);
}
/**
  * @brief  write data to the buffer
  *
  * @note   Here, if the buffer cannot write all the data to be written, the function will return the
  *         length of the data that can be written.
  *
  * @param  r Ring buffer control block
  * @param  buf The block of data to be written.
  * @param  len The size of the data block to be written.
  *
  * @retval The number of bytes actually written to the buffer
  *
  */
unsigned int ring_buf_put(ring_buf_t *r, unsigned char *buf, unsigned int len)
{
    unsigned int l;
    /* Take the smallest of the free memory and the length of the data to be written */
    len = min(len, r->size + r->front - r->rear);
    /* Take the smallest of the length of the second half of the free memory and the length of the data to be written */
    l = min(len, r->size - (r->rear & (r->size - 1)));
    /* The default free memory is discontinuous and copied in two parts ---> |00001111111100000*/
    memcpy(r->buf + (r->rear & (r->size - 1)), buf, l);
    memcpy(r->buf, buf + l, len - l);
    /* Directly move the write pointer, and it can still be calculated normally when it overflows */
    r->rear += len;
    return len;

}
/**
  * @brief  read data from buffer
  *
  * @note   Here, if the buffer does not have enough data, the function will read all the data in the buffer.
  *
  * @param  r Ring buffer control block
  * @param  buf The read data storage address.
  * @param  len The size of the data block to be read.
  *
  * @retval The number of bytes actually read into the buffer
  *
  */
unsigned int ring_buf_get(ring_buf_t *r, unsigned char *buf, unsigned int len)
{
    unsigned int l;
    /*Take the smallest of the valid data and the length of the data to be read*/
    len = min(len, r->rear - r->front);
    /*Take the smallest of the length of the second half of the valid data and the length of the data to be written*/
    l = min(len, r->size - (r->front & (r->size - 1)));
    /* Default data is separate ---> |1111110000000001111111*/
    memcpy(buf, r->buf + (r->front & (r->size - 1)), l);
    memcpy(buf + l, r->buf, len - l);
    /* Move directly to read the pointer, and it can still be calculated normally when it overflows */
    r->front += len;
    return len;
}

#define LIB_STOP_SEC_CODE
#include "Lib_MemMap.h"

#ifdef __cplusplus
}
#endif
