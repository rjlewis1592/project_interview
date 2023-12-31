#include "bit_ops_cmn.h"

#define BINARY_BASE             2
#define OCTAL_BASE              8
#define DECIMAL_BASE            10
#define HEXADECIMAL_BASE        16 

const char symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

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

int main(int argc, char *argv[])
{
    uint32_t decimal_num, base;

    if (argc != 3) {
        fprintf(stderr, "Usage: <a.out> <decimanl_number> <base>\n");
        exit (EXIT_FAILURE);
    }

    decimal_num = atoi(argv[1]);
    base = atoi(argv[2]);

    LOG_DBG("decimal_num %u, base %u\n", decimal_num, base);

    print_in_base(decimal_num, base);
    print_in_base_rec(decimal_num, base);

    return 0;
}
