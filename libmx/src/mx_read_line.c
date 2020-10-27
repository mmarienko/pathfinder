#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0) return -2;
    char *line = *lineptr;
    char buf[1];
    if (buf_size >= 65535) return -2;
    buf_size = 1;
    int k = 0;
    int i = 0;
    int n = read(fd, buf, buf_size);
    if (n == 0) return -1;
    while (n != 0) {
        if (buf[0] == delim) {
            line[i] = '\0';
            return k;
        }
        line[i++] = buf[0];
        k++;
        n = read(fd, buf, buf_size);
        if (n == -1) return -2;
    }
    line[i] = '\0';
    return k;
}
