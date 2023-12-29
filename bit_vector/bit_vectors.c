#include "bit_ops_cmn.h"

#define MASK    0x7U // 0000.....0111

#define SET_OP  0x1U
#define CLR_OP  0x2U
#define TGL_OP  0x3U
#define PRINT   0x4U

const unsigned int u8_bitsz = sizeof(uint8_t) * NBBY;

void print_bv(uint8_t *bv, int n_elements)
{
    int i;
    int n = 0;

    assert(bv != NULL);
    assert(n_elements > 0);

    n = ((unsigned int)n_elements + (u8_bitsz - 1)) >> 3;

    for (i = 0; i < (n * u8_bitsz); i++) {
        printf("%d", (bv[i >> 3] >> (u8_bitsz - 1 - (i & MASK))) & (0x1U));

        if (((i + 1) % 8) == 0)
            printf(" ");
    }


    printf("\n");
}

void tgl_bv(uint8_t *bv, int i)
{
    assert(bv != NULL);
    assert(i >= 0);

    bv[i >> 3] ^= ((0x1U) << (i & MASK));
}

void clr_bv(uint8_t *bv, int i)
{
    assert(bv != NULL);
    assert(i >= 0);

    bv[i >> 3] &= ~((0x1U) << (i & MASK));

}

void set_bv(uint8_t *bv, int i)
{
    assert(bv != NULL);
    assert(i >= 0);

    bv[i >> 3] |= ((0x1U) << (i & MASK));

}

void init_bv(uint8_t **bv, int n_elements)
{
    int n = 0;

    assert(bv != NULL);
    assert(n_elements > 0);

    //n = (n_elements + (u8_bitsz - 1)) / (u8_bitsz);
    n = ((unsigned int)n_elements + (u8_bitsz - 1)) >> 3;

    LOG_DBG("n %d", n);

    assert(n);

    *bv = calloc(n, sizeof(uint8_t));

    if ((*bv) == NULL) {
        LOG_ERR("calloc(): %s (%d)", strerror(errno), errno);
        exit (EXIT_FAILURE);
    }

    LOG_DBG("Success: (*bv) %p", (*bv));
}

int main(int argc, char *argv[])
{
    int n_elements = 0, bit_pos = 0;
    int op;
    uint8_t *bv = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: a.out <n>\n");
        exit (EXIT_FAILURE);
    }
    
    n_elements = atoi(argv[1]);

    init_bv(&bv, n_elements);
    print_bv(bv, n_elements);

    while (true) {
        printf("Enter the operation: 1.SET, 2.CLEAR 3.TOGGLE 4.PRINT\n");
        scanf("%d", &op);

        switch (op) {
            case SET_OP:
                printf("Enter the bit position to set: ");
                scanf("%d", &bit_pos);
                set_bv(bv, bit_pos);
                break;
            case CLR_OP:
                printf("Enter the bit position to clear: ");
                scanf("%d", &bit_pos);
                clr_bv(bv, bit_pos);
                break;
            case TGL_OP:
                printf("Enter the bit position to toggle: ");
                scanf("%d", &bit_pos);
                tgl_bv(bv, bit_pos);
                break;
            case PRINT:
                print_bv(bv, n_elements);
                break;
            default:
                LOG_ERR("default case %d", op);
                break;
        }
        print_bv(bv, n_elements);
    }

    if (bv != NULL) {
        free(bv);
    }

    return 0;
}