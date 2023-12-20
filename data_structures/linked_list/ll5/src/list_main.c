#include "list_defs.h"
#include "list_ops.h"
#include "list_cmn.h"

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
#define LIST_DELETE						12U
#define LIST_ASC_ORDR_SORTD				13U
#define INSERT_IN_ASC_SORTD_LIST		14U
#define SORT_LIST_IN_ASC_ORDER			15U
#define RM_DUP_SORTED					16U
#define PRINT_MID_ELEMENT				17U
#define PRINT_NTH_NODE_FROM_LAST		18U
#define DEL_LAST_OCCURANCE				19U
#define DEL_MID_NODE					20U
#define DEL_N_AFTER_M					21U
#define PAIRWISE_SWAP_NODES_DATA		22U
#define PAIRWISE_SWAP_NODES				23U
#define SORT_012_NODES					24U
#define MERGE_TWO_LISTS					25U
#define INSERT_2ND_INTO_1ST				26U
#define RM_EVERY_KTH_NODE				27U
#define REV_LIST_IN_K_GROUPS_ALL 		28U
#define REV_LIST_IN_K_GROUPS 			29U
#define ADD_NUMBERS_IN_TWO_LISTS		30U
#define LIST_EXIT						99U

static void create_list(node_t **head);
int conv_numstr_to_int(char *nptr, int base, int *out_val);

int conv_numstr_to_int(char *nptr, int base, int *out_val)
{	
	long result = 0;
	char *endptr = NULL;

	if ((nptr == NULL) || (out_val == NULL)) {
		LOG_ERR("nptr %p, endptr %p, out_val %p", nptr, endptr, out_val);
		return -1;
	}

	if (base != 10) {
		LOG_ERR("base %d - cannot be handled", base);
		return -1;
	}

	errno = 0;
	result = strtol(nptr, &endptr, 0);

	LOG_DBG("nptr \"%s\", endptr \"%s\", result %ld, errno %d, strerror(errno) \"%s\"\n", nptr, endptr, result, errno, strerror(errno));

	if (nptr == endptr) {
		LOG_ERR("NAN \"%s\", result %ld", nptr, result);
		return -1;
	}

    if (*endptr != '\0') {
        LOG_ERR("Further characters after number: \"%s\"", endptr);
		return -1;
	}

	if ((result == LONG_MAX || result == LONG_MIN) && (errno == ERANGE))
	{
    	// out of range, handle or exit
		LOG_ERR("OUT OF RANGE\n");
		return -1;
	}

	if (result >= INT_MAX) {
		LOG_ERR("Again overflow! result (%ld) > INT _MAX", result);
		return -1;
	}
 	/* If we got here, strtol() successfully parsed a number. */
    LOG_ERR("strtol() returned %ld\n", result);

	*out_val = (int)result; 
	return 0;

}

static void create_list(node_t **head)
{
	int i, n, value;
	int ret = 0;
	char ch;
	int lower = 10;
	int upper = 50;

	printf("Insert manually? press 'y' for yes: ");
	scanf(" %c", &ch);

	if (ch == 'y')
	{
		printf("Enter the no of elements to insert: ");
		scanf("%d", &n);
		printf("Enter %d elements: ", n);
		for (i = 0; i < n; i++) {
			scanf("%d", &value);
			ret |= insert_rear(head, value);
		}
		if (ret == LIST_OP_FAILURE) {
			fprintf(stderr, "Fail: insert_reat()\n");
		}
	} else {
		printf("Enter the no of values to insert @ rear: ");
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			srand(time(NULL));
			sleep(1);
			value = rand() % (upper + 1 - lower) + lower;
			printf("(%d, %d), ", i, value);
			ret = insert_rear(head, value);
			if (ret == LIST_OP_FAILURE) {
				fprintf(stderr, "Fail: insert_rear()\n");
			}
		}
	}

	printf("\n");
	return;
}

