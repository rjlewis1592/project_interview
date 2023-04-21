/* Implementation of string functions */
#include "cmn_hdr.h"
#include "cmn_defs.h"

char *my_strcpy(char *dst, const char *src)
{
    if (!dst || !src) {
        fprintf(stderr, "Error: dst %p, src %p\n", dst, src);
        return NULL;
    }

    while (*src != '\0') {
        *dst++ = *src++;
    }

    *dst = '\0';

    return dst;
}