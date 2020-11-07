#include "../inc/libmx.h"

int mx_open_file(const char *filename) {
    int fd = open(filename, O_RDONLY);

    if (fd < 0)
    {
        mx_stderr("error: file ");
        mx_stderr(filename);
        mx_stderr(" does not exist\n");
        exit(EXIT_FAILURE);
    }

    return fd;
}
