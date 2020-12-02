#include "../inc/pathfinder.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        mx_printerr("usage: ");
        mx_printerr(argv[0]);
        mx_printerr(" [filename]\n");
        exit(EXIT_FAILURE);
    }

    int file = open(argv[1], O_RDONLY);

    if (file < 0)
    {
        close(file);
        mx_printerr("error: ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    int empty = mx_read_line(&line, 10, '\n', file);

    if (empty == -1)
    {
        if (line)
            mx_strdel(&line);

        close(file);
        mx_printerr("error: ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(EXIT_FAILURE);
    }

    size_t size = mx_atoi(line); 

    if (size == 0)
    {
        mx_strdel(&line);
        close(file);
        mx_printerr("error: line 1 is not valid\n");
        exit(EXIT_FAILURE);
    }

    t_bridge *bridges = NULL;

    char *from = NULL;
    char *to = NULL;
    char *distance = NULL;                                                     

    size_t index = 0; 

    while ((empty = mx_read_line(&line, 10, '\n', file)) != -1)
    {
        if (mx_get_char_index(line, '-') == -1 || mx_get_char_index(line, ',') == -1) {
            if (bridges) mx_free_bridge(bridges);
            mx_strdel(&line);
            close(file);
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(index + 2));
            mx_printerr(" is not valid\n");
            exit(EXIT_FAILURE);
        }

        from = mx_strndup(line, mx_get_char_index(line, '-'));
        to = mx_strndup(mx_strstr(line, "-") + 1, mx_get_char_index(mx_strstr(line, "-") + 1, ','));
        distance = mx_strndup(mx_strstr(line, ",") + 1, mx_get_char_index(mx_strstr(line, ",") + 1, '\n'));

        if (!mx_isvalid(from, to, distance)) {
            mx_free_bridge(bridges);
            mx_strdel(&line);
            mx_strdel(&from);
            mx_strdel(&to);
            close(file);
            char *line_index = mx_itoa(index + 2);
            mx_printerr("error: line ");
            mx_printerr(line_index);
            mx_printerr(" is not valid\n");
            mx_strdel(&line_index);
            exit(EXIT_FAILURE);
        }

        if (mx_atoi(distance) > INT_MAX) {
            mx_free_bridge(bridges);
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(EXIT_FAILURE);
        }

        mx_push_bridge_back(&bridges, from, to, distance);

        index++;
    }

    // if (mx_bridge_size(bridges) != size) {
    //     mx_free_bridge(bridges);
    //     mx_strdel(&line);
    //     close(file);
    //     mx_printerr("error: invalid number of islands\n");
    //     exit(EXIT_FAILURE);
    // }

    // if (mx_check_if_sum_is_too_big(graph)) {
    //     mx_delete_graph(&graph);
    //     mx_strdel(&line);
    //     close(file);
    //     mx_printerr("error: sum of bridges lengths is too big\n");
    //     exit(EXIT_FAILURE);
    // }

    char **islands = init_islands(bridges, size);
    int **matrix = init_matrix(bridges, islands, size);

    printf("        ");

    for (size_t i = 0; i < size; i++)
    {
        printf("%8s", islands[i]);
    }
    printf("\n\n");

    for (size_t i = 0; i < size; i++)
    {
        printf("%8s", islands[i]);
        for (size_t j = 0; j < size; j++)
        {
            printf("%8d", matrix[i][j]);
        }
        printf("\n");
    }

    mx_free_bridge(bridges);
    mx_strdel(&line);
    close(file);
}
