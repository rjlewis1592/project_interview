/* List utility function implementations */
#include "list_defs.h"
#include "list_ops.h"
#include "list_cmn.h"

static node_t *create_node(int value);

void list_display(node_t **head)
{
	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error: head %p", __FUNCTION__, __LINE__, head);
		return;
	}

	printf("LIST: ");

	while ((*head) != NULL) {
		printf("%d ->", (*head)->data);
		head = &((*head)->next);
	}
	printf("NULL\n");

	return;
}

/* allocate memory for new node in head.
 * data - value 
 * next - NULL
 */
static node_t *create_node(int value)
{
	node_t *new_node = NULL;
	
	new_node = (node_t *)malloc(sizeof(node_t));
	if (new_node == NULL) {
		fprintf(stderr, "%s, %d: malloc(): %s (%d)\n",  __FUNCTION__, __LINE__, strerror(errno), errno);
		return NULL;
	}

	new_node->data = value;
	new_node->next = NULL;

	return new_node;
}

node_t* insert_front(node_t *hd, int value)
{
	node_t *new_node = NULL;
	node_t **head = NULL;

	head = &hd;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error: head %p", __FUNCTION__, __LINE__, head);
		return NULL;
	}

	new_node = create_node(value);
	if (new_node == NULL) {
		fprintf(stderr, "%s, %d: could not create a new node\n",  __FUNCTION__, __LINE__);
		return NULL;
	}

	new_node->next = *head;
	*head = new_node;

	return hd;
}

node_t* insert_rear(node_t *hd, int value)
{
	node_t *new_node = NULL;
	node_t **head = NULL;

	head = &hd;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error: head %p", __FUNCTION__, __LINE__, head);
		return NULL;
	}

	new_node = create_node(value);
	if (new_node == NULL) {
		fprintf(stderr, "%s, %d: could not create a new node\n", __FUNCTION__, __LINE__);
		return NULL;
	}

	while ((*head) != NULL) {
		head = &((*head)->next);
	}

	*head = new_node;

	return hd;
}

node_t* delete_front(node_t *hd)
{
	node_t *tmp_head = NULL;
	node_t **head = NULL;

	head = &hd;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error: head %p", __FUNCTION__, __LINE__, head);
		return NULL;
	}

	if ((*head) == NULL) {
		fprintf(stderr, "%s, %d - Empty list. Nothing to delete. (*head) %p\n", __FUNCTION__, __LINE__, (*head));
		return NULL;
	}

	tmp_head = *head;
	*head = (*head)->next;
	free(tmp_head);
	tmp_head = NULL; // dangling pointer - fix it !

	return hd;
}

node_t* delete_rear(node_t *hd)
{
	node_t **head = NULL;
	head = &hd;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error: head %p", __FUNCTION__, __LINE__, head);
		return NULL;
	}

	if ((*head) == NULL) {
		fprintf(stderr, "%s, %d - Empty list. Nothing to delete. (*head) %p\n", __FUNCTION__, __LINE__, (*head));
		return NULL;
	}

	while ((*head)->next != NULL) {
		head = &((*head)->next);
	}

	free(*head);
	*head = NULL; // dangling pointer - fix it !

	return hd;
}

/* Insert a new node after key.
 * If key not found, insert node at the end of list
 */
int insert_after_key(node_t **head, int key_value, int new_value)
{
	node_t *new_node = NULL;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error: head %p", __FUNCTION__, __LINE__, head);
		return -1;
	}

	new_node = create_node(new_value);
	if (new_node == NULL) {
		fprintf(stderr, "%s, %d: could not create a new node\n", __FUNCTION__, __LINE__);
		return -1;
	}

	while (((*head) != NULL) && ((*head)->data != key_value)) {
		head = &((*head)->next);
	}

	if ((*head) == NULL) { // key not found - insert new node at the end of list
#ifdef LIST_DEBUG
		fprintf(stderr, "%s, %d: key %d not found! Inserting %d to the end of list\n", __FUNCTION__, __LINE__, key_value, new_value);	
#endif // LIST_DEBUG
		*head = new_node;
	} else { // key found - insert new node after it
#ifdef LIST_DEBUG
		fprintf(stderr, "%s, %d: key %d found! Inserting %d after it\n", __FUNCTION__, __LINE__, key_value, new_value);	
#endif // LIST_DEBUG

		new_node->next = (*head)->next;
		(*head)->next = new_node;
	}

	return 0;
}

/* Insert a new node after key.
 * If key not found, insert node at the end of list
 */
int insert_before_key(node_t **head, int key_value, int new_value)
{
	node_t *new_node = NULL;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error: head %p", __FUNCTION__, __LINE__, head);
		return -1;
	}

	new_node = create_node(new_value);
	if (new_node == NULL) {
		fprintf(stderr, "%s, %d: could not create a new node\n", __FUNCTION__, __LINE__);
		return -1;
	}

	while (((*head) != NULL) && ((*head)->data != key_value)) {
		head = &((*head)->next);
	}

	if ((*head) == NULL) { // key not found - insert at rear
#ifdef LIST_DEBUG
		fprintf(stderr, "%s, %d: key %d not found! Inserting %d to the end of list\n", __FUNCTION__, __LINE__, key_value, new_value);	
#endif // LIST_DEBUG
		*head = new_node;
	} else { // key found - insert before
#ifdef LIST_DEBUG
        fprintf(stderr, "%s, %d: Success - found %d key. Inserting new value %d after it\n", __FUNCTION__, __LINE__, key_value, new_value);
#endif // LIST_DEBUG
		new_node->next = *head;
		*head = new_node;
	}

	return 0;
}

