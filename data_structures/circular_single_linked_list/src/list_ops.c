#include "list_cmn.h"
#include "list_defs.h"
#include "list_ops.h"

static node_t *create_node(int value);

static node_t *create_node(int value)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
        return NULL;
    }

    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}

node_t *insert_front(node_t *last, int value)
{
    node_t *new_node = NULL;

    new_node = create_node(value);
    if (new_node == NULL) {
        LOG_ERR("Could not create new node for %d", value);
        return last;
    }

    if (last == NULL) {
        new_node->next = new_node;
        last = new_node;
    } else {
        new_node->next = last->next;
        last->next = new_node;
    }

    return last;
}

node_t *insert_last(node_t *last, int value)
{
    node_t *new_node = NULL;

    new_node = create_node(value);
    if (new_node == NULL) {
        LOG_ERR("Could not create new node for %d", value);
        return last;
    }

    if (last == NULL) {
        new_node->next = new_node;
    } else {
        new_node->next = last->next;
        last->next = new_node;
    }

    last = new_node;

    return last;
}

node_t *insert_at_position(node_t *last, int value, int pos)
{
    int count = INT_MIN;
    node_t *curr = NULL;
    node_t *prev = NULL;

    if (pos <= 0) {
        LOG_ERR("Invalid position %d", pos);
        return last;
    }
    
    curr = last->next;  // head;
    prev = last;
    count = 1; // atleaset one node is there and curr is pointing at it.

    do {
        if (count == pos) {
            node_t *new_node = NULL;
            LOG_DBG("At position %d - inserting %d", pos, value);
            new_node = create_node(value);
            if (new_node == NULL) {
                LOG_ERR("could not create new node %d", value);
                return last;
            }
            new_node->next = curr;
            prev->next = new_node;

            break;
        } else {
            count++;
            prev = curr;
            curr = curr->next;
        }
    } while (curr != last->next);

    if (curr == last->next) {
        LOG_ERR("positiong %d > list size %d", pos, list_size(last));
    }

    return last;
}

node_t *insert_after_key(node_t *last, int key_value, int new_value)
{
    node_t *temp = NULL;

    if (last == NULL) {
        LOG_ERR("empty list");
        return last;
    }

    temp = last->next;
    do {
        if (temp->data == key_value) {
            LOG_DBG("key (%d) found - inserting new value (%d) after it" , key_value, new_value);
            node_t *new_node = create_node(new_value);
            if (new_node == NULL) {
                LOG_ERR("could not create new node for %d", new_value);
                return last;
            }

            new_node->next = temp->next;
            temp->next = new_node;

            if (temp == last) {
                last = new_node;
            }
            break;
        } else {
            temp = temp->next;
        }
    } while (temp != last->next);

    if (temp == last->next) {
        LOG_DBG("could not find key %d", key_value);
    }

    return last;
}

node_t *insert_before_key(node_t *last, int key_value, int new_value)
{
    node_t *curr = NULL;
    node_t *prev = NULL;

    if (last == NULL) {
        LOG_ERR("empty list");
        return last;
    }

    prev = last;
    curr = last->next;

    do {
        if (curr->data == key_value) {
            LOG_DBG("key (%d) found - inserting new value (%d) after it" , key_value, new_value);

            node_t *new_node = create_node(new_value);
            if (new_node == NULL) {
                LOG_ERR("could not create new node for %d", new_value);
                return last;
            }

            new_node->next = curr;
            prev->next = new_node;

            break;
        } else {
            prev = curr;
            curr = curr->next;
        }
    } while (curr != last->next);

    if (curr == last->next) {
        LOG_DBG("could not find key %d", key_value);
    }

    return last;
}

node_t *delete_front(node_t *last)
{
    node_t *temp = NULL;

    if (last == NULL) {
        LOG_ERR("empty list");
        return last;
    }

    if (last->next == last) {
        LOG_DBG("Just a single node in the list - deleting it...");
        free(last);
        last = NULL;
    } else {
        temp = last->next;
        last->next = last->next->next;

        LOG_DBG("free()ing %p, %d", temp, temp->data);
        free(temp);
        temp = NULL;
    }

    return last;
}

