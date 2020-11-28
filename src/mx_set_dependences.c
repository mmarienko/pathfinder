#include "../inc/pathfinder.h"

void mx_set_dependences(t_graph **graph, const char *from, const char *to, const char *distance) {
    if (!graph || !(*graph) || !from || !to || !distance)
        return;

    if (mx_check_isduplicate(*graph, from, to)) {
        mx_printerr("error: duplicate bridges\n");
        mx_delete_graph(graph);
        exit(EXIT_FAILURE);
    }

    int index1 = mx_get_vertex_index(*graph, from);
    int index2 = mx_get_vertex_index(*graph, to);
    size_t dist = mx_atoi(distance);

    if (index1 == -1 || index2 == -1)
        return;

    (*graph)->dependences[index1][index2] = dist;
    (*graph)->dependences[index2][index1] = dist;
}
