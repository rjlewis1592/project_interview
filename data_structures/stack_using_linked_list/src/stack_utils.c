#include "stack_cmn.h"
#include "stack_defs.h"
#include "stack_utils.h"

stk_t* create_stack_entry(int value)
{
	stk_t *new_entry = (stk_t *)malloc(sizeof(stk_t));
	if (new_entry == NULL) {
		LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
		return NULL;
	}

	new_entry->data = value;
	new_entry->next = NULL;

	return new_entry;
}

void stack_destroy(stk_t **st)
{
	stk_t *temp = NULL;
	if (st == NULL) {
		LOG_ERR("st %p", st);
		return;
	}

	while ((*st) != NULL) {
		temp = *st;
		(*st) = (*st)->next;
		free(temp);
		temp = NULL;
	}

	return;
}

void stack_display(stk_t **st)
{
	if (st == NULL) {
		LOG_ERR("st %p", st);
		return;
	}

	printf("list_stack: ");

	while ((*st) != NULL) {
		printf("%d -> ", (*st)->data);
		st = &((*st)->next);
	}

	printf("NULL\n");
}

bool is_stack_empty(stk_t **st)
{
	if (st == NULL) {
		LOG_ERR("st %p", st);
		exit (EXIT_FAILURE);
	}

	if ((*st) == NULL) 
		return true;

	return false;
}

int stack_peek(stk_t **st)
{
	if (st == NULL) {
		LOG_ERR("st %p", st);
		exit (EXIT_FAILURE);
	}
	if ((*st) == NULL)  {
		LOG_DBG("Empty stack - *st %p", *st);
		return INT_MIN;
	}

	return ((*st)->data);
}