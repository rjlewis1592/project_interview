#include "cmn_hdr.h"
#include "cmn_defs.h"

char *my_strncpy(char *dst, const char *src, size_t n)
{
    size_t i = 0;
    char *td = NULL;
    const char *ts = NULL;

    if (!dst || !src) {
        fprintf(stderr,  "Err - invalid args: dst %p, src %p\n", dst, src);
        return NULL;
    }

    for (ts = src, td = dst; (i < n) && (*ts != '\0'); ts++, td++) {
        *td = *ts;
        i++;
    }

    for (; i < n; i++) {
        *td = '\0';
    }

    return dst;

}
int main(int argc, char *argv[])
{
    size_t n = 0;
    char dst[BUFSZ_1024] = {0};
    const char *src = NULL;

    if (argc != 3) {
        fprintf(stderr, "Usage: <a.out> <string> <nbytes>\n");
        exit(EXIT_FAILURE);
    }

    src = (const char *)argv[1];
    n = (size_t)atoi(argv[2]); // atoi is risky - use stroul wrapper

    printf("src \"%s\", n %zu bytes\n", src, n);

    if (my_strncpy(dst, src, n) == NULL) {
        fprintf(stderr, "Err - my_strncpy()\n");
        goto clean_up;
    }

    if (n > 0) { // ensure to terminate 'dst' with '\0'
        dst[n - 1] = '\0';
        printf("dst \"%s\", src \"%s\"\n", dst, src);
    }
clean_up:
    // free()
    // close fd's and fp's
    return 0;
}