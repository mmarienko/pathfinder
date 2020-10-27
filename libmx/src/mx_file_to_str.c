#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        return NULL;
    }
    char buf;
    int count = 0;

    while (read(fd, &buf, 1) > 0) {
        count++;
    }
    close(fd);

    char* str = malloc(count + 1);
    int fd2 = open(file, O_RDONLY);

    count = 0;
    while (read(fd, &buf, 1) > 0) {
        str[count] = buf;
        count++;
    }
    close (fd2);
    
    str[count] = '\0';
    return str;
}

