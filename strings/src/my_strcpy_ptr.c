#include "cmn_hdr.h"
#include "cmn_defs.h"

char *my_strcpy(char *dst, const char *src)
{
    char *td = NULL;
    const char *ts = NULL;

    if (!dst || !src) {
        return NULL;
    }

    printf("%d@%s: src \"%s\"\n", __LINE__, __FUNCTION__, src);

    for (ts = src, td = dst; *ts != '\0'; ts++, td++) {
        *td = *ts;
    }

    printf("%d@%s: dst \"%s\"\n", __LINE__, __FUNCTION__, dst);

    return dst;
}

int main(int argc, char *argv[])
{
    char dst[BUFSZ_256] = {0};
    const char *src = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: <a.out> <string>\n");
        exit(EXIT_FAILURE);
    }

    src = (const char *) argv[1]; 
    printf("%d@%s: src \"%s\"\n", __LINE__, __FUNCTION__, src);

    if (my_strcpy(dst, src) != NULL) {
        printf("%d@%s: dst \"%s\"\n", __LINE__, __FUNCTION__, dst);
    }
    
    return 0;
}