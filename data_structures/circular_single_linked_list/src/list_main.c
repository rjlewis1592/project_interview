#include "list_cmn.h"
#include "list_utils.h"
#include "list_ops.h"

#define INSERT_FRONT					1U
#define INSERT_LAST						2U
#define INSERT_AT_POS					3U
#define INSERT_AFTER_KEY				4U
#define INSERT_BEFORE_KEY				5U
#define DELETE_FRONT					6U
#define DELETE_LAST						7U
#define DELETE_AFTER_KEY				8U
#define DELETE_BEFORE_KEY				9U
#define LIST_DISPLAY					10U
#define LIST_SIZE						11U
#define DELETE_KEY_NODE					12U

#define LIST_EXIT						99U

int main()
{
	int op;
	int value;
	int pos;
	int key;

	int i, n;
    int lower = 10;
    int upper = 50;
	char ch;

	node_t *last = NULL;

	LOG_DBG("ENTER");

	while (true) {
		printf("\nEnter list operation:\n");
		printf("1.INSERT_FRONT, 2.INSERT_LAST, 3.INSERT_AT_POS, 4.INSERT_AFTER_KEY, 5.INSERT_BEFORE_KEY\n");
		printf("6.DELETE_FRONT, 7.DELETE_LAST, 8.DELETE_AFTER_KEY, 9.DELETE_BEFORE_KEY, 10.LIST_DISPLAY, 11.LIST_SIZE\n");
		printf("12. DELETE_KEY_NODE\n");
		printf("99.LIST_EXIT\n");
		scanf("%u", &op);

		switch (op)
		{
			case INSERT_FRONT: 		// 1U
				printf("Insert manually? press 'y' for yes: ");
				scanf(" %c", &ch);
				if (ch == 'y') {
					printf("INSERT_FRONT: Enter the number of elements to insert front: ");
					scanf("%d", &n);
					printf("INSERT_FRONT: Enter %d elements to insert front: ", n);
					for (i = 0; i < n; i++) {
						scanf("%d", &value);
						last = insert_front(last, value);
					}
				} else {
					printf("Enter the number of elements to insert front: ");
					scanf("%d", &n);
					printf("INSERT_FRONT: inserting %d elements automatically...\n", n);
					fflush(stdout);
					for (i = 0; (i < n); i++) {
						srand(time(NULL));
						sleep(1);
						value = rand() % (upper + 1 - lower) + lower;
						printf("(%d, %d) ", i, value);
						fflush(stdout);
						last = insert_front(last, value);
					}
				}
				list_display(last);
				break;

			case INSERT_LAST: 		// 2U
				printf("Insert manually? press 'y' for yes: ");
				scanf(" %c", &ch);
				if (ch == 'y') {
					printf("INSERT_LAST: Enter the number of elements to insert last: ");
					scanf("%d", &n);
					printf("Enter %d elements to insert front: ", n);
					for (i = 0; i < n; i++) {
						scanf("%d", &value);
						last = insert_last(last, value);
					}
				} else {
					printf("INSERT_LAST: Enter the number of elements to insert last: ");
					scanf("%d", &n);
					printf("INSERT_LAST: inserting %d elements automatically...\n", n);
					fflush(stdout);
					for (i = 0; (i < n); i++) {
						srand(time(NULL));
						sleep(1);
						value = rand() % (upper + 1 - lower) + lower;
						printf("(%d, %d) ", i, value);
						fflush(stdout);
						last = insert_last(last, value);
					}
				}
				list_display(last);
				break;			

			case INSERT_AT_POS:		// 3U
				printf("Enter the (value, pos): ");
				scanf("%d %d", &value, &pos);
				last = insert_at_position(last, value, pos);
				list_display(last);
				break;

			case INSERT_AFTER_KEY:		// 4U
				printf("INSERT_AFTER_KEY: Enter the (value, key): ");
				scanf("%d %d", &value, &key);
				last = insert_after_key(last, key, value);
				list_display(last);
				break;

			case INSERT_BEFORE_KEY:		// 5U
				printf("INSERT_BEFORE_KEY: Enter the (value, key): ");
				scanf("%d %d", &value, &key);
				last = insert_before_key(last, key, value);
				list_display(last);
				break;

			case DELETE_FRONT:			// 6U
				last = delete_front(last);
				list_display(last);
				break;

			case DELETE_LAST:			// 7U
				last = delete_last(last);
				list_display(last);
				break;

			case DELETE_AFTER_KEY:		// 8U
				printf("DELETE_AFTER_KEY: Enter the key: ");
				scanf("%d",  &key);
				last = delete_after_key(last, key);
				list_display(last);
				break;

			case DELETE_BEFORE_KEY:		// 9U
				printf("DELETE_BEFORE_KEY: Enter the key: ");
				scanf("%d",  &key);
				last = delete_before_key(last, key);
				list_display(last);
				break;

			case LIST_DISPLAY:			// 10U
				list_display(last);
				break;

			case LIST_SIZE:				// 11U
				printf("number of nodes %d\n", list_size(last));
				break;

			case DELETE_KEY_NODE:		// 12U			
				printf("DELETE_KEY_NODE: Enter the key: ");
				scanf("%d",  &key);
				last = delete_key_node(last, key);
				list_display(last);
				break;

			case LIST_EXIT:	 			// 99U
				printf("Exiting...\n");
				goto exit_list;

			default:
				printf("Default case - op %u.\n", op);
				break;
		} // switch
	} // while

exit_list:
	list_exit(last);

	return 0;
}