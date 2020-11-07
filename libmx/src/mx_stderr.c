#include "../inc/libmx.h"

void mx_stderr(const char *error) {
    write(STDERR_FILENO, error, mx_strlen(error));
}
