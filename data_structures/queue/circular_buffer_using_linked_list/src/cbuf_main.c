#include "cbuf_cmn.h"
#include "cbuf_utils.h"
#include "cbuf_ops.h"

#define	CBUF_ENQUEUE			1U
#define CBUF_DEQUEUE			2U
#define CBUF_DISPLAY			3U
#define CBUF_EXIT				99U

int main()
{
	int op;
	int value;

	int ret = INT_MIN;

	int i, n;
    int lower = 10;
    int upper = 50;
	char ch;

	cbuf_t *cb = NULL;

	LOG_DBG("ENTER");

	ret = cbuf_create(&cb);
	if (ret == CBUF_OP_FAIL) {
		LOG_ERR("could not create initial circular buffer");
		exit (EXIT_FAILURE);
	}

	LOG_DBG("Success: created & initialized circular buffer");
	print_cbuf_status(cb);

	while (true) {
		printf("\nEnter circular buffer operation:\n");
		printf("1.CBUF_ENQUEUE, 2.CBUF_DEQUEUE, 3.CBUF_DISPLAY, 99.CBUF_EXIT\n");
		scanf("%u", &op);

		switch (op)
		{
			case CBUF_ENQUEUE: 		// 1U
				printf("Insert manually? press 'y' for yes: ");
				scanf(" %c", &ch);
				if (ch == 'y') {
					printf("CBUF_ENQUEUE: Enter the number of elements to enqueue: ");
					scanf("%d", &n);
					ret = 0;
					printf("CBUF_ENQUEUE: Enter %d elements to enqueue: ", n);
					for (i = 0; (i < n) && (ret == CBUF_OP_SUCCESS); i++) {
						scanf("%d", &value);
						ret |= cbuf_enqueue(cb, value);
					}
					if (ret != CBUF_OP_SUCCESS) {
						LOG_ERR("cbuf_enqueue(): failed to enqueue %d", value);
					}
				} else {
					printf("CBUF_ENQUEUE: Enter the number of elements to enqueue: ");
					scanf("%d", &n);
					ret = 0;
					printf("CBUF_ENQUEUE: Enqueuing %d elements automatically... ", n);
					fflush(stdout);
					for (i = 0; (i < n) && (ret == CBUF_OP_SUCCESS); i++) {
						srand(time(NULL));
						sleep(1);
						value = rand() % (upper + 1 - lower) + lower;
						printf("(%d, %d) ", i, value);
						fflush(stdout);
						ret |= cbuf_enqueue(cb, value);
					}
					if (ret != CBUF_OP_SUCCESS) {
						LOG_ERR("cbuf_enqueue(): failed to enqueue %d", value);
					}
				}
				cbuf_display(cb);
				break;

			case CBUF_DEQUEUE: 		// 2U
				ret = 0;
				ret = cbuf_dequeue(cb);
				if (ret != CBUF_OP_SUCCESS) {
					LOG_ERR("cbuf_dequeue(): failed to dequeue");
				}
				cbuf_display(cb);
				break;			

			case CBUF_DISPLAY:		// 3U
				cbuf_display(cb);
				break;

			case CBUF_EXIT:	 	// 99U
				printf("Exiting...\n");
				goto exit_cbuf;

			default:
				printf("Default case - op %u.\n", op);
				break;
		} // switch
	} // while

exit_cbuf:
	cbuf_exit(cb);
	cbuf_display(cb);

	return 0;
}