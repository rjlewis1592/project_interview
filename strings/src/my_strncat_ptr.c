#include "cmn_hdr.h"
#include "cmn_defs.h"

char *my_strncat(char *s1, const char *s2, size_t n)
{
    size_t i;
    char *ts1 = NULL;
    const char *ts2 = NULL;

    if (!s1 || !s2) {
        fprintf(stderr, "s1 %p, s2 %p\n", s1, s2);
        return NULL;
    }

    ts2 = s2;
    ts1 = s1 + strlen(s1);

    for (i = 0; (i < n) && *ts1 != '\0'; ts1++, ts2++, i++) {
        *ts1 = *ts2; 
    }

    *ts1 = '\0';

    return s1;
}

int main(int argc, char *argv[])
{
    char s1[BUFSZ_1024] = {0};
    const char *s2 = NULL;
    size_t n = 0;

    if (argc != 4) {
        fprintf(stderr, "Usage: <a.out> <s1> <s2> <nbytes>\n");
        exit(EXIT_FAILURE);
    }

    strcpy(s1, argv[1]);
    s2 = (const char *)argv[2];
    n = (size_t)atoi(argv[3]);

    printf("Before: s1 \"%s\", s2 \"%s\", n %zu bytes\n", s1, s2, n);

    if (my_strncat(s1, s2, n) == NULL) {
        printf("Err - my_strncat()\n");
    }
    printf("After: s1 \"%s\", s2 \"%s\"\n", s1, s2);
    
    return 0;
}