#include "stack_defs.h"
#include "stack_cmn.h"
#include "stack_utils.h"
#include "stack_ops.h"

#define STACK_PUSH		1U
#define STACK_POP		2U
#define STACK_DISPLAY	3U
#define STACK_PEEK		4U
#define IS_STACK_EMPTY	5U
#define IS_STACK_FULL	6U
#define STACK_EXIT		7U


int main(int argc, char *argv[])
{
	int i, n, value, ret;
    int lower = 10;
    int upper = 50;
	char ch;
	int op;
	int capacity;

	stk_t *st = NULL;

	LOG_DBG("ENTER");

	if (argc != 2) {
		fprintf(stderr, "Usage: <a.out> <capacity>\n");
		exit(EXIT_FAILURE);
	}

	capacity = atoi(argv[1]);

	LOG_DBG("capacity %d", capacity);

	while (capacity <= 0) {
		fprintf(stderr, "Enter capacity >= 1: ");
		scanf("%d", &capacity);
	}

	st = stack_create(capacity);

	if (st == NULL) {
		LOG_ERR("could not create stack of capacity %d", capacity);
		exit (EXIT_FAILURE);
	}

	LOG_DBG("Success: stackk created with capacity %d", capacity);

	while (true) {
		printf("\nEnter stack operation:\n");
		printf("1.STACK_PUSH, 2.STACK_POP, 3.STACK_DISPLAY, 4.STACK_PEEK\n");
		printf("5.IS_STACK_EMPTY, 6.IS_STACK_FULL, 7.STACK_EXIT\n");
		scanf("%u", &op);

		switch (op)
		{
			case STACK_PUSH:
				printf("Insert manually? press 'y' for yes: ");
				scanf(" %c", &ch);
				if (ch == 'y') {
					printf("Enter the number of elements to push: ");
					scanf("%d", &n);
					printf("Enter %d elements to push: ", n);
					for (i = 0; i < n; i++) {
						scanf("%d", &value);
						ret |= stack_push(st, value);
					}
					if (ret == STACK_OPS_FAILURE) {
						fprintf(stderr, "Fail: stack_push()\n");
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
						ret |= stack_push(st, value);
					}
					if (ret  == STACK_OPS_FAILURE) {
						fprintf(stderr, "Fail: stack_push()\n");
					}
				}
				break;

			case STACK_POP:
				ret = stack_pop(st);
				if (ret == STACK_OPS_FAILURE) {

				}
				break;

			case STACK_DISPLAY:
				stack_display(st);
				break;

			case STACK_PEEK:
				ret = stack_peek(st);
				if (ret == INT_MIN ) {
					LOG_ERR("could not get stack TOP. ret = %d", ret);
				} else {
					printf("stack TOP %d", ret);
				}
				break;

			case IS_STACK_EMPTY:
				if (is_stack_empty(st) == true) {
					LOG_DBG("stack EMPTY");
				} else {
					LOG_DBG("stack NOT empty");
				}
				break;

			case IS_STACK_FULL:
				if (is_stack_full(st) == true) {
					LOG_DBG("stack FULL");
				} else {
					LOG_DBG("stack NOT full");
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
	stack_destroy(st);

	return 0;
}