int main()
{
	int i, m, n, k, value, ret, key;
	int mid_data = INT_MIN;
	int data = INT_MIN;
    int lower = 10;
    int upper = 50;
	char ch;
	unsigned int op;
	int pos;
	node_t *head = NULL;
	node_t *first = NULL;
	node_t *second = NULL;
	node_t *result = NULL;
	char numstr[BUFLEN_32] = {0};

	LOG_DBG("ENTER");

	while (true) {
		printf("Enter list operation:\n");
		printf("1.INSERT_FRONT, 2.INSERT_REAR, 3.INSERT_AT_POS, 4.INSERT_AFTER_KEY, 5.INSERT_BEFORE_KEY\n");
		printf("6.DELETE_FRONT, 7.DELETE_REAR, 8.LIST_DISPLAY, 9.LIST_SIZE, 10.LIST_REVERSE\n");
		printf("11.RM_DUP_UNSORTED, 12.LIST_DELETE, 13.IS_LIST_SORTD_IN_ASC, 14.INSERT_IN_ASC_SORTD_LIST\n");
		printf("15.SORT_LIST_IN_ASC_ORDER, 16.RM_DUP_SORTED 17.PRINT_MID_ELEMENT\n");
		printf("18.PRINT_NTH_NODE_FROM_LAST, 19.DEL_LAST_OCCURANCE, 20.DEL_MID_NODE, 21.DEL_N_AFTER_M\n");
		printf("22.PAIRWISE_SWAP_NODES_DATA, 23.PAIRWISE_SWAP_NODES, 24.SORT_012_NODES, 25.MERGE_TWO_LIST\n");
		printf("26.INSERT_2ND_INTO_1ST, 27.RM_EVERY_KTH_NODE, 28.REV_LIST_IN_K_GROUPS_ALL, 29.REV_LIST_IN_K_GROUPS\n");
		printf("30.ADD_NUMBERS_IN_TWO_LISTS\n");
		printf("99.LIST_EXIT\n");
		scanf("%u", &op);

		switch (op)
		{
			case INSERT_FRONT: // 1U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				printf("Insert manually? press 'y' for yes: ");
				scanf(" %c", &ch);
				if (ch == 'y') {
					printf("Enter the value to insert @ front: ");
					scanf("%d", &value);
					ret = insert_front(&head, value); 		
					if (ret  == LIST_OP_FAILURE) {
						fprintf(stderr, "Fail: insert_front()\n");
					} else {
						printf("Success: insert_front()\n");
					}
				} else {
					printf("Enter the no of values to insert @ front: ");
					scanf("%d", &n);
					for (i = 0; i < n; i++)
					{
						srand(time(NULL));
						sleep(1);
						value = rand() % (upper + 1 - lower) + lower;
						printf("(%d, %d), ", i, value);
						ret = insert_front(&head, value);
						if (ret  == LIST_OP_FAILURE) {
							fprintf(stderr, "Fail: insert_front()\n");
						}
					}
				}
				printf("\n");
#ifdef LIST_DEBUG
				better_list_display(&head, "INSERT_FRONT");
#endif // LIST_DEBUG
				break;

			case INSERT_REAR: // 2U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				printf("Insert manually? press 'y' for yes: ");
				scanf(" %c", &ch);
				if (ch == 'y') {
					printf("Eneter the no of elements to insert: ");
					scanf("%d", &n);
					printf("Enter %d elements: ", n);
					for (i = 0; i < n; i++) {
						scanf("%d", &value);
						ret |= insert_rear(&head, value);
					}
					if (ret  == LIST_OP_FAILURE) {
						fprintf(stderr, "Fail: insert_reat()\n");
					} else {
						printf("Success: insert_rear()\n");
					}
				} else {
					printf("Enter the no of values to insert @ rear: ");
					scanf("%d", &n);
					for (i = 0; i < n; i++)
					{
						srand(time(NULL));
						sleep(1);
						value = rand() % (upper + 1 - lower) + lower;
						printf("(%d, %d), ", i, value);
						ret = insert_rear(&head, value);
						if (ret  == LIST_OP_FAILURE) {
							fprintf(stderr, "Fail: insert_rear()\n");
						}
					}
				}
				printf("\n");
#ifdef LIST_DEBUG
				better_list_display(&head, "INSERT_REAR:");
#endif // LIST_DEBUG
				break;

			case INSERT_AT_POS: // 3U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				printf("Enter (value, pos): ");
				scanf("%d %d", &value, &pos);
				ret = insert_at_position(&head, value, pos);
				if (ret  == LIST_OP_FAILURE) {
					fprintf(stderr, "Fail: insert_at_position()\n");
				} else {
					printf("Success: insert_at_position()\n");
				}
#ifdef LIST_DEBUG
				better_list_display(&head, "INSERT_AT_POS"); 		
#endif // LIST_DEBUG
				break;

			case INSERT_AFTER_KEY: // 4U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				printf("Enter (key value, new_value): ");
				scanf("%d %d", &key, &value);
				ret = insert_after_key(&head, key, value);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Fail: insert_after_key()\n");
				} else {
					printf("Success: insert_after_key()\n");
				}
#ifdef LIST_DEBUG
				better_list_display(&head, "INS_AFTER_KEY");
#endif // LIST_DEBUG
				break;

			case INSERT_BEFORE_KEY: // 6U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				printf("Enter (key value, new_value): ");
				scanf("%d %d", &key, &value);
				ret = insert_before_key(&head, key, value);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Fail: insert_before_key()\n");
				} else {
					printf("Success: insert_before_key()\n");
				}
#ifdef LIST_DEBUG
				better_list_display(&head, "INS_B4_KEY");
#endif // LIST_DEBUG
				break;

			case DELETE_FRONT: // 6U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				ret = delete_front(&head);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Fail: delete_front()\n");
				} else {
					printf("Success: delete_front()\n");
				}
