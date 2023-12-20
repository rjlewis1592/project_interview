#include "list_defs.h"
#include "list_ops.h"
#include "list_cmn.h"

#define INSERT_REAR_MANUAL				0U
#define INSERT_FRONT					1U
#define INSERT_REAR						2U
#define INSERT_AT_POS					3U
#define INSERT_AFTER_KEY				4U
#define INSERT_BEFORE_KEY				5U
#define DELETE_FRONT					6U
#define DELETE_REAR						7U
#define LIST_DISPLAY					8U
#define LIST_SIZE						9U
#define LIST_REVERSE					10U
#define RM_DUP_UNSORTED					11U
#define LIST_EXIT						12U

int main()
{
	int i, n, value, ret, key;
    int lower = 10;
    int upper = 50;
	unsigned int op, pos;
	struct node *head = NULL;

	while (true) {
		printf("Enter list operation:\n");
		printf("0.INSERT_REAR_MANUAL\n");
		printf("1.INSERT_FRONT, 2.INSERT_REAR, 3.INSERT_AT_POS, 4.INSERT_AFTER_KEY, 5.INSERT_BEFORE_KEY\n");
		printf("6.DELETE_FRONT, 7.DELETE_REAR, 8.LIST_DISPLAY, 9.LIST_SIZE, 10.LIST_REVERSE, 11.RM_DUP_UNSORTED, 12.LIST_EXIT\n");
		printf("13.RM_DUP_UNSORTED\n");
		scanf("%u", &op);

		switch (op)
		{
			case INSERT_REAR_MANUAL: // 11U
				printf("Eneter the no of elements n: ");
				scanf("%d",  &n);
				printf("Enter %d elements to be inserted rear: ", n);
				for (i = 0; i < n; i++) {
					scanf("%d", &value);
					insert_rear(&head, value);
				}
				list_display(&head); 		
				printf("============\n");
				break;
			case INSERT_FRONT: // 1U
				//printf("Enter the value to insert @ front: ");
				printf("Enter the no of values to insert @ front: ");
				scanf("%d", &n);
				for (i = 0; i < n; i++) {
        			srand(time(NULL));
        			sleep(1);
        			value = rand() % (upper + 1 - lower) + lower;
					printf("Inserting %d at front...\n", value);
					ret = insert_front(&head, value); 		
					if (ret < 0) {
						fprintf(stderr, "Insert front failed\n");
	 				} else {
#ifdef LIST_DEBUG
						list_display(&head); 		
#endif // LIST_DEBUG
						printf("\n");
					}
    			}
				break;
			case INSERT_REAR: // 2U
				//printf("Enter the value to insert @ rear: ");
				printf("Enter the no of values to insert @ rear: ");
				scanf("%d", &n);
				for (i = 0; i < n; i++) {
        			srand(time(NULL));
        			sleep(1);
        			value = rand() % (upper + 1 - lower) + lower;
					printf("Inserting %d at rear...\n", value);
					ret = insert_rear(&head, value); 		
					if (ret < 0) {
						fprintf(stderr, "Insert rear failed\n");
					} else {
#ifdef LIST_DEBUG
						list_display(&head); 		
#endif // LIST_DEBUG
						printf("\n");
					}
				}
				printf("\n");
#ifdef LIST_DEBUG
				printf("LIST: ");
				list_display(&head); 		
#endif // LIST_DEBUG
				break;
			case INSERT_AT_POS: // 3U
				printf("Enter (value, pos): ");
				scanf("%d %u", &value, &pos);
				insert_at_position(&head, value, pos);
#ifdef LIST_DEBUG
				list_display(&head); 		
#endif // LIST_DEBUG
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

			case INSERT_BEFORE_KEY: // 5U
				printf("Enter (key value, new_value): ");
				scanf("%d %d", &key, &value);
				ret = insert_before_key(&head, key, value);
				if (ret == 0) {
					fprintf(stderr, "%s, %d: Success - insert_before_key(): ret %d\n", __FUNCTION__, __LINE__, ret);
#ifdef LIST_DEBUG
					list_display(&head); 		
#endif // LIST_DEBUG
				} else {
					fprintf(stderr, "%s, %d: Fail - insert_before_key(): ret %d\n", __FUNCTION__, __LINE__, ret);
				}
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
				printf("list size: %d\n", list_size(&head));
				break;
			case LIST_REVERSE: // 10U
				ret = list_reverse(&head);
				if (ret == 0) {
					fprintf(stderr, "%s, %d: Success - reversed list(): ret %d\n", __FUNCTION__, __LINE__, ret);
#ifdef LIST_DEBUG
					list_display(&head); 		
#endif // LIST_DEBUG
				} else {
					fprintf(stderr, "%s, %d: Fail - could not reverse list(): ret %d\n", __FUNCTION__, __LINE__, ret);
				}
				break;
			case RM_DUP_UNSORTED: // 11U
				printf("INITIAL LIST: ");
				list_display(&head); 		
				ret = list_rm_dup_unsorted(&head);
				if (ret == 0) {
#ifdef LIST_DEBUG
					list_display(&head); 		
#endif // LIST_DEBUG
				}
				break;
			case LIST_EXIT:	 // 12U
				printf("Exiting...\n");
				delete_list(&head);
				break;
			default:
				printf("Default case - op %u.\n", op);
				break;
		} // switch
	} // while
	/* free memory, close open files, other cleanup etc */
	return 0;
}
