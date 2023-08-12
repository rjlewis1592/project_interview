#include "list_defs.h"
#include "list_ops.h"
#include "list_cmn.h"

#define INSERT_FRONT		1U
#define INSERT_REAR			2U
#define INSERT_AT_POS		3U
#define INSERT_AFTER_KEY	4U
#define INSERT_BEFORE_KEY	5U
#define DELETE_FRONT		6U
#define DELETE_REAR			7U
#define LIST_DISPLAY		8U
#define LIST_SIZE			9U
#define LIST_EXIT			10U

int main()
{
	int i, n, value, ret, key;
    int lower = 10;
    int upper = 50;
	unsigned int op, pos;
	struct node *head = NULL;

	while (true) {
		printf("Enter list operation:\n");
		printf("1.INSERT_FRONT, 2.INSERT_REAR, 3.INSERT_AT_POS, 4.INSERT_AFTER_KEY, 5.INSERT_BEFORE_KEY\n");
		printf("6.DELETE_FRONT, 7.DELETE_REAR, 9.LIST_DISPLAY, 10.LIST_SIZE, 11.LIST_EXIT\n");
		scanf("%u", &op);

		switch (op)
		{
			case INSERT_FRONT: // 1U
				//printf("Enter the value to insert @ front: ");
				printf("Enter the no of values to insert @ front: ");
				scanf("%d", &n);
				for (i = 0; i < n; i++) {
        			srand(time(NULL));
        			sleep(1);
        			value = rand() % (upper + 1 - lower) + lower;
					printf("(%d, %d), ", i, value);
					ret = insert_front(&head, value); 		
					if (ret < 0) {
						fprintf(stderr, "Insert front failed\n");
					}
    			}
				printf("\n");
#ifdef LIST_DEBUG
				list_display(&head); 		
#endif // LIST_DEBUG
				break;
			case INSERT_REAR: // 2U
				//printf("Enter the value to insert @ rear: ");
				printf("Enter the no of values to insert @ rear: ");
				scanf("%d", &n);
				for (i = 0; i < n; i++) {
        			srand(time(NULL));
        			sleep(1);
        			value = rand() % (upper + 1 - lower) + lower;
					printf("(%d, %d), ", i, value);			
					ret = insert_rear(&head, value); 		
					if (ret < 0) {
						fprintf(stderr, "Insert rear failed\n");
					}
				}
				printf("\n");
#ifdef LIST_DEBUG
				list_display(&head); 		
#endif // LIST_DEBUG
				break;

			case INSERT_AT_POS: // 3U
				printf("Enter (value, pos): ");
				scanf("%d %u", &value, &pos);
				insert_at_position(&head, value, pos);
				break;

			case INSERT_AFTER_KEY: // 4U
				printf("Enter (key value, new_value): ");
				scanf("%d %d", &key, &value);
				ret = insert_after_key(&head, key, value);
				if (ret == 0) {
					fprintf(stderr, "%s, %d: Success - insert_after_key(): ret %d\n", __FUNCTION__, __LINE__, ret);
#ifdef LIST_DEBUG
					list_display(&head); 		
#endif // LIST_DEBUG
				} else {
					fprintf(stderr, "%s, %d: Fail - insert_after_key(): ret %d\n", __FUNCTION__, __LINE__, ret);
				}
				break;

			case INSERT_BEFORE_KEY: // 6U
				printf("Enter (value, pos): ");
				scanf("%d %u", &value, &pos);
				insert_before_key(&head, value, pos);
				break;

			case DELETE_FRONT: // 6U
				delete_front(&head);
#ifdef LIST_DEBUG
				list_display(&head); 		
#endif // LIST_DEBUG
				break;
            case DELETE_REAR: // 7U
				delete_rear(&head);
#ifdef LIST_DEBUG
				list_display(&head); 		
#endif // LIST_DEBUG
				break;
			case LIST_DISPLAY:// 8U
				list_display(&head); 		
				break;
			case LIST_SIZE: // 9U
				printf("list size: %zu\n", list_size(&head));
				break;
			case LIST_EXIT:	 // 10U
				printf("Exiting...\n");
				goto list_exit;
			default:
				printf("Default case - op %u.\n", op);
				break;
		} // switch
	} // while
list_exit:
	delete_list(&head);
	/* free memory, close open files, other cleanup etc */
	return 0;
}
