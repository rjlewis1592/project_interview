#include "bit_ops_cmn.h"

#define MASK    0x1F // 0000.....1111

#define SET_OP      0x1U
#define CLR_OP      0x2U
#define TGL_OP      0x3U
#define IS_SET      0x4U
#define IS_CLR      0x5U
#define PRINT       0x6U
#define DO_SORT     0x7U
#define DO_EXIT     0x8U

#define U32_BYTES       (sizeof(uint32_t))
#define U32_BITS        ((U32_BYTES) * NBBY)

#define GET_ARRSZ(n_elements)    (((n_elements) + (U32_BITS - 1)) >> 5)

const unsigned int u32_bitsz = sizeof(uint32_t) * NBBY;

bool is_set(uint32_t *bv, int bit_pos, int n_elements)
{
    assert(bv != NULL);
    assert(n_elements > 0);
    assert((bit_pos >= 0) && (bit_pos < n_elements));

    if ((bv[bit_pos >> 5] & (0x1U << (bit_pos & MASK))) == 0)
        return false;

    return true;
}

bool is_clr(uint32_t *bv, int bit_pos, int n_elements)
{
    assert(bv != NULL);
    assert(n_elements > 0);
    assert((bit_pos >= 0) && (bit_pos < n_elements));

    if ((bv[bit_pos >> 5] & (0x1U << (bit_pos & MASK))) == 0)
        return true;

    return false;
}

void print_bv(uint32_t *bv, int n_elements)
{
    int i, n;
    int bucket = 0;
    int begin = 0;
    int end = 0;
    int total_capacity = 0;

    assert(bv != NULL);
    assert(n_elements > 0);

    n = GET_ARRSZ(n_elements);

    total_capacity = n *32;

    bucket = n_elements / 32; 
    begin = (bucket * 32);
    end = (begin + (total_capacity - n_elements));

    for (i = 0; i < (n * U32_BITS); i++) {
        if ((i >= begin) && (i < end))
            printf("x");
        else
            printf("%d", (bv[i >> 5] >> ((U32_BITS - 1 - (i & MASK)))) & 0x1U);

        if (((i + 1) % 8) == 0)
            printf(" ");

        if (((i + 1) % U32_BITS) == 0)
            printf("| ");
    }

    printf("\n");

}

void tgl_bv(uint32_t *bv, int bit_pos, int n_elements)
{
    assert(bv != NULL);
    assert(n_elements > 0);
    assert ((bit_pos >= 0) && (bit_pos < n_elements));

    bv[bit_pos >> 5] ^= (0x1U << (bit_pos & MASK));

}

void clr_bv(uint32_t *bv, int bit_pos, int n_elements)
{

    assert(bv != NULL);
    assert(n_elements > 0);
    assert((bit_pos >= 0) && (bit_pos < n_elements));

    bv[bit_pos >> 5] &= ~(0x1U << (bit_pos & MASK));
}

void set_bv(uint32_t *bv, int bit_pos, int n_elements)
{
    assert(bv != NULL);
    assert(n_elements > 0);
    assert((bit_pos >= 0) && (bit_pos < n_elements));

    bv[bit_pos >> 5] |= (0x1U << (bit_pos & MASK));
}

void init_bv(uint32_t **bv, int n_elements)
{
    int n = 0;

    assert(bv != NULL);
    assert(n_elements > 0);

    n = GET_ARRSZ(n_elements);   

    LOG_DBG("BV array size, n = %d", n);

    (*bv) = calloc(n, sizeof(uint32_t));

    if ((*bv) == NULL) {
        LOG_ERR("calloc(): %s (%d)", strerror(errno), errno);
        exit (EXIT_FAILURE);
    }

    LOG_DBG("Success: allocated (*bv) %p", *bv);

    return;
}


void do_sort(int n_elements)
{
    int i;
    uint32_t *bv = NULL;
    int set[] = {3, 9, 7, 12, 5, 27, 0, 8, 3, 19, 11, -1};

    init_bv(&bv, n_elements);
    print_bv(bv, n_elements);

    for (i = 0; set[i] != -1; i++) {
        set_bv(bv, set[i], n_elements);
    }

    print_bv(bv, n_elements);

    for(i = 0; i < (sizeof(set)/sizeof(set[0])); i++) {
        if (is_set(bv, i, n_elements) == true) {
            printf("%d\n", i);
        }
    }
    printf("\n");

}

int main(int argc, char *argv[])
{
    int n_elements = 0, bit_pos = 0;
    int op;
    bool rv;
    uint32_t *bv = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: a.out <n>\n");
        exit (EXIT_FAILURE);
    }
    
    n_elements = atoi(argv[1]);

    init_bv(&bv, n_elements);
    print_bv(bv, n_elements);

    while (true) {
        printf("Enter the operation: 1.SET, 2.CLEAR 3.TOGGLE 4.IS_SET, 5.IS_CLR, 6.PRINT, 7.DO_SORT, 8.EXIT\n");
        scanf("%d", &op);

        switch (op) {
            case SET_OP:
                printf("Enter the bit position to set: ");
                scanf("%d", &bit_pos);
                set_bv(bv, bit_pos, n_elements);
                break;

            case CLR_OP:
                printf("Enter the bit position to clear: ");
                scanf("%d", &bit_pos);
                clr_bv(bv, bit_pos, n_elements);
                break;

            case TGL_OP:
                printf("Enter the bit position to toggle: ");
                scanf("%d", &bit_pos);
                tgl_bv(bv, bit_pos, n_elements);
                break;

            case IS_SET:
                printf("Enter the bit position to check if set: ");
                scanf("%d", &bit_pos);
                rv = is_set(bv, bit_pos, n_elements);
                if (rv == true) {
                    printf("bit %d is SET in BITVECTOR\n", bit_pos);
                } else {
                    printf("bit %d is NOT SET in BITVECTOR\n", bit_pos);
                }
                break;

            case IS_CLR:
                printf("Enter the bit position to check if clear: ");
                scanf("%d", &bit_pos);
                rv = is_clr(bv, bit_pos, n_elements);
                if (rv == true) {
                    printf("bit %d is UNSET in BITVECTOR\n", bit_pos);
                } else {
                    printf("bit %d is NOT UNSET(CLEAR) in BITVECTOR\n", bit_pos);
                }
                break;

            case PRINT:
                print_bv(bv, n_elements);
                break;

            case DO_SORT:
                do_sort(n_elements);
                break;

            case DO_EXIT:
                printf("Exiting...\n");
                goto clean_up;

            default:
                LOG_ERR("default case %d", op);
                break;
        }
        print_bv(bv, n_elements);
    }

clean_up:
    if (bv != NULL) {
        printf("free()ing %p...\n", bv);
        free(bv);
    }

    return 0;
}