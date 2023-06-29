/* List utility function implementations */
#include "list_defs.h"

#include "list_ops.h"
#include "list_cmn.h"

static node_t *create_node(int value)
{
	node_t *tmp = (node_t *)malloc(sizeof(node_t));

	if (!tmp) {
		fprintf(stderr, "malloc(): %s\n", strerror(errno));
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
		fprintf(stderr, "%s: Cannot create new node. Return.\n", __func__);
		return new_node;
	}

	new_node->next = head;
	head = new_node;

	return head;
}

node_t* insert_rear(node_t *head, int value)
{
	node_t *tmp = NULL;
	node_t *new = NULL;

	new = create_node(value);

	if (new == NULL) {
		fprintf(stderr, "%s: Cannot create new node. Return.\n", __func__);
		return new;
	}

	if (head == NULL) {
		head = new;
		head->next = NULL;
		return new;
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

int insert_at_position2(node_t **head, int value, unsigned int pos)
{
	size_t list_sz;
	node_t *new_node = NULL;

	assert(head);

	list_sz = list_size(*head);

	if (pos < 1 || (pos > (list_sz + 1))) {
		fprintf(stderr, "%s: invalid position %d, list_sz %zu\n", __func__, pos, list_sz);
		return -1;

	}

	if ((new_node = create_node(value)) == NULL) {
		fprintf(stderr, "%s: could not create a new node\n", __func__);
		return 1;
	}

	while (pos--) {
		if (pos == 0) {
			new_node->next = *head;
			*head = new_node;
		} else {
			head = &((*head)->next);
		}
	}

	return 0;
}

node_t* insert_at_position3(node_t *head_ptr, int value, unsigned int pos)
{
	node_t **head = &head_ptr;
	size_t list_sz;
	node_t *new_node = NULL;

	assert(head);

	list_sz = list_size(*head);

	if (pos < 1 || (pos > (list_sz + 1))) {
		fprintf(stderr, "%s: invalid position %d, list_sz %zu\n", __func__, pos, list_sz);
		return head_ptr;

	}

	if ((new_node = create_node(value)) == NULL) {
		fprintf(stderr, "%s: could not create a new node\n", __func__);
		return head_ptr;
	}

	while (pos--) {
		if (pos == 0) {
			new_node->next = *head;
			*head = new_node;
		} else {
			head = &((*head)->next);
		}
	}

	return head_ptr;
}
int insert_rear2(node_t **head_dptr, int value)
{
        assert(head_dptr); 

        node_t *new_node = create_node(value);

        if (!new_node) {
                fprintf(stderr, "%s: Could not create new node. Return.\n", __func__);
                return LIST_FAILURE;
        }

        while (*head_dptr) {
                head_dptr = &((*head_dptr)->next);
        }

        *head_dptr = new_node;

        return LIST_SUCCESS;
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

node_t *delete_rear2(node_t *head, int *retval)
{
	node_t *entry = NULL;
	node_t *prev = NULL;


	if (head == NULL) {
		fprintf(stderr, "%s: empty list\n", __func__);
		return NULL;
	}

	entry = head;
	prev = NULL;

	while (entry->next != NULL) {
		prev = entry;
		entry = entry->next;
	}	

	*retval = entry->data;

	if (prev == NULL) { // No previous node i.e only one node in the list
		head = NULL;
	} else {
		prev->next = entry->next; // NULL
	}

	free(entry);

	return head;

}

int delete_rear3(node_t **head_dptr, int *retval)
{
	assert(head_dptr);

	printf("%d@%s: list head %p\n", __LINE__, __func__, *head_dptr);

	if ((*head_dptr) == NULL) {
		fprintf(stderr, "%s: empty list\n", __func__);
		return LIST_FAILURE;
	}

	while ((*head_dptr)->next != NULL) {
		head_dptr = &((*head_dptr)->next);
	}

	*retval = (*head_dptr)->data;
	printf("%s: delete node %d\n", __func__, *retval);

	free((*head_dptr));

	*head_dptr = NULL;

	printf("%d@%s: list head %p\n", __LINE__, __func__, *head_dptr);
	return LIST_SUCCESS;
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
	node_t *temp = NULL;

	if (head == NULL) {
		fprintf(stderr, "%s: emtpy list\n", __func__);
		return 0;
	}

	temp = head;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}

	return count;
}
