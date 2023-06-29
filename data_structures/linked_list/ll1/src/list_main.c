#include "list_defs.h"
#include "list_ops.h"
#include "list_cmn.h"

#define INSERT_FRONT		1U
#define INSERT_REAR			2U
#define DELETE_FRONT		3U
#define DELETE_REAR			4U
#define LIST_DISPLAY		5U
#define LIST_EXIT			6U
#define DELETE_REAR_2		7U
#define DELETE_REAR_3		8U
#define INSERT_REAR_2		9U
#define INSERT_AT_POS		10U
#define INSERT_AT_POS2		11U
#define INSERT_AT_POS3		12U
#define LIST_SIZE			13U

int main()
{
	int value, data;
	unsigned int op, pos;
	struct node *head = NULL;

	while (true) {
		printf("Enter list operation choice of operation:\n\
			1.INSERT_FRONT\n\
			2.INSERT_REAR\n\
		    3.DELETE_FRONT\n\
		    4.DELETE_REAR\n\
		    5.LIST_DISPLAY\n\
		    6.EXIT\n\
			7.DELETE_REAR_2\n\
			8.DELETE_REAR_3\n\
			9.INSERT_REAR_2\n\
			10.INSERT_AT_POS\n\
			11.INSERT_AT_POS2\n\
			12.INSERT_AT_POS3\n\
			13.LIST_SIZE\n");
		scanf("%u", &op);

		switch (op)
		{
			case INSERT_FRONT:
				printf("Enter the value to insert @ front: ");
				scanf("%d", &value);
				head = insert_front(head, value); 		
				if (!head) {
					printf("Error inserting @ front\n");
				}
#ifdef LIST_DEBUG
				printf("--------- linked list --------------\n");
				list_display(head); 		
				printf("====================================\n");
#endif // LIST_DEBUG
				break;
			case INSERT_REAR:	
				printf("Enter the value to insert @ rear: ");
				scanf("%d", &value);
				head = insert_rear(head, value); 		
#ifdef LIST_DEBUG
				printf("--------- linked list --------------\n");
				list_display(head); 		
				printf("====================================\n");
#endif // LIST_DEBUG
				break;
			case DELETE_FRONT:	
				head = delete_front(head, &data); 		
				printf("%s: deleted %d @ front\n", __func__,  data);
#ifdef LIST_DEBUG
				printf("--------- linked list --------------\n");
				list_display(head); 		
				printf("====================================\n");
#endif // LIST_DEBUG
				break;
                	case DELETE_REAR:
				head = delete_rear(head, &data); 		
#ifdef LIST_DEBUG
				printf("%s: deleted %d @ rear\n", __func__,  data);
				printf("--------- linked list --------------\n");
				list_display(head); 		
				printf("====================================\n");
#endif // LIST_DEBUG
				break;
			case LIST_DISPLAY:	
				printf("--------- linked list --------------\n");
				list_display(head); 		
				printf("====================================\n");
				break;
			case LIST_EXIT:	
				printf("Exiting...\n");
				goto list_exit;
			case DELETE_REAR_2:
				head = delete_rear2(head, &data); 		
				printf("%s: deleted %d @ rear\n", __func__,  data);
#ifdef LIST_DEBUG
				printf("--------- linked list --------------\n");
				list_display(head); 		
				printf("====================================\n");
#endif // LIST_DEBUG
				break;
			case DELETE_REAR_3:
				printf("%s: head %p\n", __func__, head);
				if (delete_rear3(&head, &data) == LIST_SUCCESS) { 		
					printf("%s: deleted %d @ rear\n", __func__,  data);
#ifdef LIST_DEBUG
					printf("--------- linked list --------------\n");
					list_display(head); 		
					printf("====================================\n");
#endif // LIST_DEBUG
				
				} else {
					printf("%s: empty list\n", __func__);
				}

				printf("%s: list_head %p\n", __func__, head);
				break;
			case INSERT_REAR_2:	
				printf("Enter the value to insert @ rear: ");
				scanf("%d", &value);
				if (insert_rear2(&head, value) == LIST_SUCCESS) { 		
#ifdef LIST_DEBUG
					printf("--------- linked list --------------\n");
					list_display(head); 		
					printf("====================================\n");
#endif // LIST_DEBUG
				}
				break;
			case INSERT_AT_POS:
				printf("Enter (value, pos): ");
				scanf("%d %u", &value, &pos);
				head = insert_at_position(head, value, pos);
				break;
			case INSERT_AT_POS2:
				printf("Enter (value, pos): ");
				scanf("%d %u", &value, &pos);
				if (!insert_at_position2(&head, value, pos)) {
					printf("%s: success inserting %d @ position %u\n", __func__, value, pos);
					list_display(head);
				}
				break;
			case INSERT_AT_POS3:
				printf("Enter (value, pos): ");
				scanf("%d %u", &value, &pos);
				head = insert_at_position3(head, value, pos);
				list_display(head);
				break;
			case LIST_SIZE:
				printf("list size: %zu\n", list_size(head));
				break;
			default:
				printf("Default case.\n");
				break;
		}
	} // while

list_exit:
	delete_list(head);
	/* free memory, close open files, other cleanup etc */
	return 0;
}
