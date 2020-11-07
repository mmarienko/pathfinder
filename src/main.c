#include "../inc/pathfinder.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        mx_stderr("usage: ./pathfinder [filename]\n");
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    int fd = mx_open_file(filename);
    size_t n = get_count_islands(filename, fd);
    t_c_node *bridges = get_bridges_from_file(fd);
    char **islands = get_islands_from_bridges(bridges, n);
    int **w_matrix = init_w_matrix(bridges, islands, n);
    int **h_matrix = init_h_matrix(bridges, islands, n);
    bool **rep_matrix = init_rep_matrix(n);
    init_floyds_algorithm(w_matrix, h_matrix, rep_matrix, n);
    print_shortest(w_matrix, h_matrix, islands, rep_matrix, n);
    mx_free_int_matrix(w_matrix, n);
    mx_free_int_matrix(h_matrix, n);
    mx_free_char_matrix(islands, n);

    return 0;
}
