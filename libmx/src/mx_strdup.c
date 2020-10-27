#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    char *result = mx_strnew(mx_strlen(str) + 1);
    return (mx_strcpy(result,str));
}
