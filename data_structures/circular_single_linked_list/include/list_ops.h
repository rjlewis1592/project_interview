#ifndef LIST_OPS_H_
#define LIST_OPS_H_

#include "list_cmn.h"

node_t *insert_front(node_t *last, int value);                             // INSERT_FRONT		        1U
node_t *insert_last(node_t *last, int value);                              // INSERT_LAST		        2U
node_t *insert_at_position(node_t *last, int value, int pos);              // INSERT_AT_POS            3U
node_t *insert_after_key(node_t *last, int key_value, int new_value);      // INSERT_AFTER_KEY		    4U		
node_t *insert_before_key(node_t *last, int key_value, int new_value);     // INSERT_BEFORE_KEY	    5U
node_t *delete_front(node_t *last);                                        // DELETE_FRONT			    6U
node_t *delete_last(node_t *last);                                         // DELETE_LAST			    7U
node_t *delete_after_key(node_t *last, int key);
node_t *delete_before_key(node_t *last, int key);
void list_display(node_t *last);                                            // LIST_DISPLAY			    8U
int list_size(node_t *last);                                                // LIST_SIZE			    9U
node_t *delete_key_node(node_t *last, int key);                             // DELETE_KEY_NODE          12U

void list_exit(node_t *last);                                           // LIST_EXIT			    99U
#endif // LIST_OPS_H_
