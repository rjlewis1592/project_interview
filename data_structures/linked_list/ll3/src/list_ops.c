#include "list_defs.h"
#include "list_cmn.h"
#include "list_ops.h"

static node_t *create_node(int value);

static node_t *create_node(int value)
{
    node_t *new_node = NULL;

    new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        fprintf(stderr, "%d@%s: malloc() - %s(%d)\n", __LINE__, __FUNCTION__, strerror(errno), errno);
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
        fprintf(stderr, "%d@%s: Error - head %p\n", __LINE__, __FUNCTION__, head);
        return LIST_FAILURE;
    }

    new_node = create_node(value);

    if (new_node == NULL) {
#ifdef LIST_DEBUG
        fprintf(stderr, "%d@%s: Fail - could not create new node\n", __LINE__, __FUNCTION__);
#endif // LIST_DEBUG
        return LIST_FAILURE;
    }

    new_node->next = *head;
    *head = new_node;

    return LIST_SUCCESS;
}

int insert_rear(node_t **head, int value)
{
    node_t *new_node = NULL;

    if (head == NULL) {
        fprintf(stderr, "%d@%s: Error - head %p\n", __LINE__, __FUNCTION__, head);
        return LIST_FAILURE;
    }

    new_node = create_node(value);

    if (new_node == NULL) {
#ifdef LIST_DEBUG
        fprintf(stderr, "%d@%s: Fail - could not create new node\n", __LINE__, __FUNCTION__);
#endif // LIST_DEBUG
        return LIST_FAILURE;
    }

    while ((*head) != NULL) {
        head = &((*head)->next);
    }

    *head = new_node;

    return LIST_SUCCESS;
}

/* List start index - 0
 * if list is smaller than the given position, insert new node at the list end
  */
int insert_at_position(node_t **head, int value, int pos)
{
    int idx = 0;
    node_t *new_node = NULL;

    if (head == NULL) {
        fprintf(stderr, "%d@%s: Error - head %p\n", __LINE__, __FUNCTION__, head);
        return LIST_FAILURE;
    }

    if (pos < 0) {
        fprintf(stderr, "%d@%s: Error - Invalid position %d\n", __LINE__, __FUNCTION__, pos);
        return LIST_FAILURE;
    }

    new_node = create_node(value);

    if (new_node == NULL) {
#ifdef LIST_DEBUG
        fprintf(stderr, "%d@%s: Fail - could not create new node\n", __LINE__, __FUNCTION__);
#endif // LIST_DEBUG
        return LIST_FAILURE;
    }   

    while ((*head) != NULL && (idx < pos)) {
        head = &((*head)->next);
        idx++;
    }

    if ((*head) == NULL) { // position is greater than list size - insert at end
#ifdef LIST_DEBUG
        fprintf(stderr, "%d@%s: pos (%d) > list size. Inserting %d at the end of list\n", __LINE__, __FUNCTION__, pos, value);
#endif // LIST_DEBUG
        *head = new_node; 
    } else { // insert at given position
#ifdef LIST_DEBUG
        fprintf(stderr, "%d@%s: Inserting %d at positoin %d of list\n", __LINE__, __FUNCTION__, value, pos);
#endif // LIST_DEBUG
        new_node->next = *head;
        *head = new_node;
    }

    return LIST_SUCCESS;
}

/* Insert a node after the first instance of given key node.
 * If the key node is found in list and is same as new node, do not insert new node.
 * If key node not found, insert at end.
 */
int insert_after_key(node_t **head, int key_value, int value)
{
    node_t *new_node = NULL;

    if (head == NULL) {
        fprintf(stderr, "%d@%s: Error - head %p\n", __LINE__, __FUNCTION__, head);
        return LIST_FAILURE;
    }

    new_node = create_node(value);

    if (new_node == NULL) {
#ifdef LIST_DEBUG
        fprintf(stderr, "%d@%s: Fail - could not create new node\n", __LINE__, __FUNCTION__);
#endif // LIST_DEBUG
        return LIST_FAILURE;
    }

    while ((*head != NULL) && ((*head)->data != key_value)) {
        head = &((*head)->next);
    }

    if (*head == NULL) {
#ifdef LIST_DEBUG
        fprintf(stderr, "%d@%s: key (%d) not found! Inserting (%d) at end\n", __LINE__, __FUNCTION__, key_value, value);
#endif //LIST_DEBUG
        *head = new_node;;
    } else { // key node found 
        if (key_value == value) {
#ifdef LIST_DEBUG
            fprintf(stderr, "%d@%s: key (%d) found but same as new value (%d). Do not insert \n", __LINE__, __FUNCTION__, key_value, value);
#endif //LIST_DEBUG
        } else {
#ifdef LIST_DEBUG
            fprintf(stderr, "%d@%s: Inserting (%d) after key (%d)\n", __LINE__, __FUNCTION__, value, key_value);
#endif //LIST_DEBUG
            new_node->next = (*head)->next;
            (*head)->next = new_node;
        }
    }

    return LIST_SUCCESS;
}

