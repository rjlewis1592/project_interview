#ifndef LIST_OPS_H_
#define LIST_OPS_H_

#include "list_cmn.h"

node_t* insert_front(node_t *head, int value);
node_t* insert_rear(node_t *head, int value);
node_t* delete_front(node_t *head, int *data);
node_t* delete_rear(node_t *head, int *data);
node_t* delete_rear2(node_t *head, int *data);
void list_display(node_t *head);
void delete_list(node_t *head);
size_t list_size(node_t *head);
node_t* insert_at_position(node_t *head,  int value, unsigned int pos);

#endif // LIST_OPS_H_
