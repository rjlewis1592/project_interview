#include "bit_ops_cmn.h"

#define BINARY_BASE             2
#define OCTAL_BASE              8
#define DECIMAL_BASE            10
#define HEXADECIMAL_BASE        16 

#define SET_NW(n) (((n) + 31) >> 5)
#define SET_W(index) ((index) >> 5)
#define SET_MASK(index) (1U << ((index) & 31))

#define SET_DECLARE(name, size) uint32_t name[SET_NW(size)] = {0}
#define SET_1(name, index) (name[SET_W(index)] |= SET_MASK(index))
#define SET_0(name, index) (name[SET_W(index)] &= ~SET_MASK(index))
#define SET_GET(name, index) (name[SET_W(index)] & SET_MASK(index))

#define print_bits_generic(where, n) _Generic((n), \
                uint8_t: print_bits_uint8_t, \
                int8_t: print_bits_uint8_t, \
                uint16_t: print_bits_uint16_t, \
                int16_t: print_bits_uint16_t, \
                uint32_t: print_bits_uint32_t, \
                int32_t: print_bits_uint32_t, \
                uint64_t: print_bits_uint64_t, \
                int64_t: print_bits_uint64_t) \
            (where, n)

#if 0
enum {
    a = 255,
    b = 65535,
    c = 4294967295,
    d = 18446744073709551615
} maxes;
#endif

const char symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

const char* bit_rep[16] = {
    "0000", "0001", "0010", "0011",
    "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011",
    "1100", "1101", "1110", "1111",
};
#if 0
void print_bits_uint8_t(FILE *out, uint8_t n) {
    fprintf(out, "%s%s", bit_rep[n >> 4], bit_rep[n & 0xFu]);
}
void print_bits_uint16_t(FILE *out, uint16_t n) {
    print_bits_uint8_t(out, n >> 8); // first 8 bits
    print_bits_uint8_t(out, n & 0xFFu); // last 8 bits
}
void print_bits_uint32_t(FILE *out, uint32_t n) {
    print_bits_uint16_t(out, n >> 16); // first 16 bits
    print_bits_uint16_t(out, n & 0xFFFFu); // last 16 bits
}
void print_bits_uint64_t(FILE *out, uint64_t n) {
    print_bits_uint32_t(out, n >> 32); // first 32 bits
    print_bits_uint32_t(out, n & 0xFFFFFFFFu); // last 32 bits
}
#endif

void swap_xor(uint8_t *a, uint8_t *b)
{

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

uint8_t next_power_of_two_naive_uint8(uint8_t n)
{
    uint8_t r = 0x1U;

    while (r <= n)  {
        r = (r * 2); // or r<<=1
    }

    return r;
}

uint8_t next_power_of_two_uint8(uint8_t n)
{
    if (n == 0)
        return 1;

    n--;

    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    //n |= (n >> 8);

    n++;
    
    return n;
}

uint32_t next_power_of_two_uint32(uint32_t n)
{
    if (n == 0)
        return 1;

    n--;

    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);

    n++;
    
    return n;
}

uint16_t next_power_of_two_naive_uint16(uint16_t n)
{
    uint16_t r = 0x1U;

    while (r < n)  {
        r = (r * 2); // or r<<=1
    }

    return r;
}

uint32_t next_power_of_two_naive_uint32(uint32_t n)
{
    uint32_t r = 0x1U;

    while (r < n)  {
        r = (r * 2); // or r<<=1
    }

    return r;
}

bool is_power_of_two(uint32_t n)
{
    return (n && (!(n & (n - 1))));
}

void get_remainder(u_int16_t u16_n)
{
    int i;

    if ((u16_n & (u16_n - 1)) != 0) {
        LOG_ERR("%hu is NOT a power of 2", u16_n);
        return;
    } 

    for (i = 1; i < 100; i++) {
        printf("%2d mod %d = %2d%c", i, u16_n, (i & (u16_n - 1)), ((i & (u16_n - 1)) != 0) ? ' ' : '\n');
    }

    printf("\n");
}

// 0xDCBEu; // 1101 1100 1011 1110
uint16_t get_bits(uint16_t n, int i, int j)
{
    return  ((n >> i)  & (~(~0x0U << (j - i + 1))));
}