#ifdef LIST_DEBUG
				better_list_display(&head, "DEL_FRONT");
#endif // LIST_DEBUG
				break;

            case DELETE_REAR: // 7U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				ret = delete_rear(&head);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Fail: delete_rear()\n");
				} else {
					printf("Success: delete_rear()\n");
				}
#ifdef LIST_DEBUG
				better_list_display(&head, "DEL_REAR");
#endif // LIST_DEBUG
				break;

			case LIST_DISPLAY:// 8U
				better_list_display(&head, "LIST");
				break;

			case LIST_SIZE: // 9U
				printf("list size: %d\n", list_size(&head));
				break;

			case LIST_REVERSE: // 10U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				ret = list_reverse(&head);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: list_reverse()\n");
				} else {
#ifdef LIST_DEBUG
				better_list_display(&head, "REVERSED_LIST");
#endif // LIST_DEBUG
				}
				break;

			case RM_DUP_UNSORTED: // 11U
				printf("Eneter the no of elements to insert: ");
				scanf("%d", &n);
				printf("Enter %d elements: ", n);
				for (i = 0; i < n; i++) {
					scanf("%d", &value);
					insert_rear(&head, value);
				}
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				ret = list_rm_dup_unsorted(&head);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: list_rm_dup_unsorted()\n");
				} else {
#ifdef LIST_DEBUG
				better_list_display(&head, "DUP_RM_LIST"); 		
#endif // LIST_DEBUG
				}
				break;

			case LIST_DELETE: // 12U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				ret = delete_list(&head);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: delete_list()\n");
				} else {
					printf("Success: delete_list() - head %p\n", head);
					//prinrtf("*head %p\n", *head);
				}
#ifdef LIST_DEBUG
				better_list_display(&head, "DEL_LIST");
#endif // LIST_DEBUG
				break;

			case LIST_ASC_ORDR_SORTD: // 13U
				printf("Eneter the no of elements to insert: ");
				scanf("%d", &n);
				printf("Enter %d elements: ", n);
				for (i = 0; i < n; i++) {
					scanf("%d", &value);
					insert_rear(&head, value);
				}
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				ret = is_list_sorted_in_asc_order(&head);
				if (ret == LIST_EMPTY) {
					fprintf(stderr, "Empty list - nothing to validate\n");
				} else if (ret == LIST_OP_SUCCESS) {
					printf("The list is sorted in ascending order...\n");
				} else {
					printf("Unsorted list ...\n");
				}
				break;

			case INSERT_IN_ASC_SORTD_LIST: // 14U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				printf("Enter the element to insert: ");
				scanf("%d", &value);
				ret = insert_in_ascending_sorted_list(&head, value);
				if (ret == LIST_OP_FAILURE) {
					printf("Fail: insert_in_ascending_sorted_list()\n");
				}
#ifdef LIST_DEBUG
				better_list_display(&head, "INS_ASC_SORTD_LIST");
#endif // LIST_DEBUG
				break;

			case SORT_LIST_IN_ASC_ORDER: // 15U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				ret = sort_list_in_ascending_order(&head);
				if (ret == LIST_OP_FAILURE) {
					printf("Fail: sort_list_in_ascending_order()\n");
				}
#ifdef LIST_DEBUG
				better_list_display(&head, "AFTER_ASC_SORT");
