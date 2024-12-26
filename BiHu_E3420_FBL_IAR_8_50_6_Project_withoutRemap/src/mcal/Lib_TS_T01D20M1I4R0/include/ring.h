/********************************************************
 *      Copyright(c) 2019   Semidrive  Semiconductor    *
 *      All rights reserved.                            *
 ********************************************************/
#ifndef RING_H
#define RING_H

typedef struct {
    unsigned char *buf;
    unsigned int size;
    unsigned int front;
    unsigned int rear;
} ring_buf_t;



int ring_buf_create(ring_buf_t *r, unsigned char *buf, unsigned int size);

void ring_buf_clr(ring_buf_t *r);

unsigned int ring_buf_len(ring_buf_t *r);

unsigned int ring_buf_put(ring_buf_t *r, unsigned char *buf, unsigned int len);

unsigned int ring_buf_get(ring_buf_t *r, unsigned char *buf, unsigned int len);

#endif

