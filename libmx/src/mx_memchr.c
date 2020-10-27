#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n)
{
    const char *big = (const char *)s;
    size_t length;
    for (length = 0; length < n; length++)
        if (big[length] == c)
            return (void *)&big[length];
    return NULL;
}
