#include "cmn_hdr.h"
#include "cmn_defs.h"

char *my_strcpy(char *dst, size_t dst_sz, const char *src)
{
    char *td = NULL;
    const char *ts = NULL;
    size_t src_len = 0;

    if (!dst || !src) {
        fprintf(stderr, "Invalid inputs - dst %p, src %p\n", dst, src);
        return NULL;
    }

    for (ts = src; *ts != '\0'; ts++) {
        src_len++;
    }

    if (dst_sz < (src_len + 1)) {
        fprintf(stderr, "dst_sz: %zu bytes - insufficient buffer\n", dst_sz);
        return NULL;
    }

    for (ts = src, td = dst; *ts != '\0'; ts++, td++) {
        *td = *ts;
    }

    *td = '\0';

    return dst;
}

int main(int argc, char *argv[])
{
    char new_str[BUFSZ_8] = {0};

    if (argc != 2) {
        fprintf(stderr, "Usage: <a.out> <string>\n");
        exit(EXIT_FAILURE);
    }

    printf("argv[1]: \"%s\"\n", argv[1]);

    if (my_strcpy(new_str, BUFSZ_8, (const char *)argv[1]) != NULL) {
        printf("new_str: \"%s\"\n", new_str);
    }
    
    return 0;
}