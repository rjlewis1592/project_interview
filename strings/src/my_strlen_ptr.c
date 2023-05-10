#include "cmn_hdr.h"
#include "cmn_defs.h"

size_t my_strlen(const char *s)
{
    size_t slen = 0;
    const char *ts = NULL;

    if (!s) {
        fprintf(stderr,  "Err - invalid input s %p. Exiting...\n", s);
        exit (EXIT_FAILURE);
    }

    for (ts = s; *ts != '\0'; ts++) {
        slen++;
    }

    return slen;
}

int main(int argc, char *argv[])
{
    size_t slen = 0;
    const char *s = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: <a.out> <string>\n");
        exit(EXIT_FAILURE);
    }

    s = (const char *)argv[1];

    printf("%d@%s: s \"%s\"\n", __LINE__, __FUNCTION__, s);

    slen = my_strlen(s);

    printf("Length of string \"%s\", slen %zu bytes\n", s, slen);

    return 0;
}