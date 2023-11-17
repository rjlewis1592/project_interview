#ifndef STACK_UTILS_H_
#define STACK_UTILS_H_

#include "stack_cmn.h"

stk_t *create_stack_entry(int value);
void stack_destroy(stk_t **st);
void stack_display(stk_t **st);
bool is_stack_empty(stk_t **st);
int stack_peek(stk_t **st);

#endif // STACK_UTILS_H_