#include "cmn_hdr.h"
#include "cmn_defs.h"

char *my_strstr(const char *haystack, const char *needle)
{
    size_t needlelen = 0; 

    if (!haystack || !needle) {
        return NULL;
    }

    needlelen = strlen(needle);
    for ( ;(haystack = strchr(haystack, *needle)) != NULL; haystack++) {
        if (strncmp(haystack, needle, needlelen) == 0) {
            return (char *)haystack;
        }
    }
    
    return NULL;
}

int main(int argc, char *argv[])
{

    char *str = NULL;

    if (argc != 3) {
        fprintf(stderr, "Usage: <a.out> <haystack> <needle>\n");
        exit(EXIT_FAILURE);
    }

    if ((str = my_strstr((const char *)argv[1], (const char *)argv[2])) != NULL) {
        printf("needle \"%s\" found at %s\n", argv[2], str);
    } else {
        printf("needle \"%s\" NOT found in haystack \"%s\"\n", argv[2], argv[1]);
    }

    return 0;
}