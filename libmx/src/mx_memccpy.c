#include "../inc/libmx.h"

void *mx_memccpy(void *restrictdst, const void *restrictsrc, int c, size_t n)
{
    char t;
    size_t i;
    char *dst = (char *)restrictdst;
    const char *src = (const char *)restrictsrc;

    for (i = 0; i < n; i++)
    {
        dst[i] = t = src[i];
        if (t == '\0')
            break;
        if (t == c)
            return &dst[i + 1];
    }
    return NULL;
}
