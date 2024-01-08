#ifndef LIST_OPS_H_
#define LIST_OPS_H_

#include "list_cmn.h"

int insert_front(node_t **head, int value);                             // INSERT_FRONT		        1U
int insert_rear(node_t **head, int value);                              // INSERT_REAR		        2U
int insert_at_position(node_t **head, int value, int pos);              // INSERT_AT_POS            3U
int insert_after_key(node_t **head, int key_value, int new_value);      // INSERT_AFTER_KEY		    4U		
int insert_before_key(node_t **head, int key_value, int new_value);     // INSERT_BEFORE_KEY	    5U
int delete_front(node_t **head);                                        // DELETE_FRONT			    6U
int delete_rear(node_t **head);                                         // DELETE_REAR			    7U
void list_display(node_t **head);                                       // LIST_DISPLAY			    8U
int list_size(node_t **head);                                           // LIST_SIZE			    9U
int list_reverse(node_t **head);                                        // LIST_REVERSE			    10U
int list_rm_dup_unsorted(node_t **head);                                // RM_DUP_UNSORTED		    11U
int delete_list(node_t **head);                                         // LIST_DELETE			    12U
int is_list_sorted_in_asc_order(node_t **head);                         // LIST_ASC_ORDR_SORTD      13U
int insert_in_ascending_sorted_list(node_t **head, int value);          // INSERT_IN_ASC_SORTD_LIST	14U	
int sort_list_in_ascending_order(node_t **head);                        // SORT_LIST_IN_ASC_ORDER   15U
int list_rm_dup_sorted(node_t **head);                                  // RM_DUP_UNSORTED		    16U
int get_mid_element(node_t **head, int *value);                         // PRINT_MID_ELEMENT        17U
int get_nth_node_from_last(node_t **head, int n, int *data);            // PRINT_NTH_NODE_FROM_LAST 18U
int del_last_occurance(node_t **head, int value);                       // DEL_LAST_OCCURANCE       19U
int del_mid_node(node_t **head);                                        // DEL_MID_NODE             20U
int delete_n_after_m(node_t **head, int m, int n);                      // DEL_N_AFTER_M            21U
int pairwise_swap_nodes_data(node_t **head);                            // PAIRWISE_SWAP_NODES_DATA 22U
int pairwise_swap_nodes(node_t **head);                                 // PAIRWISE_SWAP_NODES      23U
int sort_012_nodes(node_t **head);                                      // SORT_012_NODES           24U
int merge_two_lists(node_t **first, node_t **second);                   // MERGE_TWO_LISTS          25U
int insert_second_list_into_first(node_t **first, node_t **second);     // INSERT_2ND_INTO_1ST      26U
int rm_every_kth_node(node_t **head, int k);                            // RM_EVERY_KTH_NODE        27U
#if 0
node_t *rev_list_in_k_groups(node_t *head, int k);                      // REV_LIST_IN_K_GROUPS     28U
#else
node_t *rev_list_in_k_groups_all(node_t **head, int k);                 // REV_LIST_IN_K_GROUPS_ALL 28U
#endif
node_t *rev_list_in_k_groups(node_t **head, int k);                     // REV_LIST_IN_K_GROUPS     29U
int add_numbers_in_two_lists(node_t **first, node_t **second, node_t **result);          // ADD_NUMBERS_IN_TWO_LISTS 30U
int sub_numbers_in_two_lists(node_t **first, node_t **second, node_t **result);          // SUB_NUMBERS_IN_TWO_LISTS 31U
int list_exit(node_t **head);                                           // LIST_EXIT			    99U


void better_list_display(node_t **head, const char *title);


#endif // LIST_OPS_H_
