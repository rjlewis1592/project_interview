#ifndef LIST_OPS_H_
#define LIST_OPS_H_

#include "list_cmn.h"

int insert_front(node_t **head, int value);
int insert_rear(node_t **head, int value);
int insert_at_position(node_t **head, int value, int pos);
int insert_after_key(node_t **head, int key_value, int new_value);
int insert_before_key(node_t **head, int key_value, int new_value);
int delete_front(node_t **head);
int delete_rear(node_t **head);
int delete_rear2(node_t **head, int *data);
void list_display(node_t **head);
void delete_list(node_t **head);
int list_size(node_t **head);
int list_reverse(node_t **head);
int list_rm_dup_unsorted(node_t **head);


#endif // LIST_OPS_H_
