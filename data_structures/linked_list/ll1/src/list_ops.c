/* List utility function implementations */
#include "list_defs.h"

#include "list_ops.h"
#include "list_cmn.h"

static node_t *create_node(int value)
{
	node_t *tmp = (node_t *)malloc(sizeof(node_t));
	if (!tmp) {
		fprintf(stderr, "malloc(): %s (%d)\n", strerror(errno), errno);
		return NULL;
	}

	tmp->data = value;
	tmp->next = NULL;

	return tmp;
}

node_t* insert_front(node_t *head, int value)
{
	node_t *new_node = create_node(value);
	if (!new_node) {
		fprintf(stderr, "%s: Cannot create new node. Return orginal list head.\n", __func__);
		return head;
	}

	new_node->next = head;
	head = new_node;

	return head; // new head
}

node_t* insert_rear(node_t *head, int value)
{
	node_t *tmp = NULL;
	node_t *new = NULL;

	new = create_node(value);

	if (new == NULL) {
		fprintf(stderr, "%s: Cannot create new node. Return original list head.\n", __func__);
		return head;
	}

	if (head == NULL) { // empty list
		head = new;
		head->next = NULL;
		return head;
	} 

	tmp = head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

 	tmp->next = new;
	new->next = NULL;

	return head;
}

node_t* insert_at_position(node_t *head,  int value, unsigned int pos)
{
	unsigned int curr_pos = 0;
	node_t *current = NULL;
	node_t *new_node = NULL;
	size_t lsz =  list_size(head);

	printf("%s: list_size %zu, pos %u\n", __func__, lsz, pos);

	if ((pos < 1)) {
		fprintf(stderr, "%s: invalied position %u. list_size %zu\n", __func__, pos, lsz);
		 return head;
	}

	new_node = create_node(value);
	if (new_node == NULL) {
		fprintf(stderr, "%s: could not get new node\n", __func__);
		return head; 
	}

	// If the list is empty, just insert the new node at head 
	if (head == NULL) {
		printf("%s: empty list. insert node at head\n", __func__);
		head = new_node;
	} else if (pos == 1) {
		printf("%s: only one node.\n", __func__);
		new_node->next = head->next;
		head = new_node;
	} else { 
		if (pos > (lsz + 1)) {
			printf("pos (%u) > list_size (%zu). Reset given pos to list size)\n", pos, lsz);
			pos = lsz + 1;
			printf("new position %u\n", pos);
		}
		current = head;
		curr_pos = 1;
		while (current != NULL) {
			if (curr_pos == (pos - 1)) {
				new_node->next = current->next;
				current->next = new_node;
				list_display(head);
				return head;
			}
			curr_pos++;
			current = current->next;
		}

	}

	list_display(head);
	return head;
}


node_t* delete_front(node_t *head, int *data)
{
	node_t *tmp = NULL;

	if (head == NULL) {
		fprintf(stderr, "%s: empty list\n", __func__);
		return head;
	}

	tmp = head;
	printf("%s: deleting front node %d\n", __func__, tmp->data);
	*data = tmp->data;
	head = head->next;
	free(tmp);

	if (head != NULL) {
		printf("%s:  new head %d\n", __func__, head->data);
	}

	return head;
}

node_t* delete_rear(node_t *head, int *data)
{
	node_t *temp = NULL;
	node_t *prev = NULL;

	if (head == NULL) {
		fprintf(stderr, "%s: empty list\n", __func__);
		return head;
	}

	if (head->next == NULL) {
		printf("%s: deleting the only node %d\n", __func__, head->data);
		*data = head->data;
		free(head);
		head = NULL; // head is a dangling pointer. Fix it!!
		return head;
	}

	temp = head;
	while (temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}

	printf("%s: deleting rear node %d\n", __func__, temp->data);
	*data = temp->data;
	prev->next = NULL;
	free(temp);

	return head;

}

void delete_list(node_t *head)
{
	node_t *current = NULL;
	node_t *next = NULL;

	if (head == NULL) {
		fprintf(stderr, "Empty list\n");
		return;
	}

	current = head;

	while (current != NULL) {
		next = current->next;
		printf("Freeing current: %d\n", current->data);
		free(current);
		current = next;
	}

	printf("head %p, current %p, next %p\n", head, current, next);

	if (head != NULL) {
		printf("head %p is dangling pointer, fix it!!\n", head);
		head = NULL;
		printf("head %p\n", head);
	}
}

size_t list_size(node_t *head)
{
	size_t count = 0;
	node_t *tmp = NULL;

	if (head == NULL) {
		fprintf(stderr, "%s: emtpy list\n", __func__);
		return 0;
	}

	for (tmp = head; tmp != NULL; tmp = tmp->next) {
		count++;
	}

	return count;
}

void list_display(node_t *head)
{               
     node_t *tmp = NULL;
 
     if (head == NULL) {
         fprintf(stderr, "Empty list\n");
         return;
     }
     
     tmp = head;
     while (tmp != NULL) {
         printf("(%d) -> ", tmp->data);
         tmp = tmp->next;
     }
 
     printf("NULL\n");
     return;
}