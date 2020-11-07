#include "../inc/pathfinder.h"

int get_count_islands(const char *filename, int fd)
{
    char *str = (char *)malloc(sizeof(char));

    if (mx_read_line(&str, 1, '\n', fd) == -1)
    {
        mx_stderr("error: file ");
        mx_stderr(filename);
        mx_stderr(" is empty\n");
        exit(EXIT_FAILURE);
    }

    int rezult = mx_atoi(str);
    mx_strdel(&str);
    str = NULL;

    if (rezult <= 0)
    {
        mx_stderr("error: line 1 is not valid\n");
        exit(EXIT_FAILURE);
    }

    return rezult;
}
