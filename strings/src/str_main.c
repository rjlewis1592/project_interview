#include "cmn_hdr.h"
#include "cmn_defs.h"
#include "str_utils.h"

int main(int argc, char *argv[])
{
    char str[BUFSZ_8] = {0};

    if (argc != 2) {
        fprintf(stderr, "Usage: <a.out> <string>\n");
        exit (EXIT_FAILURE);
    }

    printf("argv[1]: \"%s\"\n", argv[1]);
    my_strcpy(str, argv[1]);

    printf("str: \"%s\"\n", str);

    return 0;
}