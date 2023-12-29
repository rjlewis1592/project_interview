#include "bit_ops_cmn.h"

#define BV_DEBUG    1


int g_bv_array_sz = 0;

#if 0
void print_bv(uint8_t *bv, int memb_sz , int bv_array_sz)
{
    int i, j;

    LOG_DBG("bv_array_sz %d", bv_array_sz);

    for (i = 0; i < bv_array_sz; i++) {
        for (j = 0; j < 8; j++) {
            printf("%d", (bv[i] >> (8 - 1 - j)) & (0x1U));

            if (((j + 1) % 8) == 0)
                printf(" ");
        }
    }

    printf("\n");
}
#else
void print_bv(uint8_t *bv, int memb_sz , int bv_array_sz)
{
    int i = 0;
    int n_bits = bv_array_sz * memb_sz * NBBY; // number of bits in bit vector set

    assert(bv != NULL);
    assert((memb_sz > 0) && (bv_array_sz > 0));


    for (i = 0; i < n_bits; i++) {
        printf("%d", (bv[i/8] >> (8 - 1 - (i % 8))) & (0x1U));
        
        if (((i + 1) % 8) == 0)
            printf(" ");
    }

    printf("\n");
}
#endif

void set_bv(uint8_t *bv, int i)
{
    assert(bv != NULL);
    assert(i >= 0);

    print_bv(bv, sizeof(uint8_t), g_bv_array_sz);

    LOG_DBG("i %d, index %d, mask %d", i, (i / 8), (i % 8));

    bv[i / 8] |= (0x1U << (8 - 1 - (i % 8)));

    //print_bv(bv, sizeof(uint8_t), g_bv_array_sz);
}

void init_bv(uint8_t **bv, int n)
{
    const int ui8_sz_in_bits = sizeof(uint8_t) * NBBY;
    int bv_array_sz = 0;
    assert((bv != NULL) && (n > 0));

    bv_array_sz =  (n + (ui8_sz_in_bits  - 1)) / ui8_sz_in_bits;
    g_bv_array_sz = bv_array_sz;

    *bv = (uint8_t *)calloc(bv_array_sz, sizeof(uint8_t));
    if ((*bv) == NULL) {
        LOG_ERR("calloc(): %s (%d)", strerror(errno), errno);
        exit (EXIT_FAILURE);
    }

    LOG_DBG("Success: (*bv ) %p", (*bv));

#ifdef BV_DEBUG
    print_bv((*bv), sizeof(uint8_t) , bv_array_sz);
#endif // BV_DEBUG


    return;
}

int main()
{
    int n_elements; // total number of elements in set
    int bit_pos;
    uint8_t *bv = NULL;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n_elements);

    init_bv(&bv, n_elements);


    while (true) {
        printf("Enter the bit position to set: ");
        scanf("%d", &bit_pos);
        set_bv(bv, bit_pos);
        print_bv(bv, sizeof(uint8_t), g_bv_array_sz);
    }

    if (bv != NULL)
        free(bv);

    return 0;
}