#if 0
// beginning index 0
int insert_at_position(node_t **head, int value, unsigned int pos)
{	
	//int lsz = 0;
	int nc = 0;
	node_t *new_node = NULL;

#ifdef LIST_DEBUG
    fprintf(stderr, "%s, %d: Inserting %d at pos(%d)\n", __FUNCTION__, __LINE__, value, pos);
#endif // LIST_DEBUG

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error: head %p", __FUNCTION__, __LINE__, head);
		return -1;
	}

#if 0
	lsz = list_size(head);

	if (lsz < 0) {
		fprintf(stderr, "%s, %d - lsz: %d", __LINE__, __FUNCTION__, lsz);
		return -1;
	}
#endif
	
	new_node = create_node(value);
	if (new_node == NULL) {
		fprintf(stderr, "%s, %d: could not create a new node\n", __FUNCTION__, __LINE__);
		return -1;
	}

	while (((*head) != NULL) && (nc < pos)) {
		head = &((*head)->next);
		nc++;
	}

if ((*head) == NULL) {
#ifdef LIST_DEBUG
    	fprintf(stderr, "%s, %d: pos(%d) >= nc(%d) - Insert node at end of list\n", __FUNCTION__, __LINE__, pos, nc);
#endif // LIST_DEBUG
		*head = new_node;
	} else {
#ifdef LIST_DEBUG
    	fprintf(stderr, "%s, %d: pos %d,  nc %d - Insertig node\n", __FUNCTION__, __LINE__, pos, nc);
#endif // LIST_DEBUG
		new_node->next = (*head);
		*head = new_node;
	}

	return 0;
}
#else
// beginning index 1
int insert_at_position(node_t **head, int value, unsigned int pos)
{	
	//int lsz = 0;
	int nc = 0;
	node_t *new_node = NULL;

#ifdef LIST_DEBUG
    fprintf(stderr, "%s, %d: Inserting %d at pos(%d)\n", __FUNCTION__, __LINE__, value, pos);
#endif // LIST_DEBUG

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error: head %p", __FUNCTION__, __LINE__, head);
		return -1;
	}

	if (pos <= 0) {
#ifdef LIST_DEBUG
    	fprintf(stderr, "%s, %d: Invalid pos %d. Inserting positing should be >0 \n", __FUNCTION__, __LINE__, pos);
#endif // LIST_DEBUG
		return -1;
	}
#if 0
	lsz = list_size(head);

	if (lsz < 0) {
		fprintf(stderr, "%s, %d - lsz: %d", __LINE__, __FUNCTION__, lsz);
		return -1;
	}
#endif
	
	new_node = create_node(value);
	if (new_node == NULL) {
		fprintf(stderr, "%s, %d: could not create a new node\n", __FUNCTION__, __LINE__);
		return -1;
	}

	while (((*head) != NULL) && (nc < (pos - 1))) {
		head = &((*head)->next);
		nc++;
	}

if ((*head) == NULL) {
#ifdef LIST_DEBUG
    	fprintf(stderr, "%s, %d: *head %p, pos(%d) > total nc(%d) - Insert node at end of list\n", __FUNCTION__, __LINE__, *head, pos, nc);
#endif // LIST_DEBUG
		*head = new_node;
	} else {
#ifdef LIST_DEBUG
    	fprintf(stderr, "%s, %d: pos %d,  nc %d - Insertig node\n", __FUNCTION__, __LINE__, pos, nc);
#endif // LIST_DEBUG
		new_node->next = (*head);
		*head = new_node;
	}

	return 0;
}
#endif

int list_size(node_t **head)
{
	int nc = 0;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error: head %p", __FUNCTION__, __LINE__, head);
		return -1;
	}

	while ((*head) != NULL) {
		nc++;
		head = &((*head)->next);
	}
	
	return nc;
}

node_t* delete_list(node_t *hd)
{
	node_t *tmp = NULL;
	node_t **head = &hd;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error: head %p", __FUNCTION__, __LINE__, head);
		return hd;
	}

	while ((*head) != NULL) {
		tmp = *head;
		*head = (*head)->next;
#ifdef LIST_DEBUG
    	fprintf(stderr, "%s, %d: free()ing  %p, data %d\n", __FUNCTION__, __LINE__, tmp, tmp->data);
#endif // LIST_DEBUG
		free(tmp);
		tmp = NULL; // dangling pointer - fix it!
#ifdef LIST_DEBUG
    	fprintf(stderr, "%s, %d: tmp %p\n", __FUNCTION__, __LINE__, tmp);
#endif // LIST_DEBUG
	}

	return hd;
}

int list_reverse(node_t **head)
{
	node_t *cur = NULL;
	node_t *prv = NULL;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error: head %p", __FUNCTION__, __LINE__, head);
		return -1;
	}

	while ((*head) != NULL) {
		cur = *head;
		(*head) = (*head)->next;
		cur->next = prv;
		prv = cur;
	}

	*head = cur;

	return 0;
}

int list_rm_dup_unsorted(node_t **head)
{
	node_t *h = NULL;
	node_t *c = NULL;
	node_t *p = NULL;
	node_t *t = NULL;
	int key;

	if (head == NULL) {
		fprintf(stderr, "%s, %d - Error: head %p", __FUNCTION__, __LINE__, head);
		return -1;
	}

	h = *head;

	while (h != NULL) {
		key = h->data;
		p = h;
		c = h->next;

		while (c != NULL) {
			if (key == c->data) {
				t = c;
				c = c->next;
				free(t);
				p->next = c;
			} else {
				p = c;
				c = c->next;
			}
		}

		h = h->next;
	}

	return 0;
}
