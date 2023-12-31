#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <stdint.h>

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

    printf("%s, %d: decimal_num %u, base %u\n", __FUNCTION__, __LINE__, decimal_num, base);

    if ((base != 2) && (base != 8) && (base != 16)) {
        fprintf(stderr, "Invalid base %u\n", base);
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

    printf("(%d) base (10) = %s%s\n", decimal_num, ((base == 2) ? "0b" : ((base == 8) ? "0o" : "0x")), conv_str);

    return;
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

    printf("%s, %d: decimal_num %u, base %u\n", __FUNCTION__, __LINE__, decimal_num, base);

    print_in_base(decimal_num, base);

    return 0;
}
