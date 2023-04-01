#include "cmn_hdr.h"

void log_msg(const char *str)
{
    printf("%s, %d: \"%s\"\n", __FUNCTION__, __LINE__, str);
}