#include "bit_ops_cmn.h"

static uint32_t find_lonely_int_xor(uint32_t *a, int asz)
{
    int i;
    uint32_t result = 0;

    for (i = 0; i < asz; i++) {
        result ^= a[i];
    }

    return result;
}

int main(int argc, char *argv[])
{
    u_int32_t *p = NULL;
    int n = 0;
    uint32_t rv;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: <a.out> <array_sz\n");
        exit (EXIT_FAILURE);
    }

    n = atoi(argv[1]);

    p = (uint32_t *)malloc(n * sizeof(int));
    if (p == NULL) {
        LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
        exit (EXIT_FAILURE);
    }

    printf("Enter array elements with lonely integer: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    for (i = 0; i < n; i++) {
        printf("%d, ", p[i]);
    }
    printf("\n");

    rv = find_lonely_int_xor(p, n);

    if (rv != 0) {
        printf("lonely integer - %d\n", rv);
    } else {
        printf("lonely integer not found\n");
    }

    if (p != NULL) {
        free(p);
    }

    return 0;
}