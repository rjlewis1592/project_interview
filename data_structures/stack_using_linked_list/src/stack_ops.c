#include "stack_defs.h"
#include "stack_cmn.h"
#include "stack_ops.h"
#include "stack_utils.h"

int stack_push(stk_t **st, int value)
{
	stk_t *new_entry = NULL;

	if (st == NULL) {
		LOG_ERR("st %p", st);
		return STACK_OPS_FAILURE;
	}

	new_entry = create_stack_entry(value);
	if (new_entry == NULL) {
		LOG_DBG("could not create new stack entry for value %d", value);
		return STACK_OPS_FAILURE;
	}

	new_entry->next = *st;
	*st = new_entry;

	return STACK_OPS_SUCCESS;
}

int stack_pop(stk_t **st)
{
	stk_t *temp = NULL;

	if (st == NULL) {
		LOG_ERR("st %p", st);
		return STACK_OPS_FAILURE;
	}

	if ((*st) == NULL) {
		LOG_DBG("stack underflow - *st %p", *st);
		return STACK_OPS_FAILURE;
	}

	temp = *st;
	*st = (*st)->next;
	memset(temp, 0, sizeof(stk_t));
	free(temp);
	temp = NULL;

	return STACK_OPS_SUCCESS;
}
