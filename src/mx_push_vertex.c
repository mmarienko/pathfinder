#include "../inc/pathfinder.h"

void mx_push_vertex(t_graph **graph, const char *vertex) {
    if (!graph || !(*graph) || !vertex)
        return;

    if (mx_get_vertex_index(*graph, vertex) != -1)
        return;

    size_t last_index = mx_get_last_vertex_index(*graph);

    if (last_index == (*graph)->size) {
        mx_delete_graph(graph);
        mx_printerr("error: invalid number of islands\n");
        exit(EXIT_FAILURE);
    }

    (*graph)->vertices[last_index] = mx_strdup(vertex);
}
