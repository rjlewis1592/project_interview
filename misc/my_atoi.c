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

int my_atoi(const char *s)
{
    int i = INT_MIN;
    int sign = 1;
    int n = INT_MIN;

    if (!s)
        return 0;

    i = 0;
    while (s[i] == ' ') {
        i++;
    }

    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        sign = 1;
        i++;
    }

    n = 0;
    for ( ; ((s[i] >= '0') && (s[i] <= '9')); i++) {
        if ((n > INT_MAX/10)) {
            if (sign == -1) {
                printf("Underflow\n");
                return INT_MIN;
            } else {
                printf("Overflow\n");
                return INT_MAX;
            }
        } else if (n == INT_MAX/10) {
            if (sign == -1) {
                if (s[i] - '0' > 8) {
                    printf("Underflow\n");
                    return INT_MIN;
                }
            } else {
                if (s[i] - '0' > 7) {
                    printf("Overflow\n");
                    return INT_MAX;
                }
            }
        }

        n = n * 10 + s[i] - '0';

#if 0
        if ((n > INT_MAX/10) || ((n == INT_MAX/10) && (s[i] - '0' > 7))) {
            return ((sign == 1 ? INT_MAX : INT_MIN));
        }
        n = n * 10 + s[i] - '0';
#endif
    }

    return (n * sign);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: <a.out> <numeric_str>\n");
        exit (EXIT_FAILURE);
    }

    printf("argv[1]: \"%s\"\n", argv[1]);

    printf("%d\n", my_atoi((const char *)argv[1]));

    return 0;
}
