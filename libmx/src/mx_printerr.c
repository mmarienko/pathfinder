#include "../inc/libmx.h"

void mx_printerr(const char *str) {
    write(STDERR_FILENO, str, mx_strlen(str));
}
