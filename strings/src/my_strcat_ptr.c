#include "cmn_hdr.h"
#include "cmn_defs.h"

#if 0
char *my_strcat(char *s1, const char *s2)
{
    char *ts1 = NULL;
    const char *ts2 = NULL;

    if (!s1 || !s2) {
        fprintf(stderr, "Err - Invalid input: s1 %p, s2 %p\n", s1, s2);
        return NULL;
    }

    ts1 = s1 + strlen(s1);
    for (ts2 = s2; *ts2 != '\0'; ts2++, ts1++) {
        *ts1 = *ts2;
    }

    *ts1 = '\0';

    return s1;
}
#else
char *my_strcat(char *s1, const char *s2)
{

    if (!s1 || !s2) {
        fprintf(stderr, "Err - Invalid input: s1 %p, s2 %p\n", s1, s2);
        return NULL;
    }

    s1 = s1 + strlen(s1);
    for (;*s2 != '\0'; s1++, s2++) {
        *s1 = *s2;
    }

    *s1 = '\0';

    return s1;
}
#endif

int main(int argc, char *argv[])
{
    char s1[BUFSZ_1024] = {0};
    const char *s2 = NULL;

    if (argc != 3) {
        fprintf(stderr, "Usage: <a.out> <s1> <s2>\n");
        exit(EXIT_FAILURE);
    }

    strcpy(s1, argv[1]);
    s2 = (const char *)argv[2];

    printf("Before: s1 \"%s\", s2 \"%s\"\n", s1, s2);

    if (my_strcat(s1, s2) == NULL) {
        printf("Err - my_strcat()\n");
    }
    printf("After: s1 \"%s\", s2 \"%s\"\n", s1, s2);
    
    return 0;
}
