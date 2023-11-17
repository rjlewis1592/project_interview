#include "stack_defs.h"
#include "stack_cmn.h"
#include "stack_utils.h"
#include "stack_ops.h"

#define STACK_PUSH		1U
#define STACK_POP		2U
#define STACK_DISPLAY	3U
#define STACK_PEEK		4U
#define IS_STACK_EMPTY	5U
#define STACK_EXIT		6U


int main()
{
	int i, n, value, ret;
    int lower = 10;
    int upper = 50;
	char ch;
	int op;

	stk_t *st = NULL;

	while (true) {
		printf("\nEnter stack operation:\n");
		printf("1.STACK_PUSH, 2.STACK_POP, 3.STACK_DISPLAY, 4.STACK_PEEK\n");
		printf("5.IS_STACK_EMPTY, 6.STACK_EXIT\n");
		scanf("%u", &op);

		switch (op)
		{
			case STACK_PUSH:
				printf("Insert manually? press 'y' for yes: ");
				scanf(" %c", &ch);
				ret = 0;
				if (ch == 'y') {
					printf("Enter the number of elements to push: ");
					scanf("%d", &n);
					printf("Enter %d elements to push: ", n);
					for (i = 0; i < n; i++) {
						scanf("%d", &value);
						ret |= stack_push(&st, value);
					}
					if (ret == STACK_OPS_FAILURE) {
						fprintf(stderr, "Fail: stack_push()\n");
					} else {
						stack_display(&st);
					}
				} else {
					printf("Enter the number of elements to push: ");
					scanf("%d", &n);
					printf("Pushing %d elements automatically into stack...\n", n);
					fflush(stdout);
					for (i = 0; i < n; i++) {
						srand(time(NULL));
						sleep(1);
						value = rand() % (upper + 1 - lower) + lower;
						printf("(%d, %d) ", i, value);
						fflush(stdout);
						ret |= stack_push(&st, value);
					}
					if (ret  == STACK_OPS_FAILURE) {
						fprintf(stderr, "Fail: stack_push()\n");
					} else {
						stack_display(&st);
					}
				}
				break;

			case STACK_POP:
				ret = 0;
				ret = stack_pop(&st);
				if (ret == STACK_OPS_FAILURE) {
					fprintf(stderr, "Fail: stack_pop()\n");
				} else {
					stack_display(&st);
				}
				break;

			case STACK_DISPLAY:
				stack_display(&st);
				break;

			case STACK_PEEK:
				ret = 0;
				ret = stack_peek(&st);
				if (ret == INT_MIN ) {
					LOG_ERR("could not get stack TOP. ret = %d", ret);
				} else {
					printf("stack TOP %d", ret);
				}
				break;

			case IS_STACK_EMPTY:
				if (is_stack_empty(&st) == true) {
					LOG_DBG("stack EMPTY");
				} else {
					LOG_DBG("stack NOT empty");
					stack_display(&st);
				}
				break;

			case STACK_EXIT:
				LOG_DBG("Exiting...");
				goto stack_exit;
				break;

			default:
				printf("Default case - op %u.\n", op);
				break;
		} // switch
	} // while

	/* free memory, close open files, other cleanup etc */
stack_exit:
	stack_destroy(&st);
	LOG_DBG("st %p\n", st);

	return 0;
}