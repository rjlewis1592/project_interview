#include "queue_cmn.h"
#include "queue_defs.h"
#include "queue_ops.h"
#include "queue_utils.h"

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

int enqueue(queue_t *q, int value)
{
    node_t *new_node = NULL;

    if (q == NULL) {
        LOG_ERR("q %p", q);
        exit (EXIT_FAILURE);
    }

    new_node = create_node(value);
    if (new_node == NULL) {
        LOG_ERR("could not create new node for %d", value);
        return QUEUE_OP_FAIL;
    }

    if (is_queue_empty(q) == true) {
        q->tail = q->head = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }

    return QUEUE_OP_SUCCESS;
}

int dequeue(queue_t *q)
{
    node_t *temp = NULL;

    if (q == NULL) {
        LOG_ERR("q %p", q);
        exit (EXIT_FAILURE);
    }

    if (is_queue_empty(q) == true) {
        LOG_ERR("empty queue - nothing to dequeue");
        return QUEUE_OP_FAIL;
    }

    temp = q->head;

    q->head = q->head->next;

    if (q->head == NULL) { // empty queue - resert queue indices
        q->tail = NULL;
    }

    LOG_DBG("dequeue()ing %d...", temp->data);
    free(temp);
    temp = NULL;

    return QUEUE_OP_SUCCESS;
}
