//#include "cbuf_defs.h"
#include "cbuf_main.h"
#include "cbuf_cmn.h"
#include "cbuf_utils.h"
#include "cbuf_ops.h"

int main(int argc, char *argv[])
{
	int i, n, value, ret, data;
    int lower = 10;
    int upper = 50;
	char ch;
	int op;

	int cbuf_capacity;
	cbuf_t *cb = NULL;

	LOG_DBG("ENTER");

	if (argc != 2) {
		fprintf(stderr, "Usage: <a.out> <capacity>\n");
		exit(EXIT_FAILURE);
	}

	cbuf_capacity = atoi(argv[1]);

	LOG_DBG("cbuff_capacity %d", cbuf_capacity);

	while (cbuf_capacity <= 0) {
		fprintf(stderr, "Enter capacity >= 1: ");
		scanf("%d", &cbuf_capacity);
	}

	cb = cb_create(cbuf_capacity);

	if (cb == NULL) {
		LOG_ERR("could not create circular buffer of capacity %d", cbuf_capacity);
		exit (EXIT_FAILURE);
	}

	LOG_DBG("Success: circular buffer created with capacity %d", cbuf_capacity);

	while (true) {
		printf("\nEnter the operation - 1.ENQUEUE, 2.DEQUEUE, 3.DISPLAY, 4.EXIT, 5. STATUS: ");
		scanf("%u", &op);

		switch (op)
		{
			case CB_ENQUEUE:
				printf("Insert manually? press 'y' for yes: ");
				scanf(" %c", &ch);
				if (ch == 'y') {
					printf("Enter the number of elements to enqueue: ");
					scanf("%d", &n);
					printf("Enter %d elements to enqueue: ", n);
					ret = 0;
					for (i = 0; i < n; i++) {
						scanf("%d", &value);
						ret |= cb_enqueue(cb, value);
					}
					if (ret == CBUF_OPS_FAIL) {
						fprintf(stderr, "Fail: cq_enqueue()\n");
					} else {
						cb_display(cb);
					}
				} else {
					printf("Enter the number of elements to enqueue: ");
					scanf("%d", &n);
					printf("Enqueuing %d elements automatically into queue...\n", n);
					fflush(stdout);
					ret = CBUF_OPS_SUCCESS;
					for (i = 0; (i < n) && (ret == CBUF_OPS_SUCCESS); i++) {
						srand(time(NULL));
						sleep(1);
						value = rand() % (upper + 1 - lower) + lower;
						printf("(%d, %d) ", i, value);
						fflush(stdout);
						ret = cb_enqueue(cb, value);
					}
					if (ret  == CBUF_OPS_FAIL) {
						fprintf(stderr, "Failed to enqueue %d\n", value);
					}
					cb_display(cb);
				}
				break;

			case CB_DEQUEUE:
				if (cb_dequeue(cb, &data) != CBUF_OPS_SUCCESS) {
					fprintf(stderr, "Failed to dequeue\n");
				} else {
					printf("Successfully dequeued %d\n", data);
				}
				cb_display(cb);
				break;
			case CB_DISPLAY:
				cb_display(cb);
				break;
			case CB_EXIT:
				goto cb_exit;
				break;
			case CB_STATUS:
				cb_print_status(cb);
				break;
			default:
				printf("Default case - op %u.\n", op);
				break;
		} // switch
	} // while

	/* free memory, close open files, other cleanup etc */
cb_exit:
	printf("Exiting...\n");
	cb_destroy(cb);
	return 0;
}