#include "cmn_hdr.h"
#include "cmn_defs.h"

int my_strlen(const char *s)
{
    size_t slen = 0;
    const char *ts  = NULL;

    if (!s)
        return -1;

    for (ts = s; *ts != '\0'; ts++) {
        slen++;
    }

    return slen;
}

char *my_strrev_one(char *s)
{
    int i, j, slen;
    char ch;

    if (!s) {
        fprintf(stderr, "Err - s %p\n", s);
        return s; // NULL
    }
    
    slen = my_strlen((const char *)s);
    if (slen < 0) {
        return s;
    }

    printf("%d@%s: slen %d bytes\n", __LINE__, __FUNCTION__, slen);

    memset(&ch, 0, sizeof(char));

    for (i = 0, j = (slen - 1); i < j; i++, j--)  {
        ch = s[i];
        s[i] = s[j];
        s[j] = ch;
   }

    printf("%d@%s: s \"%s\"\n", __LINE__, __FUNCTION__, s);

    return s;
}

int main(int argc, char *argv[])
{
    char *s = NULL;
    if (argc != 2) {
        fprintf(stderr, "Usage: <a.out> <string>\n");
        exit(EXIT_FAILURE);
    }

    s = argv[1];
    printf("original string - s: \"%s\"\n", s);

    my_strrev_one(s);

    printf("reversed string - s: \"%s\"\n", s);

    return 0;
}