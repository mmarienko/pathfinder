#include "../inc/libmx.h"

void *mx_memcpy(void *restrictdst, const void *restrictsrc, size_t n)
{
    char *d = restrictdst;
    const char *s = restrictsrc;
    while (n--)
        *d++ = *s++;
    return restrictdst;
}
