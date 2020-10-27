#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int c = 1;
    int last = 0;
    if (str == NULL) {
        return -1;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter && str[i] != str[i - 1])
            c++;
        
        last = i;
    }

    if (str[0] == delimiter)
        c--;
    if (str[last] == delimiter)
        c--;

    return c;
}