#endif // LIST_DEBUG
				break;


			case RM_DUP_SORTED: // 16U
				printf("Eneter the no of elements to insert: ");
				scanf("%d", &n);
				printf("Enter %d elements: ", n);
				for (i = 0; i < n; i++) {
					scanf("%d", &value);
					insert_rear(&head, value);
				}
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
				ret = list_rm_dup_sorted(&head);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: list_rm_dup_unsorted()\n");
				} else {
#ifdef LIST_DEBUG
				better_list_display(&head, "DUP_RM_LIST"); 		
#endif // LIST_DEBUG
				}
				break;

				case PRINT_MID_ELEMENT:	// 17U
				ret = get_mid_element(&head, &mid_data);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: get_mid_element()\n");
				} else {
#ifdef LIST_DEBUG
					better_list_display(&head, "PRINT_MID"); 		
#endif // LIST_DEBUG
					printf("middle element %d\n", mid_data);
				}
				break;

			case PRINT_NTH_NODE_FROM_LAST:	// 18U
				printf("Enter n from last: ");
				scanf("%d", &n);
				ret = get_nth_node_from_last(&head, n, &data);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: get_nth_node_from_last()\n");
				} else {
#ifdef LIST_DEBUG
					better_list_display(&head, "PRINT_NTH_NODE_FROM_LAST"); 		
#endif // LIST_DEBUG
					printf("nth node from last %d\n", data);
				}
				break;

			case DEL_LAST_OCCURANCE:			// 19U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST"); 		
#endif // LIST_DEBUG
				printf("Enter the value: ");
				scanf("%d", &value);
				ret = del_last_occurance(&head, value);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: del_last_occurance()\n");
				} else {
#ifdef LIST_DEBUG
					better_list_display(&head, "DEL_LAST_OCCURANCE"); 		
#endif // LIST_DEBUG
				}
				break;

			case DEL_MID_NODE:			// 20U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST"); 		
#endif // LIST_DEBUG
				ret = del_mid_node(&head);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: del_mid_node()\n");
				} else {
#ifdef LIST_DEBUG
					better_list_display(&head, "DEL_MID_NODE"); 		
#endif // LIST_DEBUG
				}
				break;

			case DEL_N_AFTER_M:			// 21U
				printf("Enter m and n: ");
				scanf("%d %d", &m, &n);
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST"); 		
#endif // LIST_DEBUG
				ret = delete_n_after_m(&head, m, n);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: delete_n_after_m()\n");
				} else {
#ifdef LIST_DEBUG
					better_list_display(&head, "DEL_N_AFTER_M"); 		
#endif // LIST_DEBUG
				}
				break;

			case PAIRWISE_SWAP_NODES_DATA:			// 22U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST"); 		
#endif // LIST_DEBUG
				ret = pairwise_swap_nodes_data(&head);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: pairwis_swap_nodes()\n");
				} else {
#ifdef LIST_DEBUG
					better_list_display(&head, "PAIRWISE_NODES_DATA_SWAP"); 		
#endif // LIST_DEBUG
				}
				break;

			case PAIRWISE_SWAP_NODES:				// 23U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST"); 		
#endif // LIST_DEBUG
				ret = pairwise_swap_nodes(&head);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: pairwis_swap_nodes()\n");
				} else {
#ifdef LIST_DEBUG
					better_list_display(&head, "PAIRWISE_SWAP_NODES"); 		
#endif // LIST_DEBUG
				}
				break;

			case SORT_012_NODES:				// 24U
#ifdef LIST_DEBUG
				better_list_display(&head, "INITIAL_LIST"); 		
#endif // LIST_DEBUG
				ret = sort_012_nodes(&head);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: sort_012_nodes()\n");
				}
#ifdef LIST_DEBUG
				better_list_display(&head, "012_LIST"); 		
#endif // LIST_DEBUG
				break;

			case MERGE_TWO_LISTS:				// 25U
				create_list(&second);
#ifdef LIST_DEBUG
				better_list_display(&head, "INIT_LIST: "); 		
				better_list_display(&second, "SECOND_LIST: "); 		
#endif // LIST_DEBUG
				ret = merge_two_lists(&head, &second);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: merge_two_lists()\n");
				} else {
#ifdef LIST_DEBUG
					better_list_display(&head, "MERGED_LIST: "); 		
#endif // LIST_DEBUG
				}
				break;

			case INSERT_2ND_INTO_1ST:				// 26U
				create_list(&second);
