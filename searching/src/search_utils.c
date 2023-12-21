#include "search_cmn.h"
#include "search_utils.h"

int get_random_n()
{
    int random_n;
    int lower = 5;
    int upper = 10;

    srand(time(NULL));
    sleep(1);
    random_n = rand() % (upper + 1 - lower) + lower;

    return random_n;
}

int *create_array(int n)
{
    int i, value;
    int *arr = NULL;
    int lower = 10;
    int upper = 100;

    arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL) {
        LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
        exit (EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        srand(time(NULL));
        sleep(1);
        value = rand() % (upper + 1 - lower) + lower;
        arr[i] = value;
    }

    return arr;
}

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

int do_my_compare(const void *x, const void *y)
{
    int a = *((int *)x);
    int b = *((int *)y);

    if (a < b)
        return (-1);
    if (a > b)
        return (1);

    return (0);
    
}