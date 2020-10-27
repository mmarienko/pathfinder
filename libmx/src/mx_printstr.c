#include "../inc/libmx.h"

void mx_printstr(const char *s) {
    int y = mx_strlen(s);
    for (int i = 0; i < y; i++) {
        mx_printchar(s[i]);
    }
}