#ifdef LIST_DEBUG
				better_list_display(&head, "INIT_LIST"); 		
				better_list_display(&second, "SECOND_LIST"); 		
#endif // LIST_DEBUG
				ret = insert_second_list_into_first(&head, &second);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: insert_second_list_into_first()\n");
				} else {
#ifdef LIST_DEBUG
					better_list_display(&head, "INSERTED_LIST"); 		
					better_list_display(&second, "SECOND_LIST"); 		
#endif // LIST_DEBUG
				}
				break;

			case RM_EVERY_KTH_NODE:				// 27U
				printf("Enter k: ");
				scanf("%d", &k);
#ifdef LIST_DEBUG
				better_list_display(&head, "INIT_LIST"); 		
#endif // LIST_DEBUG
				ret = rm_every_kth_node(&head, k);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: rm_every_kth_node()\n");
				} else {
#ifdef LIST_DEBUG
					better_list_display(&head, "RM_EVERY_K_NODE_LIST"); 		
#endif // LIST_DEBUG
				}
				break;

			case REV_LIST_IN_K_GROUPS_ALL:				// 28U
				printf("Enter k: ");
				scanf("%d", &k);
#ifdef LIST_DEBUG
				better_list_display(&head, "INIT_LIST"); 		
#endif // LIST_DEBUG
#if 0
				head = rev_list_in_k_groups(head, k);
#else
				head = rev_list_in_k_groups_all(&head, k);
#endif
#ifdef LIST_DEBUG
				better_list_display(&head, "REV_LIST_IN_K_GROUPS_ALL"); 		
#endif // LIST_DEBUG
				break;

			case REV_LIST_IN_K_GROUPS:				// 29U
				printf("Enter k: ");
				scanf("%d", &k);
#ifdef LIST_DEBUG
				better_list_display(&head, "INIT_LIST"); 		
#endif // LIST_DEBUG
#if 0
				head = rev_list_in_k_groups(head, k);
#else
				head = rev_list_in_k_groups(&head, k);
#endif
#ifdef LIST_DEBUG
				better_list_display(&head, "REV_LIST_IN_K_GROUPS"); 		
#endif // LIST_DEBUG
				break;

			case ADD_NUMBERS_IN_TWO_LISTS:				// 30U
				printf("***** Creating first numeric list ******\n");
				printf("Enter first numeric string: ");
				scanf("%s", numstr);
				printf("numstr \"%s\"\n", numstr);
				for (i = 0; numstr[i] != '\0'; i++) {
					int val = 0;
					if (isdigit(numstr[i]) == 0) { // not a digit
						delete_list(&head);
					}
					val = numstr[i] - '0';
					insert_rear(&first, val);				
				}
				printf("***** Creating second numeric list ******\n");
				printf("Enter second numeric string: ");
				scanf("%s", numstr);
				printf("numstr \"%s\"\n", numstr);
				for (i = 0; numstr[i] != '\0'; i++) {
					int val = 0;
					if (isdigit(numstr[i]) == 0) { // not a digit
						delete_list(&head);
					}
					val = numstr[i] - '0';
					insert_rear(&second, val);
				}
#ifdef LIST_DEBUG
				better_list_display(&first,  "FIRST_LIST : "); 		
				better_list_display(&second, "SECOND_LIST: "); 		
#endif // LIST_DEBUG
				ret = add_numbers_in_two_lists(&first, &second, &result);
				if (ret == LIST_OP_FAILURE) {
					fprintf(stderr, "Error: add_numbers_in_two_lists()\n");
				} else {
#ifdef LIST_DEBUG
					better_list_display(&result, "RESULT_LIST: "); 		
#endif // LIST_DEBUG
					delete_list(&first);
					delete_list(&second);
				}
				break;
			case LIST_EXIT:	 // 99U
				printf("Exiting...\n");
				goto exit_list;

			default:
				printf("Default case - op %u.\n", op);
				break;
		} // switch
	} // while

exit_list:
#ifdef LIST_DEBUG
	better_list_display(&head, "INITIAL_LIST");
#endif // LIST_DEBUG
	ret = list_exit(&head);
	if (ret == LIST_OP_FAILURE) {
		fprintf(stderr, "Error: list_exit()\n");
	} else {
		printf("Success: list_exit()\n");
	}

#ifdef LIST_DEBUG
	better_list_display(&head, "EXIT_LIST");
#endif // LIST_DEBUG

	/* free memory, close open files, other cleanup etc */
	return 0;
}