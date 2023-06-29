#include "list_defs.h"
#include "list_ops.h"
#include "list_cmn.h"

#define INSERT_FRONT		1U
#define INSERT_REAR			2U
#define DELETE_FRONT		3U
#define DELETE_REAR			4U
#define INSERT_AT_POS		5U
#define LIST_DISPLAY		6U
#define LIST_SIZE			7U
#define LIST_EXIT			8U

int main()
{
	int value, data;
	unsigned int op, pos;
	struct node *head = NULL;

	while (true) {
		printf("Enter list operation:\n");
		printf("1.INSERT_FRONT, 2.INSERT_REAR, 3.DELETE_FRONT, 4.DELETE_REAR\n");
		printf("5.INSERT_AT_POS, 6.LIST_DISPLAY, 7.LIST_SIZE, 8.LIST_EXIT\n");
		scanf("%u", &op);

		switch (op)
		{
			case INSERT_FRONT: // 1U
				printf("Enter the value to insert @ front: ");
				scanf("%d", &value);
				head = insert_front(head, value); 		
				if (!head) {
					printf("Error inserting @ front\n");
				}
#ifdef LIST_DEBUG
				list_display(head); 		
#endif // LIST_DEBUG
				break;
			case INSERT_REAR: // 2U
				printf("Enter the value to insert @ rear: ");
				scanf("%d", &value);
				head = insert_rear(head, value); 		
#ifdef LIST_DEBUG
				list_display(head); 		
#endif // LIST_DEBUG
				break;
			case DELETE_FRONT: // 3U
				head = delete_front(head, &data); 		
				printf("%s: Success - deleted %d @ front\n", __func__,  data);
#ifdef LIST_DEBUG
				list_display(head); 		
#endif // LIST_DEBUG
				break;
            case DELETE_REAR: // 4U
				head = delete_rear(head, &data); 		
				printf("%s: Success - deleted %d @ rear\n", __func__,  data);
#ifdef LIST_DEBUG
				list_display(head); 		
#endif // LIST_DEBUG
				break;
			case INSERT_AT_POS: // 5U
				printf("Enter (value, pos): ");
				scanf("%d %u", &value, &pos);
				head = insert_at_position(head, value, pos);
				break;
			case LIST_DISPLAY:// 6U
				list_display(head); 		
				break;
			case LIST_SIZE: // 7U
				printf("list size: %zu\n", list_size(head));
				break;
			case LIST_EXIT:	 // 8U
				printf("Exiting...\n");
				goto list_exit;
			default:
				printf("Default case - op %u.\n", op);
				break;
		} // switch
	} // while
list_exit:
	delete_list(head);
	/* free memory, close open files, other cleanup etc */
	return 0;
}