/* Insert a node before a given key node.
 * If given key node iss found in the list and is same as the new node, skip inserting
 * if Key node is not found in the list, insert new node at the end
*/
int insert_before_key(node_t **head, int key_value, int value)
{
    node_t *new_node = NULL;

    if (head == NULL) {
        fprintf(stderr, "%d@%s: Error - head %p\n", __LINE__, __FUNCTION__, head);
        return LIST_FAILURE;
    }

    new_node = create_node(value);

    if (new_node == NULL) {
#ifdef LIST_DEBUG
        fprintf(stderr, "%d@%s: Fail - could not create new node\n", __LINE__, __FUNCTION__);
#endif // LIST_DEBUG
        return LIST_FAILURE;
    }

    while ((*head != NULL) && ((*head)->data != key_value)) {
        head = &((*head)->next);
    }

    if (*head == NULL) {
#ifdef LIST_DEBUG
        fprintf(stderr, "%d@%s: key (%d) not found! Inserting (%d) at end\n", __LINE__, __FUNCTION__, key_value, value);
#endif //LIST_DEBUG
        *head = new_node;
    } else { // key node found
        if (key_value == value) {
#ifdef LIST_DEBUG
            fprintf(stderr, "%d@%s: key (%d) found but same as new value (%d). Do not insert \n", __LINE__, __FUNCTION__, key_value, value);
    #endif //LIST_DEBUG
        } else {
            new_node->next = *head;
            *head = new_node;
        }
    }
        return LIST_SUCCESS;
}

int delete_front(node_t **head)
{
    node_t *temp = NULL;

    if (head == NULL) {
        fprintf(stderr, "%d@%s: Error - head %p\n", __LINE__, __FUNCTION__, head);
        return LIST_FAILURE;
    }

    if (*head == NULL) {
#ifdef LIST_DEBUG
        fprintf(stderr, "%d@%s: Empty list - nothing to delete. *head %p\n",  __LINE__, __FUNCTION__, *head);
#endif // LIST_DEBUG
        return LIST_SUCCESS;
    }

    temp = *head;
    *head = (*head)->next;
    free(temp);
    temp = NULL; // dangling pointer - fix it !

    return LIST_SUCCESS;
}

int delete_rear(node_t **head)
{
    if (head == NULL) {
        fprintf(stderr, "%d@%s: Error - head %p\n", __LINE__, __FUNCTION__, head);
        return LIST_FAILURE;
    }

    if (*head == NULL) {
#ifdef LIST_DEBUG
        fprintf(stderr, "%d@%s: Empty list - nothing to delete. *head %p\n",  __LINE__, __FUNCTION__, *head);
#endif // LIST_DEBUG
        return LIST_SUCCESS;
    }

    while (((*head)->next) != NULL) {
        head = &((*head)->next);
    }

#ifdef LIST_DEBUG
    fprintf(stderr, "%d@%s: deleting %d\n", __LINE__, __FUNCTION__,  (*head)->data);
#endif // LIST_DEBUG

    free(*head);
#ifdef LIST_DEBUG
    fprintf(stderr, "%d@%s: *head %p - dangling pointer - fix it!\n", __LINE__, __FUNCTION__, *head);
#endif // LIST_DEBUG

    *head = NULL;

#ifdef LIST_DEBUG
    fprintf(stderr, "%d@%s: fixed dangling pointer - *head %p\n", __LINE__, __FUNCTION__, *head);
#endif // LIST_DEBUG

    return LIST_SUCCESS;
}

void list_display(node_t **head)
{
	if (head == NULL) {
		fprintf(stderr, "%d@%s: Error - head %p\n", __LINE__, __FUNCTION__, head);
		return;
	}

	if (*head == NULL) {
		fprintf(stderr, "Empty list\n");
		return;
	}

	while (*head != NULL) {
		printf("(%d) ", (*head)->data);
		head = &((*head)->next);
	}

	printf("\n");

}

void delete_list(node_t **head)
{
	node_t *prev = NULL;

	if (head == NULL) {
		fprintf(stderr, "%d@%s: Error - head %p\n", __LINE__, __FUNCTION__, head);
		return;
	}

	while (*head != NULL) {
		prev = *head;
		*head = (*head)->next;
		free(prev);
#ifdef LIST_DEBUG
		fprintf(stderr, "%d@%s: freed()ed prev %p - dangling pointer. Fix it !\n", __LINE__, __FUNCTION__, prev);
#endif // LIST_DEBUG
		prev = NULL;
#ifdef LIST_DEBUG
		fprintf(stderr, "%d@%s: prev %p\n", __LINE__, __FUNCTION__, prev);
#endif // LIST_DEBUG
	}

#ifdef LIST_DEBUG
	fprintf(stderr, "%d@%s: List deleted - *head %p\n", __LINE__, __FUNCTION__, *head);
#endif // LIST_DEBUG
}

int list_size(node_t **head)
{

    return LIST_SUCCESS;
}

int list_reverse(node_t **head)
{
    node_t *curr = NULL;
    node_t *prev = NULL;

    if (head == NULL) {
        fprintf(stderr, "%d@%s: Error - head %p\n", __LINE__, __FUNCTION__, head);
        return LIST_FAILURE;
    }

    while ((*head) != NULL) {
        curr = *head;
        *head = (*head)->next;
        curr->next = prev;
        prev = curr;
    }

    *head = curr;

    return LIST_SUCCESS;
}
/* 
 * Remove duplicate element from unsorted list
*/
int list_rm_dup_unsorted(node_t **head)
{
    node_t *hd = NULL;
    node_t *nxt_hd = NULL;

     if (head == NULL) {
        fprintf(stderr, "%d@%s: Error - head %p\n", __LINE__, __FUNCTION__, head);
        return LIST_FAILURE;
    }

    if (*head == NULL) {
		fprintf(stderr, "Empty list\n");
		return LIST_SUCCESS;
	}

    hd = *head;
    while ((hd != NULL) && (hd->next != NULL)) {
        nxt_hd = hd;

        while (nxt_hd->next != NULL) {
            if (hd->data == nxt_hd->next->data) {
                node_t *dup = nxt_hd->next;
                nxt_hd->next = nxt_hd->next->next;
                free(dup);
                dup = NULL;
            } else {
                nxt_hd = nxt_hd->next;
            }
        }
        hd = hd->next;
    }
    return LIST_SUCCESS;
}
