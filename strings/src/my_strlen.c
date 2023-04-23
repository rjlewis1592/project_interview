#include "cmn_hdr.h"
#include "cmn_defs.h"

int my_strlen(const char *s)
{
    int slen = 0;
    const char *ts = NULL;

    if (!s) {
        fprintf(stderr,  "Err - invalid input s %p\n", s);
        return -1;
    }

    for (ts = s; *ts != '\0'; ts++) {
        slen++;
    }

    return slen;
}

int main(int argc, char *argv[])
{
    int slen = 0;
    if (argc != 2) {
        fprintf(stderr, "Usage: <a.out> <string>\n");
        exit(EXIT_FAILURE);
    }

    slen = my_strlen((const char *)argv[1]);

    if (slen < 0) {
        fprintf(stderr, "Error calculating string length - slen %d\n", slen);
        exit(EXIT_FAILURE);
    }
    printf("Length of string \"%s\", slen %d bytes\n", argv[1], slen);

    return 0;
}