node_t *delete_last(node_t *last)
{
    if (last == NULL) {
        LOG_ERR("empty list");
        return last;
    }

    if (last->next == last) {
        LOG_DBG("Just a single node in the list %d - deleting it...", last->data);
        free(last);
        last = NULL;
    } else {
        node_t *temp = last->next;
        
        while (temp->next != last) {
            temp = temp->next;
        }

        temp->next = last->next;
        LOG_DBG("free()ing last %p, %d", last, last->data);
        free(last);
        last = NULL;
        last = temp;

    }

    return last;
}

node_t *delete_after_key(node_t *last, int key)
{
    node_t *temp = NULL;

     if (last == NULL) {
        LOG_ERR("empty list");
        return last;
    }

    if (last->next == last) {
        LOG_DBG("Just a single node %d - nothing to delete after it", last->data);
        return last;
    }

    temp = last->next;
    do {
        if (temp->data == key) {
            node_t *temp_next = NULL;
            LOG_DBG("key %d found - deleting the next node %d after it", temp->data, temp->next->data);
            temp_next = temp->next;
            temp->next = temp_next->next;

            if (temp_next == last) {
                last = temp;
            }
            free(temp_next);
            temp_next = NULL;
            break;
        } else {
            temp = temp->next;
        }
    } while (temp != last->next);

    if (temp == last->next) {
        LOG_DBG("could not find key %d", key);
    }

    return last;
}


node_t *delete_before_key(node_t *last, int key)
{
    node_t *prev = NULL;
    node_t *curr = NULL;

    if (last == NULL) {
        LOG_ERR("empty list");
        return last;
    }

    if (last->next == last) {
        LOG_DBG("Just a single node %d - nothing to delete before it", last->data);
        return last;
    }

    prev = last;
    curr = last->next;
    do {
        if (curr->next->data == key) {
            LOG_DBG("key %d foun ! Deleting previous node %d", curr->next->data, curr->data);
            prev->next = curr->next;
            if (curr == last) {
                last = prev;
            }
            free (curr);
            curr = NULL;
            break;
        } else {
            prev = curr;
            curr = curr->next;
        }
    } while (curr != last->next);

    if (curr == last->next) {
        LOG_DBG("key %d - NOT FOUND !", key);
    }

    return last;
}

node_t *delete_key_node(node_t *last, int key)
{
    node_t *prev = NULL;
    node_t *curr = NULL;

     if (last == NULL) {
        LOG_ERR("empty list");
        return last;
    }

    if (last->next == last) {
        if (last->data == key) {
            LOG_DBG("Just a single node (%d) - key (%d) matches", last->data, key);
            free(last);
            last = NULL;
        } else {
            LOG_DBG("key (%d) NOT found", key);
        }

        return last;
    }

    prev = last;
    curr = last->next;
    do {
        if (curr->data == key) {
            LOG_DBG("key (%d) found", key);
            prev->next = curr->next;
            if (curr == last) {
                last = prev;
            }
            LOG_DBG("free()ing %d...", curr->data);
            free(curr);
            curr = NULL;
            break;
        } else {
            prev = curr;
            curr = curr->next;
        }
    } while (curr != last->next);

    if (curr == last->next) {
        LOG_DBG("key %d - NOT FOUND !", key);
    }

    return last;
}

int list_size(node_t *last)
{
    node_t *temp = NULL;
    int count = 0;

    if (last == NULL) {
        LOG_DBG("empty list");
        return count; // 0
    }

    temp = last->next;
    do {
        count++;
        temp = temp->next;
    } while (temp != last->next);

    LOG_DBG("count %d", count);
    return count;
}

void list_exit(node_t *last)
{
    node_t  *temp = NULL;
    node_t  *head = NULL;

    if (last == NULL) {
        LOG_DBG("empty list - nothing to delete");
        return;
    }

    head = last->next;

    while (head != last) {
        temp = head;
        head = head->next;
        LOG_DBG("free()ing temp %p, %d", temp, temp->data);
        free(temp);
        temp = NULL;
        if (last->next != NULL) // last.next is a dangling pointer after freeing first node - fix it !
            last->next = NULL;
    }

    LOG_DBG("free()ing last %p, %d", last, last->data);
    free(last);
    last = NULL;

    return;
}