#ifndef QUEUE_UTILS_H_
#define QUEUE_UTILS_H_

#include "queue_cmn.h"

int queue_create(queue_t **q);
void queue_display(queue_t *q);
void queue_exit(queue_t *q);
bool is_queue_empty(queue_t *q);
void print_queue_status(queue_t *q);

#endif // QUEUEU_UTILS_H_