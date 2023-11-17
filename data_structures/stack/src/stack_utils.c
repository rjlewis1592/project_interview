#include "stack_cmn.h"
#include "stack_defs.h"
#include "stack_utils.h"

static void stack_init(stk_t *st, int capacity)
{
	st->top = -1;
	st->capacity = capacity;
	memset(st->arr, 0, (sizeof(int) * (st->capacity)));
}

stk_t* stack_create(int capacity)
{
	stk_t *st = NULL;
	if (capacity <= 0) {
		LOG_ERR("capacity %d", capacity);
		return NULL;
	}

	st = (stk_t *)malloc(sizeof(stk_t));
	if (st == NULL) {
		LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
		return NULL;
	}

	LOG_DBG("Success: allocated st %p", st);

	st->arr = (int *)malloc(sizeof(int) * capacity);
	if (st->arr == NULL) {
		LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
		free(st);
		st = NULL;
		return NULL;
	}

	LOG_DBG("Success: allocated st->arr %p", st->arr);

	stack_init(st, capacity);

	return st;
}

void stack_destroy(stk_t *st)
{
	if (st == NULL) {
		LOG_ERR("st %p", st);
		return;
	}

	if (st->arr != NULL) {
		LOG_DBG("freeing st->arr %p", st->arr);
		free(st->arr);
		st->arr = NULL;
	}

	LOG_DBG("freeing st %p", st);
	free(st);
	st = NULL;

	return;
}

void stack_display(stk_t *st)
{
	int i = 0;

	if (st == NULL) {
		LOG_ERR("st %p", st);
		return;
	}

	printf("----- stack -----\n");
	printf("top			: %d\n", st->top);
	printf("capacity	: %d\n", st->capacity);
	printf("arr:\n");
	for (i = st->top; i >= 0; i--) {
		printf("%d\n", st->arr[i]);
	}

	printf("======= end ======\n");
}

bool is_stack_empty(stk_t *st)
{
	if ((st != NULL) && (st->top == -1))
		return true;

	return false;
}

bool is_stack_full(stk_t *st)
{
	if ((st != NULL) && (st->top == (st->capacity - 1)))
		return true;

	return false;
}

int stack_peek(stk_t *st)
{
	if (st == NULL) {
		LOG_ERR("st %p", st);
		return INT_MIN;
	}

	if (is_stack_empty(st) == true) {
		LOG_ERR("Empty stack");
		return INT_MIN;
	}

	if (st->arr == NULL) {
		LOG_ERR("stack memory not allocated");
		return INT_MIN;
	}

	return (st->arr[st->top]);

}