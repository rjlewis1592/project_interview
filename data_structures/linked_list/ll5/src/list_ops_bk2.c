#include "list_cmn.h"
#include "list_defs.h"
#include "list_ops.h"

static node_t *create_node(int value)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        LOG_ERR("malloc(): %s(%d)", strerror(errno), errno);
        return NULL;
    }

    new_node->data = value;
    new_node->next = NULL;

    return new_node;

}

int delete_list(node_t **head)
{
    node_t *tmp = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_FAILURE;
    }

    while ((*head) != NULL) {
        tmp = *head;
        *head = (*head)->next;
        LOG_DBG("free()ing tmp %p, tmp->data %d", tmp, tmp->data);
        free(tmp);
        tmp = NULL; // dangling pointer - fix it !
        LOG_DBG("tmp %p", tmp);
    }

    LOG_DBG("*head %p", *head);

    return LIST_SUCCESS;
}

void list_display(node_t **head)
{
    int i = 0;
    int lsz = 0;
    if (head == NULL) {
        LOG_ERR("head %p", head);
        return;
    }

    lsz = list_size(head);

    printf("\n");
    printf("======");
    for (i = 0; i < lsz; i++) {
        printf("======");
    }
    printf("\n");
    printf("list: ");
    while ((*head) != NULL) {
        printf("(%d) ", (*head)->data);
        head = &((*head)->next);
    }

    printf("\n");
    printf("======");
    for (i = 0; i < lsz; i++) {
        printf("======");
    }

    printf("\n");

    return;
}

int insert_front(node_t **head, int value)
{
    node_t *new_node = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_FAILURE;
    }

    new_node = create_node(value);
    if (new_node == NULL) {
        LOG_DBG("Could not create new node!");
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
        LOG_ERR("head %p", head);
        return LIST_FAILURE;
    }

    new_node = create_node(value);
    if (new_node == NULL) {
        LOG_ERR("Could not create new node!");
        return LIST_FAILURE;
    }

    while ((*head) != NULL) {
        head = &((*head)->next);
    }

    *head = new_node;

    return LIST_SUCCESS;
}

/* Insert a new node at a given postion in the linked list.
 * if the given position is greater than size of the list, then insert node at the end.
 * Assume list beginning index as 1
*/
int insert_at_position(node_t **head, int value, int pos)
{
    int nc = 1; // node count - initialize to 1 as list index begins from 1;
    node_t *new_node = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_FAILURE;
    }

    if (pos <= 0) {
        LOG_ERR("Invalid pos %d", pos);
        return LIST_FAILURE;
    }

    new_node = create_node(value);
    if (new_node == NULL) {
        LOG_ERR("Could not create new node!");
        return LIST_FAILURE;
    }

    while ((*head != NULL) && (nc < pos)) {
        head = &((*head)->next);
        nc++;
    }

    if (*head == NULL) { // end of list
        LOG_DBG("End of list - nc %d, pos %d. Inserting node %d", nc, pos, value);
        *head = new_node;
    } else {
        LOG_DBG("Inserting node %d at pos %d, nc %d", value, pos, nc);
        new_node->next = *head;
        *head = new_node;
    }

    return LIST_SUCCESS;
}

/* Insert the given value after a key value in the list.
 * If the key value not found, insert at the end.                    
 */

int insert_after_key(node_t **head, int key_value, int new_value)
{
    node_t *new_node = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_FAILURE;
    }

    new_node = create_node(new_value);
    if (new_node == NULL) {
        LOG_ERR("Could not create new node!");
        return LIST_FAILURE;
    }

    while ((*head != NULL) && (((*head)->data)!= key_value)) {
        head = &((*head)->next);
    }

    if (*head == NULL) {
        LOG_DBG("End of list - key %d not found. Insert %d at end.", key_value, new_value);
        *head = new_node;
    } else {
        LOG_DBG("key %d found. Insert new value %d after it", key_value, new_value);
        new_node->next = (*head)->next;
        (*head)->next = new_node;
    }

    return LIST_SUCCESS;
}

int insert_before_key(node_t **head, int key_value, int new_value)
{
    node_t *new_node = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_FAILURE;
    }

    new_node = create_node(new_value);
    if (new_node == NULL) {
        LOG_ERR("Could not create new node!");
        return LIST_FAILURE;
    }

    while ((*head != NULL) && ((*head)->data != key_value)) {
        head = &((*head)->next);
    }

    if (*head == NULL) {
        LOG_DBG("End of list - key %d not found. Insert %d at end.", key_value, new_value);
        *head = new_node;
    } else {
        LOG_DBG("key %d found. Insert new value %d before key", key_value, new_value);
        new_node->next = *head;
        *head = new_node;
    }

    return LIST_SUCCESS;
}

int delete_front(node_t **head)
{
    return LIST_SUCCESS;
}

int delete_rear(node_t **head)
{
    return LIST_SUCCESS;
}

int list_size(node_t **head)
{
    int count = 0;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return -1;
    }

    while ((*head) != NULL) {
        count++;
        head = &((*head)->next);
    }

    return count;
}

int list_reverse(node_t **head)
{
    return LIST_SUCCESS;
}

int list_rm_dup_unsorted(node_t **head)
{
    return LIST_SUCCESS;
}

int list_exit(node_t **head)
{
    return delete_list(head);
}