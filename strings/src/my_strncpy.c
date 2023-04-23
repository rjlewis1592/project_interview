#include "cmn_hdr.h"
#include "cmn_defs.h"

// the dst_bufsz should be the the (min(s, stlren(src)) + 1)
char *my_strncpy(char *dst, size_t dst_bufsz, const char *src, size_t n)
{
    size_t i;
    size_t src_len = 0;

    if (!dst || !src) {
        fprintf(stderr, "Err - dst %p, src %p\n", dst, src);
        return dst;
    }

    memset(dst, 0, dst_bufsz);

    for (i = 0; src[i] != '\0'; i++) {
        src_len++;
    }

    n =  (n > src_len) ? src_len : n;
     
    printf("%d@%s: dst_bufsz: %zu bytes, n: %zu bytes, src_len: %zu bytes\n", __LINE__, __FUNCTION__, dst_bufsz, n, src_len);

    if (dst_bufsz < (n + 1)) {
        fprintf(stderr,  "Err - insufficient destination buffer\n");
        return dst;
    }

    for (i = 0; i < n; i++) {
       dst[i] = src[i]; 
    }

    dst[i] = '\0';

    return dst;
}

int main(int argc, char *argv[])
{
#define DST_BUFSZ   BUFSZ_8
    char dst[DST_BUFSZ] = {0};
    const char *src = NULL;
    size_t nbytes = 0;

    if (argc != 3) {
        fprintf(stderr, "Usage: <a.out> <string> <nbytes>\n");
        exit(EXIT_FAILURE);
    }

    src = (const char *)argv[1];
    nbytes = (size_t) atoi(argv[2]); // risky - use strtoul wrapper

    printf("src: \"%s\", nbytes %zu\n", src, nbytes);

    printf("dst: \"%s\"\n", my_strncpy(dst, DST_BUFSZ, src, nbytes));

    return 0;
}