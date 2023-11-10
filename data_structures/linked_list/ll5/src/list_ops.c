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
        return LIST_OP_FAILURE;
    }

    while ((*head) != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
        tmp = NULL; // dangling pointer - fix it!
    }

    return LIST_OP_SUCCESS; 
}

void list_display(node_t **head)
{
    if (head == NULL) {
        LOG_ERR("head %p", head);
        return;
    }

    printf("list: ");

    while ((*head) != NULL) {
        printf("(%d) ", (*head)->data);
        head = &((*head)->next);
    }

    printf("\n");

    return;
}

void better_list_display(node_t **head, const char *str)
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
    printf("%s: ", (str != NULL ? str : "LIST"));
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
        return LIST_OP_FAILURE;
    }

    new_node = create_node(value);
    if (new_node == NULL) {
        LOG_DBG("Could not create new node!");
        return LIST_OP_FAILURE;
    }

    new_node->next = *head;
    *head = new_node;

    return LIST_OP_SUCCESS;
}

int insert_rear(node_t **head, int value)
{
    node_t *new_node = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    new_node = create_node(value);
    if (new_node == NULL) {
        LOG_ERR("Could not create new node!");
        return LIST_OP_FAILURE;
    }

    while ((*head) != NULL) {
        head = &((*head)->next);
    }

    *head = new_node;

    return LIST_OP_SUCCESS;
}

/* Insert a new node at a given postion in the linked list.
 * if the given position is greater than size of the list, then insert node at the end.
 * Assume list beginning index as 1
*/
int insert_at_position(node_t **head, int value, int pos)
{
    int nc = 0;
    node_t *new_node = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (pos <= 0) {
        LOG_ERR("Invalid pos %d", pos);
        return LIST_OP_FAILURE;
    }

    new_node = create_node(value);
    if (new_node == NULL) {
        LOG_DBG("Could not create new node!");
        return LIST_OP_FAILURE;
    }

    nc = 1;
    while (((*head) != NULL) && (nc < pos)) {
        nc++;
        head = &((*head)->next);
    }

    if ((*head) == NULL) {
        LOG_DBG("Empty/End of list. pos %d, nc %d. Insert %d.", pos, nc, value);
        *head = new_node;
    } else {
        LOG_DBG("Inserting %d at pos %d, nc %d", value, pos, nc);
        new_node->next = *head;
        *head = new_node;
    }

    return LIST_OP_SUCCESS;
}

/* Insert the given value after a key value in the list.
 * If the key value not found, insert at the end.                    
 */
int insert_after_key(node_t **head, int key_value, int new_value)
{
    node_t *new_node = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    new_node = create_node(new_value);
    if (new_node == NULL) {
        LOG_DBG("Could not create new node!");
        return LIST_OP_FAILURE;
    }

    while (((*head) != NULL) && ((*head)->data != key_value)) {
        head = &((*head)->next);
    }

    if ((*head) == NULL) {
        LOG_DBG("Empty/End of list. Key %d not found. Insert %d", key_value, new_value);
        *head = new_node;
    } else {
        LOG_DBG("Key %d found. Insert %d after it", key_value, new_value);
        new_node->next = (*head)->next;;
        (*head)->next = new_node;
    }

    return LIST_OP_SUCCESS;
}

/* Insert a given value before a key value in the list
 * If key value not found, insert new value at the end
 */

int insert_before_key(node_t **head, int key_value, int new_value)
{
    node_t *new_node = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    new_node = create_node(new_value);
    if (new_node == NULL) {
        LOG_DBG("Could not create new node!");
        return LIST_OP_FAILURE;
    }


    while (((*head) != NULL) && ((*head)->data != key_value)) {
        head = &((*head)->next);
    }

    if ((*head) == NULL) {
        LOG_DBG("Empty/End of list. Key %d not found. Insert %d", key_value, new_value);
        *head = new_node;
    } else {
        new_node->next = *head;
        *head = new_node;
    }

    return LIST_OP_SUCCESS;
}

int delete_front(node_t **head)
{
    node_t *tmp = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (*head == NULL) {
        LOG_DBG("*head %p - Nothing to delete", *head);
        return LIST_OP_FAILURE;
    }

    tmp = *head;
    *head = (*head)->next;
    free(tmp);
    tmp = NULL; // dangling pointer - fix it!

    return LIST_OP_SUCCESS;
}

