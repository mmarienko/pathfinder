#include "../inc/libmx.h"

char *mx_strndup(const char *str, size_t n) {
    size_t len = 0;
    char* copy;
    for (; len < n && str[len]; len++){} // while str exist (may be shorter than n)
    if ((copy = malloc(len + 1)) == NULL) {
        return NULL;
    }
    mx_strncpy(copy, str, len);
    return copy;
}
