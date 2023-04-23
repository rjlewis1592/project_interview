#include "cmn_hdr.h"
#include "cmn_defs.h"

char *my_strcat(char *s2, size_t s2_bufsz, const char *s1)
{
    char *ts2 = NULL;
    const char *ts1 = NULL;
    size_t s1_len = 0;
    size_t s2_len = 0;

    if (!s2 || !s1) {
        fprintf(stderr, "Err - Invalid input: s2 %p, s1 %p\n", s2, s1);
        return NULL;
    }

    for (ts1 = s1; *ts1 != '\0'; ts1++) {
        s1_len++; 
    }

    for (ts2 = s2; *ts2 != '\0'; ) {
        s2_len++; 
        ts2++; 
    }

    printf("s2_bufsz: %zu bytes, s2_len: %zu bytes, s1_len: %zu bytes\n", s2_bufsz, s2_len, s1_len);

    if (s2_bufsz < (s2_len + s1_len + 1)) {
        fprintf(stderr, "Insufficient s2 buffer size %zu bytes\n", s2_bufsz);
        return s2;
    }

    for (ts1 = s1; *ts1 != '\0'; ts1++, ts2++) {
        *ts2 = *ts1;
    }

    *ts2 = '\0';

    return s2;
}

#define S2_BUFSZ    (BUFSZ_8 + 1)

int main(int argc, char *argv[])
{
    char s2[S2_BUFSZ] = "Helloo";

    if (argc != 2) {
        fprintf(stderr, "Usage: <a.out> <string>\n");
        exit(EXIT_FAILURE);
    }

    printf("argv[1]: \"%s\", s2: \"%s\"\n", argv[1], s2);

    printf("After concatenation, s2: \"%s\"\n", my_strcat(s2, S2_BUFSZ, (const char *)argv[1]));
    
    return 0;
}