void replace_bits(uint16_t *n, uint16_t m, uint8_t i, uint8_t j)
{
    (*n) =  ((*n) & ((~((~(~0x0U << (j - i + 1))) << (i))) | ((m) << (i))));
}

void pairwise_swap(uint16_t *u16)
{
    *u16 = (((*u16) & 0xAAAAU) >> 0x1U) | (((*u16) & 0x5555U) << 0x1U);
}

void print_bits_uint8_t(FILE *out, uint8_t n)
{
    fprintf(out, "%s%s", bit_rep[n >> 4U], bit_rep[n & 0xFU]);
}

void print_bits_uint16_t(FILE *out, uint16_t n)
{
    print_bits_uint8_t(out, (n >> 8U));
    printf(" ");
    print_bits_uint8_t(out, (n & 0xFFU));
}

void print_bits_uint32_t(FILE *out, uint32_t n)
{
    print_bits_uint16_t(out, (n >> 16U));
    printf(" ");
    print_bits_uint16_t(out, (n & 0xFFFFU));
}

void print_bits_uint64_t(FILE *out, uint64_t n)
{
        print_bits_uint32_t(out, (n >> 32U));
        printf(" ");
        print_bits_uint32_t(out, (n & 0xFFFFFFFFU));
}

void revsere_str(char s[])
{
    int i, j;
    char ch;

    for (i = 0, j = (strlen(s) - 1); i < j; i++, j--) {
        ch = s[i];
        s[i] = s[j];
        s[j] = ch;
    }

    return;
}

void print_in_base(uint32_t decimal_num, uint32_t base)
{
    char conv_str[32] = {0};
    uint32_t tmp, remainder = 0;
    int i = 0;

    LOG_DBG("decimal_num %u, base %u\n", decimal_num, base);

    if ((base != BINARY_BASE) && (base != OCTAL_BASE) && (base != HEXADECIMAL_BASE)) {
        LOG_ERR("Invalid base %u\n", base);
        return;
    }

    i = 0;
    tmp = decimal_num;
    while (tmp > 0) {
        remainder = tmp % base;
        conv_str[i++] = symbols[remainder];
        tmp = tmp / base;
    }

    revsere_str(conv_str);

    LOG_DBG("(%d) base (10) = %s%s\n", decimal_num, ((base == 2) ? "0b" : ((base == 8) ? "0o" : "0x")), conv_str);

    return;
}

void print_in_base_rec0(uint32_t decimal_num, uint32_t base)
{
    int r = 0;

    if (decimal_num == 0) {
        printf("%s", ((base == 2) ? "0b" : ((base == 8) ? "0o" : "0x")));
        return;
    }

    r = decimal_num % base;

    print_in_base_rec0((decimal_num / base), base);

    printf("%c", symbols[r]);

}

void print_in_base_rec(uint32_t decimal_num, uint32_t base)
{
    if ((base != BINARY_BASE) && (base != OCTAL_BASE) && (base != HEXADECIMAL_BASE)) {
        LOG_ERR("Invalid base %u\n", base);
        return;
    } 

    print_in_base_rec0(decimal_num, base);
    printf("\n");
}

void print_uint16_t_bits(uint16_t u16_n)
{
    int i;

    for (i = ((sizeof(uint16_t) * NBBY) - 1); i >= 0; i--) { 
        printf("%d",((u16_n & (0x1u << i)) ? 1 : 0));


        if ((i % NBBY) == 0)
           printf(" ");
    }

    printf("\n");

    return;
}

void print_uint16_t_bits_simple_rec(uint16_t u16_n)
{
    if (u16_n == 0) {
        return;
    }

    print_uint16_t_bits_simple_rec((u16_n >> 1));
    printf("%d", (u16_n & 0x1U));

    return;
}

