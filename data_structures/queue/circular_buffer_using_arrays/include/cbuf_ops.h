#ifndef CBUF_OPS_H_
#define CBUF_OPS_H_

#include "cbuf_cmn.h"

/* Function declarations */
void cb_deinit(cbuf_t *cb);
int cb_enqueue(cbuf_t *cb, int value);
int cb_dequeue(cbuf_t *cb,int *data);

#endif // CBUF_OPS_H_
