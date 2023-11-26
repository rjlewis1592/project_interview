#include "cbuf_defs.h"
#include "cbuf_utils.h"

static void cbuf_init(cbuf_t *cb);

static void cbuf_init(cbuf_t *cb)
{
    if (cb == NULL) {
        LOG_ERR("cb %p", cb);
        exit (EXIT_FAILURE);
    }

    cb->head = NULL;
    cb->tail = NULL;

    LOG_DBG("Success: initialized circular buffer - cb->head %p, cb->tail %p", cb->head, cb->tail);

    return;
}

int cbuf_create(cbuf_t **cb)
{
    if (cb == NULL) {
        LOG_ERR("cb %p", cb);
        return CBUF_OP_FAIL;
    }

    *cb = (cbuf_t *)malloc(sizeof(cbuf_t));

    if ((*cb) == NULL) {
        LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
        return CBUF_OP_FAIL;
    }

    LOG_DBG("Success: created circular buffer %p", *cb);

    cbuf_init((*cb));

    return CBUF_OP_SUCCESS;
}


void print_cbuf_status(cbuf_t *cb)
{
    if (cb == NULL) {
        LOG_ERR("cb %p", cb);
        return;
    }

    printf("cb %p, cb->head %p, cb->tail %p", cb, cb->head, cb->tail);

    if (cb->head != NULL) {
        printf("cb->head->data %d, cb->head->next %p ", cb->head->data, cb->head->next);
    }

    if (cb->tail != NULL) {
        printf("cb->tail->data %d, cb->tail->next %p", cb->tail->data, cb->tail->next);
    }

    printf("\n");

    return;
}


void cbuf_display(cbuf_t *cb)
{
    node_t *temp = NULL;

    if (cb == NULL) {
        LOG_ERR("cb %p", cb);
        return;
    }

    printf("\nCIRCULAR BUFFER: ");
    fflush(stdout);

    if (is_cbuf_empty(cb) == true) {
        LOG_DBG("empty circular buffer");
        printf("\n");
        return;
    }

    temp = cb->head;
    do {
        printf("(%d) ", temp->data);
        temp = temp->next;
    } while (temp != cb->tail->next);
   
    printf("\n");

    return;
}

void cbuf_exit(cbuf_t *cb)
{
    node_t *temp = NULL;

    if (cb == NULL) {
        LOG_ERR("cb %p", cb);
        return;
    }

    if (is_cbuf_empty(cb) == true) {
        LOG_DBG("empty circular buffer");
        return;
    }

    while (cb->head != cb->tail) {
        temp = cb->head;
        cb->head = cb->head->next;
        cb->tail->next = cb->head;
        LOG_DBG("free()ing %d", temp->data);
        free(temp);
        temp = NULL;
    }

    // head = cb->tail - reached last element or circular buffer had just one element
    LOG_DBG("free()ing %d", cb->head->data);
    free(cb->head);
    cb->head = cb->tail = NULL;

    print_cbuf_status(cb);

    return;
}