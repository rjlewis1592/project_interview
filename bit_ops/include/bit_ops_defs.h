#ifndef  BIT_OPS_DEFS_H_
#define  BIT_OPS_DEFS_H_

#define SET_BIT(x, n) ((x) |= (1U << (n)))
#define CLR_BIT(x, n) ((x) &= ~(1U << (n)))
#define TOGGLE_BIT(x, n) ((x) ^= (1U << (n)))
#define IS_BIT_SET(x, n) ((x) & (1U << (n)))
#define SWAP_NIBBLES(x) ((x) = ((x) << 4) | ((x) >> 4))
#define SWAP_BYTES(x) ((x) = ((x) << 8) | ((x) >> 8))

#endif // BIT_OPS_DEFS_H_ 
