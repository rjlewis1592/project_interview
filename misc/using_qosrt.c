#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <stdint.h>

static int compare_fn(const void *p, const void *q)
{
    int x, y;

    assert ((p != NULL) && (q != NULL));

    x = *((int *)p);
    y = *((int *)q);

    if (x < y)
        return -1;
    else if (x > y)
        return 1;
    else
        return 0;
}

int main()
{
    int *p = NULL;
    int i, n;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n <= 0) {
        exit(EXIT_FAILURE);
    }

    p = (int *)malloc(sizeof(int) * n);
    if (p == NULL) {
        fprintf(stderr, "malloc(): %s (%d)", strerror(errno), errno);
        exit(EXIT_FAILURE);
    }

    printf("Enter array %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("p: ");
    for (i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");


    qsort(p, n, sizeof(int), compare_fn);

    printf("sorted p: ");
    for (i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    if (p != NULL) {
        free(p);
    }

    return 0;
}