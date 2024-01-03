#include "bit_ops_cmn.h"
#include "bit_ops_defs.h"
#include "bit_ops.h"
#include "bit_ops_utils.h"

size_t count_bits(unsigned int n)
{
    size_t count = 0;

    while (n) {
        n &= (n - 1);
        count++;
    }

    return count;
}

void left_rotate(unsigned int *num, unsigned int nbits)
{
    unsigned int x = *num;

    if (nbits == 0)
        return;

    x = ((x << nbits)) | (x >> (sizeof(unsigned int) * NBBY - nbits));
    *num = x;
}

void right_rotate(unsigned int *num, unsigned int nbits)
{
    unsigned int x = *num;

    if (nbits == 0)
        return;

    x = ((x >> nbits)) | (x << (sizeof(unsigned int) * NBBY - nbits));
    *num = x;
}

void swap_bytes_in_word(uint16_t *u)
{
	uint16_t x = *u;

	x = ((x << 8) | (x >> 8));

	*u = x;
}
#if 0
uint32_t swap_bytes_in_uint32(uint32_t u)
{
    uint32_t x  = 0;
#if 0
    x |= ((0x000000FFU & u) << 24);
    x |= ((0x0000FF00U & u) << 8);
    x |= ((0x00FF0000U & u) >> 8);
    x |= ((0xFF000000U & u) >> 24);
#else
    x |= ((u & 0x000000FFU) << 24);
    x |= ((u & 0x0000FF00U) << 8);
    x |= ((u & 0x00FF0000U) >> 8);
    x |= ((u & 0xFF000000U)  >> 24);
#endif
#if 0
 converted |= ((0x000000ff & value) << 24);
 converted |= ((0x0000ff00 & value) << 8);
 converted |= ((0x00ff0000 & value) >> 8);
 converted |= ((0xff000000 & value) >> 24);
 #endif
    return x;
}
#else
void swap_bytes_in_uint32(uint32_t *u)
{
    unsigned int v = *u;
    unsigned int x = 0U;

    x |= ((v & 0x000000FFU) << 24U);
    x |= ((v & 0x0000FF00U) << 8U);
    x |= ((v & 0x00FF0000U) >> 8U);
    x |= ((v & 0xFF000000U) >> 24U);


    *u  = x;
}
#endif

void swap_two_bytes_in_uint32(uint32_t *u)
{
    unsigned int v = *u;
    unsigned int x = 0U;

    x = ((v & 0x000000FFU) << 8U) | ((v & 0x0000FF00U) >> 8U);


    *u  = x;
}


// Ritchie exercises

/* 
 * returns the (right adjusted) n-bit field of x that begins at position p.
 * For example, getbits(x,4,3) returns the three bits in bit positions 4, 3 and 2, right adjusted,
 * where position p = 4, no of bits n = 3
 */
uint16_t get_bits(uint16_t x , int p, int n)
{
    //return ((x >> p) & (~(~0 << n)));
    return ((x >> (p - n + 0x1U)) & (~(~0x0U << n)));
}

/* 
 * returns x with the n bits that begin at position p set to the rightmost n bits of y, 
 * leaving the other bits unchanged.
 */
uint16_t set_bits(uint16_t x, int p, int n, uint16_t y)
{
    return ((x & ~((~(~0x0U << n)) << (p - n + 1)))| ((y & ~(~0x0U  << n)) << (p - n + 1)));
}

/*
 * returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged.
 */
uint16_t invert_bits(uint16_t x, int p, int n)
{
    return (x ^ ((~(~0x0U << n)) << (p - n + 1)));
}

/*
* returns the value of the integer x rotated to the right by n bit positions.
*/ 
uint16_t right_rotate_bits(uint16_t x, int n)
{

    return ((x >> n) | ((x & (~(~0x0U << n))) << ((sizeof(uint16_t) * NBBY) - n)));
}