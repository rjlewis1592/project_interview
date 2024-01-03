#include "bit_ops_cmn.h"
#include "bit_ops_utils.h"

//#define BITVALUE(x, n)      (((x) >> (n)) & 0x1U)

void print_bits(unsigned int x)
{
    int i = 0;
    int numbits = sizeof(unsigned int) * NBBY;
    printf("%3u: ", x);
    //for (i = ((sizeof(unsigned int) * NBBY) -1) ; i >= 0; i--)
    for (i = 0; i < numbits; i++)
    {
        //printf("%d", ((x) & (1U << i)));
        printf("%d", ((x) >> (numbits - 1 - i)) & 0x1U);

        if (((numbits - 1 - i) % NBBY) == 0)
            printf(" ");
    }

    printf("\n");
}

void print_bits_of_byte(uint8_t u)
{
    int i = 0;

    printf("u %u: ", u);
    int numbits = sizeof(uint8_t) * NBBY;
    for (i = 0; i < numbits; i++)
    {
        printf("%d", ((u) >> (numbits - 1 - i)) & 0x1U);

        if ((numbits - 1 - i) % (NBBY / 2) == 0)
            printf(" ");
    }

    printf("\n");
}

void print_uint16_t_bits(uint16_t x)
{
    int i = 0;

    printf("%u: ", x);

    int numbits = sizeof(uint16_t) * NBBY;
    for (i = 0; i < numbits; i++)
    {
        printf("%d", ((x) >> (numbits - 1 - i)) & 0x1U);

        if (((numbits - 1 - i) % NBBY) == 0)
            printf(" ");
    }

    printf("\n");
}

void print_uint32_bits(uint32_t x)
{
    int i = INT_MIN;

    printf("x %u: ", x);
    int numbits = sizeof(uint32_t) * NBBY;
    for (i = 0; i < numbits; i++)
    {
        printf("%d", ((x) >> (numbits - 1 - i)) & 0x1U);

        if (((numbits - 1 - i) % NBBY) == 0)
            printf(" ");
    }

    printf("\n");
}