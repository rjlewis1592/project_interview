#ifndef CBUF_UTILS_H_
#define CBUF_UTILS_H_

#include "cbuf_cmn.h"

cbuf_t *cb_create(int cb_capacity);
void cb_destroy(cbuf_t *cb);

void cb_reset_indices(cbuf_t *cb);
int cb_display(const cbuf_t *cb);
void cb_print_status(const cbuf_t *cb);

bool is_cb_empty(const cbuf_t *cb);
bool is_cb_full(const cbuf_t *cb);

//static void cb_init(cbuf_t *cb, int cb_capacity);

#endif // CBUF_UTILS_H_