#include <stdio.h>
#include <stdlib.h>

#define WORDSIZE        32
#define BIT_WS          5
#define MASK            0x1F

int initbv(int **bv, int val)
{
    *bv = calloc((val / WORDSIZE + 1), sizeof(int));

    return *bv != NULL;
}

void set(int bv[], int i)
{
    bv[i >> BIT_WS] |= (1 << (i & MASK));

}

int member(int bv[], int i)
{
    return bv[i >> BIT_WS] & (1 << (i & MASK));
}

int main()
{
    int *bv, i;
    int s1[] = {32, 5, 0};
    int s2[] = {32, 4, 5, 0};


    initbv(&bv, 32);

    for (i = 0; s1[i] != 0; i++) {
        set(bv, s1[i]);
    }

    for (i = 0; s2[i] != 0; i++) {
        if (member(bv, s2[i])) {
            printf("%d\n", s2[i]);
        }
    }

    free(bv);

    return 0;
}