#ifndef STACK_UTILS_H_
#define STACK_UTILS_H_

#include "stack_cmn.h"

stk_t *stack_create(int capacity);
void stack_destroy(stk_t *st);
void stack_display(stk_t *st);
bool is_stack_empty(stk_t *st);
bool is_stack_full(stk_t *st);
int stack_peek(stk_t *st);

#endif // STACK_UTILS_H_