#include "sort_cmn.h"
#include "sort_utils.h"

int* dup_array(int *src, int n)
{
    int *dest = (int *)malloc(sizeof(int) * n);
    if (dest == NULL) {
        LOG_ERR("malloc(): %s(%d)", strerror(errno), errno);
        return NULL;
    }

    memcpy(dest, src, sizeof(int) * n);

    return dest;
}

void print_array(int *a, int n, const char *title)
{
    int i;

    if (a == NULL) {
        LOG_ERR("=== Empty array ===, a %p", a);
        return;
    }

    if (n < 0) {
        LOG_ERR("Invalid input: %d", n);
        return;
    }

    printf("%s (%d): ", (title != NULL ? title : "ARRAY"), n);
    for (i = 0; i < n; i++) {
        printf("%-3d ", a[i]);
    }

    printf("\n");
    return;
}

void do_swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}