int delete_rear(node_t **head)
{
    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (*head ==  NULL) {
        LOG_DBG("*head %p - Nothing to delete", *head);
        return LIST_OP_FAILURE;
    }

    while ((*head)->next != NULL) {
        head = &((*head)->next);
    }

    free(*head);
    *head = NULL; // dangling pointer - fix it!

    return LIST_OP_SUCCESS;
}

int list_size(node_t **head)
{
    int nc = INT_MIN;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return nc; 
    }

    if (*head == NULL) {
        LOG_DBG("Empty list - *head %p", *head);
        nc = 0;
        return nc;
    }

    nc = 1;
    while ((*head) != NULL) {
        head = &((*head)->next);
        nc++;
    }

    return (nc - 1);
}

int list_reverse(node_t **head)
{
    node_t *curr = NULL;
    node_t *prev = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if ((*head)->next == NULL) { // single entry
        return LIST_OP_SUCCESS;
    }
    while ((*head) != NULL) {
        curr = *head;
        *head = (*head)->next;
        curr->next = prev;
        prev = curr;
    }

    *head = curr;

    return LIST_OP_SUCCESS;
}
#if 0
int list_rm_dup_unsorted(node_t **head)
{
    node_t *hd = NULL; 

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    hd = *head;
    while ((*head != NULL) && ((*head)->next != NULL)) {
        node_t *nh = *head;

        while (nh->next != NULL) {
            if ((*head)->data == nh->next->data) {
                node_t *t = nh->next;
                nh->next = nh->next->next;
                free(t);
                t = NULL;
            } else {
                nh = nh->next;
            }
        }

        *head = (*head)->next;
    }

    *head = hd;

    return LIST_OP_SUCCESS;
}
#else
int list_rm_dup_unsorted(node_t **head)
{
    node_t *h = NULL;
    node_t *nh = NULL;
    node_t *pr = NULL;

    while (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    h = *head;

    while ((h != NULL) && ((h->next) != NULL)) {
        pr = h;
        nh = h->next;

        while (nh != NULL) {
            if (h->data == nh->data) {
                node_t *t = nh;
                nh = nh->next;
                pr->next = nh;
                free(t);
                t = NULL;  //dangling pointer - fix it!
            } else {
                pr = nh;
                nh = nh->next;
            }
        }
        h = h->next;
    }

    return LIST_OP_SUCCESS;
}
#endif

/* 
 * Return TRUE if the given list in ascending order.
 * The list might contain duplicates.
 */
int is_list_sorted_in_asc_order(node_t **head)
{
    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (*head == NULL) {
        LOG_DBG("Empty list - consider it as a sorted list");
        return LIST_OP_SUCCESS;
    }

    while (((*head)->next != NULL) && (((*head)->data) <= ((*head)->next->data)))
    {
        head = &((*head)->next);
    }

    if ((*head)->next == NULL)
    {
        return LIST_OP_SUCCESS;
    }

    return LIST_OP_FAILURE;
}

/*
* Insert a given element in a list that is sorted in ascending order.
* The list might contain duplicate elements.
*/
int insert_in_ascending_sorted_list(node_t **head, int value)
{
    node_t *new_node = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (is_list_sorted_in_asc_order(head) != LIST_OP_SUCCESS) {
        LOG_DBG("Unsorted list");
        return LIST_OP_FAILURE;
    }

    new_node = create_node(value);
    if (new_node == NULL) {
        LOG_DBG("Could not create new node!");
        return LIST_OP_FAILURE;
    }

    while ((*head != NULL) && (((*head)->data) < value))
    {
        head = &((*head)->next);
    }

    new_node->next = *head;
    *head = new_node;

    return LIST_OP_SUCCESS;

}
static void node_data_swap(int *x, int *y)
{
    int temp = INT_MIN;

    temp = *x;
    *x = *y;
    *y = temp; 
}

#if 1
int sort_list_in_ascending_order(node_t **head)
{
    int i;
    int n = INT_MIN; // list node count 
    node_t *temp = NULL;
    node_t *end_node = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    n = list_size(head);

    if (n <= 0) {
        LOG_DBG("list nocde count - n %d", n);
        return LIST_OP_FAILURE;
    }

    end_node = NULL;
    for (i = 0; i < (n - 1); i++) {
        bool swapped = false;
        for (temp = *head; temp->next != end_node; temp = temp->next) {
            if ((temp->data) > (temp->next->data)) {
                node_data_swap(&(temp->data), &(temp->next->data));
                swapped = true;
            }
        }
        end_node = temp;

        if (swapped == false) {
            break;
        }
    }

    return LIST_OP_SUCCESS;
}
#if 0
int sort_list_in_ascending_order(node_t **head)
{
    node_t *temp = NULL;
    node_t *end_node = NULL;
    int i = INT_MIN;
    int n = INT_MIN;

    if (head == NULL)  {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    n = list_size(head);

    if (n <= 0) {
        LOG_ERR("Invalid n %d", n);
        return LIST_OP_FAILURE;
    }

    end_node = NULL;
    for (i = 0; i < (n - 1); i++) {
        bool swapped = false;
        for (temp = *head; temp->next != end_node; temp = temp->next) {
            if ((temp->data) > (temp->next->data)) {
                node_data_swap(&(temp->data), &(temp->next->data));
                swapped = true;
            }
        }

        end_node = temp;

        if (swapped == false) {
            break;
        }
    }

    return LIST_OP_SUCCESS;
}
#endif

#else
int sort_list_in_ascending_order(node_t **head)
{
    node_t *h = NULL;
    node_t *t = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (*head == NULL) {
        LOG_DBG("Empty list - *head %p", *head);
        return LIST_OP_FAILURE;
    }

    h = *head;
    while (h->next != NULL)
    {
        t = h->next;
        while (t != NULL)
        {
            if (h->data > t->data) {
                //node_data_swap(&(h->data), &(t->data));
                h->next = t->next;
                t->next = h;
            }
           // t = t->next;;
           t = h->next;
        }
        //h = h->next;
        h = t;
    }

    return LIST_OP_SUCCESS;
}
#endif

int list_rm_dup_sorted(node_t **head)
{
    node_t *h = NULL;
    node_t *t = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (is_list_sorted_in_asc_order(head) != LIST_OP_SUCCESS) {
        LOG_DBG("Unsorted list");
        return LIST_OP_FAILURE;
    }

    h = *head;

    while ((h != NULL) && (h->next != NULL)) {
        if (h->data == h->next->data) {
            t = h->next;
            h->next = h->next->next;
            free(t);
            t = NULL;
        } else {
            h = h->next;
        }
    }

    return LIST_OP_SUCCESS;
}

int get_mid_element(node_t **head, int *value)
{
    node_t *sp = NULL;
    node_t *fp = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (*head == NULL) {
        LOG_DBG("Empty list - *head %p", *head);
        return LIST_OP_FAILURE;
    }

    sp = *head;
    fp = *head;
    while ((fp != NULL) && (fp->next != NULL)) {
        sp = sp->next;
        fp = fp->next->next;
    }

    *value = sp->data;

    return LIST_OP_SUCCESS;

}

int get_nth_node_from_last(node_t **head, int n, int *out_data)
{
    node_t *mp = NULL;
    node_t *rp = NULL;
    int i = INT_MIN;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (n <= 0) {
        LOG_ERR("Invalid n %d", n);
        return LIST_OP_FAILURE;
    }

    if (out_data == NULL) {
        LOG_ERR("out_data %p", out_data);
        return LIST_OP_FAILURE;
    }

    if (*head == NULL) {
        LOG_DBG("Empty list - *head %p", *head);
        *out_data = 0xDEADBEEF;
        return LIST_OP_FAILURE;
    }

    mp = *head;
    rp = *head;
    for (i = 1; (i < n) && (rp != NULL); i++) {
        rp = rp->next;
    }

    if (rp == NULL) {
        LOG_ERR("n (%d) > list size", n);
        *out_data = 0xDEADBEEF;
        return LIST_OP_FAILURE;
    }

    while ((rp != NULL) && (rp->next != NULL)) {
        mp = mp->next;
        rp = rp->next;
    }

    *out_data = (mp != NULL) ? mp->data : 0xDEADBEEF;

    return LIST_OP_SUCCESS;
}

int del_last_occurance(node_t **head, int key_value)
{
    node_t **temp = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (*head == NULL) {
        LOG_DBG("Empty list - *head %p", *head);
        return LIST_OP_FAILURE;
    }

    while ((*head) != NULL) {
        printf("==> head %p, *head %p,(*head)->data %d ==> ", head, *head, (*head)->data);
        if ((*head)->data == key_value) {
            temp = head;
        }
        head = &((*head)->next);
        printf("head %p, *head %p\n", head, *head);
    }

    if (temp == NULL) {
        LOG_DBG("key %d not found in the list", key_value);
    } else {
        node_t *temp2 = *temp;
        *temp = (*temp)->next;
        free(temp2);
        temp2 = NULL; // dangling pointer - fix it;
    }

    return LIST_OP_SUCCESS;
}

int del_mid_node(node_t **head)
{
    node_t *fp = NULL;
    node_t *tp = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (*head == NULL) {
        LOG_DBG("Empty list - *head %p", *head);
        return LIST_OP_FAILURE;
    }

    fp = *head;
    while ((fp != NULL) && (fp->next != NULL)) {
        fp = fp->next->next;
        head = &((*head)->next);
    }

    tp = *head;
    *head = (*head)->next;
    free(tp);
    tp = NULL;

    return LIST_OP_SUCCESS;
}

int delete_n_after_m(node_t **head, int m, int n)
{
    int i = INT_MIN;
    //node_t *mp = NULL;
    node_t *np = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if ((m <=0) || (n <= 0)) {
        LOG_ERR("m %d, n %d", m, n);
        return LIST_OP_FAILURE;
    }

    if (*head == NULL) {
        LOG_DBG("Empty list - *head %p", *head);
        return LIST_OP_FAILURE;
    }

    //mp = *head;
    for (i = 1; (i < m) && /* (mp != NULL) */ (*head != NULL); i++) {
        //mp = mp->next;
        head = &((*head)->next);
    } 

    //if (mp == NULL) {
    if (*head == NULL) {
        LOG_ERR("n (%d) > list size", n);
        return LIST_OP_FAILURE;
    }

    //np = mp->next;
    np = (*head)->next;
    for (i = 0; (i < n) && (np != NULL); i++) {
        node_t *tp = np;
        LOG_DBG("deleting %d", np->data);
        np = np->next;
        free(tp);
        tp = NULL; // dangling pointer - fix it!
    }

    if (i < n) {
        LOG_DBG("(i %d, n %d) deleted %d nodes - nothing more to delete", i, n, i);
    }

    //mp->next = np;
    (*head)->next = np;

    return LIST_OP_SUCCESS;
}

/* swap the data from the adjacent nodes */
int pairwise_swap_nodes_data(node_t **head)
{
    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (*head == NULL) {
        LOG_DBG("Empty list - *head %p", *head);
        return LIST_OP_FAILURE;
    }

    while (((*head) != NULL) && ((*head)->next != NULL)) {
        node_data_swap(&((*head)->data), &((*head)->next->data));
        head = &((*head)->next->next);
    }

    return LIST_OP_SUCCESS;
}

#if 1
int pairwise_swap_nodes(node_t **head)
{
    node_t *nn_node = NULL; // next.next node from head
    node_t *new_head = NULL;
    node_t *temp_head = NULL;

    LOG_DBG("ENTER");

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (*head == NULL) {
        LOG_ERR("Empty list - *head %p", *head);
        return LIST_OP_FAILURE;
    }

    if ((*head)->next == NULL) {
        LOG_ERR("Just one node in the list");
        return LIST_OP_FAILURE;
    }

    temp_head = *head; // save the head, just in case
    new_head = (*head)->next;

    while ((*head != NULL) && ((*head)->next != NULL)) {
        nn_node = (*head)->next->next;
        (*head)->next->next = *head;;
        if ((nn_node != NULL) && (nn_node->next != NULL)) {
            (*head)->next = nn_node->next;
        } else {
            (*head)->next = nn_node;
        }

        (*head) = nn_node;
    }

    *head = new_head;

    return LIST_OP_SUCCESS;
}

#else
int pairwise_swap_nodes(node_t **head)
{
    node_t *tmp_head = NULL;
    node_t *new_head = NULL;
    node_t *next_node = NULL; // next
    node_t *next_next_node = NULL; // next->next

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    tmp_head = *head;

    if ((tmp_head != NULL) && (tmp_head->next != NULL)) {
        new_head = tmp_head->next;
    }

    while ((tmp_head != NULL) && (tmp_head->next != NULL)) {
        next_node = tmp_head->next;
        next_next_node = tmp_head->next->next;

        next_node->next = tmp_head;
        tmp_head->next = next_next_node;

        if ((tmp_head->next != NULL) && (tmp_head->next->next != NULL)) {
            tmp_head->next = tmp_head->next->next;
        }
        tmp_head = next_next_node;
    }

    *head = new_head;
    return LIST_OP_SUCCESS;
}
#endif

static void link_zero_one_two_list(node_t **zero_hd, node_t **one_hd, node_t **two_hd)
{
    node_t **tmp_one_hd = NULL;

    tmp_one_hd = one_hd;

    while (*one_hd != NULL) {
        one_hd = &((*one_hd)->next);
    }

    *one_hd = *two_hd;

    while (*zero_hd != NULL) {
        zero_hd = &((*zero_hd)->next);
    }
    *zero_hd = *tmp_one_hd;

    return;
}

int sort_012_nodes(node_t **head)
{
    node_t *curr = NULL;
    node_t *zero_head = NULL;
    node_t *one_head = NULL;
    node_t *two_head = NULL;

    if  (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (*head == NULL) {
        LOG_DBG("Empty list - *head %p", *head);
        return LIST_OP_FAILURE;
    }

    curr = *head;

    while (curr != NULL) { 
        if (curr->data == 0) {
            insert_rear(&zero_head, curr->data);
        } else if (curr->data == 1) {
            insert_rear(&one_head, curr->data);
        } else if (curr->data == 2) {
            insert_rear(&two_head, curr->data);
        }
        curr = curr->next;
    }

    //link_zero_one_two_list(&zero_head, &one_head, &two_head) ;

    merge_two_lists(&one_head, &two_head);
    merge_two_lists(&zero_head, &one_head);

    delete_list(head);
    *head = zero_head;
    return LIST_OP_SUCCESS;
}

// merge second list into fist
int merge_two_lists(node_t **first_head, node_t **second_head)
{
    if ((first_head == NULL) || (second_head == NULL)) {
        LOG_ERR("first_head %p, second_head %p", first_head, second_head);
        return LIST_OP_FAILURE;
    }

    while (*first_head != NULL) {
        first_head = &((*first_head)->next);
    }

    *first_head = *second_head;

    return LIST_OP_SUCCESS;
}

int insert_second_list_into_first(node_t **first, node_t **second)
{
    node_t *f_next = NULL;
    node_t *s_next = NULL;
    node_t *fh = NULL;
    node_t *sh = NULL;


    if ((first == NULL) || (second == NULL)) {
        LOG_ERR("first %p, second %p", first, second);
        return LIST_OP_FAILURE;
    }

    fh = *first;
    sh = *second;

    while ((fh != NULL) && (sh != NULL)) {
        f_next = fh->next;
        s_next = sh->next;
        fh->next = sh;
        sh->next = f_next;
        fh = f_next;
        sh = s_next;
    }

    *second = sh;

    return LIST_OP_SUCCESS;
}

/* remove every kth node from the list */
int rm_every_kth_node(node_t **head, int k)
{
    int idx = INT_MIN;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return LIST_OP_FAILURE;
    }

    if (k <= 0) {
        LOG_ERR("k = %d\n", k);
        return LIST_OP_FAILURE;
    }

    idx = 1;
    while ((*head) != NULL) {
        if ((idx % k) == 0) {
            node_t *tmp = *head;
            *head = (*head)->next;
            free(tmp);
            tmp = NULL; // dangling pointer - fix it!
        } else {
            head = &((*head)->next);
        }
        idx++;
    }

    if (k > (idx - 1)) {
        LOG_DBG(" k(%d) is greater than number of nodes(%d)", k, (idx - 1));
    }

    return LIST_OP_SUCCESS;
}

/* reverse list in k groups where k is less the list size.  
 * If list size is not a multiple of k, then reverse the left out nodes at the end */
    //n = 8
    //k = 3

    //1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
     //              t              t
#if 0
node_t* rev_list_in_k_groups(node_t *head, int k)
{
    int c = INT_MIN;
    node_t *curr = NULL;
    node_t *prev = NULL;
    node_t *thead = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return head;
    }

    if (k <= 0) {
        LOG_ERR("k %d", k);
        return head;
    }

    c = k;
    prev = NULL;
    thead = head;
    while ((thead != NULL) && (c > 0)) {
        curr = thead;
        thead = thead->next;
        curr->next = prev;
        prev = curr;
        c--;
    }

    if (thead != NULL) {
        head->next = rev_list_in_k_groups(thead, k);
    }

    return curr;
}
#else
node_t* rev_list_in_k_groups_all(node_t **head, int k)
{
    int c = INT_MIN;
    node_t *curr = NULL;
    node_t *prev = NULL;
    node_t *thead = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return NULL;
    }

    if (k <= 0) {
        LOG_ERR("k %d", k);
        return (*head);
    }

    c = k;
    prev = NULL;
    thead = *head;
    while ((thead != NULL) && (c > 0)) {
        curr = thead;
        thead = thead->next;
        curr->next = prev;
        prev = curr;
        c--;
    }

    if (thead != NULL) {
        (*head)->next = rev_list_in_k_groups_all(&thead, k);
    }

    return curr;
}
#endif

