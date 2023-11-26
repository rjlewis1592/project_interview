#ifndef CBUF_UTILS_H_
#define CBUF_UTILS_H_

#include "cbuf_cmn.h"

int cbuf_create(cbuf_t **q);
void cbuf_display(cbuf_t *q);
void cbuf_exit(cbuf_t *q);
bool is_cbuf_empty( cbuf_t *q);
void print_cbuf_status(cbuf_t *q);

#endif // CBUF_UTILS_H_