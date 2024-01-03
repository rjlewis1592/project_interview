#ifndef BIT_OPS_H_
#define BIT_OPS_H_

#include "bit_ops_cmn.h"

size_t count_bits(unsigned int n);
void left_rotate(unsigned int *num, unsigned int nbits);
void right_rotate(unsigned int *num, unsigned int nbits);
void swap_bytes_in_word(uint16_t *u);
void swap_bytes_in_uint32(uint32_t *u);
void swap_two_bytes_in_uint32(uint32_t *u);

// Ritchie exercises
uint16_t get_bits(uint16_t x , int p, int n);
uint16_t set_bits(uint16_t x, int p, int n, u_int16_t y);
uint16_t invert_bits(uint16_t x, int p, int n);
uint16_t right_rotate_bits(uint16_t x, int n);
#endif // LIST_OPS_H_