void demo_print_bits_generic(void)
{
    uint8_t a = 145;
    uint16_t b = 1089;
    uint32_t c = 30432;
    int32_t d = 3232;

    printf("uint8_t 145: "); // works on uint8_t !
    print_bits_generic(stdout, a);
    printf("\n"); // works on uint8_t !
    printf("uint16_t 1089: "); // works on uint8_t !
    print_bits_generic(stdout, b);
    printf("\n"); // works on uint16_t !
    printf("uint32_t 1089: "); // works on uint8_t !
    print_bits_generic(stdout, c);
    printf("\n"); // works on uint32_t !
    printf("int32_t 1089: "); // works on uint8_t !
    print_bits_generic(stdout, d);
    printf("\n"); // works on int32_t !
}

int main(int argc, char *argv[])
{
    uint32_t decimal_num, base;
    uint64_t u64_n;
    uint32_t u32_n;
    uint16_t u16_n;
    uint8_t u8_n;

    if (argc != 3) {
        fprintf(stderr, "Usage: <a.out> <decimanl_number> <base>\n");
        exit (EXIT_FAILURE);
    }

    decimal_num = atoi(argv[1]);
    base = atoi(argv[2]);

    LOG_DBG("decimal_num %u, base %u\n", decimal_num, base);

    demo_print_bits_generic();

    print_in_base(decimal_num, base);

    printf("BASE REC: ");
    print_in_base_rec(decimal_num, base);

    printf("Enter uint16_t number: ");
    scanf("%hu", &u16_n);

    printf("UIN16_T BITS: ");
    print_uint16_t_bits(u16_n);


    printf("BITS REC: ");
    print_uint16_t_bits_simple_rec(u16_n);
    printf("\n");

    printf("Enter uint8_t number: ");
    scanf("%hhu", &u8_n);

    print_bits_uint8_t(stdout, u8_n);
    printf("\n");
    print_bits_uint16_t(stdout, u16_n);
    printf("\n");

    printf("Enter uint32_t number: ");
    scanf("%u", &u32_n);
    print_bits_uint32_t(stdout, u32_n);
    printf("\n");

    printf("Enter uint64_t number: ");
    scanf("%llu", &u64_n);
    print_bits_uint64_t(stdout, u64_n);
    printf("\n");

    print_bits_uint8_t(stdout, 255U);
    printf("\n");
    print_bits_uint16_t(stdout, 65535U);
    printf("\n");
    print_bits_uint32_t(stdout, 4294967295U);
    printf("\n");
    print_bits_uint64_t(stdout, 18446744073709551615ULL);
    printf("\n");


    u16_n = 0x0U;
    printf("Enter uint16_t number for pairwise swap: ");
    scanf("%hu", &u16_n);
    print_bits_uint16_t(stdout, u16_n);
    printf("\n");
    pairwise_swap(&u16_n);
    print_bits_uint16_t(stdout, u16_n);
    printf("\n");

    u16_n = 0xDCBEu; // 1101 1100 1011 1110
    print_bits_uint16_t(stdout, u16_n);
    printf("\n");
    replace_bits(&u16_n, 0x1u, 3, 6);
    print_bits_uint16_t(stdout, u16_n);
    printf("\n");


    u16_n = 0xDCBEu; // 1101 1100 1011 1110
    printf("GET BITS: u16_n: ");
    print_bits_uint16_t(stdout, u16_n);
    printf("\n");
    printf("GET BITS:  ");
    print_bits_uint16_t(stdout, get_bits(u16_n, 3, 6));
    printf("\n");

    printf("Enter a uint16_t number: ");
    scanf("%hu", &u16_n);
    get_remainder(u16_n);

#if 0
    uint8_t a = 0x0U, b = 0x1U, c = 0x2U, d = 0x3U, e = 0x4U, f = 0x5U, g = 0x7U, h = 127U, i = 128U, j = 0xFFU;
    printf("next power of 2 for %u: %u\n", a, next_power_of_two_naive_uint8(a));
    printf("next power of 2 for %u: %u\n", b, next_power_of_two_naive_uint8(b));
    printf("next power of 2 for %u: %u\n", c, next_power_of_two_naive_uint8(c));
    printf("next power of 2 for %u: %u\n", d, next_power_of_two_naive_uint8(d));
    printf("next power of 2 for %u: %u\n", e, next_power_of_two_naive_uint8(e));
    printf("next power of 2 for %u: %u\n", f, next_power_of_two_naive_uint8(f));
    printf("next power of 2 for %u: %u\n", g, next_power_of_two_naive_uint8(g));
    printf("next power of 2 for %u: %u\n", h, next_power_of_two_naive_uint8(h));
    printf("next power of 2 for %u: %u\n", i, next_power_of_two_naive_uint8(i));
    printf("next power of 2 for %u: %u\n", j, next_power_of_two_naive_uint8(j));
#else
    uint8_t a = 0x0U, b = 0x1U, c = 0x2U, d = 0x3U, e = 0x4U, f = 0x5U, g = 0x7U, h = 127U, i = 128U, j = 0xFFU; 
    printf("next power of 2 for %u: %u\n", a, next_power_of_two_uint8(a));
    printf("next power of 2 for %u: %u\n", b, next_power_of_two_uint8(b));
    printf("next power of 2 for %u: %u\n", c, next_power_of_two_uint8(c));
    printf("next power of 2 for %u: %u\n", d, next_power_of_two_uint8(d));
    printf("next power of 2 for %u: %u\n", e, next_power_of_two_uint8(e));
    printf("next power of 2 for %u: %u\n", f, next_power_of_two_uint8(f));
    printf("next power of 2 for %u: %u\n", g, next_power_of_two_uint8(g));
    printf("next power of 2 for %u: %u\n", h, next_power_of_two_uint8(h));
    printf("next power of 2 for %u: %u\n", i, next_power_of_two_uint8(i));
    printf("next power of 2 for %u: %u\n", j, next_power_of_two_uint8(j));

    uint32_t aa = 0x0U, bb = 0x1U, cc = 0x2U, dd = 0x3U, ee = 0x4U, ff = 0x5U, gg = 0x7U, hh = 127U, ii = 128U, jj = UINT32_MAX; 
    printf("next power of 2 for %u: %u\n", aa, next_power_of_two_uint32(aa));
    printf("next power of 2 for %u: %u\n", bb, next_power_of_two_uint32(bb));
    printf("next power of 2 for %u: %u\n", cc, next_power_of_two_uint32(cc));
    printf("next power of 2 for %u: %u\n", dd, next_power_of_two_uint32(dd));
    printf("next power of 2 for %u: %u\n", ee, next_power_of_two_uint32(ee));
    printf("next power of 2 for %u: %u\n", ff, next_power_of_two_uint32(ff));
    printf("next power of 2 for %u: %u\n", gg, next_power_of_two_uint32(gg));
    printf("next power of 2 for %u: %u\n", hh, next_power_of_two_uint32(hh));
    printf("next power of 2 for %u: %u\n", ii, next_power_of_two_uint32(ii));
    printf("next power of 2 for %u: %u\n", jj, next_power_of_two_uint32(jj));
#endif

    // Declares uint32_t bitset[3] = {0};
    SET_DECLARE(bitset, 84);

    // Sets the bits 1 and 80 to 1
    SET_1(bitset, 1);
    SET_1(bitset, 80);

    printf("Is bit %d set? Answer: %s.\n", 1, SET_GET(bitset, 1) ? "YES" : "NO");
    printf("Is bit %d set? Answer: %s.\n", 2, SET_GET(bitset, 2) ? "YES" : "NO");
    printf("Is bit %d set? Answer: %s.\n", 80, SET_GET(bitset, 80) ? "YES" : "NO");


    char *p = "ABCDEFGH";
    while(*p) {
        printf("%c", *p | ' ');
        p++;
    }
    printf("\n");

    char *q = "abcdefgh";
    while (*q)
    {
        printf("%c", *q & '_');
        q++;
    }
    printf("\n");

    char *r = "aBcDeFgH";
    while (*r)
    {
        printf("%c", *r ^ ' ');
        r++;
    }
    printf("\n");

    // Getting the lowercase letter position in the alphabet
    for (char i = 'a'; i <= 'z'; i++)
    {
        printf("%c --> %d\n", i, (i ^ '`'));
    }

    // Getting the uppercase letter position in the alphabet
    for (char i = 'A'; i <= 'Z'; i++)
    {
        printf("%c --> %d\n", i, (i & '?'));
    }

    return 0;
}
