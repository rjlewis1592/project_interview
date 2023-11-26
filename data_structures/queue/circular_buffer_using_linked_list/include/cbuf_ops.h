#ifndef CBUF_OPS_H_
#define CBUF_OPS_H_

#include "cbuf_cmn.h"

int cbuf_enqueue(cbuf_t *q, int value);
int cbuf_dequeue(cbuf_t *q);

#endif // CBUF_OPS_H_
