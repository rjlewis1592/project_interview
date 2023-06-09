#include "cmn_hdr.h"
#include "cmn_defs.h"

size_t my_strlen(const char *s)
{
    size_t slen = 0;
    unsigned int i = 0;

    if (!s) {
        fprintf(stderr,  "Err - invalid input s %p. Exiting...\n", s);
        exit (EXIT_FAILURE);
    }

    for (i = 0; s[i] != '\0'; i++) {
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