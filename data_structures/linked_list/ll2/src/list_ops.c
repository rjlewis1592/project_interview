/* List utility function implementations */
#include "list_defs.h"
#include "list_ops.h"
#include "list_cmn.h"

void list_display(node_t **head)
{
	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error. head %p\n", __FUNCTION__, __LINE__, head);
		return;
	}

	if ((*head) == NULL) {
		fprintf(stderr, "%s, %d - Empty list. *head %p\n", __FUNCTION__, __LINE__, *head);
		return;
	}

	while ((*head) != NULL) {
		printf("%d->", (*head)->data);
		head = &((*head)->next);
	}
	printf("NULL\n");

	return;
}

static node_t *create_node(int value)
{
	node_t *new_node =  NULL;

	new_node = (node_t *)malloc(sizeof(node_t));
	if (new_node == NULL) {
		fprintf(stderr, "%s, %d - malloc(): %s(%d)\n", __FUNCTION__, __LINE__, strerror(errno), errno);
		return NULL;
	}

	new_node->data = value;
	new_node->next = NULL;

	return new_node;
}

int insert_front(node_t **head, int value)
{
	node_t *new_node = NULL;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error. head %p\n", __FUNCTION__, __LINE__, head);
		return -1;
	}

	new_node = create_node(value);
	if (new_node == NULL) {
		fprintf(stderr, "%s, %d - Error. Cannot create new node for value %d\n", __FUNCTION__, __LINE__, value);
		return -1;
	}

	new_node->next = *head;
	*head = new_node;

	return 0;
}

int insert_rear(node_t **head, int value)
{
	node_t *new_node = NULL;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error. head %p\n", __FUNCTION__, __LINE__, head);
		return -1;
	}

	new_node = create_node(value);
	if (new_node == NULL) {
		fprintf(stderr, "%s, %d - Error. Cannot create new node for value %d\n", __FUNCTION__, __LINE__, value);
		return -1;
	}

	while ((*head) != NULL) {
		head = &((*head)->next);
	}

	*head = new_node;

	return 0;
}

int delete_front(node_t **head)
{
	node_t *tmp_head = NULL;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error. head %p\n", __FUNCTION__, __LINE__, head);
		return -1;
	}

	if ((*head) == NULL) {
		fprintf(stderr, "%s, %d - Empty list. Nothing to delete. (*head) %p\n", __FUNCTION__, __LINE__, (*head));
		return 0;
	}

#ifdef LIST_DEBUG
	fprintf(stderr, "%s, %d - deleting node (%p, %d)\n", __FUNCTION__, __LINE__, (*head), (*head)->data);
#endif // LIST_DEBUG

	tmp_head = (*head);
	(*head) = (*head)->next; // new head
	free(tmp_head);
	tmp_head = NULL; // Dangling pointer - fix it !

#ifdef LIST_DEBUG
	fprintf(stderr, "%s, %d - fixed dangling head - tmp_head %p\n", __FUNCTION__, __LINE__, tmp_head);
#endif // LIST_DEBUG

	return 0;
}

int delete_rear(node_t **head)
{
	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error. head %p\n", __FUNCTION__, __LINE__, head);
		return -1;
	}

	if ((*head) == NULL) {
		fprintf(stderr, "%s, %d - Empty list. Nothing to delete. (*head) %p\n", __FUNCTION__, __LINE__, (*head));
		return 0;
	}

	while ((*head)->next != NULL) {
		head = &((*head)->next);
	}

#ifdef LIST_DEBUG
	fprintf(stderr, "%s, %d - deleting node (%p, %d)\n", __FUNCTION__, __LINE__, (*head), (*head)->data);
#endif // LIST_DEBUG

	free(*head);
	*head = NULL;

#ifdef LIST_DEBUG
	fprintf(stderr, "%s, %d - freed first node %p\n", __FUNCTION__, __LINE__, head);
#endif // LIST_DEBUG

	return 0;
}

int insert_after_key(node_t **head, int key_value, int new_value)
{
	node_t *new_node = NULL;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error. head %p\n", __FUNCTION__, __LINE__, head);
		return -1;
	}
	new_node = create_node(new_value);
	if (new_node == NULL) {
		fprintf(stderr, "%s, %d: Error - could not create new node for value %d\n", __FUNCTION__, __LINE__, new_value);
		return -1;
	}

	while(((*head) != NULL) && ((*head)->data != key_value))
	{
		head = &((*head)->next);
	}

	if (*head == NULL) {
#ifdef LIST_DEBUG
		fprintf(stderr, "%s, %d: key %d not found! Inserting %d to the end of list\n", __FUNCTION__, __LINE__, key_value, new_value);
#endif // LIST_DEBUG
		*head = new_node;
		return 0;
	} else {
#ifdef LIST_DEBUG
		fprintf(stderr, "%s, %d: Success - found %d key. Inserting new value %d after it\n", __FUNCTION__, __LINE__, key_value, new_value);
#endif // LIST_DEBUG
		new_node->next = (*head)->next;
		(*head)->next = new_node;
	}

	return 0;
}

int insert_at_position(node_t **head, int value, unsigned int pos)
{
	return 0;
}

size_t list_size(node_t **head)
{
	return 0;
}

void delete_list(node_t **head)
{
	return;
}