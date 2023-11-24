#include "queue_cmn.h"
#include "queue_utils.h"
#include "queue_ops.h"

#define	ENQUEUE				1U
#define DEQUEUE				2U
#define Q_DISPLAY			3U
#define Q_EXIT				99U

int main()
{
	int op;
	int value;

	int ret = INT_MIN;

	int i, n;
    int lower = 10;
    int upper = 50;
	char ch;

	queue_t *q = NULL;

	LOG_DBG("ENTER");

	ret = queue_create(&q);
	if (ret == QUEUE_OP_FAIL) {
		LOG_ERR("could not create initial queue");
		exit (EXIT_FAILURE);
	}

	while (true) {
		printf("\nEnter queue operation:\n");
		printf("1.ENQUEUE, 2.DEQUEUE, 3.Q_DISPLAY, 99.Q_EXIT\n");
		scanf("%u", &op);

		switch (op)
		{
			case ENQUEUE: 		// 1U
				printf("Insert manually? press 'y' for yes: ");
				scanf(" %c", &ch);
				if (ch == 'y') {
					printf("ENQUEUE: Enter the number of elements to enqueue: ");
					scanf("%d", &n);
					ret = 0;
					printf("ENQUEUE: Enter %d elements to enqueue: ", n);
					for (i = 0; (i < n) && (ret == QUEUE_OP_SUCCESS); i++) {
						scanf("%d", &value);
						ret |= enqueue(q, value);
					}
					if (ret != QUEUE_OP_SUCCESS) {
						LOG_ERR("enqueue(): failed to enqueue %d", value);
					}
				} else {
					printf("ENQUEUE: Enter the number of elements to enqueue: ");
					scanf("%d", &n);
					ret = 0;
					printf("ENQUEUE: Enqueuing %d elements automatically... ", n);
					fflush(stdout);
					for (i = 0; (i < n) && (ret == QUEUE_OP_SUCCESS); i++) {
						srand(time(NULL));
						sleep(1);
						value = rand() % (upper + 1 - lower) + lower;
						printf("(%d, %d) ", i, value);
						fflush(stdout);
						ret |= enqueue(q, value);
					}
					if (ret != QUEUE_OP_SUCCESS) {
						LOG_ERR("enqueue(): failed to enqueue %d", value);
					}
				}
				queue_display(q);
				break;

			case DEQUEUE: 		// 2U
				ret = 0;
				ret = dequeue(q);
				if (ret != QUEUE_OP_SUCCESS) {
					LOG_ERR("dequeue(): failed to dequeue");
				}
				queue_display(q);
				break;			

			case Q_DISPLAY:		// 3U
				queue_display(q);
				break;

			case Q_EXIT:	 	// 99U
				printf("Exiting...\n");
				goto exit_queue;

			default:
				printf("Default case - op %u.\n", op);
				break;
		} // switch
	} // while

exit_queue:
	queue_exit(q);
	queue_display(q);

	return 0;
}