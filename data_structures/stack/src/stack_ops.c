#include "stack_defs.h"
#include "stack_cmn.h"
#include "stack_ops.h"
#include "stack_utils.h"

int stack_push(stk_t *st, int item)
{
	if (st == NULL) {
		LOG_ERR("st %p", st);
		return STACK_OPS_FAILURE;
	}

	if (is_stack_full(st) == true) {
		LOG_DBG("stack overflow");
		return STACK_OPS_FAILURE;
	}

	if (st->arr == NULL) {
		LOG_ERR("memory not allocated for stack data");
		return STACK_OPS_FAILURE;
	}

	st->arr[++st->top] = item;

	return STACK_OPS_SUCCESS;
}

int stack_pop(stk_t *st)
{
	if (st == NULL) {
		LOG_ERR("st %p", st);
		return STACK_OPS_FAILURE;
	}

	if (is_stack_empty(st) == true) {
		LOG_DBG("stack underflow, st->top %d", st->top);
		return STACK_OPS_FAILURE;
	}

	if (st->arr == NULL) {
		LOG_ERR("memory not allocated for stack data");
		return STACK_OPS_FAILURE;
	}

	LOG_DBG("popping %d, st->top %d", st->arr[st->top], st->top);

	memset(&st->arr[st->top], 0, sizeof(int));

	st->top--;

	return STACK_OPS_SUCCESS;
}