node_t* rev_list_in_k_groups(node_t **head, int k)
{
    int c = INT_MIN;
    node_t *curr = NULL;
    node_t *prev = NULL;
    node_t *thead = NULL;

    if (head == NULL) {
        LOG_ERR("head %p", head);
        return NULL;
    }

    if (k <= 0) {
        LOG_ERR("k %d", k);
        return (*head);
    }

    c = k;
    prev = NULL;
    thead = *head;
    while ((thead != NULL) && (c > 0)) {
        curr = thead;
        thead = thead->next;
        curr->next = prev;
        prev = curr;
        c--;
    }

    if (c > 0) {
        node_t *tmp_head = curr;
        prev = NULL;
        while (tmp_head != NULL) {
            curr = tmp_head;
            tmp_head = tmp_head->next;
            curr->next = prev;
            prev = curr;

        }
        return curr; 
    }

    if (thead != NULL) {
        (*head)->next = rev_list_in_k_groups(&thead, k);
    }

    return curr;
}

#if 1
int add_numbers_in_two_lists(node_t **first, node_t **second, node_t **result)
{
    int sum = INT_MIN;
    int carry = INT_MIN;
    int ret = 0;

    if ((first == NULL) || (second == NULL) || (result == NULL)) {
        LOG_ERR("first %p, second %p, result %p", first, second, result);
        return LIST_OP_FAILURE;
    }

    list_reverse(first);
    list_reverse(second);

    delete_list(result); // clear of the result list - just in case !
    sum = 0;
    carry = 0;

    while ((*first != NULL) || (*second != NULL)) {
        sum = carry + ((*first) ? (*first)->data : 0) + ((*second) ? (*second)->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        ret = insert_front(result, sum);
        if (ret == LIST_OP_FAILURE) {
            goto op_err;
        }

        if (*first)
            first = &((*first)->next);
        if (*second)
            second = &((*second)->next);
    } // while 

    if (carry > 0)
        insert_front(result, carry);

    return LIST_OP_SUCCESS;

op_err:
    delete_list(result);
    return LIST_OP_FAILURE;

}
#else
int add_numbers_in_two_lists(node_t **first, node_t **second, node_t **result)
{
    int sum = INT_MIN;
    int carry = INT_MIN;
    int ret = 0;

    if ((first == NULL) || (second == NULL) || (result == NULL)) {
        LOG_ERR("first %p, second %p, result %p", first, second, result);
        return LIST_OP_FAILURE;
    }

    list_reverse(first);
    better_list_display(first, "rev_first");
    list_reverse(second);
    better_list_display(second, "rev_secnd");

    delete_list(result); // clear of the result list - just in case !

    sum = 0;
    carry = 0;
    while ((*first != NULL) || (*second != NULL)) {
        sum = carry + ((*first) ? (*first)->data : 0) + ((*second) ? (*second)->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        LOG_DBG("sum = %d", sum);
        ret = insert_rear(result, sum);

        if (*first)
            first = &((*first)->next);

        if (*second)
            second = &((*second)->next);
    }

    if (carry > 0)
        insert_rear(result, carry);

    list_reverse(result);

    return LIST_OP_SUCCESS;
}
#endif

int list_exit(node_t **head)
{
    return delete_list(head);
}