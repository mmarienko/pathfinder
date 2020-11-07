#include "../inc/pathfinder.h"

t_c_node *get_bridges_from_file(int fd)
{
    char *src_t = NULL;
    char *dest_t = NULL;
    char *weight_t = NULL;
    t_c_node *bridges = NULL;
    
    for (int i = 0;; i++)
    {
        src_t = (char *)malloc(sizeof(char));
        dest_t = (char *)malloc(sizeof(char));
        weight_t = (char *)malloc(sizeof(char));

        if (mx_read_line(&src_t, 1, '-', fd) <= 0)
            break;
        if (mx_read_line(&dest_t, 1, ',', fd) <= 0)
            break;
        if (mx_read_line(&weight_t, 1, '\n', fd) <= 0)
            break;

        mx_c_push_back(&bridges, src_t, dest_t, weight_t);
    }

    mx_strdel(&src_t);
    mx_strdel(&dest_t);
    mx_strdel(&weight_t);

    return bridges;
}
