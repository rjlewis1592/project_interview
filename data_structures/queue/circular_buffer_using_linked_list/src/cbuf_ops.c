#include "cbuf_cmn.h"
#include "cbuf_defs.h"
#include "cbuf_ops.h"
#include "cbuf_utils.h"

static node_t *create_node(int value);

static node_t *create_node(int value)
{
    node_t *new_node = NULL;

    new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
        return NULL;
    }

    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}

bool is_cbuf_empty(cbuf_t *cb)
{
    if (cb == NULL) {
        LOG_ERR("cb %p", cb);
        exit (EXIT_FAILURE);
    }

    if ((cb->head == NULL) && (cb->tail == NULL))
        return true;
    
    return false;
}

int cbuf_enqueue(cbuf_t *cb, int value)
{
    node_t *new_node = NULL; 

    if (cb == NULL) {
        LOG_ERR("cb %p", cb);
        exit (EXIT_FAILURE);
    }

    new_node = create_node(value);
    if (new_node == NULL) {
        LOG_DBG("could not create new node for %d", value);
        return CBUF_OP_FAIL;
    }

    if (is_cbuf_empty(cb) == true) {
        new_node->next = new_node;
        cb->head = cb->tail = new_node;
    } else {
        new_node->next = cb->head;
        cb->tail->next = new_node;
        cb->tail = new_node;
    }

    return CBUF_OP_SUCCESS;
}

int cbuf_dequeue(cbuf_t *cb)
{
    node_t *temp = NULL;

    if (cb == NULL) {
        LOG_ERR("cb %p", cb);
        exit (EXIT_FAILURE);
    }

    if (is_cbuf_empty(cb) == true) {
        LOG_DBG("empty circular buffer - nothing to dequeue");
        return CBUF_OP_FAIL;
    }

    temp = cb->head;
    if (cb->head == cb->tail) {
        cb->head = cb->tail = NULL; // single element in the queue - reset indices
    } else {
        cb->head = cb->head->next;
        cb->tail->next = cb->head;
    }

    LOG_DBG("deque()ing %d...", temp->data);
    free(temp);
    temp = NULL;

    return CBUF_OP_SUCCESS;
}
