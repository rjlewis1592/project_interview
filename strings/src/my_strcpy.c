#include "cmn_hdr.h"
#include "cmn_defs.h"

char *my_strcpy(char *dst, const char *src)
{
    unsigned int i = 0;

    if (!dst || !src) {
        return NULL;
    }

    for (i = 0; src[i] != '\0'; i++) {
        dst[i] = src[i];
    }

    dst[i] = '\0';

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