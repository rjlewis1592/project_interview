#include "list_defs.h"
#include "list_utils.h"

void list_display(node_t *last)
{
    printf("\nCIRCULAR LIST: ");

    if (last == NULL) {
        printf("empty list");
        return; // empty list
    }

    node_t *temp = last->next;
    do {
        printf("%d -> ",  temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("\n");

    return;
}