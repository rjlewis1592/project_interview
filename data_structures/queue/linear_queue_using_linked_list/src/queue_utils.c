#include "queue_defs.h"
#include "queue_utils.h"

static void queue_init(queue_t *q);

static void queue_init(queue_t *q)
{
    if (q == NULL) {
        LOG_ERR("q %p", q);
        exit (EXIT_FAILURE);
    }

    q->head = NULL;
    q->tail = NULL;

    return;
}

int queue_create(queue_t **qp)
{
    if (qp == NULL) {
        LOG_ERR("qp %p", qp);
        return QUEUE_OP_FAIL;
    }

    *qp = (queue_t *)malloc(sizeof(queue_t));
    if ((*qp) == NULL) {
        LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
        return QUEUE_OP_FAIL;
    }

    queue_init((*qp));

    LOG_DBG("Success: created initial queue %p", *qp);

    return QUEUE_OP_SUCCESS;
}

void print_queue_status(queue_t *q)
{
    if (q == NULL) {
        LOG_ERR("q %p", q);
        return;
    }

    printf("q %p, q->head %p, q->tail %p,", q, q->head, q->tail);

    if (q->head != NULL) {
        printf("q->head->data %d, q->head->next %p,", q->head->data, q->head->next);
    }

    if (q->tail != NULL) {
        printf("q->tail->data %d, q->tail->next %p", q->tail->data, q->tail->next);
    }

    printf("\n");

    return;
}

void queue_display(queue_t *q)
{   
    node_t *temp = NULL;

    if (q == NULL) {
        LOG_ERR("q %p", q);
        exit (EXIT_FAILURE);
    }

    printf("\nLINEAR QUEUE: ");
    fflush(stdout);

    if (is_queue_empty(q) == true) {
        printf("empty queue");
        printf("\n");
        return;
    }


    temp = q->head;
    do {
        printf("(%d) ", temp->data);
        temp = temp->next;
    } while (temp != NULL);

    printf("\n");

    return;
}

bool is_queue_empty(queue_t *q)
{
    if (q == NULL) {
        LOG_ERR("q %p", q);
        exit (EXIT_FAILURE);
    }

    if ((q->head == NULL) && (q->tail == NULL))  {
        return true;
    }
    
    return false;
}

void queue_exit(queue_t *q)
{
    node_t *temp = NULL; 
    if (q == NULL) {
        LOG_ERR("q %p", q);
        return;
    }

    print_queue_status(q);
    do {
        temp = q->head;
        q->head = q->head->next;
        LOG_DBG("free()ing (%p, %d)", temp, temp->data);
        free(temp);
        temp = NULL;
    } while (q->head != NULL);

    if (q->head == NULL) {
        q->tail = NULL;
    }

    print_queue_status(q);

    return;
}
