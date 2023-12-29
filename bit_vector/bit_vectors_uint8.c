#include "bit_ops_cmn.h" 

void print_bv_array(uint8_t bv[], int bv_arrsz)
{
    int i = 0;
    int j = 0;
    int num_bits = bv_arrsz * sizeof(uint8_t) * NBBY;

    LOG_DBG("bv_arrsz %d", bv_arrsz);

    for (i = 0; i < bv_arrsz; i++) {
        for (j = 0; j < (sizeof(uint8_t) * NBBY); j++) {
            printf("%d", (bv[i] >> ((sizeof(uint8_t) * NBBY) - 1 - j)) & (0x1U));
        }
        printf(" ");
    }
    printf("\n");
}

void set_bv_array(uint8_t bv[], int bv_arrsz, int pos)
{
    int i = 0;
    int j = 0;

    LOG_DBG("bv_arrsz %d", bv_arrsz);

    int num_bits = bv_arrsz * sizeof(uint8_t) * NBBY;

    for (i = 0; i < bv_arrsz; i++) {
        for (j = 0; j < (sizeof(uint8_t) * NBBY); j++) {
            bv[i] = bv[i] | (0x1U << ((sizeof(uint8_t) * NBBY * (i + 1))  - pos - 1));
        }
    }
}

int main()
{
    int pos = 0;
    uint8_t bv[4] = {0}; // 4 bytes * NBBY = 32 bits array

    int asz = sizeof(bv)/sizeof(bv[0]);

    print_bv_array(bv, sizeof(bv)/sizeof(bv[0]));

    printf("Enter bit pos: ");
    scanf("%d", &pos);

    set_bv_array(bv, (sizeof(bv)/sizeof(bv[0])), pos);
    print_bv_array(bv, sizeof(bv)/sizeof(bv[0]));

    return 0;
}