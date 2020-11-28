#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ");
        mx_printerr(argv[0]);
        mx_printerr(" [filename]\n");
        exit(EXIT_FAILURE);
    }

    int file = open(argv[1], O_RDONLY);

    if (file < 0) {
        close(file);
        mx_printerr("error: ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    int empty = mx_read_line(&line, 10, '\n', file); // later empty can b e removed

    if (empty == -1) {
        if (line) mx_strdel(&line);
        close(file);
        mx_printerr("error: ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(EXIT_FAILURE);
    }

    // check that number of islands are equal to this 
    size_t size = mx_atoi(line); // inputed number of islands

    if (size == 0) {
        mx_strdel(&line);
        close(file);
        mx_printerr("error: line 1 is not valid\n");
        exit(EXIT_FAILURE);
    }

    t_graph *graph = mx_create_graph(size);

    if (!graph) {
        mx_strdel(&line);
        close(file);
        mx_printerr("error: system error\n");
        exit(EXIT_FAILURE);
    }

    size_t index = 0; // for error generator

    while ((empty = mx_read_line(&line, 10, '\n', file)) != -1) {
        if (mx_get_char_index(line, '-') == -1 || mx_get_char_index(line, ',') == -1) {
            if (graph) mx_delete_graph(&graph);
            mx_strdel(&line);
            close(file);
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(index + 2));
            mx_printerr(" is not valid\n");
            exit(EXIT_FAILURE);
        }

        char *from = mx_strndup(line, mx_get_char_index(line, '-'));  // melloced
        char *to = mx_strndup(mx_strstr(line, "-") + 1, mx_get_char_index(mx_strstr(line, "-") + 1, ','));  // melloced
        char *distance = mx_strstr(line, ",") + 1;  // not melloced   // mx_atoi for adding to graph

        if (!mx_isvalid(from, to, distance)) {
            mx_delete_graph(&graph);
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
            mx_delete_graph(&graph);
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(EXIT_FAILURE);
        }

        mx_push_vertex(&graph, from);
        mx_push_vertex(&graph, to);
        mx_set_dependences(&graph, from, to, distance);

        index++;

        mx_strdel(&from);
        mx_strdel(&to);
    }

    // if (mx_get_last_vertex_index(graph) != graph->size) {
    //     mx_delete_graph(&graph);
    //     mx_strdel(&line);
    //     close(file);
    //     mx_printerr("error: invalid number of islands\n");
    //     exit(EXIT_FAILURE);
    // }

    if (mx_check_if_sum_is_too_big(graph)) {
        mx_delete_graph(&graph);
        mx_strdel(&line);
        close(file);
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(EXIT_FAILURE);
    }

    // ~~~~~~~~~~~~~~~ print graph ~~~~~~~~~~~~~~~ //

    // mx_printstr("size: ");
    // mx_printint(graph->size);
    // mx_printchar('\n');

    // mx_printchar('\n');
    // mx_print_strarr(graph->vertices, " | ");
    // mx_printchar('\n');

    // for (size_t i = 0; i < graph->size; i++) {
    //     for (size_t j = 0; j < graph->size; j++) {
    //         mx_printchar('[');
    //         mx_printint(graph->dependences[i][j]);
    //         mx_printchar(']');
    //     }

    //     mx_printchar('\n');
    // }

    // mx_printchar('\n');

    // ~~~~~~~~~~~~~~~ print graph ~~~~~~~~~~~~~~~ //

    for (size_t i = 0; i < graph->size; i++)
        mx_dijkstra(&graph, graph->vertices[i]); 

    mx_delete_graph(&graph);
    mx_strdel(&line);
    close(file);
}
