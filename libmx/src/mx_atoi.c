#include "../inc/libmx.h"

size_t mx_atoi(const char *str) {
    if (!str)
        return 0;
    
    size_t num = 0;

    for (int i = 0; i < mx_strlen(str); i++) {
        if (mx_isdigit(str[i]))
            num = num * 10 + (size_t)str[i] - 48;
        else
            return 0;
    }

    return num;
}
