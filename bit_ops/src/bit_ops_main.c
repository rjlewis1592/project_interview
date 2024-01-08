#include "bit_ops_cmn.h" 
#include "bit_ops_defs.h" 
#include "bit_ops.h" 
#include "bit_ops_utils.h" 

#define SET_BIT_OPS                 1
#define CLEAR_BIT_OPS               2
#define TOGGLE_BIT_OPS              3
#define BIT_COUNT_OPS               4
#define LEFT_ROTATE_OPS             5
#define RIGHT_ROTATE_OPS            6
#define SWAP_NIBBLES_IN_BYTE        7 
#define SWAP_BYTES_IN_WORD          8 
#define SWAP_BYTES_IN_UINT32   	    9 
#define SWAP_TWO_BYTES_IN_UINT32    10
// Ritchie exercises
#define GET_BITS                    11
#define SET_BITS                    12
#define INVERT_BITS                 13
#define RIGHT_ROTATE_BITS           14

int main()
{
    unsigned int x = 0;
    unsigned int n = 0;
    uint8_t u8_var = 0;
	uint16_t u16_var = 0;
	uint32_t u32_var = 0;
    int op;
    // Ritchie exercises
	uint16_t u16_n = 0, res = 0, y;
    int num, pos;

    printf("Enter a number: ");
    scanf("%u", &x);

    print_bits(x);

    while (1) {
        printf("\nEnter the BIT OPERATION: \n");
        printf("1.SET_BIT, 2.CLEAR_BIT, 3.TOGGLE_BIT, 4.COUNT_BITS, 5.LEFT_ROTATE, 6.RIGHT_ROTATE, 7.SWAP_NIBBLES, 8.SWAP_BYTES_IN_WORD, 9.SWAP_BYTES_IN_UINT32\n");
        printf("10. SWAP_TWO_BYTES_IN_UINT32, 11.GET_BITS, 12.SET_BITS, 13.INVERT_ BITS, 14.RIGHT_ROTATE_BITS \n");
        scanf("%d", &op);

        switch (op) {
            case SET_BIT_OPS:
                printf("SET_BIT_OPS: enter bit position between 0 and %lu (both inclusive): ", ((sizeof(unsigned int) * NBBY) - 1));
                scanf("%u", &n);
                if (n >= (sizeof(unsigned int) * NBBY)) {
                    printf("Invalid postion: %u. Enter bit position between 0 and %lu (both inclusive): ", n, ((sizeof(unsigned int) * NBBY) - 1));
                    scanf("%u", &n);
                }
                printf("setting bit at position %d for %d\n", n, x);
                print_bits(x);
                SET_BIT(x, n);
                print_bits(x);
                break;

            case CLEAR_BIT_OPS:
                printf("CLEAR_BIT_OPS: enter bit position between 0 and %lu (both inclusive): ", ((sizeof(unsigned int) * NBBY) - 1));
                scanf("%u", &n);
                if (n >= (sizeof(unsigned int) * NBBY)) {
                    printf("Invalid postion: %u. Enter bit position between 0 and %lu (both inclusive): ", n, ((sizeof(unsigned int) * NBBY) - 1));
                    scanf("%u", &n);
                }
                printf("clearing bit at position %d for %d\n", n, x);
                print_bits(x);
                CLR_BIT(x, n);
                print_bits(x);
                break;

            case TOGGLE_BIT_OPS:
                printf("TOGGLE_BIT_OPS: enter bit position between 0 and %lu (both inclusive): ", ((sizeof(unsigned int) * NBBY) - 1));
                scanf("%u", &n);
                if (n >= (sizeof(unsigned int) * NBBY)) {
                    printf("Invalid postion: %u. Enter bit position between 0 and %lu (both inclusive): ", n, ((sizeof(unsigned int) * NBBY) - 1));
                    scanf("%u", &n);
                }
                printf("toggling bit at position %d for %d\n", n, x);
                print_bits(x);
                TOGGLE_BIT(x, n);
                print_bits(x);
                break;

            case BIT_COUNT_OPS:
                printf("BIT_COUNT_OPS: no of bits set: %zu\n", count_bits(x));
                break;

            case LEFT_ROTATE_OPS:
                printf("LEFT_ROTATE_OPS: enter number of bits to rotate left: ");
                scanf("%u", &n);
                if (n > (sizeof(unsigned int) * NBBY)) {
                    printf("number of bits: %u. truncate it\n", n);
                    n = n % (sizeof(unsigned int) * NBBY);
                    printf("truncated number of bits: %u\n", n);
                }
                print_bits(x);
                left_rotate(&x, n);
                print_bits(x);
                break;

            case RIGHT_ROTATE_OPS:
                printf("RIGHT_ROTATE_OPS: enter number of bits to rotate right: ");
                scanf("%u", &n);
                if (n > (sizeof(unsigned int) * NBBY)) {
                    printf("number of bits: %u. truncate it\n", n);
                    n = n % (sizeof(unsigned int) * NBBY);
                    printf("truncated number of bits: %u\n", n);
                }
                print_bits(x);
                right_rotate(&x, n);
                print_bits(x);
                break;
            case SWAP_NIBBLES_IN_BYTE:
                printf("SWAP_NIBBLES_IN_BYTE: Enter a 8 byte unsigned integer: ");
                scanf("%hhu", &u8_var);
                print_bits_of_byte(u8_var);
                SWAP_NIBBLES(u8_var);
                print_bits_of_byte(u8_var);
                break;
            case SWAP_BYTES_IN_WORD:
                printf("SWAP_BYTES_IN_WORD: Enter a 16 bits unsigned integer: ");
                scanf("%hu", &u16_var);
                print_uint16_t_bits(u16_var);
                swap_bytes_in_word(&u16_var);
                print_uint16_t_bits(u16_var);
                break;
            case SWAP_BYTES_IN_UINT32:
                //printf("SWAP_BYTES_IN_UINT32: Enter a 32 bit unsigned integer: ");
                //scanf("%x", &u32_var);
                u32_var = 0x11223344;
                printf("0x%x\n", u32_var);
                print_uint32_bits(u32_var);
#if 0
                printf("0x%x\n", swap_bytes_in_uint32(u32_var));
#else
                swap_bytes_in_uint32(&u32_var);
#endif
                printf("0x%x\n", u32_var);
                print_uint32_bits(u32_var);
                break;
            case SWAP_TWO_BYTES_IN_UINT32:
                //printf("SWAP_TWO_BYTES_IN_UINT32: Enter uint32_t: ");
                //scanf("%u", &u32_var);
                u32_var = 0x11223344;
                printf("0x%x\n", u32_var);
                print_uint32_bits(u32_var);
                swap_two_bytes_in_uint32(&u32_var);
                printf("0x%x\n", u32_var);
                print_uint32_bits(u32_var);
                break;

            // Richtie exercises
            case GET_BITS:
                printf("GET_BITS: Enter uint16_t number (u16_n), positiion (pos) & number of bits (num): ");
                scanf("%hu %d %d", &u16_n, &pos, &num);
                print_bits(u16_n);
                res = get_bits(u16_n, pos, num);
                print_bits(res);
                u16_n = num = pos = res = 0;
                break;

            case SET_BITS:
                printf("SET_BITS: Enter uint16_t number (u16_n), y, position (pos) & number of bits (num) : ");
                scanf("%hu %hu %d %d", &u16_n, &y, &pos, &num);
                print_bits(u16_n);
                print_bits(y);
                res = set_bits(u16_n, pos, num, y);
                print_bits(res);
                u16_n = num = pos = res = y = 0;
                break;

            case INVERT_BITS:
                printf("INVERT_BITS: Enter uint16_t number (u16_n), number of bits (num), position (pos): ");
                scanf("%hu %d %d", &u16_n, &num, &pos);
                print_bits(u16_n);
                res = invert_bits(u16_n, pos, num);
                print_bits(res);
                u16_n = num = pos = res = 0;
                break;

            case RIGHT_ROTATE_BITS:
                printf("RIGHT_ROTATE_BITS: Enter uint16_t number (u16_n), number of bits (num): ");
                scanf("%hu %d", &u16_n, &num);
                print_uint16_t_bits(u16_n);
                res = right_rotate_bits(u16_n, num);
                print_uint16_t_bits(res);
                u16_n = num = res = 0;
                break;

            default:
                fprintf(stderr, "%d@%s: Default\n", __LINE__, __FUNCTION__);
                break;
        }
    }

    return 0;
}
